#ifndef CHAIN_OF_RESPONSIBILITY_HPP
#define CHAIN_OF_RESPONSIBILITY_HPP

#include <string>
#include <memory>
#include <iostream>

/**
 * @brief The interface for handling requests in the chain.
 */
class Handler {
public:
	virtual ~Handler() = default;

	/**
	 * @brief Handles the request or forwards it to the next handler.
	 * @param request The request to handle.
	 */
	virtual void handleRequest(const std::string &request) const = 0;

	/**
	 * @brief Sets the next handler in the chain.
	 * @param next The next handler.
	 * @return A reference to the current handler for chaining.
	 */
	virtual Handler *setNext(std::shared_ptr<Handler> next) = 0;
};

/**
 * @brief Abstract base class that implements the chaining mechanism.
 */
class AbstractHandler : public Handler {
protected:
	std::shared_ptr<Handler> nextHandler; ///< The next handler in the chain.

public:
	virtual ~AbstractHandler() = default;

	/**
	 * @copydoc Handler::setNext
	 */
	Handler *setNext(std::shared_ptr<Handler> next) override {
		this->nextHandler = next;
		return this;
	}

	/**
	 * @brief Forwards the request to the next handler if available.
	 * @param request The request to handle.
	 */
	void handleRequest(const std::string &request) const override {
		if (nextHandler) {
			nextHandler->handleRequest(request);
		}
	}
};

/**
 * @brief A concrete handler that processes specific requests.
 */
class ConcreteHandlerA : public AbstractHandler {
public:
	/**
	 * @brief Handles the request if applicable or forwards it to the next handler.
	 * @param request The request to handle.
	 */
	void handleRequest(const std::string &request) const override {
		if (request == "A") {
			std::cout << "ConcreteHandlerA handled request: " << request << "\n";
		} else {
			std::cout << "ConcreteHandlerA passing request: " << request << "\n";
			AbstractHandler::handleRequest(request);
		}
	}
};

/**
 * @brief Another concrete handler that processes different requests.
 */
class ConcreteHandlerB : public AbstractHandler {
public:
	/**
	 * @brief Handles the request if applicable or forwards it to the next handler.
	 * @param request The request to handle.
	 */
	void handleRequest(const std::string &request) const override {
		if (request == "B") {
			std::cout << "ConcreteHandlerB handled request: " << request << "\n";
		} else {
			std::cout << "ConcreteHandlerB passing request: " << request << "\n";
			AbstractHandler::handleRequest(request);
		}
	}
};

#endif // CHAIN_OF_RESPONSIBILITY_HPP
