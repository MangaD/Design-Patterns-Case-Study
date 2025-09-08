
/**
 * Minimal recursive-descent parser for a boolean DSL.
 *
 * Grammar (EBNF):
 *   Expr   := OrExpr
 *   OrExpr := AndExpr { '|' AndExpr }
 *   AndExpr:= NotExpr { '&' NotExpr }
 *   NotExpr:= '!' NotExpr | Primary
 *   Primary:= 'true' | 'false' | Identifier | '(' Expr ')'
 *   Identifier := [A-Za-z_][A-Za-z0-9_]*
 */
public final class Parser {
    private final String s;
    private int i = 0;

    public Parser(String s) {
        this.s = s;
    }

    public Expression parse() {
        Expression e = parseOr();
        skipWs();
        if (i != s.length()) {
            throw new IllegalStateException("Unexpected trailing input at " + i);
        }
        return e;
    }

    private Expression parseOr() {
        Expression left = parseAnd();
        while (true) {
            skipWs();
            if (consume('|')) {
                Expression right = parseAnd();
                left = new Or(left, right);
            } else break;
        }
        return left;
    }

    private Expression parseAnd() {
        Expression left = parseNot();
        while (true) {
            skipWs();
            if (consume('&')) {
                Expression right = parseNot();
                left = new And(left, right);
            } else break;
        }
        return left;
    }

    private Expression parseNot() {
        skipWs();
        if (consume('!')) {
            return new Not(parseNot());
        }
        return parsePrimary();
    }

    private Expression parsePrimary() {
        skipWs();
        if (i >= s.length()) throw new IllegalStateException("Unexpected end of input");
        char c = s.charAt(i);
        if (c == '(') {
            i++;
            Expression e = parseOr();
            if (!consume(')')) throw new IllegalStateException("Expected ')'");
            return e;
        }
        if (isIdentStart(c)) {
            String ident = parseIdent();
            if (ident.equals("true"))  return new Constant(true);
            if (ident.equals("false")) return new Constant(false);
            return new Variable(ident);
        }
        throw new IllegalStateException("Unexpected character '" + c + "' at " + i);
    }

    private boolean isIdentStart(char c) {
        return Character.isLetter(c) || c == '_';
    }
    private boolean isIdentChar(char c) {
        return Character.isLetterOrDigit(c) || c == '_';
    }

    private String parseIdent() {
        skipWs();
        if (i >= s.length() || !isIdentStart(s.charAt(i))) {
            throw new IllegalStateException("Expected identifier at " + i);
        }
        int start = i++;
        while (i < s.length() && isIdentChar(s.charAt(i))) i++;
        return s.substring(start, i);
    }

    private void skipWs() {
        while (i < s.length() && Character.isWhitespace(s.charAt(i))) i++;
    }

    private boolean consume(char c) {
        skipWs();
        if (i < s.length() && s.charAt(i) == c) {
            i++;
            return true;
        }
        return false;
    }
}
