import pytest
from iterator import ConcreteAggregate, ConcreteIterator


def test_iterator_traversal():
	"""
	Test traversing a collection using the ConcreteIterator.
	"""
	aggregate = ConcreteAggregate[str]()
	aggregate.add_item("Element 1")
	aggregate.add_item("Element 2")
	aggregate.add_item("Element 3")

	iterator = aggregate.create_iterator()

	assert iterator.has_next()
	assert iterator.next() == "Element 1"

	assert iterator.has_next()
	assert iterator.next() == "Element 2"

	assert iterator.has_next()
	assert iterator.next() == "Element 3"

	assert not iterator.has_next()
	with pytest.raises(StopIteration):
		iterator.next()


def test_empty_collection():
	"""
	Test iterating over an empty collection.
	"""
	aggregate = ConcreteAggregate[int]()
	iterator = aggregate.create_iterator()

	assert not iterator.has_next()
	with pytest.raises(StopIteration):
		iterator.next()


def test_multiple_data_types():
	"""
	Test the iterator with collections of different data types.
	"""
	# Integers
	int_aggregate = ConcreteAggregate[int]()
	int_aggregate.add_item(1)
	int_aggregate.add_item(2)

	int_iterator = int_aggregate.create_iterator()
	assert int_iterator.next() == 1
	assert int_iterator.next() == 2

	# Strings
	str_aggregate = ConcreteAggregate[str]()
	str_aggregate.add_item("a")
	str_aggregate.add_item("b")

	str_iterator = str_aggregate.create_iterator()
	assert str_iterator.next() == "a"
	assert str_iterator.next() == "b"
