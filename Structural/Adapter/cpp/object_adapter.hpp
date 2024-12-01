#ifndef OBJECT_ADAPTER_HPP
#define OBJECT_ADAPTER_HPP

#include <iostream> // For std::cout

/**
 * @brief The Target interface defines the domain-specific interface expected by the client.
 *
 * The Target interface acts as the standard contract for clients that need to interact
 * with certain functionality. It abstracts away specific implementation details,
 * allowing clients to remain decoupled from concrete implementations.
 */
class Target {
public:
	/// @brief Virtual destructor ensures proper cleanup of derived objects.
	virtual ~Target() = default;

	/**
	 * @brief The standard request method expected by the client.
	 *
	 * Derived classes implement this method to provide domain-specific behavior.
	 */
	virtual void request() const = 0;
};

/**
 * @brief The Adaptee class provides the existing functionality that needs adaptation.
 *
 * Adaptee defines methods that do not match the Target interface but offer useful
 * functionality. The Adapter class bridges the gap between Adaptee and Target.
 */
class Adaptee {
public:
	/**
	 * @brief A specific method offered by Adaptee.
	 *
	 * This method needs to be adapted for use by clients expecting the Target interface.
	 */
	void specificRequest() const {
		std::cout << "Adaptee: Specific request called." << std::endl;
	}
};

/**
 * @brief The Adapter class makes Adaptee compatible with the Target interface.
 *
 * The Adapter implements the Target interface and translates calls from the client
 * to the Adaptee's methods. This enables the client to work seamlessly with Adaptee
 * without being aware of its specific implementation.
 */
class Adapter : public Target {
private:
	Adaptee* adaptee; ///< Pointer to the Adaptee instance used for delegation.

public:
	/**
	 * @brief Constructs the Adapter with an Adaptee instance.
	 * @param adaptee Pointer to the Adaptee instance to be adapted.
	 *
	 * The Adapter takes ownership of the Adaptee pointer and uses it to
	 * delegate requests from the client.
	 */
	explicit Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

	/**
	 * @brief Implements the Target interface by delegating to the Adaptee.
	 *
	 * This method translates the Target's `request()` call into a call
	 * to the Adaptee's `specificRequest()` method.
	 */
	void request() const override {
		std::cout << "Adapter: Translating request to Adaptee's specificRequest()." << std::endl;
		adaptee->specificRequest();
	}
};

#endif // OBJECT_ADAPTER_HPP
