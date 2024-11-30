import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

/**
 * @brief Generic Object Pool for managing reusable objects.
 *
 * The ObjectPool class provides a way to manage and reuse a pool of objects,
 * reducing the overhead of repeatedly creating and destroying objects. Objects
 * implementing the {@link Reusable} interface can be added to the pool,
 * borrowed, and returned for reuse.
 *
 * @param <T> The type of objects managed by the pool, which must implement the {@link Reusable} interface.
 */
public class ObjectPool<T extends Reusable> {
	private final Queue<T> pool; // Queue to store reusable objects
	private final Set<T> inPool; // Set to track objects currently in the pool

	/**
	 * @brief Constructs an empty ObjectPool.
	 */
	public ObjectPool() {
		this.pool = new LinkedList<>();
		this.inPool = new HashSet<>();
	}

	/**
	 * @brief Adds a reusable object to the pool.
	 *
	 * @param obj The reusable object to be added to the pool.
	 * @throws IllegalArgumentException if the object is null.
	 */
	public void addObject(T obj) {
		if (obj == null) {
			throw new IllegalArgumentException("Cannot add a null object to the pool.");
		}
		if (inPool.contains(obj)) {
			throw new IllegalArgumentException("Object is already in the pool.");
		}
		pool.offer(obj);
		inPool.add(obj);
	}

	/**
	 * @brief Borrows a reusable object from the pool.
	 *
	 * @return A reusable object from the pool.
	 * @throws IllegalStateException if the pool is empty.
	 */
	public T borrowObject() {
		if (pool.isEmpty()) {
			throw new IllegalStateException("No available objects in the pool.");
		}
		T obj = pool.poll();
		inPool.remove(obj);
		return obj;
	}

	/**
	 * @brief Returns a reusable object to the pool.
	 *
	 * The returned object is reset to its initial state before being added
	 * back to the pool.
	 *
	 * @param obj The reusable object to return to the pool.
	 * @throws IllegalArgumentException if the object is null.
	 */
	public void returnObject(T obj) {
		if (obj == null) {
			throw new IllegalArgumentException("Cannot return a null object to the pool.");
		}
		if (inPool.contains(obj)) {
			throw new IllegalArgumentException("Object is already in the pool.");
		}
		obj.reset();
		pool.offer(obj);
		inPool.add(obj);
	}

	/**
	 * @brief Gets the current size of the pool.
	 *
	 * @return The number of reusable objects currently in the pool.
	 */
	public int getSize() {
		return pool.size();
	}
}
