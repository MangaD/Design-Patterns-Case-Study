import pytest
from memento import Originator, Caretaker, Memento


def test_save_and_restore_state():
	"""
	Test the Memento pattern for saving and restoring state.
	"""
	originator = Originator()
	caretaker = Caretaker()

	# Set and save initial state
	originator.set_state("State1")
	caretaker.add_memento(originator.create_memento())

	# Change state and save it
	originator.set_state("State2")
	caretaker.add_memento(originator.create_memento())

	# Verify current state
	assert originator.get_state() == "State2"

	# Restore to the previous state
	originator.restore_memento(caretaker.get_memento(0))
	assert originator.get_state() == "State1"


def test_caretaker_stores_multiple_mementos():
	"""
	Test the Caretaker's handling of multiple Mementos.
	"""
	originator = Originator()
	caretaker = Caretaker()

	# Save multiple states
	originator.set_state("StateA")
	caretaker.add_memento(originator.create_memento())
	originator.set_state("StateB")
	caretaker.add_memento(originator.create_memento())
	originator.set_state("StateC")
	caretaker.add_memento(originator.create_memento())

	# Restore and verify each state
	assert caretaker.get_memento(0).get_state() == "StateA"
	assert caretaker.get_memento(1).get_state() == "StateB"
	assert caretaker.get_memento(2).get_state() == "StateC"


def test_invalid_memento_index():
	"""
	Test the Caretaker's exception handling for invalid indices.
	"""
	caretaker = Caretaker()

	with pytest.raises(IndexError):
		caretaker.get_memento(0)

	with pytest.raises(IndexError):
		caretaker.get_memento(-1)


def test_restore_state_to_previous():
	"""
	Test the Originator's ability to restore state to multiple previous states.
	"""
	originator = Originator()
	caretaker = Caretaker()

	# Save states
	for state in ["Initial", "Intermediate", "Final"]:
		originator.set_state(state)
		caretaker.add_memento(originator.create_memento())

	# Restore states in reverse order
	for i in range(2, -1, -1):
		originator.restore_memento(caretaker.get_memento(i))
		assert originator.get_state() == caretaker.get_memento(i).get_state()
