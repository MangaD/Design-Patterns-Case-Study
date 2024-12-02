import unittest
from typing import Protocol
from adapter import Target, Adaptee, Adapter

class MockTarget(Target):
	"""
	A mock implementation of the Target protocol for testing purposes.
	"""
	def request(self) -> str:
		return "MockTarget: Request handled."


class TestAdapterPattern(unittest.TestCase):
	"""
	Unit tests for the Adapter Pattern implementation.
	"""

	def test_adapter_translation(self):
		"""
		Test that the Adapter correctly translates Target's request to Adaptee's specific_request.
		"""
		adaptee = Adaptee()
		adapter = Adapter(adaptee)

		expected_output = (
			"Adapter: Translating request to Adaptee's specific_request.\n"
			"Adaptee: Specific request called."
		)
		self.assertEqual(adapter.request(), expected_output)

	def test_adapter_with_null_adaptee(self):
		"""
		Test that the Adapter raises an exception when initialized with a None Adaptee.
		"""
		with self.assertRaises(ValueError) as context:
			Adapter(None)
		self.assertEqual(str(context.exception), "Adaptee cannot be None")

	def test_adaptee_direct_usage(self):
		"""
		Test that the Adaptee works directly without the Adapter.
		"""
		adaptee = Adaptee()
		self.assertEqual(adaptee.specific_request(), "Adaptee: Specific request called.")

	def test_mock_target(self):
		"""
		Test that a mock implementation of the Target protocol behaves as expected.
		"""
		target = MockTarget()
		self.assertEqual(target.request(), "MockTarget: Request handled.")

	def test_target_conformance(self):
		"""
		Test whether Adapter conforms to the Target protocol.
		"""
		adaptee = Adaptee()
		adapter = Adapter(adaptee)

		def client_code(target: Target):
			"""
			Simulate a client using the Target protocol.
			"""
			return target.request()

		result = client_code(adapter)
		expected = (
			"Adapter: Translating request to Adaptee's specific_request.\n"
			"Adaptee: Specific request called."
		)
		self.assertEqual(result, expected)


if __name__ == "__main__":
	unittest.main()
