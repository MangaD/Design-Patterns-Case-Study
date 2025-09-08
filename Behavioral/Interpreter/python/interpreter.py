from typing import Dict

class Expression:
	"""
	Represents an expression in a simple boolean grammar.
	All concrete expressions must implement the interpret method.
	"""
	def interpret(self, ctx: Dict[str, bool]) -> bool:
		"""
		Interprets the expression under the provided context.

		:param ctx: A dictionary mapping variable names to boolean values.
		:return: The boolean result of evaluating the expression.
		:raises NotImplementedError: If not implemented in a subclass.
		"""
		raise NotImplementedError("Subclasses must implement interpret().")


class Constant(Expression):
	"""
	Terminal expression representing a boolean constant.
	"""
	def __init__(self, value: bool):
		"""
		Initializes a constant expression.

		:param value: The boolean literal value.
		"""
		self._value = value

	def interpret(self, ctx: Dict[str, bool]) -> bool:
		"""
		Returns the stored literal value (context is ignored).

		:param ctx: The interpretation context (unused).
		:return: The stored boolean literal.
		"""
		return self._value


class Variable(Expression):
	"""
	Terminal expression representing a variable lookup.
	"""
	def __init__(self, name: str):
		"""
		Initializes a variable expression.

		:param name: The variable name to look up in the context.
		"""
		self._name = name

	def interpret(self, ctx: Dict[str, bool]) -> bool:
		"""
		Looks up the variable value in the context.

		:param ctx: The interpretation context.
		:return: The boolean value bound to the variable.
		:raises KeyError: If the variable is not present in the context.
		"""
		if self._name not in ctx:
			raise KeyError(f"Unbound variable: {self._name}")
		return ctx[self._name]


class Not(Expression):
	"""
	Nonterminal expression for logical NOT.
	"""
	def __init__(self, expr: Expression):
		"""
		Initializes a NOT expression.

		:param expr: The operand to negate.
		"""
		self._expr = expr

	def interpret(self, ctx: Dict[str, bool]) -> bool:
		"""
		Evaluates logical negation of the operand.

		:param ctx: The interpretation context.
		:return: The negated boolean value.
		"""
		return not self._expr.interpret(ctx)


class And(Expression):
	"""
	Nonterminal expression for logical AND.
	"""
	def __init__(self, left: Expression, right: Expression):
		"""
		Initializes an AND expression.

		:param left: The left operand.
		:param right: The right operand.
		"""
		self._left = left
		self._right = right

	def interpret(self, ctx: Dict[str, bool]) -> bool:
		"""
		Evaluates logical conjunction of both operands.

		:param ctx: The interpretation context.
		:return: The result of left AND right.
		"""
		return self._left.interpret(ctx) and self._right.interpret(ctx)


class Or(Expression):
	"""
	Nonterminal expression for logical OR.
	"""
	def __init__(self, left: Expression, right: Expression):
		"""
		Initializes an OR expression.

		:param left: The left operand.
		:param right: The right operand.
		"""
		self._left = left
		self._right = right

	def interpret(self, ctx: Dict[str, bool]) -> bool:
		"""
		Evaluates logical disjunction of both operands.

		:param ctx: The interpretation context.
		:return: The result of left OR right.
		"""
		return self._left.interpret(ctx) or self._right.interpret(ctx)


class Parser:
	"""
	A minimal recursive-descent parser for a boolean DSL.

	Grammar (EBNF):
		Expr    := OrExpr
		OrExpr  := AndExpr { '|' AndExpr }
		AndExpr := NotExpr { '&' NotExpr }
		NotExpr := '!' NotExpr | Primary
		Primary := 'true' | 'false' | Identifier | '(' Expr ')'
		Identifier := [A-Za-z_][A-Za-z0-9_]*
	"""
	def __init__(self, source: str):
		"""
		Initializes the parser with the input string.

		:param source: The source string to parse.
		"""
		self._s = source
		self._i = 0

	def parse(self) -> Expression:
		"""
		Parses the entire input as an expression.

		:return: The root Expression AST node.
		:raises ValueError: If there is leftover input or a syntax error.
		"""
		expr = self._parse_or()
		self._skip_ws()
		if self._i != len(self._s):
			raise ValueError(f"Unexpected trailing input at position {self._i}.")
		return expr

	# ----- Recursive-descent helpers -----

	def _parse_or(self) -> Expression:
		left = self._parse_and()
		while True:
			self._skip_ws()
			if self._consume('|'):
				right = self._parse_and()
				left = Or(left, right)
			else:
				break
		return left

	def _parse_and(self) -> Expression:
		left = self._parse_not()
		while True:
			self._skip_ws()
			if self._consume('&'):
				right = self._parse_not()
				left = And(left, right)
			else:
				break
		return left

	def _parse_not(self) -> Expression:
		self._skip_ws()
		if self._consume('!'):
			return Not(self._parse_not())
		return self._parse_primary()

	def _parse_primary(self) -> Expression:
		self._skip_ws()
		if self._i >= len(self._s):
			raise ValueError("Unexpected end of input while parsing primary.")
		c = self._s[self._i]
		if c == '(':
			self._i += 1
			e = self._parse_or()
			if not self._consume(')'):
				raise ValueError("Expected ')' to close group.")
			return e
		if self._is_ident_start(c):
			ident = self._parse_identifier()
			if ident == "true":
				return Constant(True)
			if ident == "false":
				return Constant(False)
			return Variable(ident)
		raise ValueError(f"Unexpected character '{c}' at position {self._i}.")

	# ----- Lexical helpers -----

	def _skip_ws(self):
		while self._i < len(self._s) and self._s[self._i].isspace():
			self._i += 1

	def _consume(self, ch: str) -> bool:
		self._skip_ws()
		if self._i < len(self._s) and self._s[self._i] == ch:
			self._i += 1
			return True
		return False

	def _is_ident_start(self, c: str) -> bool:
		return c.isalpha() or c == '_'

	def _is_ident_char(self, c: str) -> bool:
		return c.isalnum() or c == '_'

	def _parse_identifier(self) -> str:
		self._skip_ws()
		if self._i >= len(self._s) or not self._is_ident_start(self._s[self._i]):
			raise ValueError(f"Expected identifier at position {self._i}.")
		start = self._i
		self._i += 1
		while self._i < len(self._s) and self._is_ident_char(self._s[self._i]):
			self._i += 1
		return self._s[start:self._i]
