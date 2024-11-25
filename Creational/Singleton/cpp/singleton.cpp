#include "singleton.h"
#include <iostream>

Singleton::Singleton() {
	// Constructor logic (if needed)
}

Singleton::~Singleton() {
	// Destructor logic (if needed)
}

Singleton& Singleton::getInstance() {
	static Singleton instance; // Guaranteed to be thread-safe in C++11 and later
	return instance;
}

void Singleton::doSomething() {
	std::cout << "Singleton instance is working!" << std::endl;
}
