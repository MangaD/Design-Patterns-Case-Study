package Behavioral.Visitor;

import java.util.ArrayList;
import java.util.List;

/**
 * ObjectStructure manages a collection of elements and processes them with visitors.
 */
public class ObjectStructure {
	private final List<Element> elements = new ArrayList<>();

	/**
	 * Default constructor for ObjectStructure.
	 */
	public ObjectStructure() {
		// Default constructor
	}

	/**
	 * Add an element to the structure.
	 *
	 * @param element The Element to add.
	 */
	public void addElement(Element element) {
		elements.add(element);
	}

	/**
	 * Accept a visitor for all elements in the structure.
	 *
	 * @param visitor The Visitor to accept.
	 */
	public void accept(Visitor visitor) {
		for (Element element : elements) {
			element.accept(visitor);
		}
	}
}
