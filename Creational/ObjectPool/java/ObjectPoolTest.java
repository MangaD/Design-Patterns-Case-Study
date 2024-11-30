import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 * @brief Test suite for the Object Pool pattern.
 *
 * Validates the functionality of the ObjectPool class, including borrowing,
 * returning, and handling edge cases with reusable objects.
 */
public class ObjectPoolTest {

	/**
	 * @brief Test borrowing and returning a single object.
	 *
	 * Verifies that a single object can be borrowed, used, returned, and reused.
	 */
	@Test
	public void testSingleBorrowAndReturn() {
		ObjectPool<ConcreteReusable> pool = new ObjectPool<>();

		// Add an object to the pool
		ConcreteReusable reusable = new ConcreteReusable("Obj1");
		pool.addObject(reusable);

		// Borrow the object
		ConcreteReusable borrowed = pool.borrowObject();
		borrowed.use();

		// Return the object
		pool.returnObject(borrowed);

		// Borrow the object again and verify reuse
		ConcreteReusable reused = pool.borrowObject();
		assertSame(borrowed, reused, "The same object instance should be reused.");
	}

	/**
	 * @brief Test FIFO behavior with multiple objects in the pool.
	 *
	 * Ensures objects are borrowed in the order they were added and that returned
	 * objects are reused according to FIFO behavior.
	 */
	@Test
	public void testFIFOBorrowingOrder() {
		ObjectPool<ConcreteReusable> pool = new ObjectPool<>();

		// Add two objects to the pool
		ConcreteReusable obj1 = new ConcreteReusable("Obj1");
		ConcreteReusable obj2 = new ConcreteReusable("Obj2");
		pool.addObject(obj1);
		pool.addObject(obj2);

		// Borrow the first object
		ConcreteReusable borrowed1 = pool.borrowObject();
		assertSame(obj1, borrowed1, "The first borrowed object should be Obj1.");

		// Borrow the second object
		ConcreteReusable borrowed2 = pool.borrowObject();
		assertSame(obj2, borrowed2, "The second borrowed object should be Obj2.");

		// Return the first object and borrow again
		pool.returnObject(borrowed1);
		ConcreteReusable reused = pool.borrowObject();
		assertSame(obj1, reused, "Obj1 should be reused after being returned.");
	}

	/**
	 * @brief Test behavior when borrowing from an empty pool.
	 *
	 * Ensures that an exception is thrown when attempting to borrow from an
	 * empty pool.
	 */
	@Test
	public void testBorrowFromEmptyPool() {
		ObjectPool<ConcreteReusable> pool = new ObjectPool<>();

		// Attempt to borrow from an empty pool
		assertThrows(IllegalStateException.class, pool::borrowObject,
			"Borrowing from an empty pool should throw an exception.");
	}

	/**
	 * @brief Test returning null objects to the pool.
	 *
	 * Ensures that returning a null object does not corrupt the pool or cause
	 * unexpected behavior.
	 */
	@Test
	public void testReturnNullObject() {
		ObjectPool<ConcreteReusable> pool = new ObjectPool<>();

		// Add an object to the pool
		ConcreteReusable obj1 = new ConcreteReusable("Obj1");
		pool.addObject(obj1);

		// Borrow and return a valid object
		ConcreteReusable borrowed = pool.borrowObject();
		pool.returnObject(borrowed);

		// Attempt to return a null object (expect exception)
		assertThrows(IllegalArgumentException.class, () -> pool.returnObject(null),
			"Returning a null object should throw an exception.");
	}

	/**
	 * @brief Test multiple borrow and return cycles.
	 *
	 * Verifies that the pool handles repeated borrowing and returning correctly
	 * and maintains FIFO behavior.
	 */
	@Test
	public void testMultipleBorrowAndReturnCycles() {
		ObjectPool<ConcreteReusable> pool = new ObjectPool<>();

		// Add three objects to the pool
		ConcreteReusable obj1 = new ConcreteReusable("Obj1");
		ConcreteReusable obj2 = new ConcreteReusable("Obj2");
		ConcreteReusable obj3 = new ConcreteReusable("Obj3");
		pool.addObject(obj1);
		pool.addObject(obj2);
		pool.addObject(obj3);

		// Borrow two objects (FIFO order: obj1, obj2)
		ConcreteReusable borrowed1 = pool.borrowObject();
		ConcreteReusable borrowed2 = pool.borrowObject();

		assertSame(obj1, borrowed1, "The first borrowed object should be Obj1.");
		assertSame(obj2, borrowed2, "The second borrowed object should be Obj2.");

		// Return the borrowed objects (FIFO: obj3 is still in the pool)
		pool.returnObject(borrowed1); // Adds obj1 to the back of the queue
		pool.returnObject(borrowed2); // Adds obj2 to the back of the queue

		// Borrow three objects to verify FIFO order
		ConcreteReusable next1 = pool.borrowObject(); // Should retrieve obj3
		ConcreteReusable next2 = pool.borrowObject(); // Should retrieve obj1
		ConcreteReusable next3 = pool.borrowObject(); // Should retrieve obj2

		assertSame(obj3, next1, "The next borrowed object should be Obj3.");
		assertSame(obj1, next2, "The next borrowed object should be Obj1.");
		assertSame(obj2, next3, "The next borrowed object should be Obj2.");
	}

	/**
	 * @brief Test pool size consistency after multiple operations.
	 *
	 * Verifies that the pool maintains consistent size after borrowing,
	 * returning, and reusing objects.
	 */
	@Test
	public void testPoolSizeConsistency() {
		ObjectPool<ConcreteReusable> pool = new ObjectPool<>();

		// Add three objects to the pool
		pool.addObject(new ConcreteReusable("Obj1"));
		pool.addObject(new ConcreteReusable("Obj2"));
		pool.addObject(new ConcreteReusable("Obj3"));

		// Borrow and return objects
		ConcreteReusable obj1 = pool.borrowObject();
		ConcreteReusable obj2 = pool.borrowObject();
		pool.returnObject(obj1);
		pool.returnObject(obj2);

		// Verify pool size
		assertEquals(3, pool.getSize(), "Pool size should remain consistent.");
	}

	/**
	 * @brief Test duplicate return handling.
	 *
	 * Ensures that returning the same object multiple times does not corrupt
	 * the pool or create duplicates.
	 */
	@Test
	public void testDuplicateReturn() {
		ObjectPool<ConcreteReusable> pool = new ObjectPool<>();

		// Add an object to the pool
		ConcreteReusable obj1 = new ConcreteReusable("Obj1");
		pool.addObject(obj1);

		// Borrow and return the object multiple times
		ConcreteReusable borrowed = pool.borrowObject();
		pool.returnObject(borrowed);
		assertThrows(IllegalArgumentException.class, () -> pool.returnObject(borrowed),
			"Returning the same object twice should throw an exception.");

		// Verify pool integrity
		assertEquals(1, pool.getSize(), "Pool size should not change due to duplicate return.");
	}
}
