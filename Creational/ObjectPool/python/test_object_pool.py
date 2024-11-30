import unittest
from object_pool import ObjectPool, ConcreteReusable

class TestObjectPool(unittest.TestCase):
	"""
	Test suite for the ObjectPool implementation.
	"""

	def test_single_borrow_and_return(self):
		"""
		Test borrowing and returning a single object.
		"""
		pool = ObjectPool[ConcreteReusable]()
		obj = ConcreteReusable("Obj1")
		pool.add_object(obj)

		# Borrow the object
		borrowed = pool.borrow_object()
		self.assertEqual(borrowed, obj)

		# Return the object
		pool.return_object(borrowed)

		# Borrow again and verify reuse
		reused = pool.borrow_object()
		self.assertEqual(borrowed, reused)

	def test_fifo_behavior(self):
		"""
		Test that the pool behaves as FIFO (First In, First Out).
		"""
		pool = ObjectPool[ConcreteReusable]()
		obj1 = ConcreteReusable("Obj1")
		obj2 = ConcreteReusable("Obj2")
		pool.add_object(obj1)
		pool.add_object(obj2)

		# Borrow objects in FIFO order
		borrowed1 = pool.borrow_object()
		borrowed2 = pool.borrow_object()
		self.assertEqual(borrowed1, obj1)
		self.assertEqual(borrowed2, obj2)

		# Return objects
		pool.return_object(borrowed1)
		pool.return_object(borrowed2)

		# Borrow again and verify FIFO behavior
		reused1 = pool.borrow_object()
		reused2 = pool.borrow_object()
		self.assertEqual(reused1, obj1)
		self.assertEqual(reused2, obj2)

	def test_empty_pool_borrow(self):
		"""
		Test that borrowing from an empty pool raises an error.
		"""
		pool = ObjectPool[ConcreteReusable]()
		with self.assertRaises(RuntimeError):
			pool.borrow_object()

	def test_return_null_object(self):
		"""
		Test that returning a None object raises an error.
		"""
		pool = ObjectPool[ConcreteReusable]()
		with self.assertRaises(ValueError):
			pool.return_object(None)

	def test_duplicate_return(self):
		"""
		Test that returning the same object twice raises an error.
		"""
		pool = ObjectPool[ConcreteReusable]()
		obj = ConcreteReusable("Obj1")
		pool.add_object(obj)

		# Borrow and return the object
		borrowed = pool.borrow_object()
		pool.return_object(borrowed)

		# Attempt to return the same object again
		with self.assertRaises(ValueError):
			pool.return_object(borrowed)

	def test_pool_size_consistency(self):
		"""
		Test that the pool size is updated correctly after borrow and return operations.
		"""
		pool = ObjectPool[ConcreteReusable]()
		pool.add_object(ConcreteReusable("Obj1"))
		pool.add_object(ConcreteReusable("Obj2"))
		self.assertEqual(pool.get_size(), 2)

		# Borrow an object
		borrowed = pool.borrow_object()
		self.assertEqual(pool.get_size(), 1)

		# Return the object
		pool.return_object(borrowed)
		self.assertEqual(pool.get_size(), 2)

if __name__ == "__main__":
	unittest.main()
