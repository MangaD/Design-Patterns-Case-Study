from abc import ABC, abstractmethod

class Product(ABC):
	"""
	Abstract base class for products.
	
	This class defines the interface for all concrete products created
	by the factory method. All subclasses must implement the `use` method.
	"""
	
	@abstractmethod
	def use(self) -> str:
		"""
		Define the behavior of the product.
		
		Returns:
			str: A string describing the product's behavior.
		"""
		pass


class ConcreteProductA(Product):
	"""
	Concrete implementation of the Product interface.
	
	Represents a specific type of product with its own behavior.
	"""
	
	def use(self) -> str:
		"""
		Implements the behavior for ConcreteProductA.
		
		Returns:
			str: A string indicating the use of ConcreteProductA.
		"""
		return "Using ConcreteProductA"


class ConcreteProductB(Product):
	"""
	Concrete implementation of the Product interface.
	
	Represents another type of product with its own behavior.
	"""
	
	def use(self) -> str:
		"""
		Implements the behavior for ConcreteProductB.
		
		Returns:
			str: A string indicating the use of ConcreteProductB.
		"""
		return "Using ConcreteProductB"


class Creator(ABC):
	"""
	Abstract base class for creators (factories).
	
	Declares the factory method that subclasses must implement to create
	specific product instances. Provides a common operation that uses
	the product created by the factory method.
	"""
	
	@abstractmethod
	def create_product(self) -> Product:
		"""
		Factory method to create a product.
		
		Returns:
			Product: An instance of a product.
		"""
		pass

	def some_operation(self) -> None:
		"""
		Common operation that uses the product.
		"""
		product = self.create_product()
		print(product.use())


class ConcreteCreatorA(Creator):
	"""
	Concrete implementation of the Creator class.
	
	Responsible for creating instances of ConcreteProductA.
	"""
	
	def create_product(self) -> Product:
		"""
		Factory method implementation for creating ConcreteProductA.
		
		Returns:
			Product: An instance of ConcreteProductA.
		"""
		return ConcreteProductA()


class ConcreteCreatorB(Creator):
	"""
	Concrete implementation of the Creator class.
	
	Responsible for creating instances of ConcreteProductB.
	"""
	
	def create_product(self) -> Product:
		"""
		Factory method implementation for creating ConcreteProductB.
		
		Returns:
			Product: An instance of ConcreteProductB.
		"""
		return ConcreteProductB()
