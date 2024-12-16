#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Namespace for the Mediator pattern.
 */
namespace mediator_pattern {

	/**
	* @brief Forward declaration of Colleague to resolve circular dependency.
	*/
	class Colleague;

	/**
	* @brief Mediator interface to facilitate communication between colleagues.
	*/
	class Mediator {
	public:
		virtual ~Mediator() = default;

		/**
		* @brief Sends a message to a specific colleague.
		* @param sender Pointer to the sending colleague.
		* @param message The message to send.
		*/
		virtual void sendMessage(Colleague* sender, const std::string& message) = 0;

		/**
		* @brief Adds a colleague to the mediator.
		* @param colleague Pointer to the colleague to add.
		*/
		virtual void addColleague(Colleague* colleague) = 0;
	};

	/**
	* @brief Colleague interface that interacts with the mediator.
	*/
	class Colleague {
	protected:
		Mediator* mediator; ///< Pointer to the mediator.

	public:
		explicit Colleague(Mediator* mediator) : mediator(mediator) {}
		virtual ~Colleague() = default;

		/**
		* @brief Sends a message via the mediator.
		* @param message The message to send.
		*/
		virtual void send(const std::string& message) {
			mediator->sendMessage(this, message);
		}

		/**
		* @brief Receives a message.
		* @param message The message received.
		*/
		virtual void receive(const std::string& message) = 0;
	};

	/**
	* @brief Concrete implementation of the Mediator interface.
	*/
	class ConcreteMediator : public Mediator {
	private:
		std::vector<Colleague*> colleagues; ///< List of registered colleagues.

	public:
		void sendMessage(Colleague* sender, const std::string& message) override {
			// Forward the message to all colleagues except the sender.
			for (auto* colleague : colleagues) {
				if (colleague != sender) {
					colleague->receive(message);
				}
			}
		}

		void addColleague(Colleague* colleague) override {
			colleagues.push_back(colleague);
		}
	};

	/**
	* @brief Concrete implementation of the Colleague interface.
	*/
	class ConcreteColleague : public Colleague {
	private:
		std::string name; ///< Name of the colleague for identification.

	public:
		explicit ConcreteColleague(Mediator* mediator, std::string name)
			: Colleague(mediator), name(std::move(name)) {}

		void receive(const std::string& message) override {
			// Handle received message (e.g., log or display).
			std::cout << name << " received message: " << message << std::endl;
		}

		const std::string& getName() const {
			return name;
		}
	};

}  // namespace mediator_pattern

#endif // MEDIATOR_HPP
