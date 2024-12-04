import unittest
from decorator import Component, ConcreteComponent, ConcreteDecoratorA, ConcreteDecoratorB


class TestDecoratorPattern(unittest.TestCase):
	"""
	Unit tests for the Decorator Pattern implementation.
	"""

	def test_concrete_component(self):
		component = ConcreteComponent()
		self.assertEqual(component.get_description(), "Concrete Component")
		self.assertEqual(component.cost(), 10.0)

	def test_concrete_decorator_a(self):
		component = ConcreteComponent()
		decorator_a = ConcreteDecoratorA(component)

		self.assertEqual(decorator_a.get_description(), "Concrete Component + Feature A")
		self.assertEqual(decorator_a.cost(), 15.0)

	def test_concrete_decorator_b(self):
		component = ConcreteComponent()
		decorator_b = ConcreteDecoratorB(component)

		self.assertEqual(decorator_b.get_description(), "Concrete Component + Feature B")
		self.assertEqual(decorator_b.cost(), 17.5)

	def test_multiple_decorators(self):
		component = ConcreteComponent()
		decorator_a = ConcreteDecoratorA(component)
		decorator_b = ConcreteDecoratorB(decorator_a)

		self.assertEqual(decorator_b.get_description(), "Concrete Component + Feature A + Feature B")
		self.assertEqual(decorator_b.cost(), 22.5)


if __name__ == "__main__":
	unittest.main()
