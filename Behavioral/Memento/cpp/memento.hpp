#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <stdexcept>
#include <string>
#include <vector>
#include <memory>

/**
 * @brief The Memento class stores the state of the Originator.
 */
class Memento {
private:
	std::string state; ///< Saved state of the Originator

public:
	/**
	 * @brief Constructor to initialize the Memento with a state.
	 * @param state The state to save.
	 */
	explicit Memento(const std::string& state) : state(state) {}

	/**
	 * @brief Retrieves the saved state.
	 * @return The saved state as a string.
	 */
	std::string getState() const {
		return state;
	}
};

/**
 * @brief The Originator class creates and restores Memento objects.
 */
class Originator {
private:
	std::string state; ///< Current state of the Originator

public:
	/**
	 * @brief Sets the state of the Originator.
	 * @param newState The new state.
	 */
	void setState(const std::string& newState) {
		state = newState;
	}

	/**
	 * @brief Retrieves the current state of the Originator.
	 * @return The current state as a string.
	 */
	std::string getState() const {
		return state;
	}

	/**
	 * @brief Creates a Memento containing the current state.
	 * @return A unique pointer to a Memento.
	 */
	std::unique_ptr<Memento> createMemento() const {
		return std::make_unique<Memento>(state);
	}

	/**
	 * @brief Restores the state from a given Memento.
	 * @param memento The Memento to restore from.
	 */
	void restoreMemento(const Memento& memento) {
		state = memento.getState();
	}
};

/**
 * @brief The Caretaker class manages Memento objects.
 */
class Caretaker {
private:
	std::vector<std::unique_ptr<Memento>> mementos; ///< List of saved Mementos

public:
	/**
	 * @brief Adds a Memento to the list.
	 * @param memento The Memento to add.
	 */
	void addMemento(std::unique_ptr<Memento> memento) {
		mementos.push_back(std::move(memento));
	}

	/**
	 * @brief Retrieves a Memento by index.
	 * @param index The index of the desired Memento.
	 * @return A reference to the Memento at the specified index.
	 * @throws std::out_of_range if the index is invalid.
	 */
	const Memento& getMemento(size_t index) const {
		if (index >= mementos.size()) {
			throw std::out_of_range("Index out of range");
		}
		return *mementos[index];
	}
};

#endif // MEMENTO_HPP
