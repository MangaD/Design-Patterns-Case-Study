import unittest
from builder import ConcreteBuilder, Director


class TestBuilderPattern(unittest.TestCase):
	"""
	Unit tests for the Builder Pattern implementation.
	"""

	def test_full_product_construction(self):
		"""
		Test full product construction using ConcreteBuilder and Director.

		Verifies that the Director correctly orchestrates the ConcreteBuilder
		to construct a complete Product with all parts built.
		"""
		builder = ConcreteBuilder()
		director = Director(builder)

		# Construct the product
		director.construct()
		product = director.get_product()

		# Verify the constructed product
		self.assertEqual(str(product), 
						"Product [PartA: Part A built by ConcreteBuilder, PartB: Part B built by ConcreteBuilder]")

	def test_partial_product_construction(self):
		"""
		Test partial product construction directly through the ConcreteBuilder.

		Verifies that the ConcreteBuilder can construct a product incrementally
		without the involvement of the Director.
		"""
		builder = ConcreteBuilder()

		# Build Part A only
		builder.build_part_a()
		product = builder.get_result()

		# Verify that only Part A is built
		self.assertEqual(str(product), 
						"Product [PartA: Part A built by ConcreteBuilder, PartB: None]")

	def test_builder_reuse(self):
		"""
		Test reusing a ConcreteBuilder for multiple products.

		Verifies that the ConcreteBuilder can be reused to construct multiple products
		by resetting its internal state.
		"""
		builder = ConcreteBuilder()
		director = Director(builder)

		# First product
		director.construct()
		product1 = director.get_product()

		# Verify the first product
		self.assertEqual(str(product1), 
						"Product [PartA: Part A built by ConcreteBuilder, PartB: Part B built by ConcreteBuilder]")

		# Reset the builder for a new product
		builder = ConcreteBuilder()
		director = Director(builder)
		director.construct()
		product2 = director.get_product()

		# Verify the second product
		self.assertEqual(str(product2), 
						"Product [PartA: Part A built by ConcreteBuilder, PartB: Part B built by ConcreteBuilder]")


if __name__ == "__main__":
	unittest.main()
