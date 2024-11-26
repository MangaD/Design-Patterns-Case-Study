import unittest
from factory_method import ConcreteCreatorA, ConcreteCreatorB

class TestFactoryMethod(unittest.TestCase):
	"""
	Unit tests for the Factory Method pattern implementation.
	"""
	
	def test_concrete_product_a(self):
		"""
		Test that ConcreteCreatorA produces ConcreteProductA.
		"""
		creator = ConcreteCreatorA()
		product = creator.create_product()
		self.assertEqual(product.use(), "Using ConcreteProductA")
	
	def test_concrete_product_b(self):
		"""
		Test that ConcreteCreatorB produces ConcreteProductB.
		"""
		creator = ConcreteCreatorB()
		product = creator.create_product()
		self.assertEqual(product.use(), "Using ConcreteProductB")

if __name__ == "__main__":
	unittest.main()
