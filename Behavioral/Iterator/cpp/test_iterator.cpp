#include "iterator.hpp"
#include <gtest/gtest.h>
#include <string>

/**
 * @brief Test the ConcreteIterator's ability to traverse a collection.
 */
TEST(IteratorPatternTest, IteratorTraversal) {
	ConcreteAggregate<std::string> aggregate;
	aggregate.addItem("Element 1");
	aggregate.addItem("Element 2");
	aggregate.addItem("Element 3");

	auto iterator = aggregate.createIterator();

	EXPECT_TRUE(iterator->hasNext());
	EXPECT_EQ(iterator->next(), "Element 1");

	EXPECT_TRUE(iterator->hasNext());
	EXPECT_EQ(iterator->next(), "Element 2");

	EXPECT_TRUE(iterator->hasNext());
	EXPECT_EQ(iterator->next(), "Element 3");

	EXPECT_FALSE(iterator->hasNext());
	EXPECT_THROW(iterator->next(), std::out_of_range);
}

/**
 * @brief Test the ConcreteAggregate's ability to add and retrieve items via the iterator.
 */
TEST(IteratorPatternTest, AddAndIterate) {
	ConcreteAggregate<int> aggregate;
	aggregate.addItem(10);
	aggregate.addItem(20);
	aggregate.addItem(30);

	auto iterator = aggregate.createIterator();

	EXPECT_TRUE(iterator->hasNext());
	EXPECT_EQ(iterator->next(), 10);

	EXPECT_TRUE(iterator->hasNext());
	EXPECT_EQ(iterator->next(), 20);

	EXPECT_TRUE(iterator->hasNext());
	EXPECT_EQ(iterator->next(), 30);

	EXPECT_FALSE(iterator->hasNext());
}

/**
 * @brief Test the behavior of an empty iterator.
 */
TEST(IteratorPatternTest, EmptyCollection) {
	ConcreteAggregate<int> aggregate;
	auto iterator = aggregate.createIterator();

	EXPECT_FALSE(iterator->hasNext());
	EXPECT_THROW(iterator->next(), std::out_of_range);
}
