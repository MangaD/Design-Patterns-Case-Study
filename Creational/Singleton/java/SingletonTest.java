package Creational.Singleton;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 * @file SingletonTest.java
 * Unit tests for the Singleton class.
 *
 * This file contains tests to verify the correct behavior of the Singleton
 * class, ensuring it adheres to the Singleton pattern.
 */
public class SingletonTest {

	/**
	 * Test to verify that Singleton returns a single instance.
	 *
	 * This test ensures that the `getInstance()` method always returns
	 * the same instance of the Singleton class.
	 */
	@Test
	public void testSingleInstance() {
		Singleton instance1 = Singleton.getInstance();
		Singleton instance2 = Singleton.getInstance();

		// Verify both references point to the same instance
		assertSame(instance1, instance2);
	}

	/**
	 * Test the functionality of the Singleton's `doSomething()` method.
	 *
	 * This test verifies that the `doSomething()` method produces
	 * the expected output.
	 */
	@Test
	public void testDoSomething() {
		Singleton instance = Singleton.getInstance();

		// Capture standard output
		java.io.ByteArrayOutputStream outContent = new java.io.ByteArrayOutputStream();
		System.setOut(new java.io.PrintStream(outContent));

		instance.doSomething();

		// Verify the output matches the expected string
		assertEquals("Singleton instance is working!\n", outContent.toString());
	}
}
