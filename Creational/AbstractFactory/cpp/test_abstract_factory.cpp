/**
* @file test_abstract_factory.cpp
* @brief Unit tests for the Abstract Factory design pattern implementation.
* 
* This file uses Google Test to verify the correctness of the Abstract Factory
* implementation. The tests ensure that the factories produce the correct
* products and that products from different factories are compatible within
* their families.
*/

#include "abstract_factory.hpp"
#include <gtest/gtest.h>
#include <memory>

using namespace abstract_factory_pattern;

/**
* @brief Tests ConcreteFactory1.
* 
* Verifies that ConcreteFactory1 correctly creates ConcreteProductA1
* and ConcreteProductB1.
*/
TEST(AbstractFactoryTest, ConcreteFactory1) {
	ConcreteFactory1 factory;

	// Create products using ConcreteFactory1
	auto productA = factory.createProductA();
	auto productB = factory.createProductB();

	// Validate the operations of the created products
	EXPECT_EQ(productA->operationA(), "ConcreteProductA1");
	EXPECT_EQ(productB->operationB(), "ConcreteProductB1");
}

/**
* @brief Tests ConcreteFactory2.
* 
* Verifies that ConcreteFactory2 correctly creates ConcreteProductA2
* and ConcreteProductB2.
*/
TEST(AbstractFactoryTest, ConcreteFactory2) {
	ConcreteFactory2 factory;

	// Create products using ConcreteFactory2
	auto productA = factory.createProductA();
	auto productB = factory.createProductB();

	// Validate the operations of the created products
	EXPECT_EQ(productA->operationA(), "ConcreteProductA2");
	EXPECT_EQ(productB->operationB(), "ConcreteProductB2");
}

/**
* @brief Tests compatibility between products from different factories.
* 
* Ensures that products created by ConcreteFactory1 and ConcreteFactory2
* are compatible within their respective families.
*/
TEST(AbstractFactoryTest, Compatibility) {
	// Create factories
	ConcreteFactory1 factory1;
	ConcreteFactory2 factory2;

	// Create products from both factories
	auto productA1 = factory1.createProductA();
	auto productB1 = factory1.createProductB();
	auto productA2 = factory2.createProductA();
	auto productB2 = factory2.createProductB();

	// Validate operations for Factory 1's products
	EXPECT_EQ(productA1->operationA(), "ConcreteProductA1");
	EXPECT_EQ(productB1->operationB(), "ConcreteProductB1");

	// Validate operations for Factory 2's products
	EXPECT_EQ(productA2->operationA(), "ConcreteProductA2");
	EXPECT_EQ(productB2->operationB(), "ConcreteProductB2");
}
