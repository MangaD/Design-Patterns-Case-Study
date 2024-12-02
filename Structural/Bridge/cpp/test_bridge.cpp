#include "bridge.hpp"
#include <gtest/gtest.h>

/**
 * @brief Test the Abstraction with ConcreteImplementorA.
 */
TEST(BridgePatternTest, AbstractionWithConcreteImplementorA) {
	ConcreteImplementorA implementorA;
	Abstraction abstraction(&implementorA);

	EXPECT_EQ(abstraction.operation(), "Abstraction: Base operation with:\nConcreteImplementorA: Operation Implementation.");
}

/**
 * @brief Test the Abstraction with ConcreteImplementorB.
 */
TEST(BridgePatternTest, AbstractionWithConcreteImplementorB) {
	ConcreteImplementorB implementorB;
	Abstraction abstraction(&implementorB);

	EXPECT_EQ(abstraction.operation(), "Abstraction: Base operation with:\nConcreteImplementorB: Operation Implementation.");
}

/**
 * @brief Test the RefinedAbstraction with ConcreteImplementorA.
 */
TEST(BridgePatternTest, RefinedAbstractionWithConcreteImplementorA) {
	ConcreteImplementorA implementorA;
	RefinedAbstraction refinedAbstraction(&implementorA);

	EXPECT_EQ(refinedAbstraction.operation(), "RefinedAbstraction: Enhanced operation with:\nConcreteImplementorA: Operation Implementation.");
}

/**
 * @brief Test the RefinedAbstraction with ConcreteImplementorB.
 */
TEST(BridgePatternTest, RefinedAbstractionWithConcreteImplementorB) {
	ConcreteImplementorB implementorB;
	RefinedAbstraction refinedAbstraction(&implementorB);

	EXPECT_EQ(refinedAbstraction.operation(), "RefinedAbstraction: Enhanced operation with:\nConcreteImplementorB: Operation Implementation.");
}
