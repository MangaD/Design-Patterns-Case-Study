#ifndef TEMPLATE_METHOD_HPP
#define TEMPLATE_METHOD_HPP

#include <iostream>

/**
 * @brief Namespace for the Template Method pattern.
 */
namespace template_method_pattern {

/**
 * @brief Abstract base class defining the template method and its steps.
 */
class AbstractClass {
public:
	/// @brief Virtual destructor for proper cleanup of derived classes.
	virtual ~AbstractClass() = default;

	/**
	 * @brief The template method defining the skeleton of the algorithm.
	 *
	 * This method calls the steps, some of which are implemented by derived classes.
	 */
	void templateMethod() const {
		baseOperation1();
		requiredOperation1();
		baseOperation2();
		requiredOperation2();
		hook(); // Optional step
	}

protected:
	/// @brief A base operation implemented in the base class.
	void baseOperation1() const {
		std::cout << "AbstractClass: Base operation 1\n";
	}

	/// @brief Another base operation implemented in the base class.
	void baseOperation2() const {
		std::cout << "AbstractClass: Base operation 2\n";
	}

	/// @brief A hook method that can be optionally overridden by subclasses.
	virtual void hook() const {
		std::cout << "AbstractClass: Default hook implementation\n";
	}

	/// @brief A pure virtual method to be implemented by subclasses.
	virtual void requiredOperation1() const = 0;

	/// @brief Another pure virtual method to be implemented by subclasses.
	virtual void requiredOperation2() const = 0;
};

/**
 * @brief Concrete implementation of the abstract class.
 */
class ConcreteClass1 : public AbstractClass {
protected:
	void requiredOperation1() const override {
		std::cout << "ConcreteClass1: Required operation 1\n";
	}

	void requiredOperation2() const override {
		std::cout << "ConcreteClass1: Required operation 2\n";
	}

	void hook() const override {
		std::cout << "ConcreteClass1: Overridden hook implementation\n";
	}
};

/**
 * @brief Another concrete implementation of the abstract class.
 */
class ConcreteClass2 : public AbstractClass {
protected:
	void requiredOperation1() const override {
		std::cout << "ConcreteClass2: Required operation 1\n";
	}

	void requiredOperation2() const override {
		std::cout << "ConcreteClass2: Required operation 2\n";
	}
};

}  // namespace template_method_pattern

#endif // TEMPLATE_METHOD_HPP
