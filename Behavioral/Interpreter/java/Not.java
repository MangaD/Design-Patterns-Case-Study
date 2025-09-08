import java.util.Map;

/**
 * Nonterminal expression representing a logical NOT operation in the interpreter pattern.
 * Implements the {@link Expression} interface.
 */
public final class Not implements Expression {
    /**
     * The operand expression to be negated.
     */
    private final Expression expr;

    /**
     * Constructs a NOT expression with the specified operand.
     *
     * @param expr the operand expression to negate
     */
    public Not(Expression expr) {
        this.expr = expr;
    }

    /**
     * Interprets the NOT expression by evaluating its operand and returning the logical negation.
     *
     * @param ctx the context map for variable evaluation
     * @return true if the operand evaluates to false; false otherwise
     */
    @Override
    public boolean interpret(Map<String, Boolean> ctx) {
        return !expr.interpret(ctx);
    }
}
