import unittest
from decorator import Component, ConcreteComponent, ConcreteDecoratorA, ConcreteDecoratorB


class TestDecoratorPattern(unittest.TestCase):
	"""
	Unit tests for the Decorator Pattern implementation.
	"""

	def test_concrete_component(self):
		"""
		Test that the ConcreteComponent provides the correct description and cost.
		"""
		component = ConcreteComponent()
		self.assertEqual(component.get_description(), "Concrete Component")
		self.assertEqual(component.cost(), 10.0)

	def test_concrete_decorator_a(self):
		"""
		Test that the ConcreteDecoratorA correctly adds feature A to the decorated component.
		"""
		component = ConcreteComponent()
		decorator_a = ConcreteDecoratorA(component)

		self.assertEqual(decorator_a.get_description(), "Concrete Component + Feature A")
		self.assertEqual(decorator_a.cost(), 15.0)

	def test_concrete_decorator_b(self):
		"""
		Test that the ConcreteDecoratorB correctly adds feature B to the decorated component.
		"""
		component = ConcreteComponent()
		decorator_b = ConcreteDecoratorB(component)

		self.assertEqual(decorator_b.get_description(), "Concrete Component + Feature B")
		self.assertEqual(decorator_b.cost(), 17.5)

	def test_multiple_decorators(self):
		"""
		Test that multiple decorators can be applied to a component.
		"""
		component = ConcreteComponent()
		decorator_a = ConcreteDecoratorA(component)
		decorator_b = ConcreteDecoratorB(decorator_a)

		self.assertEqual(decorator_b.get_description(), "Concrete Component + Feature A + Feature B")
		self.assertEqual(decorator_b.cost(), 22.5)


if __name__ == "__main__":
	unittest.main()
