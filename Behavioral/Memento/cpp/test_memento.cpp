#include "memento.hpp"
#include <gtest/gtest.h>

/**
 * @brief Test the Memento pattern for saving and restoring state.
 */
TEST(MementoPatternTest, SaveAndRestoreState) {
	Originator originator;
	Caretaker caretaker;

	// Set and save initial state
	originator.setState("State1");
	caretaker.addMemento(originator.createMemento());

	// Change state and save it
	originator.setState("State2");
	caretaker.addMemento(originator.createMemento());

	// Verify the current state
	EXPECT_EQ(originator.getState(), "State2");

	// Restore to the previous state
	originator.restoreMemento(caretaker.getMemento(0));
	EXPECT_EQ(originator.getState(), "State1");
}

/**
 * @brief Test the Caretaker's handling of multiple Mementos.
 */
TEST(MementoPatternTest, CaretakerStoresMultipleMementos) {
	Originator originator;
	Caretaker caretaker;

	// Save multiple states
	originator.setState("StateA");
	caretaker.addMemento(originator.createMemento());
	originator.setState("StateB");
	caretaker.addMemento(originator.createMemento());
	originator.setState("StateC");
	caretaker.addMemento(originator.createMemento());

	// Restore and verify each state
	EXPECT_EQ(caretaker.getMemento(0).getState(), "StateA");
	EXPECT_EQ(caretaker.getMemento(1).getState(), "StateB");
	EXPECT_EQ(caretaker.getMemento(2).getState(), "StateC");
}

/**
 * @brief Test the Caretaker's exception handling for invalid indices.
 */
TEST(MementoPatternTest, InvalidMementoIndex) {
	Caretaker caretaker;

	EXPECT_THROW(caretaker.getMemento(0), std::out_of_range);
	EXPECT_THROW(caretaker.getMemento(1), std::out_of_range);
}
