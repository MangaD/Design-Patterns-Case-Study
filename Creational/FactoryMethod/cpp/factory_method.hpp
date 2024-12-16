#ifndef FACTORY_METHOD_HPP
#define FACTORY_METHOD_HPP

#include <memory>
#include <string>

/**
 * @brief Namespace for the Factory Method pattern.
 */
namespace factory_method_pattern {

	/**
	* @brief Interface for the Product.
	* 
	* Defines the interface for all products created by the factory.
	*/
	class Product {
	public:
		virtual ~Product() = default;

		/**
		* @brief A method that each concrete product will implement to define its behavior.
		* @return A string describing the product's behavior.
		*/
		virtual std::string use() const = 0;
	};

	/**
	* @brief Concrete implementation of the Product interface.
	* 
	* Represents a specific type of product (ConcreteProductA).
	*/
	class ConcreteProductA : public Product {
	public:
		/**
		* @brief Implements the behavior of ConcreteProductA.
		* @return A string describing the use of ConcreteProductA.
		*/
		std::string use() const override;
	};

	/**
	* @brief Concrete implementation of the Product interface.
	* 
	* Represents a specific type of product (ConcreteProductB).
	*/
	class ConcreteProductB : public Product {
	public:
		/**
		* @brief Implements the behavior of ConcreteProductB.
		* @return A string describing the use of ConcreteProductB.
		*/
		std::string use() const override;
	};

	/**
	* @brief Abstract Creator (Factory) class.
	* 
	* Declares a factory method to create products. Subclasses will override
	* the `createProduct` method to specify the type of product to create.
	*/
	class Creator {
	public:
		virtual ~Creator() = default;

		/**
		* @brief Factory method to create a Product.
		* @return A unique pointer to a newly created Product.
		*/
		virtual std::unique_ptr<Product> createProduct() const = 0;
	};

	/**
	* @brief Concrete implementation of the Creator.
	* 
	* Overrides the factory method to create ConcreteProductA.
	*/
	class ConcreteCreatorA : public Creator {
	public:
		/**
		* @brief Factory method to create ConcreteProductA.
		* @return A unique pointer to a ConcreteProductA instance.
		*/
		std::unique_ptr<Product> createProduct() const override;
	};

	/**
	* @brief Concrete implementation of the Creator.
	* 
	* Overrides the factory method to create ConcreteProductB.
	*/
	class ConcreteCreatorB : public Creator {
	public:
		/**
		* @brief Factory method to create ConcreteProductB.
		* @return A unique pointer to a ConcreteProductB instance.
		*/
		std::unique_ptr<Product> createProduct() const override;
	};

}  // namespace factory_method

#endif // FACTORY_METHOD_HPP
