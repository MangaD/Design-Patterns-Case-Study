/**
 * @file Singleton.java
 * @brief Implementation of the Singleton design pattern in Java.
 *
 * This class ensures that only one instance of the Singleton class
 * exists throughout the application's lifetime.
 */
public class Singleton {
	// The single instance of the Singleton, initialized lazily.
	private static Singleton instance;

	/**
	 * @brief Private constructor to prevent instantiation.
	 *
	 * This constructor is private to enforce the Singleton pattern
	 * by preventing direct instantiation of the class.
	 */
	private Singleton() {
		// Optional: Initialization logic here.
	}

	/**
	 * @brief Retrieves the single instance of the Singleton class.
	 *
	 * This method uses synchronized lazy initialization to ensure
	 * thread safety while creating the Singleton instance.
	 *
	 * @return The single instance of the Singleton class.
	 */
	public static synchronized Singleton getInstance() {
		if (instance == null) {
			instance = new Singleton();
		}
		return instance;
	}

	/**
	 * @brief An example method demonstrating Singleton functionality.
	 *
	 * This method performs an example action to showcase how to use
	 * the Singleton instance.
	 */
	public void doSomething() {
		System.out.println("Singleton instance is working!");
	}
}
