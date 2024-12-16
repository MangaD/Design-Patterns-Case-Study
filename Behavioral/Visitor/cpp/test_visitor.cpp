#include "visitor.hpp"
#include <gtest/gtest.h>
#include <sstream>

/**
 * @brief Test Visitor Pattern functionality.
 */
TEST(VisitorPatternTest, TestVisitorOperations) {
	std::ostringstream output;
	auto originalCoutBuffer = std::cout.rdbuf(output.rdbuf());

	// Create elements
	auto elementA = std::make_shared<ElementA>();
	auto elementB = std::make_shared<ElementB>();

	// Create visitors
	ConcreteVisitorA visitorA;
	ConcreteVisitorB visitorB;

	// Test ElementA with VisitorA
	elementA->accept(visitorA);

	// Test ElementB with VisitorA
	elementB->accept(visitorA);

	// Test ElementA with VisitorB
	elementA->accept(visitorB);

	// Test ElementB with VisitorB
	elementB->accept(visitorB);

	// Restore original cout buffer
	std::cout.rdbuf(originalCoutBuffer);

	std::string expectedOutput =
		"ConcreteVisitorA: ElementA operation.\n"
		"ConcreteVisitorA: ElementB operation.\n"
		"ConcreteVisitorB: ElementA operation.\n"
		"ConcreteVisitorB: ElementB operation.\n";

	EXPECT_EQ(output.str(), expectedOutput);
}

/**
 * @brief Test ObjectStructure with multiple visitors.
 */
TEST(VisitorPatternTest, TestObjectStructure) {
	std::ostringstream output;
	auto originalCoutBuffer = std::cout.rdbuf(output.rdbuf());

	// Create object structure
	ObjectStructure structure;
	structure.addElement(std::make_shared<ElementA>());
	structure.addElement(std::make_shared<ElementB>());

	// Create visitor
	ConcreteVisitorA visitor;

	// Test object structure with VisitorA
	structure.accept(visitor);

	// Restore original cout buffer
	std::cout.rdbuf(originalCoutBuffer);

	std::string expectedOutput =
		"ConcreteVisitorA: ElementA operation.\n"
		"ConcreteVisitorA: ElementB operation.\n";

	EXPECT_EQ(output.str(), expectedOutput);
}
