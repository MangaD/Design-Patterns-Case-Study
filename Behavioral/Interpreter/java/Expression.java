
/**
 * Expression in a small boolean grammar.
 */
import java.util.Map;

public interface Expression {
    /**
     * Interpret this expression under the provided context.
     * @param ctx Variable bindings.
     * @return boolean result
     */
    boolean interpret(Map<String, Boolean> ctx);
}
