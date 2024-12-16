#include "facade.hpp"
#include <gtest/gtest.h>

using namespace facade_pattern;

/**
 * @brief Tests the Facade pattern to ensure the interface simplifies interaction with subsystems.
 */
TEST(FacadePatternTest, SimplifiedInterface) {
	// Create the Facade instance
	Facade facade;

	// Execute the Facade operation
	std::string result = facade.operation();

	// Expected output
	std::string expected =
		"Facade: Coordinating subsystems:\n"
		"Subsystem1: Operation 1\n"
		"Subsystem2: Operation 2\n"
		"Subsystem3: Operation 3\n";

	// Verify the result
	EXPECT_EQ(result, expected);
}
