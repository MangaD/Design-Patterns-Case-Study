#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <string>
#include <memory>
#include <ostream>

/**
 * @brief Namespace for the Builder pattern.
 */
namespace builder_pattern {

	/**
	* @class Product
	* @brief Represents the complex product being built.
	*
	* The `Product` class contains components `partA` and `partB` which represent
	* the individual parts of the product. It provides methods to set its parts and
	* to display the details of the constructed product.
	*/
	class Product {
	private:
		std::string partA; ///< Represents Part A of the product
		std::string partB; ///< Represents Part B of the product

	public:
		/**
		* @brief Sets Part A of the product.
		* @param part A string representing Part A.
		*/
		void setPartA(const std::string& part);

		/**
		* @brief Sets Part B of the product.
		* @param part A string representing Part B.
		*/
		void setPartB(const std::string& part);

		/**
		* @brief Provides a string representation of the product.
		* 
		* Combines details of Part A and Part B into a formatted string
		* representation of the product.
		* 
		* @return A string describing the product's parts.
		*/
		std::string toString() const;

		/**
		* @brief Overloads the output stream operator for the `Product` class.
		* 
		* Allows the details of the `Product` to be printed to an output stream.
		* 
		* @param os The output stream.
		* @param product The product to be printed.
		* @return The output stream with product details appended.
		*/
		friend std::ostream& operator<<(std::ostream& os, const Product& product);
	};

	/**
	* @class Builder
	* @brief Abstract interface for constructing a Product.
	*
	* The `Builder` interface defines the steps required to build different parts
	* of a product and retrieve the final result. Concrete implementations of this
	* interface construct specific types of products.
	*/
	class Builder {
	public:
		/// @brief Virtual destructor to allow proper cleanup in derived classes.
		virtual ~Builder() = default;

		/**
		* @brief Builds Part A of the product.
		* 
		* Defines the step required to construct Part A of the product.
		*/
		virtual void buildPartA() = 0;

		/**
		* @brief Builds Part B of the product.
		* 
		* Defines the step required to construct Part B of the product.
		*/
		virtual void buildPartB() = 0;

		/**
		* @brief Retrieves the constructed product.
		* 
		* After all parts of the product are built, this method returns the
		* fully constructed product.
		* 
		* @return A shared pointer to the constructed Product.
		*/
		virtual std::shared_ptr<Product> getResult() = 0;
	};

	/**
	* @class ConcreteBuilder
	* @brief Concrete implementation of the Builder interface.
	*
	* The `ConcreteBuilder` class constructs a specific type of product by
	* implementing the steps defined in the `Builder` interface.
	*/
	class ConcreteBuilder : public Builder {
	private:
		std::shared_ptr<Product> product; ///< The product being constructed

	public:
		/**
		* @brief Constructor initializes a new `Product` instance.
		*
		* Creates a new `Product` instance and initializes the builder.
		*/
		ConcreteBuilder();

		/// @copydoc Builder::buildPartA()
		void buildPartA() override;

		/// @copydoc Builder::buildPartB()
		void buildPartB() override;

		/// @copydoc Builder::getResult()
		std::shared_ptr<Product> getResult() override;
	};

	/**
	* @class Director
	* @brief Orchestrates the construction process.
	*
	* The `Director` class uses a `Builder` to construct a product in a predefined
	* sequence. It ensures that the construction process is consistent and
	* follows a specific order.
	*/
	class Director {
	private:
		Builder* builder; ///< The builder used to construct the product

	public:
		/**
		* @brief Constructor accepts a builder.
		* 
		* Initializes the `Director` with a specific builder to use for the
		* construction process.
		* 
		* @param builder A pointer to the `Builder` instance.
		*/
		explicit Director(Builder* builder);

		/**
		* @brief Constructs the product by invoking the builder's methods in order.
		* 
		* Executes the sequence of steps to construct the product using the builder.
		*/
		void construct();

		/**
		* @brief Retrieves the constructed product.
		* 
		* After the construction process is complete, this method retrieves
		* the fully constructed product from the builder.
		* 
		* @return A shared pointer to the constructed Product.
		*/
		std::shared_ptr<Product> getProduct();
	};

}  // namespace builder

#endif // BUILDER_HPP
