#include "singleton.hpp"
#include <iostream>

/**
* @brief Constructs the Singleton instance.
* 
* This constructor is private to enforce the Singleton pattern, ensuring that
* no external code can directly instantiate the class. Any necessary initialization
* logic for the Singleton instance can be added here.
*/
Singleton::Singleton() {
	// Constructor logic (if needed)
}

/**
* @brief Destroys the Singleton instance.
* 
* This destructor is private to enforce the Singleton pattern, ensuring
* that no external code can directly destroy the instance. Any cleanup logic
* for the Singleton instance can be added here.
*/
Singleton::~Singleton() {
	// Destructor logic (if needed)
}

/**
* @brief Retrieves the Singleton instance.
* 
* This static method ensures that only one instance of the Singleton class
* exists throughout the program's lifecycle. The instance is lazily initialized
* on its first use, and its lifetime is automatically managed by the program.
* 
* The `static` local variable ensures thread safety in C++11 and later standards.
* 
* @return A reference to the Singleton instance.
*/
Singleton& Singleton::getInstance() {
	static Singleton instance; // Thread-safe and created only once
	return instance;
}

/**
* @brief Example method that demonstrates the Singleton's behavior.
* 
* This method serves as an example of how to interact with the Singleton instance.
* It performs a specific action, such as printing a message.
*/
void Singleton::doSomething() {
	std::cout << "Singleton instance is working!" << std::endl;
}
