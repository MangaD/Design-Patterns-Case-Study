import unittest
from bridge import Abstraction, RefinedAbstraction, ConcreteImplementorA, ConcreteImplementorB

class TestBridgePattern(unittest.TestCase):
	"""
	Unit tests for the Bridge Pattern implementation.
	"""

	def test_abstraction_with_concrete_implementor_a(self):
		"""
		Test Abstraction using ConcreteImplementorA.
		"""
		implementor = ConcreteImplementorA()
		abstraction = Abstraction(implementor)

		with self.assertLogs("bridge", level="INFO") as captured:
			abstraction.operation()

		self.assertEqual(len(captured.output), 2)
		self.assertIn("INFO:bridge:Abstraction: Delegating operation to implementor.", captured.output[0])
		self.assertIn("INFO:bridge:ConcreteImplementorA: Performing implementation.", captured.output[1])

	def test_abstraction_with_concrete_implementor_b(self):
		"""
		Test Abstraction using ConcreteImplementorB.
		"""
		implementor = ConcreteImplementorB()
		abstraction = Abstraction(implementor)

		with self.assertLogs("bridge", level="INFO") as captured:
			abstraction.operation()

		self.assertEqual(len(captured.output), 2)
		self.assertIn("INFO:bridge:Abstraction: Delegating operation to implementor.", captured.output[0])
		self.assertIn("INFO:bridge:ConcreteImplementorB: Performing implementation.", captured.output[1])

	def test_refined_abstraction_with_concrete_implementor_a(self):
		"""
		Test RefinedAbstraction using ConcreteImplementorA.
		"""
		implementor = ConcreteImplementorA()
		abstraction = RefinedAbstraction(implementor)

		with self.assertLogs("bridge", level="INFO") as captured:
			abstraction.operation()

		self.assertEqual(len(captured.output), 4)
		self.assertIn("INFO:bridge:RefinedAbstraction: Additional behavior before delegation.", captured.output[0])
		self.assertIn("INFO:bridge:Abstraction: Delegating operation to implementor.", captured.output[1])
		self.assertIn("INFO:bridge:ConcreteImplementorA: Performing implementation.", captured.output[2])
		self.assertIn("INFO:bridge:RefinedAbstraction: Additional behavior after delegation.", captured.output[3])

	def test_refined_abstraction_with_concrete_implementor_b(self):
		"""
		Test RefinedAbstraction using ConcreteImplementorB.
		"""
		implementor = ConcreteImplementorB()
		abstraction = RefinedAbstraction(implementor)

		with self.assertLogs("bridge", level="INFO") as captured:
			abstraction.operation()

		self.assertEqual(len(captured.output), 4)
		self.assertIn("INFO:bridge:RefinedAbstraction: Additional behavior before delegation.", captured.output[0])
		self.assertIn("INFO:bridge:Abstraction: Delegating operation to implementor.", captured.output[1])
		self.assertIn("INFO:bridge:ConcreteImplementorB: Performing implementation.", captured.output[2])
		self.assertIn("INFO:bridge:RefinedAbstraction: Additional behavior after delegation.", captured.output[3])

if __name__ == "__main__":
	unittest.main()
