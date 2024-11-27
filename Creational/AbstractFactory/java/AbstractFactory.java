/**
 * @brief Abstract Factory interface.
 * 
 * Defines methods for creating families of related products.
 */
public interface AbstractFactory {
	/**
	 * @brief Creates a product of type A.
	 * @return A product implementing the ProductA interface.
	 */
	ProductA createProductA();

	/**
	 * @brief Creates a product of type B.
	 * @return A product implementing the ProductB interface.
	 */
	ProductB createProductB();
}
