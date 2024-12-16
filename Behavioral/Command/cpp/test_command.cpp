#include "command.hpp"
#include <gtest/gtest.h>

using namespace command_pattern;

/**
 * @brief Test the execution of a single command.
 */
TEST(CommandPatternTest, SingleCommandExecution) {
	auto receiver = std::make_shared<Receiver>();
	auto command = std::make_shared<ConcreteCommand>(receiver, "Operation1");

	Invoker invoker;
	invoker.setCommand(command);

	// Capture output
	testing::internal::CaptureStdout();

	// Execute command
	invoker.pressButton();

	// Verify output
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Receiver: Performing Operation1.\n");
}

/**
 * @brief Test the undo operation of a single command.
 */
TEST(CommandPatternTest, SingleCommandUndo) {
	auto receiver = std::make_shared<Receiver>();
	auto command = std::make_shared<ConcreteCommand>(receiver, "Operation2");

	Invoker invoker;
	invoker.setCommand(command);

	// Capture output
	testing::internal::CaptureStdout();

	// Undo command
	invoker.pressUndo();

	// Verify output
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Receiver: Reversing Operation2.\n");
}

/**
 * @brief Test the scenario where no command is set.
 */
TEST(CommandPatternTest, NoCommandSet) {
	Invoker invoker;

	// Capture output
	testing::internal::CaptureStdout();

	// Attempt to execute without a command
	invoker.pressButton();

	// Verify output
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Invoker: No command set.\n");
}

/**
 * @brief Test the scenario where no command is set for undo.
 */
TEST(CommandPatternTest, NoCommandSetUndo) {
	Invoker invoker;

	// Capture output
	testing::internal::CaptureStdout();

	// Attempt to undo without a command
	invoker.pressUndo();

	// Verify output
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Invoker: No command set to undo.\n");
}
