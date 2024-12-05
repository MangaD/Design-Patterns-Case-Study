import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 * @brief Unit tests for the Proxy pattern implementation.
 */
public class ProxyPatternTest {

	/**
	 * @brief Test Proxy access with authentication.
	 */
	@Test
	public void testAccessWithAuthentication() {
		Proxy proxy = new Proxy(true); // Authenticated user

		// Capture output
		java.io.ByteArrayOutputStream outputStream = new java.io.ByteArrayOutputStream();
		System.setOut(new java.io.PrintStream(outputStream));

		proxy.request("Resource1");

		String output = outputStream.toString();
		assertTrue(output.contains("Proxy: Initializing RealSubject."));
		assertTrue(output.contains("Proxy: Delegating request to RealSubject."));
		assertTrue(output.contains("RealSubject: Handling request for resource: Resource1"));
	}

	/**
	 * @brief Test Proxy access without authentication.
	 */
	@Test
	public void testAccessWithoutAuthentication() {
		Proxy proxy = new Proxy(false); // Unauthenticated user

		// Capture output
		java.io.ByteArrayOutputStream outputStream = new java.io.ByteArrayOutputStream();
		System.setOut(new java.io.PrintStream(outputStream));

		proxy.request("Resource2");

		String output = outputStream.toString();
		assertTrue(output.contains("Proxy: Access denied. Authentication required to access: Resource2"));
	}

	/**
	 * @brief Test Proxy lazy initialization.
	 */
	@Test
	public void testLazyInitialization() {
		Proxy proxy = new Proxy(true); // Authenticated user

		// Capture output
		java.io.ByteArrayOutputStream outputStream = new java.io.ByteArrayOutputStream();
		System.setOut(new java.io.PrintStream(outputStream));

		// First access
		proxy.request("Resource3");
		String firstOutput = outputStream.toString();
		assertTrue(firstOutput.contains("Proxy: Initializing RealSubject."));

		// Clear output for next request
		outputStream.reset();

		// Subsequent access
		proxy.request("Resource4");
		String secondOutput = outputStream.toString();
		assertFalse(secondOutput.contains("Proxy: Initializing RealSubject.")); // No reinitialization
	}
}
