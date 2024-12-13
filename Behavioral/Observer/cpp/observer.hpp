#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>

/**
 * @brief Abstract base class representing an observer in the Observer pattern.
 */
class Observer {
public:
	/// @brief Virtual destructor for cleanup of derived classes.
	virtual ~Observer() = default;

	/**
	 * @brief Called to notify the observer of changes in the subject.
	 */
	virtual void update() = 0;
};

/**
 * @brief Abstract base class representing a subject in the Observer pattern.
 */
class Subject {
public:
	/// @brief Virtual destructor for cleanup of derived classes.
	virtual ~Subject() = default;

	/**
	 * @brief Attach an observer to the subject.
	 * @param observer The observer to attach.
	 */
	virtual void attach(std::shared_ptr<Observer> observer) = 0;

	/**
	 * @brief Detach an observer from the subject.
	 * @param observer The observer to detach.
	 */
	virtual void detach(std::shared_ptr<Observer> observer) = 0;

	/**
	 * @brief Notify all attached observers of a change.
	 */
	virtual void notify() = 0;

	/**
	 * @brief Get the state of the subject.
	 * @return The current state of the subject as a string.
	 */
	virtual std::string getState() const = 0;

	/**
	 * @brief Set the state of the subject.
	 * @param state The new state of the subject.
	 */
	virtual void setState(const std::string &state) = 0;
};

/**
 * @brief Concrete implementation of a Subject.
 */
class ConcreteSubject : public Subject {
private:
	std::vector<std::shared_ptr<Observer>> observers; ///< List of attached observers.
	std::string state;                                ///< The current state of the subject.

public:
	/**
	 * @brief Attach an observer to the subject.
	 * @param observer The observer to attach.
	 */
	void attach(std::shared_ptr<Observer> observer) override {
		observers.push_back(observer);
	}

	/**
	 * @brief Detach an observer from the subject.
	 * @param observer The observer to detach.
	 */
	void detach(std::shared_ptr<Observer> observer) override {
		observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
	}

	/**
	 * @brief Notify all attached observers of a change.
	 */
	void notify() override {
		for (const auto &observer : observers) {
			observer->update();
		}
	}

	/**
	 * @brief Get the current state of the subject.
	 * @return The current state as a string.
	 */
	std::string getState() const override {
		return state;
	}

	/**
	 * @brief Set the state of the subject and notify observers.
	 * @param newState The new state of the subject.
	 */
	void setState(const std::string &newState) override {
		state = newState;
		notify();
	}
};

/**
 * @brief Concrete implementation of an Observer.
 */
class ConcreteObserver : public Observer {
private:
	std::string name;                      ///< The name of the observer.
	std::shared_ptr<Subject> subject;      ///< The subject this observer is observing.

public:
	/**
	 * @brief Constructor for ConcreteObserver.
	 * @param name The name of the observer.
	 * @param subject The subject to observe.
	 */
	ConcreteObserver(const std::string &name, std::shared_ptr<Subject> subject)
		: name(name), subject(std::move(subject)) {}

	/**
	 * @brief Get the name of the observer.
	 * @return The name of the observer.
	 */
	std::string getName() const {
		return name;
	}

	/**
	 * @brief Updates the observer when notified by the subject.
	 */
	void update() override {
		std::cout << "Observer " << name << " received update. New state: " << subject->getState() << std::endl;
	}
};

#endif // OBSERVER_HPP
