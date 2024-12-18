import logging
from observer import Subject, ConcreteObserver

# Configure pytest logs
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("observer")


def test_attach_and_notify_observers(caplog):
	"""
	Test attaching multiple observers and verifying notifications.

	Tests that attaching multiple observers and changing the subject state
	result in all observers being notified of the change.
	"""
	subject = Subject()
	observer1 = ConcreteObserver("Observer1")
	observer2 = ConcreteObserver("Observer2")

	# Attach observers
	subject.attach(observer1)
	subject.attach(observer2)

	# Set state and notify
	with caplog.at_level(logging.INFO):
		subject.set_state("State1")

		assert "Subject state updated to: State1" in caplog.text
		assert "Observer Observer1 received update. New state: State1" in caplog.text
		assert "Observer Observer2 received update. New state: State1" in caplog.text


def test_detach_observer(caplog):
	"""
	Test detaching an observer and verifying it no longer receives updates.

	Ensures that after detaching an observer, it does not receive notifications
	when the subject's state changes, while other attached observers do.
	"""

	subject = Subject()
	observer1 = ConcreteObserver("Observer1")
	observer2 = ConcreteObserver("Observer2")

	# Attach and detach observers
	subject.attach(observer1)
	subject.attach(observer2)
	subject.detach(observer2)

	# Set state and notify
	with caplog.at_level(logging.INFO):
		subject.set_state("State2")

		assert "Observer Observer1 received update. New state: State2" in caplog.text
		assert "Observer Observer2 received update. New state: State2" not in caplog.text


def test_no_observers(caplog):
	"""
	Test that the system behaves correctly when no observers are attached.
	
	Ensures that when the subject's state is changed without any observers 
	attached, no observer notifications occur, and only the subject's state 
	update is logged.
	"""

	subject = Subject()

	# Set state without any observers
	with caplog.at_level(logging.INFO):
		subject.set_state("State3")

		assert "Subject state updated to: State3" in caplog.text
		assert "Observer" not in caplog.text


def test_attach_same_observer_multiple_times(caplog):
	"""
	Test attaching the same observer multiple times.

	Verifies that attaching the same observer multiple times results in only
	one notification when the subject's state changes.
	"""
	subject = Subject()
	observer1 = ConcreteObserver("Observer1")

	# Attach the same observer multiple times
	subject.attach(observer1)
	subject.attach(observer1)

	# Set state and notify
	with caplog.at_level(logging.INFO):
		subject.set_state("State4")

		assert caplog.text.count("Observer Observer1 received update. New state: State4") == 1


def test_state_retrieval():
	"""
	Test subject state retrieval after update.
	
	Verifies that the subject's state is updated correctly and can be retrieved
	using the get_state method.
	"""
	subject = Subject()
	subject.set_state("State5")
	assert subject.get_state() == "State5"
