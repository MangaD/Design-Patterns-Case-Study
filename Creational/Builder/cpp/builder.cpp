#include "builder.hpp"
#include <iostream>

using namespace builder_pattern;

/**
* @file builder.cpp
* @brief Implementation of the Builder Pattern.
*
* This file contains the implementation details of the `Product`, `ConcreteBuilder`,
* and `Director` classes, following the Builder Pattern to construct complex objects.
*/

// Product implementation

void Product::setPartA(const std::string& part) {
	this->partA = part;
}

void Product::setPartB(const std::string& part) {
	this->partB = part;
}

/**
* @brief Provides a string representation of the product.
*
* Combines the details of Part A and Part B into a formatted string
* that describes the constructed product.
*
* @return A string representation of the product's parts.
*/
std::string Product::toString() const {
	return "Product [PartA: " + partA + ", PartB: " + partB + "]";
}

/**
* @brief Overloads the output stream operator for the `Product` class.
*
* Allows the details of the `Product` to be printed to an output stream.
*
* @param os The output stream to write to.
* @param product The product whose details are printed.
* @return The output stream with appended product details.
*/
namespace builder_pattern { 
	std::ostream& operator<<(std::ostream& os, const Product& product) {
		os << product.toString();
		return os;
	}
}

// ConcreteBuilder implementation

/**
* @brief Constructs a new `ConcreteBuilder` and initializes a product.
*
* Initializes the builder with a fresh `Product` instance for construction.
*/
ConcreteBuilder::ConcreteBuilder() {
	product = std::make_shared<Product>();
}

/**
* @brief Builds Part A of the product.
*
* Sets Part A of the product to a specific value defined by the builder.
*/
void ConcreteBuilder::buildPartA() {
	product->setPartA("Part A built by ConcreteBuilder");
}

/**
* @brief Builds Part B of the product.
*
* Sets Part B of the product to a specific value defined by the builder.
*/
void ConcreteBuilder::buildPartB() {
	product->setPartB("Part B built by ConcreteBuilder");
}

/**
* @brief Retrieves the constructed product.
*
* Returns the fully constructed product after all parts have been built.
*
* @return A shared pointer to the constructed `Product`.
*/
std::shared_ptr<Product> ConcreteBuilder::getResult() {
	return product;
}

// Director implementation

Director::Director(Builder* builder) : builder(builder) {}

/**
* @brief Constructs the product by invoking the builder's methods in sequence.
*
* Orchestrates the construction process by calling the builder's methods
* in a predefined order.
*/
void Director::construct() {
	builder->buildPartA();
	builder->buildPartB();
}

/**
* @brief Retrieves the constructed product from the builder.
*
* After the construction process is complete, this method retrieves
* the final constructed product from the builder.
*
* @return A shared pointer to the constructed `Product`.
*/
std::shared_ptr<Product> Director::getProduct() {
	return builder->getResult();
}
