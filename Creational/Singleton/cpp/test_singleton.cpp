#include "singleton.hpp"
#include <gtest/gtest.h>

using namespace singleton_pattern;

/**
 * @file test_singleton.cpp
 * @brief Unit tests for the Singleton class using GoogleTest.
 *
 * This file contains unit tests to verify the correct behavior of the
 * Singleton class. It ensures that only a single instance is created
 * and that the provided methods work as expected.
 */

/**
 * @brief Test to verify that Singleton returns a single instance.
 *
 * This test checks that the `getInstance()` method always returns
 * the same instance of the Singleton class, ensuring the Singleton
 * pattern is correctly implemented.
 */
TEST(SingletonTest, SingleInstance) {
	Singleton& instance1 = Singleton::getInstance();
	Singleton& instance2 = Singleton::getInstance();

	// Ensure both references point to the same instance
	ASSERT_EQ(&instance1, &instance2);
}

/**
 * @brief Test the functionality of the Singleton's `doSomething()` method.
 *
 * This test captures the standard output from the `doSomething()` method
 * and verifies that the output matches the expected string.
 */
TEST(SingletonTest, DoSomething) {
	Singleton& instance = Singleton::getInstance();

	// Capture standard output
	testing::internal::CaptureStdout();
	instance.doSomething();
	std::string output = testing::internal::GetCapturedStdout();

	// Verify the output matches the expected string
	ASSERT_EQ(output, "Singleton instance is working!\n");
}
