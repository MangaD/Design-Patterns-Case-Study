#include "state.hpp"

#include <iostream>

using namespace state_pattern;

// Context Implementation
Context::Context(std::unique_ptr<State> initialState) : state(std::move(initialState)) {}

void Context::setState(std::unique_ptr<State> newState) {
	state = std::move(newState);
}

void Context::request() {
	state->handle(*this);
}

std::string Context::getStateName() const {
	// Downcast the state to determine its concrete name.
	if (dynamic_cast<const ConcreteStateA*>(state.get())) {
		return ConcreteStateA::getName();
	} else if (dynamic_cast<const ConcreteStateB*>(state.get())) {
		return ConcreteStateB::getName();
	}
	return "Unknown State";
}

// ConcreteStateA Implementation
void ConcreteStateA::handle(Context &context) const {
	std::cout << "ConcreteStateA: Handling request. Switching to State B.\n";
	context.setState(std::make_unique<ConcreteStateB>());
}

std::string ConcreteStateA::getName() {
	return "ConcreteStateA";
}

// ConcreteStateB Implementation
void ConcreteStateB::handle(Context &context) const {
	std::cout << "ConcreteStateB: Handling request. Switching to State A.\n";
	context.setState(std::make_unique<ConcreteStateA>());
}

std::string ConcreteStateB::getName() {
	return "ConcreteStateB";
}
