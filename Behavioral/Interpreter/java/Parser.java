
/**
 * Minimal recursive-descent parser for a boolean domain-specific language (DSL).
 * <p>
 * Supports parsing logical expressions with AND, OR, NOT, constants, and variables.
 * </p>
 *
 * <p>Grammar (EBNF):</p>
 * <pre>
 *   Expr   := OrExpr
 *   OrExpr := AndExpr { '|' AndExpr }
 *   AndExpr:= NotExpr { '&' NotExpr }
 *   NotExpr:= '!' NotExpr | Primary
 *   Primary:= 'true' | 'false' | Identifier | '(' Expr ')'
 *   Identifier := [A-Za-z_][A-Za-z0-9_]*
 * </pre>
 *
 * Example usage:
 * <pre>
 *   Expression expr = new Parser("!(x & y) | z").parse();
 * </pre>
 *
 * @author David
 * @since 1.0
 */
public final class Parser {
    /**
     * The input string to parse.
     */
    private final String s;
    /**
     * The current index in the input string.
     */
    private int i = 0;

    /**
     * Constructs a parser for the given input string.
     *
     * @param s the boolean expression string to parse
     */
    public Parser(String s) {
        this.s = s;
    }

    /**
     * Parses the input string and returns the root {@link Expression}.
     *
     * @return the parsed expression tree
     * @throws IllegalStateException if the input is invalid or contains trailing characters
     */
    public Expression parse() {
        Expression e = parseOr();
        skipWs();
        if (i != s.length()) {
            throw new IllegalStateException("Unexpected trailing input at " + i);
        }
        return e;
    }

    /**
     * Parses an OR expression (OrExpr := AndExpr { '|' AndExpr }).
     *
     * @return the parsed OR expression
     */
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

    /**
     * Parses an AND expression (AndExpr := NotExpr { '&' NotExpr }).
     *
     * @return the parsed AND expression
     */
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

    /**
     * Parses a NOT expression (NotExpr := '!' NotExpr | Primary).
     *
     * @return the parsed NOT or primary expression
     */
    private Expression parseNot() {
        skipWs();
        if (consume('!')) {
            return new Not(parseNot());
        }
        return parsePrimary();
    }

    /**
     * Parses a primary expression (Primary := 'true' | 'false' | Identifier | '(' Expr ')').
     *
     * @return the parsed primary expression
     * @throws IllegalStateException if the input is invalid or incomplete
     */
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

    /**
     * Checks if the given character is a valid start for an identifier.
     *
     * @param c the character to check
     * @return true if the character is a letter or underscore; false otherwise
     */
    private boolean isIdentStart(char c) {
        return Character.isLetter(c) || c == '_';
    }

    /**
     * Checks if the given character is a valid part of an identifier.
     *
     * @param c the character to check
     * @return true if the character is a letter, digit, or underscore; false otherwise
     */
    private boolean isIdentChar(char c) {
        return Character.isLetterOrDigit(c) || c == '_';
    }

    /**
     * Parses an identifier from the input string.
     *
     * @return the parsed identifier
     * @throws IllegalStateException if the input does not start with a valid identifier
     */
    private String parseIdent() {
        skipWs();
        if (i >= s.length() || !isIdentStart(s.charAt(i))) {
            throw new IllegalStateException("Expected identifier at " + i);
        }
        int start = i++;
        while (i < s.length() && isIdentChar(s.charAt(i))) i++;
        return s.substring(start, i);
    }

    /**
     * Skips whitespace characters in the input string.
     */
    private void skipWs() {
        while (i < s.length() && Character.isWhitespace(s.charAt(i))) i++;
    }

    /**
     * Consumes the given character if it is the next non-whitespace character in the input.
     *
     * @param c the character to consume
     * @return true if the character was consumed; false otherwise
     */
    private boolean consume(char c) {
        skipWs();
        if (i < s.length() && s.charAt(i) == c) {
            i++;
            return true;
        }
        return false;
    }
}
