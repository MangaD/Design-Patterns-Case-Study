#include "flyweight.hpp"
#include <gtest/gtest.h>

/**
 * @brief Test the creation and reuse of Flyweight objects in the FlyweightFactory.
 */
TEST(FlyweightPatternTest, FlyweightCreationAndReuse) {
	FlyweightFactory factory;

	// Retrieve Flyweights with different intrinsic states
	auto fw1 = factory.getFlyweight("State1");
	auto fw2 = factory.getFlyweight("State2");

	// Reuse the Flyweight with intrinsic state "State1"
	auto fw3 = factory.getFlyweight("State1");

	// Assert that the Flyweight instances with the same intrinsic state are reused
	EXPECT_EQ(fw1, fw3);
	EXPECT_NE(fw1, fw2);

	// List all Flyweights in the factory
	factory.listFlyweights();
}

/**
 * @brief Test Flyweight operation with both intrinsic and extrinsic states.
 */
TEST(FlyweightPatternTest, FlyweightOperation) {
	FlyweightFactory factory;

	// Create Flyweights
	auto fw1 = factory.getFlyweight("SharedState");

	// Perform operations with extrinsic states
	testing::internal::CaptureStdout();
	fw1->operation("ExtrinsicState1");
	fw1->operation("ExtrinsicState2");
	std::string output = testing::internal::GetCapturedStdout();

	// Verify the output
	EXPECT_NE(output.find("ConcreteFlyweight with intrinsic state: SharedState and extrinsic state: ExtrinsicState1"), std::string::npos);
	EXPECT_NE(output.find("ConcreteFlyweight with intrinsic state: SharedState and extrinsic state: ExtrinsicState2"), std::string::npos);
}

/**
 * @brief Test listing of Flyweights in the factory.
 */
TEST(FlyweightPatternTest, ListFlyweights) {
	FlyweightFactory factory;

	// Add multiple Flyweights
	factory.getFlyweight("State1");
	factory.getFlyweight("State2");

	// Capture the output of listing Flyweights
	testing::internal::CaptureStdout();
	factory.listFlyweights();
	std::string output = testing::internal::GetCapturedStdout();

	// Verify the output contains the expected states
	EXPECT_NE(output.find("State1"), std::string::npos);
	EXPECT_NE(output.find("State2"), std::string::npos);
}
