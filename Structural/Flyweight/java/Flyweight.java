package Structural.Flyweight;

/**
 * Flyweight interface for defining common methods that Flyweight objects must implement.
 */
public interface Flyweight {
	/**
	 * Operation performed by the Flyweight object.
	 * @param extrinsicState State provided by the client at runtime.
	 */
	void operation(String extrinsicState);
}
