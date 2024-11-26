#include "factory_method.hpp"

/**
* @brief Implements the behavior for ConcreteProductA.
* 
* ConcreteProductA is a specific implementation of the Product interface.
* This method provides its unique behavior.
* 
* @return A string describing the use of ConcreteProductA.
*/
std::string ConcreteProductA::use() const {
	return "Using ConcreteProductA";
}

/**
* @brief Implements the behavior for ConcreteProductB.
* 
* ConcreteProductB is a specific implementation of the Product interface.
* This method provides its unique behavior.
* 
* @return A string describing the use of ConcreteProductB.
*/
std::string ConcreteProductB::use() const {
	return "Using ConcreteProductB";
}

/**
* @brief Factory method implementation in ConcreteCreatorA.
* 
* ConcreteCreatorA creates and returns an instance of ConcreteProductA.
* The returned product is encapsulated in a std::unique_ptr for memory safety.
* 
* @return A unique pointer to a newly created ConcreteProductA.
*/
std::unique_ptr<Product> ConcreteCreatorA::createProduct() const {
	return std::make_unique<ConcreteProductA>();
}

/**
* @brief Factory method implementation in ConcreteCreatorB.
* 
* ConcreteCreatorB creates and returns an instance of ConcreteProductB.
* The returned product is encapsulated in a std::unique_ptr for memory safety.
* 
* @return A unique pointer to a newly created ConcreteProductB.
*/
std::unique_ptr<Product> ConcreteCreatorB::createProduct() const {
	return std::make_unique<ConcreteProductB>();
}
