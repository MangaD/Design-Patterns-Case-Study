#include "composite.hpp"
#include <gtest/gtest.h>
#include <sstream>

/**
 * @brief Captures console output for validation.
 */
class OutputCapturer {
private:
	std::ostringstream buffer;
	std::streambuf* original;

public:
	void start() {
		original = std::cout.rdbuf(buffer.rdbuf());
	}

	std::string stop() {
		std::cout.rdbuf(original);
		return buffer.str();
	}
};

/**
 * @brief Tests the operation of a single leaf.
 */
TEST(CompositePatternTest, SingleLeafOperation) {
	auto leaf = std::make_shared<Leaf>("Leaf1");

	OutputCapturer capturer;
	capturer.start();

	leaf->operation();

	std::string output = capturer.stop();
	EXPECT_EQ(output, "Leaf: Leaf1 operation executed.\n");
}

/**
 * @brief Tests the operation of a composite with multiple leaves.
 */
TEST(CompositePatternTest, CompositeWithLeaves) {
	auto composite = std::make_shared<Composite>();
	auto leaf1 = std::make_shared<Leaf>("Leaf1");
	auto leaf2 = std::make_shared<Leaf>("Leaf2");

	composite->add(leaf1);
	composite->add(leaf2);

	OutputCapturer capturer;
	capturer.start();

	composite->operation();

	std::string output = capturer.stop();
	EXPECT_EQ(output,
		"Composite: Executing operation for children:\n"
		"Leaf: Leaf1 operation executed.\n"
		"Leaf: Leaf2 operation executed.\n");
}

/**
 * @brief Tests the nested composites.
 */
TEST(CompositePatternTest, NestedComposites) {
	auto root = std::make_shared<Composite>();
	auto childComposite = std::make_shared<Composite>();
	auto leaf1 = std::make_shared<Leaf>("Leaf1");
	auto leaf2 = std::make_shared<Leaf>("Leaf2");

	childComposite->add(leaf1);
	root->add(childComposite);
	root->add(leaf2);

	OutputCapturer capturer;
	capturer.start();

	root->operation();

	std::string output = capturer.stop();
	EXPECT_EQ(output,
		"Composite: Executing operation for children:\n"
		"Composite: Executing operation for children:\n"
		"Leaf: Leaf1 operation executed.\n"
		"Leaf: Leaf2 operation executed.\n");
}
