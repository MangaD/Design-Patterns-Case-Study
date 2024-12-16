#include "builder.hpp"
#include <gtest/gtest.h>
#include <sstream>

using namespace builder_pattern;

/**
* @file test_builder.cpp
* @brief Unit tests for the Builder Pattern implementation.
*
* This file contains unit tests for the Builder Pattern, ensuring that the `ConcreteBuilder`
* and `Director` classes work as expected to construct a `Product`.
*/

/**
* @brief Test full product construction using ConcreteBuilder and Director.
*
* Verifies that the `Director` orchestrates the `ConcreteBuilder` correctly to construct
* a product with all expected parts (`PartA` and `PartB`) built as specified.
*
* @test Steps:
* - Create a `ConcreteBuilder` and pass it to a `Director`.
* - Invoke `Director::construct()` to build the product.
* - Retrieve the product from the `Director` and verify its string representation.
*/
TEST(BuilderPatternTest, FullProductConstruction) {
	ConcreteBuilder builder;
	Director director(&builder);

	// Construct the product
	director.construct();
	auto product = director.getProduct();

	// Capture the product details
	std::ostringstream output;
	output << *product;

	// Verify the constructed product
	EXPECT_EQ(output.str(),
	          "Product [PartA: Part A built by ConcreteBuilder, PartB: Part B built by ConcreteBuilder]");
}

/**
* @brief Test partial product construction directly through the ConcreteBuilder.
*
* Verifies that the `ConcreteBuilder` can construct a product incrementally without
* the involvement of the `Director`.
*
* @test Steps:
* - Create a `ConcreteBuilder`.
* - Call `ConcreteBuilder::buildPartA()` but skip `buildPartB()`.
* - Retrieve the product and verify its string representation reflects only Part A.
*/
TEST(BuilderPatternTest, PartialProductConstruction) {
	ConcreteBuilder builder;

	// Partially construct the product
	builder.buildPartA();

	auto product = builder.getResult();

	// Capture the product details
	std::ostringstream output;
	output << *product;

	// Verify that only Part A is built
	EXPECT_EQ(output.str(), "Product [PartA: Part A built by ConcreteBuilder, PartB: ]");
}

/**
* @brief Test reusing a builder for multiple products.
*
* Ensures that the `ConcreteBuilder` can be reused to construct multiple products
* by resetting or reinitializing its internal state.
*
* @test Steps:
* - Create a `ConcreteBuilder` and use it with a `Director` to construct a product.
* - Retrieve the product and verify its details.
* - Reuse the same builder to construct another product and verify its details.
*/
TEST(BuilderPatternTest, BuilderReuse) {
	ConcreteBuilder builder;
	Director director(&builder);

	// First product
	director.construct();
	auto product1 = director.getProduct();

	// Capture the first product details
	std::ostringstream output1;
	output1 << *product1;

	// Verify the first product
	EXPECT_EQ(output1.str(),
	          "Product [PartA: Part A built by ConcreteBuilder, PartB: Part B built by ConcreteBuilder]");

	// Reset the builder and construct another product
	builder = ConcreteBuilder();
	director = Director(&builder);
	director.construct();
	auto product2 = director.getProduct();

	// Capture the second product details
	std::ostringstream output2;
	output2 << *product2;

	// Verify the second product
	EXPECT_EQ(output2.str(),
	          "Product [PartA: Part A built by ConcreteBuilder, PartB: Part B built by ConcreteBuilder]");
}

/**
* @brief Test constructing a product without using the Director.
*
* Ensures that the `ConcreteBuilder` can independently construct a product
* without orchestration from the `Director`.
*
* @test Steps:
* - Create a `ConcreteBuilder`.
* - Call both `buildPartA()` and `buildPartB()` directly on the builder.
* - Retrieve the product and verify its string representation.
*/
TEST(BuilderPatternTest, DirectBuilderUsage) {
	ConcreteBuilder builder;

	// Build the product manually
	builder.buildPartA();
	builder.buildPartB();

	auto product = builder.getResult();

	// Capture the product details
	std::ostringstream output;
	output << *product;

	// Verify the constructed product
	EXPECT_EQ(output.str(),
	          "Product [PartA: Part A built by ConcreteBuilder, PartB: Part B built by ConcreteBuilder]");
}
