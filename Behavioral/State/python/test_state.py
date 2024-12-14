import pytest
from state import Context, ConcreteStateA, ConcreteStateB

def test_state_transitions(caplog):
	context = Context()

	# Initial state is set to ConcreteStateA
	initial_state = ConcreteStateA()
	context.set_state(initial_state)

	# First request transitions from A to B
	with caplog.at_level("INFO"):
		context.request()
	assert "Context: Transitioned to ConcreteStateB" in caplog.text
	assert "ConcreteStateA: Handling request." in caplog.text

	# Second request transitions from B to A
	with caplog.at_level("INFO"):
		context.request()
	assert "Context: Transitioned to ConcreteStateA" in caplog.text
	assert "ConcreteStateB: Handling request." in caplog.text

def test_context_without_state(caplog):
	context = Context()

	# Request when no state is set
	with caplog.at_level("WARNING"):
		context.request()
	assert "Context: No state defined to handle the request." in caplog.text
