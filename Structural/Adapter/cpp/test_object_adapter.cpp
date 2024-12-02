#include "object_adapter.hpp"
#include <gtest/gtest.h> // GoogleTest framework for unit testing

using namespace object_adapter;

/**
 * @brief Fixture for testing the Adapter Pattern implementation.
 *
 * The fixture sets up shared objects and utilities for testing
 * the interaction between Target, Adaptee, and Adapter classes.
 */
class AdapterPatternTest : public ::testing::Test {
protected:
	Adaptee adaptee;        ///< Instance of Adaptee for testing.
	Adapter* adapter = nullptr; ///< Pointer to the Adapter being tested.

	/**
	 * @brief Sets up the test environment.
	 *
	 * This method creates an Adapter instance wrapping the Adaptee object.
	 */
	void SetUp() override {
		adapter = new Adapter(&adaptee);
	}

	/**
	 * @brief Cleans up the test environment.
	 *
	 * This method deletes the Adapter instance to free allocated resources.
	 */
	void TearDown() override {
		delete adapter;
	}
};

/**
 * @test Validates that the Adaptee's specificRequest() method works as expected.
 *
 * This test ensures the Adaptee can perform its functionality independently
 * without requiring adaptation.
 */
TEST_F(AdapterPatternTest, AdapteeFunctionality) {
	testing::internal::CaptureStdout();
	adaptee.specificRequest();
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output, "Adaptee: Specific request called.\n")
		<< "Adaptee's specificRequest() should output the correct message.";
}

/**
 * @test Validates that the Adapter translates the Target's request() call correctly.
 *
 * This test ensures the Adapter acts as an intermediary between the client
 * (using Target) and the Adaptee, translating the request method.
 */
TEST_F(AdapterPatternTest, AdapterFunctionality) {
	testing::internal::CaptureStdout();
	adapter->request();
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output,
		"Adapter: Translating request to Adaptee's specificRequest().\n"
		"Adaptee: Specific request called.\n")
		<< "Adapter should correctly translate Target's request() to Adaptee's specificRequest().";
}

/**
 * @test Verifies the Adapter implements the Target interface.
 *
 * This test ensures polymorphism by confirming that the Adapter can be used
 * in place of any Target implementation.
 */
TEST_F(AdapterPatternTest, AdapterImplementsTarget) {
	Target* target = adapter; // Adapter is used as Target
	testing::internal::CaptureStdout();
	target->request();
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output,
		"Adapter: Translating request to Adaptee's specificRequest().\n"
		"Adaptee: Specific request called.\n")
		<< "Adapter should seamlessly substitute Target without issues.";
}
