import unittest
from flyweight import FlyweightFactory


class TestFlyweightPattern(unittest.TestCase):
	"""
	Unit tests for the Flyweight pattern implementation.
	"""

	def test_flyweight_reuse(self):
		"""
		Test that the FlyweightFactory reuses existing Flyweights for the same intrinsic state.
		"""
		factory = FlyweightFactory()

		# Retrieve Flyweights with the same intrinsic state
		flyweight1 = factory.get_flyweight("SharedState")
		flyweight2 = factory.get_flyweight("SharedState")

		# Verify that the same Flyweight instance is reused
		self.assertIs(flyweight1, flyweight2)

	def test_flyweight_operation(self):
		"""
		Test that Flyweight operations correctly use intrinsic and extrinsic states.
		"""
		factory = FlyweightFactory()
		flyweight = factory.get_flyweight("State")

		# Capture logs for Flyweight operation
		with self.assertLogs("flyweight", level="INFO") as captured:
			flyweight.operation("ExtrinsicState")

		self.assertIn(
			"INFO:flyweight:ConcreteFlyweight: Intrinsic state = State, Extrinsic state = ExtrinsicState",
			captured.output,
		)

	def test_flyweight_list(self):
		"""
		Test that the FlyweightFactory correctly lists all Flyweights.
		"""
		factory = FlyweightFactory()

		# Add Flyweights
		factory.get_flyweight("State1")
		factory.get_flyweight("State2")
		factory.get_flyweight("State1")  # Reuses existing Flyweight

		# Capture logs for listing Flyweights
		with self.assertLogs("flyweight", level="INFO") as captured:
			factory.list_flyweights()

		self.assertIn("INFO:flyweight:Flyweights in Factory:", captured.output)
		self.assertIn("INFO:flyweight: - State1", captured.output)
		self.assertIn("INFO:flyweight: - State2", captured.output)


if __name__ == "__main__":
	unittest.main()
