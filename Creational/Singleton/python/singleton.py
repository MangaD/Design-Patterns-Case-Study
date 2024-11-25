"""
singleton.py
Implementation of the Singleton design pattern in Python.

This module defines a Singleton class to ensure that only one instance
of the class is created during the program's lifetime.
"""

class SingletonMeta(type):
	"""
	A metaclass for creating Singleton classes.

	Ensures that only one instance of the class exists.
	"""
	_instances = {}

	"""
	This code snippet defines the `__call__` method for a metaclass
	called `SingletonMeta`. This method is called when an instance
	of a class that uses this metaclass is created. 

	The code first checks if the class `cls` is not already in the
	`_instances` dictionary of the metaclass. If it's not, it creates
	a new instance of the class using the `super().__call__(*args, **kwargs)`
	method, which calls the `__call__` method of the parent class. The new
	instance is then stored in the `_instances` dictionary with the class
	`cls` as the key. 

	Finally, the method returns the instance stored in the `_instances`
	dictionary for the class `cls`. This ensures that only one instance
	of the class is created and allows for easy retrieval of that instance
	in the future.
	"""
	def __call__(cls, *args, **kwargs):
		if cls not in cls._instances:
			instance = super().__call__(*args, **kwargs)
			cls._instances[cls] = instance
		return cls._instances[cls]


class Singleton(metaclass=SingletonMeta):
	"""
	A Singleton class that uses the SingletonMeta metaclass.
	"""
	def do_something(self):
		return "Singleton instance is working!"


# Example usage
if __name__ == "__main__":
	s1 = Singleton()
	s2 = Singleton()

	print(s1 is s2)  # True
	print(s1.do_something())  # "Singleton instance is working!"
