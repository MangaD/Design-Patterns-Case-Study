package Structural.Adapter;

/**
 * The Adaptee class provides existing functionality that needs adaptation.
 *
 * The Adaptee defines methods that do not match the Target interface but offer
 * useful functionality. The Adapter class bridges the gap between Adaptee and Target.
 */
public class Adaptee {

	/**
	 * Default constructor for Adaptee.
	 */
	public Adaptee() {
		// Default constructor
	}

	/**
	 * A specific method offered by the Adaptee.
	 *
	 * This method demonstrates functionality that needs adaptation to match
	 * the Target interface.
	 *
	 * @return A string representing the Adaptee's specific response.
	 */
	public String specificRequest() {
		return "Adaptee: Specific request called.";
	}
}
