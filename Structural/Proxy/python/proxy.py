from abc import ABC, abstractmethod
import logging

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("proxy")


class Subject(ABC):
	"""
	Defines the common interface for the RealSubject and Proxy.
	"""

	@abstractmethod
	def request(self, resource: str) -> None:
		"""
		Handle the client's request.

		:param resource: The resource being requested.
		"""
		pass


class RealSubject(Subject):
	"""
	Performs the actual work of handling requests.
	"""

	def request(self, resource: str) -> None:
		"""
		Handles the request and simulates actual processing.

		:param resource: The resource being accessed.
		"""
		logger.info(f"RealSubject: Handling request for resource: {resource}")


class Proxy(Subject):
	"""
	Controls access to the RealSubject and adds additional functionality like authentication.
	"""

	def __init__(self, is_authenticated: bool):
		"""
		Initialize the Proxy with authentication status.

		:param is_authenticated: Whether the client is authenticated.
		"""
		self.is_authenticated = is_authenticated
		self._real_subject = None

	def request(self, resource: str) -> None:
		"""
		Handle the request by checking authentication and delegating to RealSubject.

		:param resource: The resource being requested.
		"""
		if not self.is_authenticated:
			logger.info(f"Proxy: Access denied. Authentication required to access: {resource}")
			return

		if self._real_subject is None:
			logger.info("Proxy: Initializing RealSubject.")
			self._real_subject = RealSubject()

		logger.info("Proxy: Delegating request to RealSubject.")
		self._real_subject.request(resource)
