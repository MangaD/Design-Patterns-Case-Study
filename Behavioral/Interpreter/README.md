
# Interpreter Pattern

## Category
Behavioral Design Pattern

---

## Overview

The **Interpreter Pattern** is a **behavioral design pattern** used to define a **grammar** for simple languages and provide an **interpreter** to evaluate sentences in that language. You model each grammar rule as a class (an *expression*), and build an **abstract syntax tree (AST)** from these expressions to interpret against a **context** (runtime data or variable bindings).

This pattern is particularly useful when:
- You need to evaluate frequently changing **business rules** or **filters** expressed in a compact DSL.
- You want a clean, object-oriented way to represent **expressions**, **precedence**, and **composition** (e.g., boolean logic, arithmetic, simple query languages).
- You prefer **extensibility**: adding a new operator is adding a new nonterminal class.

---

## Key Characteristics

1. **Grammar as Classes**:
   - Each production rule is represented by a class; the AST is a composition of these classes.

2. **Terminal vs. Nonterminal**:
   - **Terminal expressions** represent leaves (e.g., constants, variables).
   - **Nonterminal expressions** represent operators (e.g., NOT, AND, OR) and compose other expressions.

3. **Context-Driven**:
   - Evaluation depends on a **context** providing variable bindings or environment data.

4. **Extensibility & Composability**:
   - New operations/operators are added via new classes without changing existing ones.

5. **Trade-off**:
   - Great for **small, stable grammars**. Large/complex languages are usually better served by parser generators or dedicated interpreters.

---

## UML Diagram

The UML diagram below shows a typical boolean-expression Interpreter with terminal and nonterminal expressions.

![UML Diagram](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/MangaD/Design-Patterns-Case-Study/refs/heads/main/Behavioral/Interpreter/interpreter.puml)

---

## Implementation Walkthrough

### Participants

1. **AbstractExpression** (`Expression`):
   - Declares the `interpret(Context)` operation used by all nodes in the AST.

2. **TerminalExpression** (`Constant`, `Variable`):
   - Leaves in the tree; evaluate directly from the context (or intrinsic value).

3. **NonterminalExpression** (`Not`, `And`, `Or`):
   - Internal nodes; combine sub-expressions and define operator semantics and precedence.

4. **Context**:
   - Provides variable bindings and any runtime information needed to evaluate expressions.

5. **Parser (optional)**:
   - Converts input strings into an AST of expressions. For small grammars, a simple recursive-descent parser is common.

---

### Example: Boolean Rule DSL (Java)

Below is a compact boolean DSL where variables come from a context and operators are `!` (NOT), `&` (AND), and `|` (OR).

#### Expression and Terminals
```java
import java.util.Map;

interface Expression {
    boolean interpret(Map<String, Boolean> ctx);
}

final class Constant implements Expression {
    private final boolean value;
    Constant(boolean value) { this.value = value; }
    @Override public boolean interpret(Map<String, Boolean> ctx) { return value; }
}

final class Variable implements Expression {
    private final String name;
    Variable(String name) { this.name = name; }
    @Override public boolean interpret(Map<String, Boolean> ctx) {
        Boolean v = ctx.get(name);
        if (v == null) throw new IllegalStateException("Unbound variable: " + name);
        return v;
    }
}
```

---

#### Nonterminals
```java
final class Not implements Expression {
    private final Expression expr;
    Not(Expression expr) { this.expr = expr; }
    @Override public boolean interpret(Map<String, Boolean> ctx) { return !expr.interpret(ctx); }
}

final class And implements Expression {
    private final Expression left, right;
    And(Expression left, Expression right) { this.left = left; this.right = right; }
    @Override public boolean interpret(Map<String, Boolean> ctx) {
        return left.interpret(ctx) && right.interpret(ctx);
    }
}

final class Or implements Expression {
    private final Expression left, right;
    Or(Expression left, Expression right) { this.left = left; this.right = right; }
    @Override public boolean interpret(Map<String, Boolean> ctx) {
        return left.interpret(ctx) || right.interpret(ctx);
    }
}
```

---

#### Client Code
```java
import java.util.Map;

public class InterpreterPatternDemo {
    public static void main(String[] args) {
        Map<String, Boolean> ctx = Map.of("x", true, "y", false, "z", true);

        // Represents: !(x & y) | z
        Expression expr = new Or(
            new Not(new And(new Variable("x"), new Variable("y"))),
            new Variable("z")
        );

        boolean result = expr.interpret(ctx);
        System.out.println("Result: " + result);
    }
}
```

---

### Output
```
Result: true
```

---

## Applications

### When to Use the Interpreter Pattern
1. When domain rules can be naturally described as a **small grammar**.
2. When rules need to be **modifiable and composable** at runtime.
3. When you want a clear **OO mapping** from rules to an executable model (AST).

### Common Use Cases
1. **Business Rule Engines**:
   - Feature flags, eligibility checks, pricing rules.
2. **Filtering & Query DSLs**:
   - Search filters (e.g., `(isNew & !isArchived) | isPinned`).
3. **Configuration/Workflow Languages**:
   - Simple orchestration or validation logic.
4. **Expression Evaluators in Apps**:
   - Spreadsheet-like formulas, in-app scripting of limited scope.

---

## Advantages and Disadvantages

### Advantages
1. **Extensible**:
   - Add new operations by adding classes; existing code remains closed to modification.
2. **Readable Domain Mapping**:
   - Clear correspondence between grammar and class structure.
3. **Testable**:
   - Each expression node can be unit-tested in isolation.

### Disadvantages
1. **Class Proliferation**:
   - Many small classes for nontrivial grammars.
2. **Performance**:
   - Tree traversal and object allocation may be slower than specialized evaluators.
3. **Not for Large Languages**:
   - Complex grammars are better served by parser generators/VMs.

---

## Key Takeaways

The **Interpreter Pattern** models a small language as a composition of objects. It shines when you need *simple, evolving* grammars with first-class testability and extensibility. For large or performance-critical languages, reach for dedicated parsing tools or DSL frameworks instead.
