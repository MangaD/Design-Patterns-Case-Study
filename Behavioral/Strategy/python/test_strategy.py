import pytest
from strategy import Context, ConcreteStrategyA, ConcreteStrategyB

def test_concrete_strategy_a():
	"""
	Test that ConcreteStrategyA executes correctly.
	"""
	context = Context()
	context.set_strategy(ConcreteStrategyA())
	result = context.execute_strategy()
	assert result == "Executing strategy A.", "ConcreteStrategyA should execute correctly."

def test_concrete_strategy_b():
	"""
	Test that ConcreteStrategyB executes correctly.
	"""
	context = Context()
	context.set_strategy(ConcreteStrategyB())
	result = context.execute_strategy()
	assert result == "Executing strategy B.", "ConcreteStrategyB should execute correctly."

def test_no_strategy_set():
	"""
	Test that executing without setting a strategy raises an exception.
	"""
	context = Context()
	with pytest.raises(ValueError, match="No strategy set!"):
		context.execute_strategy()

def test_switching_strategies():
	"""
	Test switching strategies at runtime.
	"""
	context = Context()
	context.set_strategy(ConcreteStrategyA())
	assert context.execute_strategy() == "Executing strategy A."

	context.set_strategy(ConcreteStrategyB())
	assert context.execute_strategy() == "Executing strategy B."
