
#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <stdexcept>
#include <string>
#include <memory>
#include <unordered_map>

/**
 * @brief Namespace for the Interpreter pattern.
 */
namespace interpreter_pattern {

	/**
	 * @brief Context type used to provide variable bindings for interpretation.
	 * Maps variable names to boolean values.
	 */
	using Context = std::unordered_map<std::string, bool>;

	/**
	 * @brief Abstract expression in the grammar.
	 */
	class Expression {
	public:
		virtual ~Expression() = default;

		/**
		 * @brief Evaluate this expression given a @p ctx of variable bindings.
		 * @param ctx The interpretation context.
		 * @return The boolean result of evaluating the expression.
		 */
		virtual bool interpret(const Context& ctx) const = 0;
	};

	/**
	 * @brief Terminal expression representing a boolean constant.
	 */
	class Constant final : public Expression {
	private:
		bool value; ///< Stored boolean value
	public:
		/**
		 * @brief Construct a constant.
		 * @param v The boolean literal value.
		 */
		explicit Constant(bool v) : value(v) {}

		/**
		 * @brief Return the stored literal value (context is ignored).
		 */
		bool interpret(const Context&) const override {
			return value;
		}
	};

	/**
	 * @brief Terminal expression representing a variable lookup.
	 */
	class Variable final : public Expression {
	private:
		std::string name; ///< Variable identifier
	public:
		/**
		 * @brief Construct a variable reference.
		 * @param n Variable name to look up in the context.
		 */
		explicit Variable(std::string n) : name(std::move(n)) {}

		/**
		 * @brief Look up the variable in @p ctx and return its value.
		 * @throws std::out_of_range if the variable is not bound in @p ctx.
		 */
		bool interpret(const Context& ctx) const override {
			auto it = ctx.find(name);
			if (it == ctx.end()) {
				throw std::out_of_range("Unbound variable: " + name);
			}
			return it->second;
		}
	};

	/**
	 * @brief Nonterminal expression for logical NOT.
	 */
	class Not final : public Expression {
	private:
		std::unique_ptr<Expression> expr; ///< Operand to negate
	public:
		/**
		 * @brief Construct a NOT expression.
		 * @param e Operand expression.
		 */
		explicit Not(std::unique_ptr<Expression> e) : expr(std::move(e)) {}

		/**
		 * @brief Evaluate as logical negation of the operand.
		 */
		bool interpret(const Context& ctx) const override {
			return !expr->interpret(ctx);
		}
	};

	/**
	 * @brief Nonterminal expression for logical AND.
	 */
	class And final : public Expression {
	private:
		std::unique_ptr<Expression> left;  ///< Left operand
		std::unique_ptr<Expression> right; ///< Right operand
	public:
		/**
		 * @brief Construct an AND expression.
		 * @param l Left operand.
		 * @param r Right operand.
		 */
		And(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r)
			: left(std::move(l)), right(std::move(r)) {}

		/**
		 * @brief Evaluate as logical conjunction of both operands.
		 */
		bool interpret(const Context& ctx) const override {
			return left->interpret(ctx) && right->interpret(ctx);
		}
	};

	/**
	 * @brief Nonterminal expression for logical OR.
	 */
	class Or final : public Expression {
	private:
		std::unique_ptr<Expression> left;  ///< Left operand
		std::unique_ptr<Expression> right; ///< Right operand
	public:
		/**
		 * @brief Construct an OR expression.
		 * @param l Left operand.
		 * @param r Right operand.
		 */
		Or(std::unique_ptr<Expression> l, std::unique_ptr<Expression> r)
			: left(std::move(l)), right(std::move(r)) {}

		/**
		 * @brief Evaluate as logical disjunction of both operands.
		 */
		bool interpret(const Context& ctx) const override {
			return left->interpret(ctx) || right->interpret(ctx);
		}
	};

} // namespace interpreter_pattern

#endif // INTERPRETER_HPP
