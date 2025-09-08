package Behavioral.Interpreter;

import java.util.Map;

/**
 * Nonterminal expression representing a logical AND operation in the interpreter pattern.
 * Implements the {@link Expression} interface.
 */
public final class And implements Expression {
    /**
     * The left operand of the AND expression.
     */
    private final Expression left;
    /**
     * The right operand of the AND expression.
     */
    private final Expression right;

    /**
     * Constructs an AND expression with the specified left and right operands.
     *
     * @param left  the left operand expression
     * @param right the right operand expression
     */
    public And(Expression left, Expression right) {
        this.left = left;
        this.right = right;
    }

    /**
     * Interprets the AND expression by evaluating both operands and returning their logical conjunction.
     *
     * @param ctx the context map for variable evaluation
     * @return true if both operands evaluate to true; false otherwise
     */
    @Override
    public boolean interpret(Map<String, Boolean> ctx) {
        return left.interpret(ctx) && right.interpret(ctx);
    }
}
