import pytest
from interpreter import Expression, Constant, Variable, Not, And, Or, Parser

def test_constants_and_variables():
	"""
	Test evaluating constants and variable lookups.
	"""
	ctx = {"x": True, "y": False}
	assert Constant(True).interpret(ctx) is True
	assert Constant(False).interpret(ctx) is False
	assert Variable("x").interpret(ctx) is True
	assert Variable("y").interpret(ctx) is False

def test_composition_not_and_or():
	"""
	Test composition of NOT, AND, and OR.
	"""
	ctx = {"x": True, "y": False, "z": True}
	# !(x & y) | z
	expr = Or(
		Not(And(Variable("x"), Variable("y"))),
		Variable("z")
	)
	assert expr.interpret(ctx) is True

def test_operator_precedence():
	"""
	AND has higher precedence than OR; NOT has highest.
	"""
	ctx = {"x": False, "y": True, "z": True}
	# x | y & z  == x | (y & z) == True
	expr = Or(
		Variable("x"),
		And(Variable("y"), Variable("z"))
	)
	assert expr.interpret(ctx) is True

def test_unbound_variable_raises_keyerror():
	"""
	Variables absent from context should raise KeyError.
	"""
	ctx = {}
	with pytest.raises(KeyError):
		Variable("missing").interpret(ctx)

def test_parser_happy_path():
	"""
	Parse a valid expression and evaluate it.
	"""
	ctx = {"x": True, "y": False, "z": True}
	e = Parser("!(x & y) | z").parse()
	assert e.interpret(ctx) is True

def test_parser_errors():
	"""
	Invalid syntax should raise ValueError.
	"""
	with pytest.raises(ValueError):
		Parser("(").parse()
	with pytest.raises(ValueError):
		Parser("true garbage").parse()
	with pytest.raises(ValueError):
		Parser("! )").parse()
