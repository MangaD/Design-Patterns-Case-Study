
/**
 * Terminal expression representing a variable lookup.
 */
import java.util.Map;

public final class Variable implements Expression {
    private final String name;

    public Variable(String name) {
        this.name = name;
    }

    @Override
    public boolean interpret(Map<String, Boolean> ctx) {
        Boolean v = ctx.get(name);
        if (v == null) {
            throw new IllegalStateException("Unbound variable: " + name);
        }
        return v;
    }
}
