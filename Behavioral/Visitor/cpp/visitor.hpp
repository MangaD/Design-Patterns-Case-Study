#ifndef VISITOR_HPP
#define VISITOR_HPP

#include <iostream>
#include <vector>
#include <memory>

// Forward declarations
class ElementA;
class ElementB;

/**
 * @brief Visitor interface declares operations for different types of Elements.
 */
class Visitor {
public:
	virtual ~Visitor() = default;

	/**
	 * @brief Visit an ElementA instance.
	 * @param elementA The ElementA instance to visit.
	 */
	virtual void visitElementA(const ElementA& elementA) const = 0;

	/**
	 * @brief Visit an ElementB instance.
	 * @param elementB The ElementB instance to visit.
	 */
	virtual void visitElementB(const ElementB& elementB) const = 0;
};

/**
 * @brief Abstract base class for elements.
 */
class Element {
public:
	virtual ~Element() = default;

	/**
	 * @brief Accept a Visitor.
	 * @param visitor The Visitor to accept.
	 */
	virtual void accept(const Visitor& visitor) const = 0;
};

/**
 * @brief Concrete ElementA class.
 */
class ElementA : public Element {
public:
	/**
	 * @brief Perform ElementA-specific behavior.
	 * @return A message describing the operation.
	 */
	std::string operationA() const {
		return "ElementA operation.";
	}

	/**
	 * @copydoc Element::accept
	 */
	void accept(const Visitor& visitor) const override {
		visitor.visitElementA(*this);
	}
};

/**
 * @brief Concrete ElementB class.
 */
class ElementB : public Element {
public:
	/**
	 * @brief Perform ElementB-specific behavior.
	 * @return A message describing the operation.
	 */
	std::string operationB() const {
		return "ElementB operation.";
	}

	/**
	 * @copydoc Element::accept
	 */
	void accept(const Visitor& visitor) const override {
		visitor.visitElementB(*this);
	}
};

/**
 * @brief Concrete VisitorA implements operations for ElementA and ElementB.
 */
class ConcreteVisitorA : public Visitor {
public:
	void visitElementA(const ElementA& elementA) const override {
		std::cout << "ConcreteVisitorA: " << elementA.operationA() << std::endl;
	}

	void visitElementB(const ElementB& elementB) const override {
		std::cout << "ConcreteVisitorA: " << elementB.operationB() << std::endl;
	}
};

/**
 * @brief Concrete VisitorB implements operations for ElementA and ElementB.
 */
class ConcreteVisitorB : public Visitor {
public:
	void visitElementA(const ElementA& elementA) const override {
		std::cout << "ConcreteVisitorB: " << elementA.operationA() << std::endl;
	}

	void visitElementB(const ElementB& elementB) const override {
		std::cout << "ConcreteVisitorB: " << elementB.operationB() << std::endl;
	}
};

/**
 * @brief ObjectStructure manages a collection of elements.
 */
class ObjectStructure {
private:
	std::vector<std::shared_ptr<Element>> elements;

public:
	/**
	 * @brief Add an element to the structure.
	 * @param element The Element to add.
	 */
	void addElement(std::shared_ptr<Element> element) {
		elements.push_back(element);
	}

	/**
	 * @brief Accept a visitor for all elements.
	 * @param visitor The Visitor to accept.
	 */
	void accept(const Visitor& visitor) const {
		for (const auto& element : elements) {
			element->accept(visitor);
		}
	}
};

#endif // VISITOR_HPP
