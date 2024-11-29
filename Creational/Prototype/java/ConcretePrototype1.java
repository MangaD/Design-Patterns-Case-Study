/**
 * @brief A concrete implementation of the Prototype interface.
 *
 * Represents a prototype with a string attribute.
 */
public class ConcretePrototype1 implements Prototype {
	private String attribute; // The string attribute for the prototype

	/**
	 * @brief Constructor to initialize the attribute.
	 * 
	 * @param attribute The value to initialize the prototype's attribute.
	 */
	public ConcretePrototype1(String attribute) {
		this.attribute = attribute;
	}

	@Override
	public Prototype clone() {
		return new ConcretePrototype1(this.attribute);
	}

	@Override
	public void display() {
		System.out.println("ConcretePrototype1 with attribute: " + attribute);
	}
}
