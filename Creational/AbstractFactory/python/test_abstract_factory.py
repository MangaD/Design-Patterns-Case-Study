import unittest
from abstract_factory import (
	ConcreteFactory1,
	ConcreteFactory2,
	AbstractProductA,
	AbstractProductB,
)


class TestAbstractFactory(unittest.TestCase):
	"""Unit tests for the Abstract Factory Pattern implementation."""

	def test_concrete_factory1(self):
		"""Test that ConcreteFactory1 produces the correct products."""
		factory = ConcreteFactory1()
		product_a = factory.create_product_a()
		product_b = factory.create_product_b()

		self.assertEqual(product_a.operation_a(), "ConcreteProductA1")
		self.assertEqual(product_b.operation_b(), "ConcreteProductB1")

	def test_concrete_factory2(self):
		"""Test that ConcreteFactory2 produces the correct products."""
		factory = ConcreteFactory2()
		product_a = factory.create_product_a()
		product_b = factory.create_product_b()

		self.assertEqual(product_a.operation_a(), "ConcreteProductA2")
		self.assertEqual(product_b.operation_b(), "ConcreteProductB2")

	def test_compatibility(self):
		"""Test compatibility between products from the same factory."""
		factory1 = ConcreteFactory1()
		product_a1 = factory1.create_product_a()
		product_b1 = factory1.create_product_b()

		factory2 = ConcreteFactory2()
		product_a2 = factory2.create_product_a()
		product_b2 = factory2.create_product_b()

		self.assertEqual(product_a1.operation_a(), "ConcreteProductA1")
		self.assertEqual(product_b1.operation_b(), "ConcreteProductB1")
		self.assertEqual(product_a2.operation_a(), "ConcreteProductA2")
		self.assertEqual(product_b2.operation_b(), "ConcreteProductB2")


if __name__ == "__main__":
	unittest.main()
