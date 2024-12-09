import pytest
from command import Receiver, ConcreteCommandA, ConcreteCommandB, Invoker
import logging

# Configure logging for tests
logging.basicConfig(level=logging.INFO)


def test_concrete_command_a(caplog):
	"""
	Test that ConcreteCommandA invokes the correct action on the Receiver.
	"""
	receiver = Receiver()
	command_a = ConcreteCommandA(receiver)

	with caplog.at_level(logging.INFO):
		command_a.execute()

	assert "Receiver: Performing Action A." in caplog.text


def test_concrete_command_b(caplog):
	"""
	Test that ConcreteCommandB invokes the correct action on the Receiver.
	"""
	receiver = Receiver()
	command_b = ConcreteCommandB(receiver)

	with caplog.at_level(logging.INFO):
		command_b.execute()

	assert "Receiver: Performing Action B." in caplog.text


def test_invoker_execution(caplog):
	"""
	Test that the Invoker executes all added commands in order.
	"""
	receiver = Receiver()
	invoker = Invoker()

	command_a = ConcreteCommandA(receiver)
	command_b = ConcreteCommandB(receiver)

	invoker.add_command(command_a)
	invoker.add_command(command_b)

	with caplog.at_level(logging.INFO):
		invoker.execute_all()

	assert "Receiver: Performing Action A." in caplog.text
	assert "Receiver: Performing Action B." in caplog.text
