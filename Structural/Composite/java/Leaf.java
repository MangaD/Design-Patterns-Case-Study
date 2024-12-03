/**
 * @brief Represents the Leaf object in the Composite pattern.
 * A Leaf has no children and defines behavior for primitive objects.
 */
public class Leaf implements Component {
	private final String name;

	/**
	 * @brief Constructor for the Leaf.
	 * 
	 * @param name The name of the Leaf.
	 */
	public Leaf(String name) {
		this.name = name;
	}

	/**
	 * @brief Performs the operation specific to the Leaf.
	 */
	@Override
	public void operation() {
		System.out.println("Leaf " + name + " operation.");
	}
}
