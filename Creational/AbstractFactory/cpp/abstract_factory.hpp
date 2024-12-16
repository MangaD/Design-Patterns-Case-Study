#ifndef ABSTRACT_FACTORY_HPP
#define ABSTRACT_FACTORY_HPP

#include <string>
#include <memory>

/**
 * @brief Namespace for the Abstract Factory pattern.
 */
namespace abstract_factory_pattern {

	/**
	* @brief Abstract interface for Product A.
	* Provides a common interface for all implementations of Product A.
	*/
	class AbstractProductA {
	public:
		virtual ~AbstractProductA() = default;

		/**
		* @brief Performs an operation specific to Product A.
		* @return A string representing the operation performed by Product A.
		*/
		virtual std::string operationA() const = 0;
	};

	/**
	* @brief Abstract interface for Product B.
	* Provides a common interface for all implementations of Product B.
	*/
	class AbstractProductB {
	public:
		virtual ~AbstractProductB() = default;

		/**
		* @brief Performs an operation specific to Product B.
		* @return A string representing the operation performed by Product B.
		*/
		virtual std::string operationB() const = 0;
	};

	/**
	* @brief Concrete implementation of Product A for Family 1.
	*/
	class ConcreteProductA1 : public AbstractProductA {
	public:
		/**
		* @brief Implementation of Product A's operation for Family 1.
		* @return A string identifying the operation performed by ConcreteProductA1.
		*/
		std::string operationA() const override {
			return "ConcreteProductA1";
		}
	};

	/**
	* @brief Concrete implementation of Product A for Family 2.
	*/
	class ConcreteProductA2 : public AbstractProductA {
	public:
		/**
		* @brief Implementation of Product A's operation for Family 2.
		* @return A string identifying the operation performed by ConcreteProductA2.
		*/
		std::string operationA() const override {
			return "ConcreteProductA2";
		}
	};

	/**
	* @brief Concrete implementation of Product B for Family 1.
	*/
	class ConcreteProductB1 : public AbstractProductB {
	public:
		/**
		* @brief Implementation of Product B's operation for Family 1.
		* @return A string identifying the operation performed by ConcreteProductB1.
		*/
		std::string operationB() const override {
			return "ConcreteProductB1";
		}
	};

	/**
	* @brief Concrete implementation of Product B for Family 2.
	*/
	class ConcreteProductB2 : public AbstractProductB {
	public:
		/**
		* @brief Implementation of Product B's operation for Family 2.
		* @return A string identifying the operation performed by ConcreteProductB2.
		*/
		std::string operationB() const override {
			return "ConcreteProductB2";
		}
	};

	/**
	* @brief Abstract Factory interface for creating families of related products.
	* Declares methods for creating each type of product (Product A and Product B).
	*/
	class AbstractFactory {
	public:
		virtual ~AbstractFactory() = default;

		/**
		* @brief Creates a product of type A.
		* @return A unique pointer to a Product A instance.
		*/
		virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;

		/**
		* @brief Creates a product of type B.
		* @return A unique pointer to a Product B instance.
		*/
		virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
	};

	/**
	* @brief Concrete Factory 1.
	* Creates products belonging to Family 1.
	*/
	class ConcreteFactory1 : public AbstractFactory {
	public:
		/**
		* @brief Creates a ConcreteProductA1 instance.
		* @return A unique pointer to a ConcreteProductA1 instance.
		*/
		std::unique_ptr<AbstractProductA> createProductA() const override {
			return std::make_unique<ConcreteProductA1>();
		}

		/**
		* @brief Creates a ConcreteProductB1 instance.
		* @return A unique pointer to a ConcreteProductB1 instance.
		*/
		std::unique_ptr<AbstractProductB> createProductB() const override {
			return std::make_unique<ConcreteProductB1>();
		}
	};

	/**
	* @brief Concrete Factory 2.
	* Creates products belonging to Family 2.
	*/
	class ConcreteFactory2 : public AbstractFactory {
	public:
		/**
		* @brief Creates a ConcreteProductA2 instance.
		* @return A unique pointer to a ConcreteProductA2 instance.
		*/
		std::unique_ptr<AbstractProductA> createProductA() const override {
			return std::make_unique<ConcreteProductA2>();
		}

		/**
		* @brief Creates a ConcreteProductB2 instance.
		* @return A unique pointer to a ConcreteProductB2 instance.
		*/
		std::unique_ptr<AbstractProductB> createProductB() const override {
			return std::make_unique<ConcreteProductB2>();
		}
	};

}  // namespace abstract_factory

#endif // ABSTRACT_FACTORY_HPP
