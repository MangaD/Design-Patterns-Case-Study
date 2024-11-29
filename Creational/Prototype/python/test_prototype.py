"""
Unit tests for the Prototype Pattern implementation.

This module contains tests to verify the functionality of the Prototype Pattern,
ensuring that cloning and independence between clones and originals work correctly.
"""

import unittest
from prototype import ConcretePrototype1, ConcretePrototype2


class TestPrototypePattern(unittest.TestCase):
	"""
	Unit tests for the Prototype Pattern implementation.
	"""

	def test_clone_concrete_prototype1(self):
		"""
		Test cloning functionality of ConcretePrototype1.
		"""
		prototype1 = ConcretePrototype1("ExampleAttribute")

		# Clone the prototype
		cloned_prototype = prototype1.clone()

		# Verify that the clone is not the same object
		self.assertIsNot(prototype1, cloned_prototype)

		# Verify that the clone has the same attribute
		self.assertEqual(prototype1.attribute, cloned_prototype.attribute)

	def test_clone_concrete_prototype2(self):
		"""
		Test cloning functionality of ConcretePrototype2.
		"""
		prototype2 = ConcretePrototype2(42)

		# Clone the prototype
		cloned_prototype = prototype2.clone()

		# Verify that the clone is not the same object
		self.assertIsNot(prototype2, cloned_prototype)

		# Verify that the clone has the same attribute
		self.assertEqual(prototype2.attribute, cloned_prototype.attribute)

	def test_clone_and_modify(self):
		"""
		Test modifying a cloned prototype to ensure independence.
		"""
		prototype1 = ConcretePrototype1("OriginalAttribute")

		# Clone the prototype
		cloned_prototype = prototype1.clone()

		# Modify the clone
		cloned_prototype.attribute = "ModifiedAttribute"

		# Verify the original is unchanged
		self.assertNotEqual(prototype1.attribute, cloned_prototype.attribute)
		self.assertEqual(prototype1.attribute, "OriginalAttribute")

	def test_clone_multiple_instances(self):
		"""
		Test cloning and verifying independence for multiple clones.
		"""
		prototype2 = ConcretePrototype2(100)

		# Clone the prototype multiple times
		clone1 = prototype2.clone()
		clone2 = prototype2.clone()

		# Verify that clones and the original are independent
		self.assertIsNot(prototype2, clone1)
		self.assertIsNot(prototype2, clone2)
		self.assertIsNot(clone1, clone2)

		# Verify that the attributes are identical initially
		self.assertEqual(clone1.attribute, prototype2.attribute)
		self.assertEqual(clone2.attribute, prototype2.attribute)

		# Modify one clone and verify others remain unchanged
		clone1.attribute = 200
		self.assertNotEqual(clone1.attribute, clone2.attribute)
		self.assertNotEqual(clone1.attribute, prototype2.attribute)


if __name__ == "__main__":
	unittest.main()
