#ifndef FACADE_HPP
#define FACADE_HPP

#include <string>

/**
 * @brief Namespace for the Facade pattern.
 */
namespace facade_pattern {

	/**
	* @brief Subsystem1 provides a specific functionality.
	*/
	class Subsystem1 {
	public:
		/**
		* @brief Performs operation 1.
		* @return A string describing the operation.
		*/
		std::string operation1() const {
			return "Subsystem1: Operation 1\n";
		}
	};

	/**
	* @brief Subsystem2 provides a specific functionality.
	*/
	class Subsystem2 {
	public:
		/**
		* @brief Performs operation 2.
		* @return A string describing the operation.
		*/
		std::string operation2() const {
			return "Subsystem2: Operation 2\n";
		}
	};

	/**
	* @brief Subsystem3 provides a specific functionality.
	*/
	class Subsystem3 {
	public:
		/**
		* @brief Performs operation 3.
		* @return A string describing the operation.
		*/
		std::string operation3() const {
			return "Subsystem3: Operation 3\n";
		}
	};

	/**
	* @brief The Facade provides a simplified interface to the subsystems.
	*
	* The Facade delegates requests from the client to the appropriate subsystems,
	* hiding their complexity.
	*/
	class Facade {
	private:
		Subsystem1 subsystem1; ///< Instance of Subsystem1
		Subsystem2 subsystem2; ///< Instance of Subsystem2
		Subsystem3 subsystem3; ///< Instance of Subsystem3

	public:
		/**
		* @brief Executes a high-level operation by coordinating subsystems.
		* @return A string describing the combined operations.
		*/
		std::string operation() const {
			std::string result = "Facade: Coordinating subsystems:\n";
			result += subsystem1.operation1();
			result += subsystem2.operation2();
			result += subsystem3.operation3();
			return result;
		}
	};

}  // namespace facade

#endif // FACADE_HPP
