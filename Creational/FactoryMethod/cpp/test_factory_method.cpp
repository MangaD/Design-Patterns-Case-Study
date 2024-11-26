#include "factory_method.hpp"
#include <gtest/gtest.h>

/**
 * @file factory_method_tests.cpp
 * @brief Unit tests for the Factory Method Design Pattern implementation.
 *
 * This file contains GoogleTest cases to validate the behavior of the Factory Method
 * Design Pattern implementation. It tests different concrete creators and their respective
 * products to ensure the correct functionality of the factory method.
 */

/**
 * @brief Tests the creation and usage of ConcreteProductA through ConcreteCreatorA.
 *
 * This test case verifies that the `ConcreteCreatorA` creates a product of type
 * `ConcreteProductA` and that its `use()` method returns the expected string.
 */
TEST(FactoryMethodTest, ConcreteProductA) {
	// Create an instance of ConcreteCreatorA
	ConcreteCreatorA creatorA;

	// Create a product using the factory method
	auto product = creatorA.createProduct();

	// Assert that the product's use() method returns the correct output
	EXPECT_EQ(product->use(), "Using ConcreteProductA");
}

/**
 * @brief Tests the creation and usage of ConcreteProductB through ConcreteCreatorB.
 *
 * This test case verifies that the `ConcreteCreatorB` creates a product of type
 * `ConcreteProductB` and that its `use()` method returns the expected string.
 */
TEST(FactoryMethodTest, ConcreteProductB) {
	// Create an instance of ConcreteCreatorB
	ConcreteCreatorB creatorB;

	// Create a product using the factory method
	auto product = creatorB.createProduct();

	// Assert that the product's use() method returns the correct output
	EXPECT_EQ(product->use(), "Using ConcreteProductB");
}

/**
 * @brief Tests the Factory Method using base class references.
 *
 * This test case demonstrates polymorphic behavior by using base class references
 * for both creators and products. It ensures that `ConcreteCreatorA` and `ConcreteCreatorB`
 * correctly create their respective products, and that the products behave as expected.
 */
TEST(FactoryMethodTest, FactoryWithBaseCreator) {
	// Use base class references to store concrete creators
	std::unique_ptr<Creator> creatorA = std::make_unique<ConcreteCreatorA>();
	std::unique_ptr<Creator> creatorB = std::make_unique<ConcreteCreatorB>();

	// Create products using the factory method
	auto productA = creatorA->createProduct();
	auto productB = creatorB->createProduct();

	// Assert that the products' use() methods return the correct outputs
	EXPECT_EQ(productA->use(), "Using ConcreteProductA");
	EXPECT_EQ(productB->use(), "Using ConcreteProductB");
}
