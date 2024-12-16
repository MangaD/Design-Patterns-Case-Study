#include "concrete_reusable.hpp"
#include <iostream>

using namespace object_pool_pattern;

ConcreteReusable::ConcreteReusable(const std::string& id) : id(id) {}

/**
 * @brief Marks the object as in use and performs its functionality.
 * 
 * This method demonstrates how the object is used. If the object is
 * already in use, a message is printed to indicate that it cannot be
 * reused until it is reset.
 * 
 * - If the object is not in use, it transitions to the "in use" state 
 *   and prints a message to indicate it is being used.
 * - If the object is already in use, an error message is printed.
 */
void ConcreteReusable::use() {
	if (inUse) {
		std::cerr << "Object " << id << " is already in use." << std::endl;
		return;
	}
	inUse = true;
	std::cout << "Using object: " << id << std::endl;
}

/**
 * @brief Resets the object to its initial state.
 * 
 * This method clears the "in use" state of the object, making it available
 * for reuse in the object pool. A message is printed to indicate the object
 * has been reset.
 */
void ConcreteReusable::reset() {
	inUse = false;
	std::cout << "Resetting object: " << id << std::endl;
}
