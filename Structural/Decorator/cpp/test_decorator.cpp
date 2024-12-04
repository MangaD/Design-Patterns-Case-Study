#include "decorator.hpp"
#include <gtest/gtest.h>

/**
 * @brief Test the base ConcreteComponent.
 */
TEST(DecoratorPatternTest, ConcreteComponent) {
	auto component = std::make_shared<ConcreteComponent>();
	EXPECT_EQ(component->getDescription(), "Concrete Component");
	EXPECT_DOUBLE_EQ(component->cost(), 10.0);
}

/**
 * @brief Test the functionality of ConcreteDecoratorA.
 */
TEST(DecoratorPatternTest, ConcreteDecoratorA) {
	auto component = std::make_shared<ConcreteComponent>();
	auto decorated = std::make_shared<ConcreteDecoratorA>(component);

	EXPECT_EQ(decorated->getDescription(), "Concrete Component + Feature A");
	EXPECT_DOUBLE_EQ(decorated->cost(), 15.0);
}

/**
 * @brief Test the functionality of ConcreteDecoratorB.
 */
TEST(DecoratorPatternTest, ConcreteDecoratorB) {
	auto component = std::make_shared<ConcreteComponent>();
	auto decorated = std::make_shared<ConcreteDecoratorB>(component);

	EXPECT_EQ(decorated->getDescription(), "Concrete Component + Feature B");
	EXPECT_DOUBLE_EQ(decorated->cost(), 17.5);
}

/**
 * @brief Test chaining multiple decorators.
 */
TEST(DecoratorPatternTest, MultipleDecorators) {
	auto component = std::make_shared<ConcreteComponent>();
	auto decoratorA = std::make_shared<ConcreteDecoratorA>(component);
	auto decoratorB = std::make_shared<ConcreteDecoratorB>(decoratorA);

	EXPECT_EQ(decoratorB->getDescription(), "Concrete Component + Feature A + Feature B");
	EXPECT_DOUBLE_EQ(decoratorB->cost(), 22.5);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
