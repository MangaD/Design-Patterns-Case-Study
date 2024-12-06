import unittest
from proxy import Proxy


class TestProxyPattern(unittest.TestCase):
	"""
	Unit tests for the Proxy pattern implementation.
	"""

	def test_access_with_authentication(self):
		"""
		Test Proxy access with authentication.
		"""
		proxy = Proxy(is_authenticated=True)

		with self.assertLogs("proxy", level="INFO") as log:
			proxy.request("Resource1")

		log_output = "\n".join(log.output)
		self.assertIn("Proxy: Initializing RealSubject.", log_output)
		self.assertIn("Proxy: Delegating request to RealSubject.", log_output)
		self.assertIn("RealSubject: Handling request for resource: Resource1", log_output)

	def test_access_without_authentication(self):
		"""
		Test Proxy access without authentication.
		"""
		proxy = Proxy(is_authenticated=False)

		with self.assertLogs("proxy", level="INFO") as log:
			proxy.request("Resource2")

		log_output = "\n".join(log.output)
		self.assertIn("Proxy: Access denied. Authentication required to access: Resource2", log_output)

	def test_lazy_initialization(self):
		"""
		Test that RealSubject is initialized lazily.
		"""
		proxy = Proxy(is_authenticated=True)

		with self.assertLogs("proxy", level="INFO") as log:
			# First access
			proxy.request("Resource3")
		first_log_output = "\n".join(log.output)
		self.assertIn("Proxy: Initializing RealSubject.", first_log_output)

		with self.assertLogs("proxy", level="INFO") as log:
			# Subsequent access
			proxy.request("Resource4")
		second_log_output = "\n".join(log.output)
		self.assertNotIn("Proxy: Initializing RealSubject.", second_log_output)  # No reinitialization


if __name__ == "__main__":
	unittest.main()
