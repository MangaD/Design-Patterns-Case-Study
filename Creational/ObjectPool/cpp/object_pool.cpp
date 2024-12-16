#include "object_pool.hpp"

using namespace object_pool_pattern;

// ObjectPool implementation

std::unique_ptr<Reusable> ObjectPool::borrowObject() {
	if (pool.empty()) {
		throw std::runtime_error("No available objects in the pool.");
	}

	auto obj = std::move(pool.front());
	pool.pop();
	return obj;
}

void ObjectPool::returnObject(std::unique_ptr<Reusable> obj) {
	obj->reset();
	pool.push(std::move(obj));
}

void ObjectPool::addObject(std::unique_ptr<Reusable> obj) {
	pool.push(std::move(obj));
}
