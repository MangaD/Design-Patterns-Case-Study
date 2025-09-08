package Behavioral.Interpreter;

import java.util.Map;

/**
 * Represents an expression in a simple boolean grammar for the Interpreter design pattern.
 * <p>
 * Implementations of this interface define how to interpret the expression given a context of variable bindings.
 * This allows for the evaluation of logical expressions such as AND, OR, NOT, constants, and variables.
 * </p>
 *
 * <p>Example usage:</p>
 * <pre>
 *     Expression expr = new And(new Variable("x"), new Not(new Variable("y")));
 *     boolean result = expr.interpret(Map.of("x", true, "y", false));
 * </pre>
 *
 * @author David
 * @since 1.0
 */
public interface Expression {
    /**
     * Interprets this expression under the provided context of variable bindings.
     *
     * @param ctx a map containing variable names as keys and their boolean values as values
     * @return the boolean result of evaluating this expression with the given context
     * @throws IllegalStateException if a required variable is not present in the context
     */
    boolean interpret(Map<String, Boolean> ctx);
}
