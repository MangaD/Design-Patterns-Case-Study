from abc import ABC, abstractmethod

class Product:
	"""
	Represents the complex product being built.

	The Product class contains attributes `part_a` and `part_b`, which represent
	the individual parts of the product. It provides methods to set these parts
	and a string representation to display the constructed product.
	"""

	def __init__(self):
		"""
		Initializes the Product instance.

		Sets the attributes `part_a` and `part_b` to None, which represent the
		individual parts of the product.
		"""
		self.part_a = None  # Represents Part A of the product
		self.part_b = None  # Represents Part B of the product

	def set_part_a(self, part_a):
		"""
		Sets Part A of the product.

		:param part_a: A string representing Part A of the product.
		"""
		self.part_a = part_a

	def set_part_b(self, part_b):
		"""
		Sets Part B of the product.

		:param part_b: A string representing Part B of the product.
		"""
		self.part_b = part_b

	def __str__(self):
		"""
		Returns a string representation of the product.

		:return: A string describing the product's parts.
		"""
		return f"Product [PartA: {self.part_a}, PartB: {self.part_b}]"


class Builder(ABC):
	"""
	Abstract interface for constructing a Product.

	Defines methods for building different parts of a product and retrieving
	the final constructed result.
	"""

	@abstractmethod
	def build_part_a(self):
		"""Builds Part A of the product."""
		pass

	@abstractmethod
	def build_part_b(self):
		"""Builds Part B of the product."""
		pass

	@abstractmethod
	def get_result(self) -> Product:
		"""
		Retrieves the constructed product.

		:return: The constructed Product instance.
		"""
		pass


class ConcreteBuilder(Builder):
	"""
	Concrete implementation of the Builder interface.

	Constructs a specific type of product by implementing the building steps
	defined in the Builder interface.
	"""

	def __init__(self):
		"""
		Initializes a new instance of the ConcreteBuilder class.

		Initializes the builder with a new instance of the Product class.
		"""
		self.product = Product()

	def build_part_a(self):
		"""
		Builds Part A of the product.

		Sets Part A to a specific value defined by this builder.
		"""
		self.product.set_part_a("Part A built by ConcreteBuilder")

	def build_part_b(self):
		"""
		Builds Part B of the product.

		Sets Part B to a specific value defined by this builder.
		"""
		self.product.set_part_b("Part B built by ConcreteBuilder")

	def get_result(self) -> Product:
		"""
		Retrieves the constructed product.

		:return: The fully constructed Product instance.
		"""
		return self.product


class Director:
	"""
	Orchestrates the construction process.

	The Director class uses a Builder to construct a Product in a predefined sequence.
	"""

	def __init__(self, builder: Builder):
		"""
		Initializes the Director with a builder.

		:param builder: The Builder instance to use for constructing the product.
		"""
		self.builder = builder

	def construct(self):
		"""
		Constructs the product by invoking the builder's methods in sequence.
		"""
		self.builder.build_part_a()
		self.builder.build_part_b()

	def get_product(self):
		"""
		Retrieves the constructed product from the builder.

		:return: The constructed Product instance.
		"""
		return self.builder.get_result()
