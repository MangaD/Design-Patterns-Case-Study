import unittest
from composite import Leaf, Composite
from unittest.mock import patch

class TestCompositePattern(unittest.TestCase):
	"""
	Unit tests for the Composite Design Pattern implementation.
	"""

	@patch("composite.logger")
	def test_leaf_operation(self, mock_logger):
		"""
		Test the operation of a Leaf object.
		"""
		leaf = Leaf("Leaf1")
		leaf.operation()
		mock_logger.info.assert_called_with("Leaf Leaf1 operation.")

	@patch("composite.logger")
	def test_composite_add_and_get_child(self, mock_logger):
		"""
		Test adding and retrieving children in a Composite.
		"""
		composite = Composite("Composite1")
		leaf1 = Leaf("Leaf1")
		leaf2 = Leaf("Leaf2")

		composite.add(leaf1)
		composite.add(leaf2)

		self.assertEqual(composite.get_child(0), leaf1)
		self.assertEqual(composite.get_child(1), leaf2)

	@patch("composite.logger")
	def test_composite_remove_child(self, mock_logger):
		"""
		Test removing a child from a Composite.
		"""
		composite = Composite("Composite1")
		leaf = Leaf("Leaf1")

		composite.add(leaf)
		composite.remove(leaf)

		with self.assertRaises(IndexError):
			composite.get_child(0)

	@patch("composite.logger")
	def test_composite_operation(self, mock_logger):
		"""
		Test the operation of a Composite with children.
		"""
		root = Composite("Root")
		child_composite = Composite("ChildComposite")
		leaf1 = Leaf("Leaf1")
		leaf2 = Leaf("Leaf2")

		child_composite.add(leaf1)
		child_composite.add(leaf2)
		root.add(child_composite)

		root.operation()

		mock_logger.info.assert_any_call("Composite Root operation.")
		mock_logger.info.assert_any_call("Composite ChildComposite operation.")
		mock_logger.info.assert_any_call("Leaf Leaf1 operation.")
		mock_logger.info.assert_any_call("Leaf Leaf2 operation.")


if __name__ == "__main__":
	unittest.main()
