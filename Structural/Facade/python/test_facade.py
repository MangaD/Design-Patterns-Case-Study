"""
Unit tests for the Facade pattern.
"""

import unittest
from facade import Facade


class TestFacade(unittest.TestCase):
	"""
	Tests the Facade class to ensure it simplifies interaction with subsystems.
	"""

	def test_facade_operation(self):
		"""
		Test the Facade's ability to coordinate subsystems.
		"""
		# Create the Facade instance
		facade = Facade()

		# Execute the Facade operation
		result = facade.operation()

		# Expected output
		expected = (
			"Facade: Coordinating subsystems:\n"
			"Subsystem1: Operation 1\n"
			"Subsystem2: Operation 2\n"
			"Subsystem3: Operation 3\n"
		)

		# Verify the result
		self.assertEqual(result, expected)


if __name__ == "__main__":
	unittest.main()
