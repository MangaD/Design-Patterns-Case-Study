from typing import Protocol

class Target(Protocol):
	"""
	Defines the domain-specific interface used by the client.
	"""
	def request(self) -> str:
		"""
		Handles the request in a format expected by the client.
		:return: A string response.
		"""
		pass

class Adaptee:
	"""
	Defines the existing interface with specific functionality that needs adaptation.
	"""
	def specific_request(self) -> str:
		"""
		Provides functionality that needs to be adapted.
		:return: A specific string response.
		"""
		return "Adaptee: Specific request called."

class Adapter(Target):
	"""
	Adapts the Adaptee to the Target interface.
	"""
	def __init__(self, adaptee: Adaptee):
		if not adaptee:
			raise ValueError("Adaptee cannot be None")
		self._adaptee = adaptee

	def request(self) -> str:
		"""
		Translates the Target's request to the Adaptee's specific_request.
		:return: A string response translated by the Adapter.
		"""
		return f"Adapter: Translating request to Adaptee's specific_request.\n{self._adaptee.specific_request()}"
