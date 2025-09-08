package Behavioral.Interpreter;

import java.util.Map;

/**
 * Terminal expression representing a variable lookup in the interpreter pattern.
 * Implements the {@link Expression} interface.
 */
public final class Variable implements Expression {
    /**
     * The name of the variable to look up.
     */
    private final String name;

    /**
     * Constructs a Variable expression with the specified variable name.
     *
     * @param name the name of the variable
     */
    public Variable(String name) {
        this.name = name;
    }

    /**
     * Interprets the variable expression by looking up its value in the provided context.
     *
     * @param ctx the context map containing variable bindings
     * @return the boolean value of the variable
     * @throws IllegalStateException if the variable is not found in the context
     */
    @Override
    public boolean interpret(Map<String, Boolean> ctx) {
        Boolean v = ctx.get(name);
        if (v == null) {
            throw new IllegalStateException("Unbound variable: " + name);
        }
        return v;
    }
}
