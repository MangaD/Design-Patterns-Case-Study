#ifndef OBJECT_ADAPTER_HPP
#define OBJECT_ADAPTER_HPP

#include <iostream> // For std::cout

/**
 * @brief Namespace encapsulating the Object Adapter implementation.
 *
 * This namespace contains classes and interfaces demonstrating the Object Adapter pattern.
 * The Object Adapter pattern works by using composition to adapt an existing interface
 * (Adaptee) to a desired interface (Target) that is expected by the client.
 */
namespace object_adapter {

	/**
	 * @brief The Target interface defines the expected interface for the client.
	 *
	 * The Target interface acts as a standard contract for clients that interact with
	 * the system. By abstracting specific implementation details, this interface
	 * promotes flexibility and decoupling between the client and concrete implementations.
	 */
	class Target {
	public:
		/// @brief Virtual destructor ensures proper cleanup of derived objects.
		virtual ~Target() = default;

		/**
		 * @brief Standard method expected by the client.
		 *
		 * Derived classes implement this method to provide behavior tailored to
		 * the client's expectations.
		 */
		virtual void request() const = 0;
	};

	/**
	 * @brief The Adaptee class provides existing functionality needing adaptation.
	 *
	 * The Adaptee defines methods that are incompatible with the Target interface but
	 * offer useful functionality. The Adapter class bridges the gap between the Adaptee
	 * and the Target interface, enabling seamless integration.
	 */
	class Adaptee {
	public:
		/**
		 * @brief A specific method offered by the Adaptee.
		 *
		 * This method demonstrates functionality that needs adaptation to match
		 * the Target interface.
		 */
		void specificRequest() const {
			std::cout << "Adaptee: Specific request called." << std::endl;
		}
	};

	/**
	 * @brief The Adapter class adapts the Adaptee to the Target interface.
	 *
	 * The Adapter uses composition to hold an instance of Adaptee and translates
	 * calls from the Target interface into calls to the Adaptee's methods. This
	 * enables the client to interact with Adaptee functionality seamlessly.
	 */
	class Adapter : public Target {
	private:
		Adaptee* adaptee; ///< Pointer to the Adaptee instance used for delegation.

	public:
		/**
		 * @brief Constructs an Adapter with a given Adaptee instance.
		 * @param adaptee Pointer to the Adaptee instance to be adapted.
		 *
		 * The Adapter holds a reference to the Adaptee, enabling it to
		 * translate client calls into the Adaptee's specific methods.
		 */
		explicit Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

		/**
		 * @brief Implements the Target interface by delegating to the Adaptee.
		 *
		 * This method adapts the Target's `request()` call into a call
		 * to the Adaptee's `specificRequest()` method.
		 */
		void request() const override {
			std::cout << "Adapter: Translating request to Adaptee's specificRequest()." << std::endl;
			adaptee->specificRequest();
		}
	};

} // namespace object_adapter

#endif // OBJECT_ADAPTER_HPP
