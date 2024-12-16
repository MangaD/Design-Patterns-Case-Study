#ifndef CLASS_ADAPTER_HPP
#define CLASS_ADAPTER_HPP

#include <string>

/**
 * @brief Namespace for the Class Adapter pattern.
 */
namespace class_adapter_pattern {

	/**
	 * @brief Interface representing the Target.
	 * 
	 * The Target defines the domain-specific interface expected by the client.
	 * Classes implementing this interface can be used seamlessly by the client.
	 */
	class Target {
	public:
		virtual ~Target() = default;

		/**
		 * @brief Handles a generic request from the client.
		 * 
		 * This method provides the interface that the client interacts with.
		 * @return A string response from the Target.
		 */
		virtual std::string request() const = 0;
	};

	/**
	 * @brief The Adaptee class provides specific functionality.
	 * 
	 * The Adaptee has methods that perform useful operations but with an
	 * interface that is incompatible with the Target interface.
	 */
	class Adaptee {
	public:
		/**
		 * @brief Performs a specific operation provided by the Adaptee.
		 * 
		 * This method showcases the Adaptee's unique functionality.
		 * @return A string response indicating the Adaptee's behavior.
		 */
		std::string specificRequest() const {
			return "Adaptee: Specific request called.";
		}
	};

	/**
	 * @brief The Adapter class bridges the Target and Adaptee interfaces.
	 * 
	 * The Adapter allows the Adaptee's functionality to be used where the Target's
	 * interface is required by translating requests from the Target format to the
	 * Adaptee's specific format.
	 */
	class Adapter : public Target, private Adaptee {
	public:
		/**
		 * @brief Translates the Target's request into the Adaptee's specificRequest.
		 * 
		 * This method allows the client to interact with the Adaptee's functionality
		 * using the Target interface.
		 * 
		 * @return A string response combining the Adapter's translation and the Adaptee's functionality.
		 */
		std::string request() const override {
			return "Adapter: Translating request to Adaptee's specificRequest().\n" + specificRequest();
		}
	};

}  // namespace class_adapter

#endif // CLASS_ADAPTER_HPP
