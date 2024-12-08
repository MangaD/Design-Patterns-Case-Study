#include "chain_of_responsibility.hpp"
#include <gtest/gtest.h>
#include <sstream>

/**
 * @brief Test the chain of responsibility pattern.
 */
TEST(ChainOfResponsibilityTest, HandlesRequestsProperly) {
	// Create handlers
	auto handlerA = std::make_shared<ConcreteHandlerA>();
	auto handlerB = std::make_shared<ConcreteHandlerB>();

	// Chain the handlers
	handlerA->setNext(handlerB);

	// Redirect output for testing
	std::ostringstream oss;
	std::streambuf *originalCoutBuffer = std::cout.rdbuf(oss.rdbuf());

	// Test requests
	handlerA->handleRequest("A");
	handlerA->handleRequest("B");
	handlerA->handleRequest("C");

	// Restore original std::cout buffer
	std::cout.rdbuf(originalCoutBuffer);

	// Expected output
	std::string expectedOutput =
		"ConcreteHandlerA handled request: A\n"
		"ConcreteHandlerA passing request: B\n"
		"ConcreteHandlerB handled request: B\n"
		"ConcreteHandlerA passing request: C\n"
		"ConcreteHandlerB passing request: C\n";

	// Validate the output
	EXPECT_EQ(oss.str(), expectedOutput);
}
