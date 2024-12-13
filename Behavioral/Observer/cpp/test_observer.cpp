#include "observer.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <sstream>

// Custom stream to capture output for assertions
std::ostringstream outputStream;

/**
 * @brief A TestObserver that overrides update to write to the outputStream.
 */
class TestObserver : public ConcreteObserver {
public:
	TestObserver(const std::string &name, std::shared_ptr<Subject> subject)
		: ConcreteObserver(name, subject) {}

	void update() override {
		outputStream << "Observer " << getName() << " received update." << std::endl;
	}
};

// Helper function to reset the output stream
void resetOutputStream() {
	outputStream.str("");
	outputStream.clear();
}

/**
 * @brief Test attaching and notifying a single observer.
 */
TEST(ObserverPatternTest, AttachAndNotifySingleObserver) {
	auto subject = std::make_shared<ConcreteSubject>();
	auto observer = std::make_shared<TestObserver>("Observer1", subject);

	// Attach the observer to the subject
	subject->attach(observer);

	// Trigger an update
	resetOutputStream();
	subject->setState("State1");

	// Assert the correct output
	EXPECT_EQ(outputStream.str(), "Observer Observer1 received update.\n");
}

/**
 * @brief Test attaching multiple observers and verifying notifications.
 */
TEST(ObserverPatternTest, AttachAndNotifyMultipleObservers) {
	auto subject = std::make_shared<ConcreteSubject>();
	auto observer1 = std::make_shared<TestObserver>("Observer1", subject);
	auto observer2 = std::make_shared<TestObserver>("Observer2", subject);

	// Attach the observers to the subject
	subject->attach(observer1);
	subject->attach(observer2);

	// Trigger an update
	resetOutputStream();
	subject->setState("State2");

	// Assert the correct output
	EXPECT_EQ(outputStream.str(),
			  "Observer Observer1 received update.\n"
			  "Observer Observer2 received update.\n");
}

/**
 * @brief Test detaching an observer and ensuring it no longer receives updates.
 */
TEST(ObserverPatternTest, DetachObserver) {
	auto subject = std::make_shared<ConcreteSubject>();
	auto observer1 = std::make_shared<TestObserver>("Observer1", subject);
	auto observer2 = std::make_shared<TestObserver>("Observer2", subject);

	// Attach both observers
	subject->attach(observer1);
	subject->attach(observer2);

	// Detach observer1
	subject->detach(observer1);

	// Trigger an update
	resetOutputStream();
	subject->setState("State3");

	// Assert only observer2 receives the update
	EXPECT_EQ(outputStream.str(), "Observer Observer2 received update.\n");
}

/**
 * @brief Test state synchronization between subject and observers.
 */
TEST(ObserverPatternTest, StateSynchronization) {
	auto subject = std::make_shared<ConcreteSubject>();
	auto observer = std::make_shared<TestObserver>("Observer1", subject);

	// Attach the observer
	subject->attach(observer);

	// Change state in the subject
	subject->setState("SynchronizedState");

	// Verify that the subject's state is correct
	EXPECT_EQ(subject->getState(), "SynchronizedState");
}

/**
 * @brief Test notifying observers without attaching any observers.
 */
TEST(ObserverPatternTest, NotifyWithNoObservers) {
	auto subject = std::make_shared<ConcreteSubject>();

	// Trigger an update without attaching any observers
	resetOutputStream();
	subject->setState("NoObserversState");

	// Assert that no output is produced
	EXPECT_EQ(outputStream.str(), "");
}
