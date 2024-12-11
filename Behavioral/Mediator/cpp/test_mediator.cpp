#include "mediator.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

/**
 * @brief Fixture for testing the Mediator pattern.
 */
class MediatorTest : public ::testing::Test {
protected:
	std::ostringstream logStream; ///< Log stream for capturing output.

	void SetUp() override {
		// Redirect std::cout to capture output.
		std::cout.rdbuf(logStream.rdbuf());
	}

	void TearDown() override {
		// Restore std::cout.
		std::cout.rdbuf(nullptr);
	}
};

/**
 * @brief Test communication between colleagues using the mediator.
 */
TEST_F(MediatorTest, CommunicationBetweenColleagues) {
	ConcreteMediator mediator;

	ConcreteColleague colleague1(&mediator, "Colleague1");
	ConcreteColleague colleague2(&mediator, "Colleague2");

	mediator.addColleague(&colleague1);
	mediator.addColleague(&colleague2);

	colleague1.send("Hello from Colleague1");

	std::string output = logStream.str();
	EXPECT_NE(output.find("Colleague2 received message: Hello from Colleague1"), std::string::npos);
}

/**
 * @brief Test sending a message when no colleagues are registered.
 */
TEST_F(MediatorTest, SendMessageWithoutColleagues) {
	ConcreteMediator mediator;

	ConcreteColleague colleague1(&mediator, "Colleague1");

	colleague1.send("Message without other colleagues");

	std::string output = logStream.str();
	EXPECT_EQ(output, ""); // No output expected since no colleagues are registered to receive.
}

/**
 * @brief Test adding colleagues dynamically to the mediator.
 */
TEST_F(MediatorTest, DynamicColleagueAddition) {
	ConcreteMediator mediator;

	ConcreteColleague colleague1(&mediator, "Colleague1");
	ConcreteColleague colleague2(&mediator, "Colleague2");

	mediator.addColleague(&colleague1);
	colleague1.send("Hello before Colleague2 is added");

	mediator.addColleague(&colleague2);
	colleague1.send("Hello after Colleague2 is added");

	std::string output = logStream.str();
	EXPECT_EQ(output.find("Colleague2 received message: Hello before Colleague2 is added"), std::string::npos);
	EXPECT_NE(output.find("Colleague2 received message: Hello after Colleague2 is added"), std::string::npos);
}
