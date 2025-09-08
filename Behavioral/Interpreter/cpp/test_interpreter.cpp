
#include "interpreter.hpp"
#include <gtest/gtest.h>

using namespace interpreter_pattern;

/**
 * @brief Test evaluating constants and variables.
 */
TEST(InterpreterPatternTest, EvaluateConstantsAndVariables) {
	Context ctx{{{"x", true}, {"y", false}}};

	Constant t(true), f(false);
	EXPECT_TRUE(t.interpret(ctx));
	EXPECT_FALSE(f.interpret(ctx));

	Variable vx("x"), vy("y");
	EXPECT_TRUE(vx.interpret(ctx));
	EXPECT_FALSE(vy.interpret(ctx));
}

/**
 * @brief Test composition of NOT, AND, and OR (AST-style).
 */
TEST(InterpreterPatternTest, ComposeNotAndAndOr) {
	Context ctx{{{"x", true}, {"y", false}, {"z", true}}};

	// Represents: !(x & y) | z
	std::unique_ptr<Expression> expr = std::make_unique<Or>(
		std::make_unique<Not>(
			std::make_unique<And>(
				std::make_unique<Variable>("x"),
				std::make_unique<Variable>("y")
			)
		),
		std::make_unique<Variable>("z")
	);

	EXPECT_TRUE(expr->interpret(ctx));
}

/**
 * @brief Unbound variables should throw std::out_of_range.
 */
TEST(InterpreterPatternTest, UnboundVariableThrows) {
	Context ctx{};
	Variable v("missing");
	EXPECT_THROW(v.interpret(ctx), std::out_of_range);
}
