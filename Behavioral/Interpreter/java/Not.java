
/**
 * Nonterminal NOT.
 */
import java.util.Map;

public final class Not implements Expression {
    private final Expression expr;

    public Not(Expression expr) {
        this.expr = expr;
    }

    @Override
    public boolean interpret(Map<String, Boolean> ctx) {
        return !expr.interpret(ctx);
    }
}
