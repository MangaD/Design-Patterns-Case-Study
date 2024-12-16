#include "bridge.hpp"

using namespace bridge_pattern;

// ConcreteImplementorA implementation
std::string ConcreteImplementorA::operationImpl() const {
	return "ConcreteImplementorA: Operation Implementation.";
}

// ConcreteImplementorB implementation
std::string ConcreteImplementorB::operationImpl() const {
	return "ConcreteImplementorB: Operation Implementation.";
}

// Abstraction implementation
Abstraction::Abstraction(Implementor* implementor) : implementor(implementor) {}

std::string Abstraction::operation() const {
	return "Abstraction: Base operation with:\n" + implementor->operationImpl();
}

// RefinedAbstraction implementation
RefinedAbstraction::RefinedAbstraction(Implementor* implementor) : Abstraction(implementor) {}

std::string RefinedAbstraction::operation() const {
	return "RefinedAbstraction: Enhanced operation with:\n" + implementor->operationImpl();
}
