#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <iostream>
#include <memory>

/**
 * @brief Namespace for the Strategy pattern.
 */
namespace strategy_pattern {

	/**
	* @brief The Strategy interface defines a common interface for all supported algorithms.
	*/
	class Strategy {
	public:
		virtual ~Strategy() = default;

		/**
		* @brief Executes the algorithm encapsulated by the strategy.
		*/
		virtual void execute() const = 0;
	};

	/**
	* @brief Concrete Strategy A implements a specific algorithm.
	*/
	class ConcreteStrategyA : public Strategy {
	public:
		void execute() const override {
			std::cout << "Executing strategy A" << std::endl;
		}
	};

	/**
	* @brief Concrete Strategy B implements a specific algorithm.
	*/
	class ConcreteStrategyB : public Strategy {
	public:
		void execute() const override {
			std::cout << "Executing strategy B" << std::endl;
		}
	};

	/**
	* @brief Context maintains a reference to a Strategy object and delegates behavior to it.
	*/
	class Context {
	private:
		std::unique_ptr<Strategy> strategy; ///< Pointer to the current strategy.

	public:
		/**
		* @brief Sets the strategy for the context.
		* @param strategy A unique pointer to the strategy to use.
		*/
		void setStrategy(std::unique_ptr<Strategy> strategy) {
			this->strategy = std::move(strategy);
		}

		/**
		* @brief Executes the strategy.
		*/
		void executeStrategy() const {
			if (strategy) {
				strategy->execute();
			} else {
				std::cerr << "No strategy set!" << std::endl;
			}
		}
	};

}  // namespace strategy_pattern

#endif // STRATEGY_HPP
