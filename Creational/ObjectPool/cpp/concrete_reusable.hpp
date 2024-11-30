#ifndef CONCRETE_REUSABLE_HPP
#define CONCRETE_REUSABLE_HPP

#include "object_pool.hpp"
#include <string>
#include <iostream>

/**
 * @brief Concrete implementation of the Reusable interface.
 *
 * Represents an object that can be managed by an object pool. Each 
 * `ConcreteReusable` object has a unique identifier and maintains 
 * an internal state indicating whether it is currently in use.
 *
 * This class provides functionality to "use" the object and reset it 
 * to its initial state when returned to the pool.
 */
class ConcreteReusable : public Reusable {
public:
	/**
	 * @brief Constructs a reusable object with a unique identifier.
	 *
	 * @param id A unique identifier for the reusable object.
	 *
	 * This identifier helps distinguish between different instances 
	 * and is used in messages to indicate which object is being used 
	 * or reset.
	 */
	explicit ConcreteReusable(const std::string& id);

	/**
	 * @brief Simulates using the object.
	 *
	 * This method marks the object as "in use" and prints a message 
	 * indicating the object is being used. If the object is already 
	 * in use, it prints an error message to the console.
	 *
	 * Overridden from the `Reusable` interface.
	 */
	void use() override;

	/**
	 * @brief Resets the object to its initial state.
	 *
	 * This method marks the object as "not in use" and clears any 
	 * state associated with the previous usage. A message is printed 
	 * to indicate that the object has been reset and is ready for reuse.
	 *
	 * Overridden from the `Reusable` interface.
	 */
	void reset() override;

private:
	std::string id;      ///< Unique identifier for the reusable object.
	bool inUse = false;  ///< State indicating whether the object is in use.
};

#endif // CONCRETE_REUSABLE_HPP
