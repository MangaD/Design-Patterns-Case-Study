#include "strategy.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <string>

/**
 * @brief Captures console output for test verification.
 */
class ConsoleOutput {
private:
	std::ostringstream oss;
	std::streambuf* oldCout;
	std::streambuf* oldCerr;

public:
	/**
	 * @brief Start capturing output from both std::cout and std::cerr.
	 */
	void start() {
		oldCout = std::cout.rdbuf(oss.rdbuf());
		oldCerr = std::cerr.rdbuf(oss.rdbuf());
	}

	/**
	 * @brief Stop capturing output and restore original streams.
	 * @return The captured output as a string.
	 */
	std::string stop() {
		std::cout.rdbuf(oldCout);
		std::cerr.rdbuf(oldCerr);
		return oss.str();
	}
};

/**
 * @brief Test that Context can execute ConcreteStrategyA.
 */
TEST(StrategyPatternTest, ExecuteConcreteStrategyA) {
	Context context;
	context.setStrategy(std::make_unique<ConcreteStrategyA>());

	ConsoleOutput output;
	output.start();
	context.executeStrategy();
	std::string capturedOutput = output.stop();

	EXPECT_EQ(capturedOutput, "Executing strategy A\n");
}

/**
 * @brief Test that Context can execute ConcreteStrategyB.
 */
TEST(StrategyPatternTest, ExecuteConcreteStrategyB) {
	Context context;
	context.setStrategy(std::make_unique<ConcreteStrategyB>());

	ConsoleOutput output;
	output.start();
	context.executeStrategy();
	std::string capturedOutput = output.stop();

	EXPECT_EQ(capturedOutput, "Executing strategy B\n");
}

/**
 * @brief Test that Context handles missing strategy gracefully.
 */
TEST(StrategyPatternTest, NoStrategySet) {
	Context context;

	ConsoleOutput output;
	output.start();
	context.executeStrategy();
	std::string capturedOutput = output.stop();

	EXPECT_EQ(capturedOutput, "No strategy set!\n");
}
