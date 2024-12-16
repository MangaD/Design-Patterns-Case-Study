#ifndef BRIDGE_HPP
#define BRIDGE_HPP

#include <string>

/**
 * @brief Namespace for the Bridge pattern.
 */
namespace bridge_pattern {

	/**
	* @brief The Implementor interface defines the interface for low-level operations.
	*/
	class Implementor {
	public:
		virtual ~Implementor() = default;

		/**
		* @brief Performs a low-level operation.
		* @return A string representing the operation details.
		*/
		virtual std::string operationImpl() const = 0;
	};

	/**
	* @brief A concrete implementation of the Implementor interface.
	*/
	class ConcreteImplementorA : public Implementor {
	public:
		/**
		* @brief Implementation-specific operation for ConcreteImplementorA.
		* @return A string representing the operation of ConcreteImplementorA.
		*/
		std::string operationImpl() const override;
	};

	/**
	* @brief Another concrete implementation of the Implementor interface.
	*/
	class ConcreteImplementorB : public Implementor {
	public:
		/**
		* @brief Implementation-specific operation for ConcreteImplementorB.
		* @return A string representing the operation of ConcreteImplementorB.
		*/
		std::string operationImpl() const override;
	};

	/**
	* @brief The Abstraction defines the high-level control logic and delegates
	*        low-level operations to the Implementor.
	*/
	class Abstraction {
	protected:
		Implementor* implementor; ///< Pointer to the associated Implementor.

	public:
		/**
		* @brief Constructor to initialize the abstraction with an Implementor.
		* @param implementor Pointer to the Implementor instance.
		*/
		explicit Abstraction(Implementor* implementor);

		/**
		* @brief Virtual destructor to clean up resources.
		*/
		virtual ~Abstraction() = default;

		/**
		* @brief High-level operation implemented using the Implementor.
		* @return A string representing the result of the operation.
		*/
		virtual std::string operation() const;
	};

	/**
	* @brief The RefinedAbstraction adds additional functionality to the Abstraction.
	*/
	class RefinedAbstraction : public Abstraction {
	public:
		/**
		* @brief Constructor to initialize the refined abstraction with an Implementor.
		* @param implementor Pointer to the Implementor instance.
		*/
		explicit RefinedAbstraction(Implementor* implementor);

		/**
		* @brief Enhanced high-level operation implemented using the Implementor.
		* @return A string representing the result of the refined operation.
		*/
		std::string operation() const override;
	};

}  // namespace bridge_pattern

#endif // BRIDGE_HPP
