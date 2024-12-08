from __future__ import annotations
from abc import ABC, abstractmethod
from typing import Optional
import logging

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("chain_of_responsibility")


class Handler(ABC):
	"""
	Abstract Handler interface for processing requests in the chain.
	"""

	def __init__(self):
		self._next_handler: Optional[Handler] = None

	def set_next(self, handler: Handler) -> Handler:
		"""
		Sets the next handler in the chain.
		:param handler: The next handler.
		:return: The handler itself, to allow method chaining.
		"""
		self._next_handler = handler
		return handler

	@abstractmethod
	def handle_request(self, request: str) -> None:
		"""
		Handles the request or forwards it to the next handler.
		:param request: The request to handle.
		"""
		pass


class AbstractHandler(Handler):
	"""
	Abstract base class that implements the chaining mechanism.
	"""

	def handle_request(self, request: str) -> None:
		if self._next_handler:
			self._next_handler.handle_request(request)


class ConcreteHandlerA(AbstractHandler):
	"""
	A concrete handler that processes requests matching 'A'.
	"""

	def handle_request(self, request: str) -> None:
		if request == 'A':
			logger.info(f"ConcreteHandlerA handled request: {request}")
		else:
			logger.info(f"ConcreteHandlerA passing request: {request}")
			super().handle_request(request)


class ConcreteHandlerB(AbstractHandler):
	"""
	A concrete handler that processes requests matching 'B'.
	"""

	def handle_request(self, request: str) -> None:
		if request == 'B':
			logger.info(f"ConcreteHandlerB handled request: {request}")
		else:
			logger.info(f"ConcreteHandlerB passing request: {request}")
			super().handle_request(request)
