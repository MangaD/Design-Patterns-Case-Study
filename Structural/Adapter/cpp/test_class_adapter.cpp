#include "class_adapter.hpp"
#include <gtest/gtest.h>
#include <sstream>

using namespace class_adapter_pattern;

/**
 * @brief Test Fixture for the Class Adapter Pattern.
 */
class ClassAdapterTest : public ::testing::Test {
protected:
	Adapter adapter; ///< Instance of the Adapter used for testing.

	/**
	 * @brief Captures and verifies console output during tests.
	 */
	std::string captureOutput(const std::function<void()>& func) {
		std::ostringstream buffer;
		std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
		func();
		std::cout.rdbuf(old);
		return buffer.str();
	}
};

/**
 * @brief Tests the Adapter's ability to translate requests.
 */
TEST_F(ClassAdapterTest, AdapterTranslation) {
	std::string response = adapter.request();
	EXPECT_EQ(response,
		"Adapter: Translating request to Adaptee's specificRequest().\n"
		"Adaptee: Specific request called.")
		<< "Adapter should correctly translate Target's request() to Adaptee's specificRequest().";
}

/**
 * @brief Tests direct interaction with the Adaptee's specificRequest for comparison.
 */
TEST_F(ClassAdapterTest, DirectAdapteeRequest) {
	Adaptee adaptee;
	std::string response = adaptee.specificRequest();
	EXPECT_EQ(response, "Adaptee: Specific request called.")
		<< "Adaptee's specificRequest() should return its default message.";
}

