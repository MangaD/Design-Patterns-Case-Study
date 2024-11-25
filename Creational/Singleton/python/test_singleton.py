"""
test_singleton.py
Unit tests for the Singleton design pattern implementation.
"""

import unittest
from singleton import Singleton

class TestSingleton(unittest.TestCase):
	"""
	Test cases for the Singleton class.
	"""

	def test_single_instance(self):
		"""
		Test that only a single instance of the Singleton class is created.
		"""
		instance1 = Singleton()
		instance2 = Singleton()
		self.assertIs(instance1, instance2, "Singleton instances are not the same")

	def test_do_something(self):
		"""
		Test the functionality of the do_something method.
		"""
		instance = Singleton()
		self.assertEqual(instance.do_something(), "Singleton instance is working!")


if __name__ == "__main__":
	unittest.main()
