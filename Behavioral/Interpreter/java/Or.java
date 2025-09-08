import java.util.Map;

/**
 * Nonterminal expression representing a logical OR operation in the interpreter pattern.
 * Implements the {@link Expression} interface.
 */
public final class Or implements Expression {
    /**
     * The left operand of the OR expression.
     */
    private final Expression left;
    /**
     * The right operand of the OR expression.
     */
    private final Expression right;

    /**
     * Constructs an OR expression with the specified left and right operands.
     *
     * @param left  the left operand expression
     * @param right the right operand expression
     */
    public Or(Expression left, Expression right) {
        this.left = left;
        this.right = right;
    }

    /**
     * Interprets the OR expression by evaluating both operands and returning their logical disjunction.
     *
     * @param ctx the context map for variable evaluation
     * @return true if at least one operand evaluates to true; false otherwise
     */
    @Override
    public boolean interpret(Map<String, Boolean> ctx) {
        return left.interpret(ctx) || right.interpret(ctx);
    }
}
