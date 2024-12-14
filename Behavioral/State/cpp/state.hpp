#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include <string>

// Forward declarations
class Context;

// Base State Class
class State {
public:
	virtual ~State() = default;

	/**
	 * @brief Handle the request and optionally change the state.
	 * @param context Reference to the context object.
	 */
	virtual void handle(Context &context) const = 0;
};

// Context Class
class Context {
private:
	std::unique_ptr<State> state; ///< Current state of the context.
public:
	/**
	 * @brief Constructor that initializes the context with an initial state.
	 * @param initialState Initial state of the context.
	 */
	explicit Context(std::unique_ptr<State> initialState);

	/**
	 * @brief Sets the state of the context.
	 * @param newState New state to transition to.
	 */
	void setState(std::unique_ptr<State> newState);

	/**
	 * @brief Triggers the handle method of the current state.
	 */
	void request();

	/**
	 * @brief Gets the name of the current state (for testing/logging purposes).
	 * @return Name of the current state.
	 */
	std::string getStateName() const;
};

// Concrete State A
class ConcreteStateA : public State {
public:
	void handle(Context &context) const override;

	/**
	 * @brief Get the name of this state.
	 * @return State name as a string.
	 */
	static std::string getName();
};

// Concrete State B
class ConcreteStateB : public State {
public:
	void handle(Context &context) const override;

	/**
	 * @brief Get the name of this state.
	 * @return State name as a string.
	 */
	static std::string getName();
};

#endif // STATE_HPP
