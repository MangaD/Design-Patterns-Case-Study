#ifndef SINGLETON_H
#define SINGLETON_H

/**
 * @class Singleton
 * @brief A class implementing the Singleton design pattern.
 *
 * The Singleton class ensures that only one instance of the class exists
 * and provides a global point of access to that instance. This is achieved
 * using a private constructor and a static method for instance retrieval.
 */
class Singleton {
public:
	/**
	 * @brief Retrieves the single instance of the Singleton class.
	 * 
	 * This method returns a reference to the single instance of the
	 * Singleton. The instance is created lazily and is guaranteed to
	 * be thread-safe in C++11 and later.
	 *
	 * @return Singleton& A reference to the Singleton instance.
	 */
	static Singleton& getInstance();

	/**
	 * @brief An example method to demonstrate Singleton usage.
	 * 
	 * This method serves as an example of how the Singleton can
	 * provide functionality via its single instance.
	 */
	void doSomething();

private:
	/**
	 * @brief Constructs the Singleton instance.
	 *
	 * The constructor is private to prevent direct instantiation
	 * of the Singleton class.
	 */
	Singleton();

	/**
	 * @brief Destroys the Singleton instance.
	 *
	 * The destructor is private to prevent direct destruction
	 * of the Singleton instance.
	 */
	~Singleton();

	/**
	 * @brief Deleted copy constructor.
	 *
	 * Copying the Singleton instance is disabled to ensure
	 * only one instance exists.
	 */
	Singleton(const Singleton&) = delete;

	/**
	 * @brief Deleted assignment operator.
	 *
	 * Assigning one Singleton instance to another is disabled
	 * to ensure only one instance exists.
	 *
	 * @return Singleton& Reference to the Singleton instance.
	 */
	Singleton& operator=(const Singleton&) = delete;
};

#endif // SINGLETON_H
