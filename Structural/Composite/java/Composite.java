package Structural.Composite;

import java.util.ArrayList;
import java.util.List;

/**
 * Represents the Composite object in the Composite pattern.
 * A Composite can contain both Leaf and other Composite objects.
 */
public class Composite implements Component {
	private final String name;
	private final List<Component> children = new ArrayList<>();

	/**
	 * Constructor for the Composite.
	 * 
	 * @param name The name of the Composite.
	 */
	public Composite(String name) {
		this.name = name;
	}

	/**
	 * Performs the operation on the Composite and its children.
	 */
	@Override
	public void operation() {
		System.out.println("Composite " + name + " operation.");
		for (Component child : children) {
			child.operation();
		}
	}

	/**
	 * Adds a child component to the Composite.
	 * 
	 * @param component The child component to add.
	 */
	@Override
	public void add(Component component) {
		children.add(component);
	}

	/**
	 * Removes a child component from the Composite.
	 * 
	 * @param component The child component to remove.
	 */
	@Override
	public void remove(Component component) {
		children.remove(component);
	}

	/**
	 * Retrieves a child component at the specified index.
	 * 
	 * @param index The index of the child component to retrieve.
	 * @return The child component.
	 */
	@Override
	public Component getChild(int index) {
		return children.get(index);
	}
}
