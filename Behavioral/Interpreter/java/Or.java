
/**
 * Nonterminal OR.
 */
import java.util.Map;

public final class Or implements Expression {
    private final Expression left, right;

    public Or(Expression left, Expression right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public boolean interpret(Map<String, Boolean> ctx) {
        return left.interpret(ctx) || right.interpret(ctx);
    }
}
