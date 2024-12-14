#include "state.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <sstream>

// Helper function to capture console output for testing
std::string captureOutput(const std::function<void()> &func) {
	std::ostringstream buffer;
	std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
	func();
	std::cout.rdbuf(old);
	return buffer.str();
}

/**
 * @brief Test initial state of the Context.
 */
TEST(StatePatternTest, InitialState) {
	auto initialState = std::make_unique<ConcreteStateA>();
	Context context(std::move(initialState));

	EXPECT_EQ(context.getStateName(), "ConcreteStateA");
}

/**
 * @brief Test state transition from ConcreteStateA to ConcreteStateB.
 */
TEST(StatePatternTest, StateTransitionAtoB) {
	auto initialState = std::make_unique<ConcreteStateA>();
	Context context(std::move(initialState));

	// Capture output during state transition
	std::string output = captureOutput([&]() {
		context.request();
	});

	EXPECT_EQ(context.getStateName(), "ConcreteStateB");
	EXPECT_NE(output.find("ConcreteStateA: Handling request. Switching to State B."), std::string::npos);
}

/**
 * @brief Test state transition from ConcreteStateB to ConcreteStateA.
 */
TEST(StatePatternTest, StateTransitionBtoA) {
	auto initialState = std::make_unique<ConcreteStateB>();
	Context context(std::move(initialState));

	// Capture output during state transition
	std::string output = captureOutput([&]() {
		context.request();
	});

	EXPECT_EQ(context.getStateName(), "ConcreteStateA");
	EXPECT_NE(output.find("ConcreteStateB: Handling request. Switching to State A."), std::string::npos);
}

/**
 * @brief Test multiple state transitions.
 */
TEST(StatePatternTest, MultipleTransitions) {
	auto initialState = std::make_unique<ConcreteStateA>();
	Context context(std::move(initialState));

	// Transition from A to B
	std::string outputAtoB = captureOutput([&]() {
		context.request();
	});
	EXPECT_EQ(context.getStateName(), "ConcreteStateB");
	EXPECT_NE(outputAtoB.find("ConcreteStateA: Handling request. Switching to State B."), std::string::npos);

	// Transition from B to A
	std::string outputBtoA = captureOutput([&]() {
		context.request();
	});
	EXPECT_EQ(context.getStateName(), "ConcreteStateA");
	EXPECT_NE(outputBtoA.find("ConcreteStateB: Handling request. Switching to State A."), std::string::npos);

	// Transition from A to B again
	std::string outputAtoBAgain = captureOutput([&]() {
		context.request();
	});
	EXPECT_EQ(context.getStateName(), "ConcreteStateB");
	EXPECT_NE(outputAtoBAgain.find("ConcreteStateA: Handling request. Switching to State B."), std::string::npos);
}

/**
 * @brief Test getStateName with unknown state.
 */
TEST(StatePatternTest, UnknownState) {
	// Directly set the state to an unknown derived class
	class UnknownState : public State {
	public:
		void handle(Context &) const override {}
	};
	Context context(std::make_unique<UnknownState>());

	EXPECT_EQ(context.getStateName(), "Unknown State");
}
