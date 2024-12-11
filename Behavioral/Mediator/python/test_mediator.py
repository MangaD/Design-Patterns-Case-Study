import pytest
from mediator import ConcreteMediator, ConcreteColleague


@pytest.fixture
def setup_mediator_and_colleagues():
	"""
	Fixture to set up a ConcreteMediator and two ConcreteColleagues.
	"""
	mediator = ConcreteMediator()
	colleague1 = ConcreteColleague(mediator, "Colleague1")
	colleague2 = ConcreteColleague(mediator, "Colleague2")

	mediator.add_colleague(colleague1)
	mediator.add_colleague(colleague2)

	return mediator, colleague1, colleague2


def test_communication_between_colleagues(caplog, setup_mediator_and_colleagues):
	"""
	Tests that colleagues can communicate with each other via the mediator.
	"""
	_, colleague1, colleague2 = setup_mediator_and_colleagues

	with caplog.at_level("INFO"):
		colleague1.send("Hello from Colleague1")

	assert "Colleague2 received message: Hello from Colleague1" in caplog.text


def test_send_message_without_other_colleagues(caplog):
	"""
	Tests that no messages are sent when there are no other colleagues.
	"""
	mediator = ConcreteMediator()
	colleague1 = ConcreteColleague(mediator, "Colleague1")
	mediator.add_colleague(colleague1)

	with caplog.at_level("INFO"):
		colleague1.send("Hello")

	assert "received message" not in caplog.text


def test_dynamic_colleague_addition(caplog):
	"""
	Tests dynamic addition of colleagues to the mediator.
	"""
	mediator = ConcreteMediator()
	colleague1 = ConcreteColleague(mediator, "Colleague1")
	mediator.add_colleague(colleague1)

	with caplog.at_level("INFO", logger="mediator"):
		colleague1.send("Hello before Colleague2 is added")

	colleague2 = ConcreteColleague(mediator, "Colleague2")
	mediator.add_colleague(colleague2)

	with caplog.at_level("INFO", logger="mediator"):
		colleague1.send("Hello after Colleague2 is added")

	assert "Colleague2 received message: Hello before Colleague2 is added" not in caplog.text
	assert "Colleague2 received message: Hello after Colleague2 is added" in caplog.text
