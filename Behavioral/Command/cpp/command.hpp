#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>
#include <memory>

/**
 * @brief Namespace for the Command pattern.
 */
namespace command_pattern {

	/**
	* @brief The Command interface declares methods for executing and undoing commands.
	*/
	class Command {
	public:
		virtual ~Command() = default;

		/**
		* @brief Execute the command.
		*/
		virtual void execute() const = 0;

		/**
		* @brief Undo the command.
		*/
		virtual void undo() const = 0;
	};

	/**
	* @brief The Receiver class performs the actual operations associated with a request.
	*/
	class Receiver {
	public:
		void action(const std::string &operation) const {
			std::cout << "Receiver: Performing " << operation << "." << std::endl;
		}

		void reverseAction(const std::string &operation) const {
			std::cout << "Receiver: Reversing " << operation << "." << std::endl;
		}
	};

	/**
	* @brief ConcreteCommand binds a Receiver object with an action.
	*/
	class ConcreteCommand : public Command {
	private:
		std::shared_ptr<Receiver> receiver; ///< The receiver performing the action.
		std::string operation;              ///< The operation to be performed.

	public:
		/**
		* @brief Constructor to initialize the command.
		* @param receiver The receiver that performs the operation.
		* @param operation The operation to be executed.
		*/
		ConcreteCommand(std::shared_ptr<Receiver> receiver, const std::string &operation)
			: receiver(std::move(receiver)), operation(operation) {}

		/**
		* @brief Execute the command by invoking the receiver's action.
		*/
		void execute() const override {
			receiver->action(operation);
		}

		/**
		* @brief Undo the command by invoking the receiver's reverseAction.
		*/
		void undo() const override {
			receiver->reverseAction(operation);
		}
	};

	/**
	* @brief The Invoker class stores a command and triggers its execution or undo.
	*/
	class Invoker {
	private:
		std::shared_ptr<Command> command; ///< The command to be executed.

	public:
		/**
		* @brief Sets the command to be executed.
		* @param command The command to set.
		*/
		void setCommand(std::shared_ptr<Command> command) {
			this->command = std::move(command);
		}

		/**
		* @brief Executes the stored command.
		*/
		void pressButton() const {
			if (command) {
				command->execute();
			} else {
				std::cout << "Invoker: No command set." << std::endl;
			}
		}

		/**
		* @brief Undoes the stored command.
		*/
		void pressUndo() const {
			if (command) {
				command->undo();
			} else {
				std::cout << "Invoker: No command set to undo." << std::endl;
			}
		}
	};

}  // namespace command_pattern

#endif // COMMAND_HPP
