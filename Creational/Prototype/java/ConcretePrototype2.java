package Creational.Prototype;

/**
 * Another concrete implementation of the Prototype interface.
 *
 * Represents a prototype with an integer attribute.
 */
public class ConcretePrototype2 implements Prototype {
	private int attribute; // The integer attribute for the prototype

	/**
	 * Constructor to initialize the attribute.
	 * 
	 * @param attribute The value to initialize the prototype's attribute.
	 */
	public ConcretePrototype2(int attribute) {
		this.attribute = attribute;
	}

	@Override
	public Prototype clone() {
		return new ConcretePrototype2(this.attribute);
	}

	@Override
	public void display() {
		System.out.println("ConcretePrototype2 with attribute: " + attribute);
	}
}
