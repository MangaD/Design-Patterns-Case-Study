
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;
import java.util.Map;

public class InterpreterPatternTest {

    @Test
    void constantsAndVariables() {
        Map<String, Boolean> ctx = Map.of("x", true, "y", false);

        assertTrue(new Constant(true).interpret(ctx));
        assertFalse(new Constant(false).interpret(ctx));

        assertTrue(new Variable("x").interpret(ctx));
        assertFalse(new Variable("y").interpret(ctx));
    }

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

    @Test
    void parserHappyPath() {
        Map<String, Boolean> ctx = Map.of("x", true, "y", false, "z", true);
        Expression e = new Parser("!(x & y) | z").parse();
        assertTrue(e.interpret(ctx));
    }

    @Test
    void parserErrors() {
        assertThrows(IllegalStateException.class, () -> new Parser("(").parse());
        assertThrows(IllegalStateException.class, () -> new Parser("true garbage").parse());
    }

    @Test
    void unboundVariableThrows() {
        Map<String, Boolean> ctx = Map.of();
        assertThrows(IllegalStateException.class, () -> new Variable("missing").interpret(ctx));
    }
}
