import java.util.Map;

/**
 * Terminal expression representing a boolean constant in the interpreter pattern.
 * Implements the {@link Expression} interface.
 */
public final class Constant implements Expression {
    /**
     * The boolean value represented by this constant expression.
     */
    private final boolean value;

    /**
     * Constructs a Constant expression with the specified boolean value.
     *
     * @param value the boolean value this constant represents
     */
    public Constant(boolean value) {
        this.value = value;
    }

    /**
     * Interprets the constant expression, returning its boolean value.
     *
     * @param ctx the context map (not used in this implementation)
     * @return the boolean value of this constant
     */
    @Override
    public boolean interpret(Map<String, Boolean> ctx) {
        return value;
    }
}
