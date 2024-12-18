from abc import ABC, abstractmethod
import logging

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class Context:
	"""
	The Context defines the interface of interest to clients and maintains a
	reference to an instance of a State subclass representing the current state.
	"""
	def __init__(self):
		"""
		Initialize the context with an initial state.
		"""
		self._state = None

	def set_state(self, state: 'State'):
		"""
		Change the current state of the context.
		
		:param state: The new state to transition to.
		"""
		self._state = state
		logger.info("Context: Transitioned to %s", type(state).__name__)

	def request(self):
		"""
		Delegate the request to the current state.
		"""
		if self._state:
			self._state.handle(self)
		else:
			logger.warning("Context: No state defined to handle the request.")

class State(ABC):
	"""
	The State interface declares methods that all Concrete States should implement.
	"""
	@abstractmethod
	def handle(self, context: Context):
		"""
		Handle the request and transition the context to another state if needed.
		
		:param context: The context in which the state operates.
		"""
		pass

class ConcreteStateA(State):
	"""
	ConcreteStateA implements the behavior associated with a state.
	"""
	def handle(self, context: Context):
		"""
		Handle the request, log the current state and transition to ConcreteStateB.

		:param context: The context in which the state operates, allowing state transitions.
		"""
		logger.info("ConcreteStateA: Handling request.")
		logger.info("ConcreteStateA: Transitioning to ConcreteStateB.")
		context.set_state(ConcreteStateB())

class ConcreteStateB(State):
	"""
	ConcreteStateB implements the behavior associated with a state.
	"""
	def handle(self, context: Context):
		"""
		Handle the request, log the current state and transition to ConcreteStateA.

		:param context: The context in which the state operates, allowing state transitions.
		"""
		logger.info("ConcreteStateB: Handling request.")
		logger.info("ConcreteStateB: Transitioning to ConcreteStateA.")
		context.set_state(ConcreteStateA())
