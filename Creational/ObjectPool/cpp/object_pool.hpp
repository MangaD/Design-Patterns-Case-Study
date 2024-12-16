#ifndef OBJECT_POOL_HPP
#define OBJECT_POOL_HPP

#include <queue>
#include <memory>
#include <stdexcept>

/**
 * @brief Namespace for the Object Pool pattern.
 */
namespace object_pool_pattern {

	/**
	* @brief Abstract interface for reusable objects in the Object Pool Pattern.
	*
	* Classes implementing this interface represent objects that can be managed
	* by an object pool. These objects must define how they are used and reset
	* to their initial state.
	*/
	class Reusable {
	public:
		/// @brief Virtual destructor for proper cleanup in derived classes.
		virtual ~Reusable() = default;

		/**
		* @brief Use the reusable object for its intended purpose.
		*
		* Derived classes should provide concrete implementations of this method
		* to define how the object is used.
		*/
		virtual void use() = 0;

		/**
		* @brief Reset the reusable object to its initial state.
		*
		* This method ensures that objects can be safely reused by the pool,
		* clearing any state or data from previous usage.
		*/
		virtual void reset() = 0;
	};

	/**
	* @brief Generic Object Pool for managing reusable objects.
	*
	* This class provides a mechanism to borrow and return objects of type `Reusable`.
	* By reusing objects, the Object Pool reduces the overhead of frequent object
	* creation and destruction, especially in performance-critical systems.
	*/
	class ObjectPool {
	public:
		/**
		* @brief Borrow an object from the pool.
		*
		* Retrieves an object from the pool for use. If no objects are available,
		* the method throws a `std::runtime_error`.
		*
		* @return A unique pointer to a `Reusable` object.
		* @throws std::runtime_error if the pool is empty and no objects are available.
		*/
		std::unique_ptr<Reusable> borrowObject();

		/**
		* @brief Return an object to the pool.
		*
		* Returns a previously borrowed object back to the pool. The object is
		* reset to its initial state before being made available for reuse.
		*
		* @param obj A unique pointer to the reusable object being returned.
		*/
		void returnObject(std::unique_ptr<Reusable> obj);

		/**
		* @brief Add a new object to the pool.
		*
		* Allows new objects to be added to the pool for reuse. This is useful
		* for dynamically expanding the pool size as needed.
		*
		* @param obj A unique pointer to the reusable object being added.
		*/
		void addObject(std::unique_ptr<Reusable> obj);

	private:
		/**
		* @brief Internal storage for reusable objects.
		*
		* A queue that holds unique pointers to `Reusable` objects, ensuring
		* efficient management and retrieval of pooled objects.
		*/
		std::queue<std::unique_ptr<Reusable>> pool;
	};

}  // namespace object_pool

#endif // OBJECT_POOL_HPP
