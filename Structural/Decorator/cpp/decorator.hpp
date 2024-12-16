#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include <string>
#include <memory>

/**
 * @brief Namespace for the Decorator pattern.
 */
namespace decorator_pattern {

	/**
	* @brief The Component interface defines operations that can be altered by decorators.
	*/
	class Component {
	public:
		virtual ~Component() = default;

		/**
		* @brief Returns the description of the component.
		* @return A string description.
		*/
		virtual std::string getDescription() const = 0;

		/**
		* @brief Returns the cost of the component.
		* @return A float representing the cost.
		*/
		virtual float cost() const = 0;
	};

	/**
	* @brief ConcreteComponent is a basic implementation of the Component interface.
	*/
	class ConcreteComponent : public Component {
	public:
		std::string getDescription() const override {
			return "Concrete Component";
		}

		float cost() const override {
			return 10.0f;
		}
	};

	/**
	* @brief The Decorator class serves as the abstract base class for all decorators.
	*
	* This class wraps a Component object and delegates the operations while allowing
	* concrete decorators to extend or modify its behavior.
	*/
	class Decorator : public Component {
	protected:
		std::shared_ptr<Component> component; ///< The wrapped Component.

	public:
		/**
		* @brief Constructs the Decorator with a Component to wrap.
		* @param component The Component to be decorated.
		*/
		explicit Decorator(std::shared_ptr<Component> component)
			: component(std::move(component)) {}

		/**
		* @brief Delegates the getDescription method to the wrapped Component.
		* Marked as pure virtual to enforce implementation in derived classes.
		* @return A string description.
		*/
		virtual std::string getDescription() const override = 0;

		/**
		* @brief Delegates the cost method to the wrapped Component.
		* Marked as pure virtual to enforce implementation in derived classes.
		* @return A float representing the cost.
		*/
		virtual float cost() const override = 0;
	};

	/**
	* @brief A ConcreteDecorator that adds Feature A to the Component.
	*/
	class ConcreteDecoratorA : public Decorator {
	public:
		explicit ConcreteDecoratorA(std::shared_ptr<Component> component)
			: Decorator(std::move(component)) {}

		std::string getDescription() const override {
			return component->getDescription() + " + Feature A";
		}

		float cost() const override {
			return component->cost() + 5.0f;
		}
	};

	/**
	* @brief A ConcreteDecorator that adds Feature B to the Component.
	*/
	class ConcreteDecoratorB : public Decorator {
	public:
		explicit ConcreteDecoratorB(std::shared_ptr<Component> component)
			: Decorator(std::move(component)) {}

		std::string getDescription() const override {
			return component->getDescription() + " + Feature B";
		}

		float cost() const override {
			return component->cost() + 7.5f;
		}
	};

}  // namespace decorator_pattern

#endif // DECORATOR_HPP
