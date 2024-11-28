#include "prototype.hpp"
#include <iostream>

/**
 * @brief Constructs a ConcretePrototype1 object.
 * 
 * Initializes the attribute with the provided value.
 * 
 * @param attribute A string representing the prototype's attribute.
 */
ConcretePrototype1::ConcretePrototype1(const std::string& attribute)
	: attribute(attribute) {}

/**
 * @brief Creates a clone of the ConcretePrototype1 object.
 * 
 * Performs a deep copy of the current object, creating an independent instance.
 * 
 * @return A unique pointer to the cloned ConcretePrototype1.
 */
std::unique_ptr<Prototype> ConcretePrototype1::clone() const {
	return std::make_unique<ConcretePrototype1>(*this);
}

/**
 * @brief Displays the details of the ConcretePrototype1.
 * 
 * Outputs the value of the attribute to the standard output.
 */
void ConcretePrototype1::display() const {
	std::cout << "ConcretePrototype1 with attribute: " << attribute << std::endl;
}

/**
 * @brief Constructs a ConcretePrototype2 object.
 * 
 * Initializes the attribute with the provided integer value.
 * 
 * @param attribute An integer representing the prototype's attribute.
 */
ConcretePrototype2::ConcretePrototype2(int attribute)
	: attribute(attribute) {}

/**
 * @brief Creates a clone of the ConcretePrototype2 object.
 * 
 * Performs a deep copy of the current object, creating an independent instance.
 * 
 * @return A unique pointer to the cloned ConcretePrototype2.
 */
std::unique_ptr<Prototype> ConcretePrototype2::clone() const {
	return std::make_unique<ConcretePrototype2>(*this);
}

/**
 * @brief Displays the details of the ConcretePrototype2.
 * 
 * Outputs the value of the attribute to the standard output.
 */
void ConcretePrototype2::display() const {
	std::cout << "ConcretePrototype2 with attribute: " << attribute << std::endl;
}
