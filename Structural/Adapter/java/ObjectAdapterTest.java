import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @brief Unit tests for the Object Adapter pattern.
 */
public class ObjectAdapterTest {

	/**
	 * @brief Test that the Adapter translates the Target's request to the Adaptee's specificRequest.
	 */
	@Test
	public void testAdapterTranslatesRequest() {
		// Arrange
		Adaptee adaptee = new Adaptee();
		Target adapter = new Adapter(adaptee);

		// Act
		String result = adapter.request();

		// Assert
		String expectedOutput = "Adapter: Translating request to Adaptee's specificRequest().\nAdaptee: Specific request called.";
		assertEquals(expectedOutput, result, "Adapter should correctly translate Target's request() to Adaptee's specificRequest().");
	}

	/**
	 * @brief Test that the Adapter wraps an Adaptee instance.
	 */
	@Test
	public void testAdapterWrapsAdaptee() {
		// Arrange
		Adaptee adaptee = new Adaptee();
		Adapter adapter = new Adapter(adaptee);

		// Act
		String adapteeResponse = adaptee.specificRequest();
		String adapterResponse = adapter.request();

		// Assert
		assertTrue(adapterResponse.contains(adapteeResponse), "Adapter's response should include Adaptee's specificRequest() response.");
	}

	/**
	 * @brief Test that the Adapter throws an exception when initialized with a null Adaptee.
	 */
	@Test
	public void testAdapterThrowsForNullAdaptee() {
		// Act & Assert
		IllegalArgumentException exception = assertThrows(
			IllegalArgumentException.class,
			() -> new Adapter(null),
			"Adapter should throw an exception when constructed with a null Adaptee."
		);
		assertEquals("Adaptee cannot be null", exception.getMessage());
	}
}
