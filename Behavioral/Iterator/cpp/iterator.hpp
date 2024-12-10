#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <vector>
#include <memory>
#include <stdexcept>

/**
 * @brief Iterator interface for traversing collections.
 * 
 * Defines the methods for sequentially accessing elements.
 */
template<typename T>
class Iterator {
public:
	virtual ~Iterator() = default;

	/**
	 * @brief Check if there are more elements in the collection.
	 * @return True if there are more elements, otherwise false.
	 */
	virtual bool hasNext() const = 0;

	/**
	 * @brief Retrieve the next element in the collection.
	 * @return The next element.
	 * @throws std::out_of_range if there are no more elements.
	 */
	virtual T next() = 0;
};

/**
 * @brief Aggregate interface for creating iterators.
 * 
 * Provides a method to retrieve an iterator for a collection.
 */
template<typename T>
class Aggregate {
public:
	virtual ~Aggregate() = default;

	/**
	 * @brief Create an iterator for the collection.
	 * @return A unique pointer to an iterator.
	 */
	virtual std::unique_ptr<Iterator<T>> createIterator() const = 0;
};

/**
 * @brief Concrete Iterator for traversing a collection.
 * 
 * Implements the Iterator interface and provides traversal logic.
 */
template<typename T>
class ConcreteIterator : public Iterator<T> {
private:
	const std::vector<T>& collection; ///< Reference to the collection being iterated.
	size_t position;                  ///< Current position in the collection.

public:
	/**
	 * @brief Constructor initializes the iterator with a collection.
	 * @param collection The collection to iterate over.
	 */
	explicit ConcreteIterator(const std::vector<T>& collection)
		: collection(collection), position(0) {}

	/**
	 * @brief Check if there are more elements in the collection.
	 * @return True if there are more elements, otherwise false.
	 */
	bool hasNext() const override {
		return position < collection.size();
	}

	/**
	 * @brief Retrieve the next element in the collection.
	 * @return The next element.
	 * @throws std::out_of_range if there are no more elements.
	 */
	T next() override {
		if (!hasNext()) {
			throw std::out_of_range("No more elements in the iterator.");
		}
		return collection[position++];
	}
};

/**
 * @brief Concrete Aggregate that holds a collection of items.
 * 
 * Implements the Aggregate interface and provides a method to create iterators.
 */
template<typename T>
class ConcreteAggregate : public Aggregate<T> {
private:
	std::vector<T> items; ///< Collection of items.

public:
	/**
	 * @brief Add an item to the collection.
	 * @param item The item to add.
	 */
	void addItem(const T& item) {
		items.push_back(item);
	}

	/**
	 * @brief Retrieve the collection's iterator.
	 * @return A unique pointer to a ConcreteIterator.
	 */
	std::unique_ptr<Iterator<T>> createIterator() const override {
		return std::make_unique<ConcreteIterator<T>>(items);
	}
};

#endif // ITERATOR_HPP
