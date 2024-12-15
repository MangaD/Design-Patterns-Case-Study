#include "template_method.hpp"
#include <gtest/gtest.h>
#include <sstream>

/**
 * @brief Utility class for capturing and validating output streams.
 *
 * Captures the output sent to std::cout for validating test results
 * involving console output.
 */
class OutputCapture {
public:
	/// @brief Begins capturing std::cout output.
	void startCapture() {
		buffer.str("");
		buffer.clear();
		std::cout.rdbuf(buffer.rdbuf());
	}

	/// @brief Stops capturing and retrieves the captured output.
	/// @return The captured output as a string.
	std::string getCapturedOutput() {
		std::cout.rdbuf(originalBuffer);
		return buffer.str();
	}

private:
	std::stringstream buffer; ///< Internal buffer for capturing output.
	std::streambuf* originalBuffer = std::cout.rdbuf(); ///< Original buffer for std::cout.
};

/**
 * @brief Test the behavior of ConcreteClass1 when executing the template method.
 *
 * Verifies that the template method correctly executes the algorithm flow
 * and includes the specific steps and hook implementation of ConcreteClass1.
 */
TEST(TemplateMethodTest, ConcreteClass1Behavior) {
	OutputCapture capture;
	ConcreteClass1 concrete1;

	// Capture the output of the template method.
	capture.startCapture();
	concrete1.templateMethod();
	std::string capturedOutput = capture.getCapturedOutput();

	// Expected output for ConcreteClass1.
	std::string expectedOutput =
		"AbstractClass: Base operation 1\n"
		"ConcreteClass1: Required operation 1\n"
		"AbstractClass: Base operation 2\n"
		"ConcreteClass1: Required operation 2\n"
		"ConcreteClass1: Overridden hook implementation\n";

	// Validate the captured output matches the expected output.
	EXPECT_EQ(capturedOutput, expectedOutput)
		<< "ConcreteClass1 should follow the defined template method flow "
		<< "and execute its specific steps, including its custom hook.";
}

/**
 * @brief Test the behavior of ConcreteClass2 when executing the template method.
 *
 * Verifies that the template method correctly executes the algorithm flow
 * and includes the specific steps of ConcreteClass2.
 */
TEST(TemplateMethodTest, ConcreteClass2Behavior) {
	OutputCapture capture;
	ConcreteClass2 concrete2;

	// Capture the output of the template method.
	capture.startCapture();
	concrete2.templateMethod();
	std::string capturedOutput = capture.getCapturedOutput();

	// Expected output for ConcreteClass2.
	std::string expectedOutput =
		"AbstractClass: Base operation 1\n"
		"ConcreteClass2: Required operation 1\n"
		"AbstractClass: Base operation 2\n"
		"ConcreteClass2: Required operation 2\n"
		"AbstractClass: Default hook implementation\n";

	// Validate the captured output matches the expected output.
	EXPECT_EQ(capturedOutput, expectedOutput)
		<< "ConcreteClass2 should follow the defined template method flow "
		<< "and execute its specific steps, using the default hook.";
}

/**
 * @brief Test the flexibility of the hook in the template method.
 *
 * Ensures that classes inheriting from AbstractClass can optionally override
 * the hook method or rely on its default implementation.
 */
TEST(TemplateMethodTest, HookFlexibility) {
	OutputCapture capture;
	ConcreteClass1 concrete1;
	ConcreteClass2 concrete2;

	// Capture output for ConcreteClass1.
	capture.startCapture();
	concrete1.templateMethod();
	std::string output1 = capture.getCapturedOutput();

	// Capture output for ConcreteClass2.
	capture.startCapture();
	concrete2.templateMethod();
	std::string output2 = capture.getCapturedOutput();

	// Validate that ConcreteClass1 overrides the hook.
	EXPECT_NE(output1.find("ConcreteClass1: Overridden hook implementation"), std::string::npos)
		<< "ConcreteClass1 should override the hook with a custom implementation.";

	// Validate that ConcreteClass2 uses the default hook.
	EXPECT_NE(output2.find("AbstractClass: Default hook implementation"), std::string::npos)
		<< "ConcreteClass2 should use the default hook implementation.";
}

/**
 * @brief Test the overall algorithm structure of the template method.
 *
 * Ensures that the base operations and required operations execute in the
 * correct sequence as defined by the AbstractClass.
 */
TEST(TemplateMethodTest, AlgorithmStructure) {
	OutputCapture capture;
	ConcreteClass1 concrete1;

	// Capture output for ConcreteClass1.
	capture.startCapture();
	concrete1.templateMethod();
	std::string capturedOutput = capture.getCapturedOutput();

	// Check the sequence of operations in the output.
	size_t pos1 = capturedOutput.find("AbstractClass: Base operation 1");
	size_t pos2 = capturedOutput.find("ConcreteClass1: Required operation 1");
	size_t pos3 = capturedOutput.find("AbstractClass: Base operation 2");
	size_t pos4 = capturedOutput.find("ConcreteClass1: Required operation 2");

	// Validate the order of operations.
	EXPECT_TRUE(pos1 < pos2 && pos2 < pos3 && pos3 < pos4)
		<< "The algorithm steps should follow the correct order defined by the template method.";
}
