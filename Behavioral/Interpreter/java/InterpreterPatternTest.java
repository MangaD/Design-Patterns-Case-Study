package Behavioral.Interpreter;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;
import java.util.Map;

/**
 * Unit tests for the Interpreter pattern implementation.
 * Tests constant, variable, and composed expressions, as well as parser and error handling.
 */
public class InterpreterPatternTest {

    /**
     * Tests interpretation of constant and variable expressions.
     * Verifies correct evaluation of true/false constants and variable lookups.
     */
    @Test
    void constantsAndVariables() {
        Map<String, Boolean> ctx = Map.of("x", true, "y", false);

        assertTrue(new Constant(true).interpret(ctx));
        assertFalse(new Constant(false).interpret(ctx));

        assertTrue(new Variable("x").interpret(ctx));
        assertFalse(new Variable("y").interpret(ctx));
    }

    /**
     * Tests composition of NOT, AND, and OR expressions.
     * Verifies correct logical evaluation of a composed expression tree.
     */
    @Test
    void compositionNotAndOr() {
        Map<String, Boolean> ctx = Map.of("x", true, "y", false, "z", true);

        // !(x & y) | z
        Expression expr = new Or(
            new Not(new And(new Variable("x"), new Variable("y"))),
            new Variable("z")
        );

        assertTrue(expr.interpret(ctx));
    }

    /**
     * Tests parsing and evaluation of a valid expression string.
     * Verifies that the parser produces a correct expression tree.
     */
    @Test
    void parserHappyPath() {
        Map<String, Boolean> ctx = Map.of("x", true, "y", false, "z", true);
        Expression e = new Parser("!(x & y) | z").parse();
        assertTrue(e.interpret(ctx));
    }

    /**
     * Tests that the parser throws exceptions for invalid input strings.
     */
    @Test
    void parserErrors() {
        assertThrows(IllegalStateException.class, () -> new Parser("(").parse());
        assertThrows(IllegalStateException.class, () -> new Parser("true garbage").parse());
    }

    /**
     * Tests that interpreting an unbound variable throws an exception.
     */
    @Test
    void unboundVariableThrows() {
        Map<String, Boolean> ctx = Map.of();
        assertThrows(IllegalStateException.class, () -> new Variable("missing").interpret(ctx));
    }
}
