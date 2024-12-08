import unittest
from chain_of_responsibility import ConcreteHandlerA, ConcreteHandlerB
import logging


class TestChainOfResponsibility(unittest.TestCase):
	"""
	Test cases for the Chain of Responsibility pattern.
	"""

	def setUp(self):
		"""
		Sets up the chain of responsibility before each test.
		"""
		self.handler_a = ConcreteHandlerA()
		self.handler_b = ConcreteHandlerB()
		self.handler_a.set_next(self.handler_b)

	def test_handle_requests(self):
		"""
		Tests that the chain handles requests properly.
		"""
		with self.assertLogs("chain_of_responsibility", level="INFO") as captured:
			self.handler_a.handle_request("A")
			self.handler_a.handle_request("B")
			self.handler_a.handle_request("C")

		expected_logs = [
			"INFO:chain_of_responsibility:ConcreteHandlerA handled request: A",
			"INFO:chain_of_responsibility:ConcreteHandlerA passing request: B",
			"INFO:chain_of_responsibility:ConcreteHandlerB handled request: B",
			"INFO:chain_of_responsibility:ConcreteHandlerA passing request: C",
			"INFO:chain_of_responsibility:ConcreteHandlerB passing request: C",
		]

		# Assert all expected logs are present
		self.assertEqual(captured.output, expected_logs)

	def test_chain_integrity(self):
		"""
		Tests that the chain maintains its order and integrity.
		"""
		with self.assertLogs("chain_of_responsibility", level="INFO") as captured:
			self.handler_b.handle_request("B")
			self.handler_b.handle_request("C")

		expected_logs = [
			"INFO:chain_of_responsibility:ConcreteHandlerB handled request: B",
			"INFO:chain_of_responsibility:ConcreteHandlerB passing request: C",
		]

		# Assert all expected logs are present
		self.assertEqual(captured.output, expected_logs)


if __name__ == "__main__":
	unittest.main()
