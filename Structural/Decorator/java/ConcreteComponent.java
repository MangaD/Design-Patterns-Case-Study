/**
 * @brief A ConcreteComponent provides the base implementation of the Component interface.
 */
public class ConcreteComponent implements Component {
	@Override
	public String getDescription() {
		return "Concrete Component";
	}

	@Override
	public double cost() {
		return 10.0;
	}
}
