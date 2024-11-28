#include "prototype.hpp"
#include <gtest/gtest.h>

/**
 * @brief Test cloning functionality of ConcretePrototype1.
 *
 * This test verifies that cloning a ConcretePrototype1 object creates
 * an independent copy with the same attribute value.
 */
TEST(PrototypePatternTest, CloneConcretePrototype1) {
	ConcretePrototype1 prototype1("ExampleAttribute");

	// Clone the prototype
	auto clonedPrototype = prototype1.clone();

	// Verify that the clone is not the same object
	EXPECT_NE(clonedPrototype.get(), &prototype1);

	// Verify that the clone has the same attribute
	testing::internal::CaptureStdout();
	clonedPrototype->display();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "ConcretePrototype1 with attribute: ExampleAttribute\n");
}

/**
 * @brief Test cloning functionality of ConcretePrototype2.
 *
 * This test ensures that cloning a ConcretePrototype2 object produces
 * an independent instance with the same attribute value.
 */
TEST(PrototypePatternTest, CloneConcretePrototype2) {
	ConcretePrototype2 prototype2(42);

	// Clone the prototype
	auto clonedPrototype = prototype2.clone();

	// Verify that the clone is not the same object
	EXPECT_NE(clonedPrototype.get(), &prototype2);

	// Verify that the clone has the same attribute
	testing::internal::CaptureStdout();
	clonedPrototype->display();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "ConcretePrototype2 with attribute: 42\n");
}

/**
 * @brief Test modifying the cloned prototype.
 *
 * This test verifies that modifying a cloned prototype does not affect the original object.
 */
TEST(PrototypePatternTest, CloneAndModifyPrototype) {
	ConcretePrototype1 prototype1("OriginalAttribute");

	// Clone the prototype
	auto clonedPrototype = prototype1.clone();

	// Modify the clone
	auto concreteClone = dynamic_cast<ConcretePrototype1*>(clonedPrototype.get());
	ASSERT_NE(concreteClone, nullptr); // Ensure dynamic cast is successful
	concreteClone->display(); // For validation if needed.

	// Verify the original is unchanged
	testing::internal::CaptureStdout();
	prototype1.display();
	std::string originalOutput = testing::internal::GetCapturedStdout();
	EXPECT_EQ(originalOutput, "ConcretePrototype1 with attribute: OriginalAttribute\n");
}

/**
 * @brief Test cloning and verifying independence for multiple clones.
 *
 * This test ensures that multiple clones of the same prototype are
 * independent of each other and the original object.
 */
TEST(PrototypePatternTest, CloneMultipleInstances) {
	ConcretePrototype2 prototype2(100);

	// Clone the prototype multiple times
	auto clone1 = prototype2.clone();
	auto clone2 = prototype2.clone();

	// Verify that all clones and the original are independent
	EXPECT_NE(clone1.get(), &prototype2);
	EXPECT_NE(clone2.get(), &prototype2);
	EXPECT_NE(clone1.get(), clone2.get());

	// Verify attributes of the clones
	testing::internal::CaptureStdout();
	clone1->display();
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	clone2->display();
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output1, "ConcretePrototype2 with attribute: 100\n");
	EXPECT_EQ(output2, "ConcretePrototype2 with attribute: 100\n");
}
