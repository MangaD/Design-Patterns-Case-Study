
/**
 * Terminal expression representing a boolean constant.
 */
import java.util.Map;

public final class Constant implements Expression {
    private final boolean value;

    public Constant(boolean value) {
        this.value = value;
    }

    @Override
    public boolean interpret(Map<String, Boolean> ctx) {
        return value;
    }
}
