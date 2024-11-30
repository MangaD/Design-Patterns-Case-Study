#include "object_pool.hpp"
#include "concrete_reusable.hpp"
#include <gtest/gtest.h>

/**
 * @brief Test borrowing and returning objects in the object pool.
 *
 * This test validates the correct borrowing and returning behavior of the 
 * ObjectPool class. It ensures that returned objects can be reused by the pool 
 * without duplicating or recreating objects unnecessarily.
 */
TEST(ObjectPoolTest, BorrowAndReturnObject) {
	ObjectPool pool;

	// Add reusable objects to the pool
	pool.addObject(std::make_unique<ConcreteReusable>("Obj1"));
	pool.addObject(std::make_unique<ConcreteReusable>("Obj2"));

	// Borrow an object from the pool
	auto obj1 = pool.borrowObject();
	obj1->use();

	// Return the object back to the pool
	pool.returnObject(std::move(obj1));

	// Borrow another object and verify reuse
	auto obj2 = pool.borrowObject();
	obj2->use();

	// Ensure obj1 and obj2 are different instances
	EXPECT_NE(obj1.get(), obj2.get());
}

/**
 * @brief Test borrowing from an empty object pool.
 *
 * This test ensures that attempting to borrow an object from an empty pool
 * throws a `std::runtime_error`. It verifies that the pool correctly handles
 * cases where no reusable objects are available.
 */
TEST(ObjectPoolTest, BorrowFromEmptyPool) {
	ObjectPool pool;

	// Attempt to borrow from an empty pool and expect an exception
	EXPECT_THROW(pool.borrowObject(), std::runtime_error);
}

/**
 * @brief Test multiple borrow and return operations in the object pool.
 *
 * This test validates the behavior of the ObjectPool class under multiple 
 * consecutive borrow and return operations. It ensures that objects are 
 * properly reset and can be reused in a predictable manner.
 */
TEST(ObjectPoolTest, MultipleBorrowAndReturn) {
	ObjectPool pool;

	// Add multiple objects to the pool
	pool.addObject(std::make_unique<ConcreteReusable>("Obj1"));
	pool.addObject(std::make_unique<ConcreteReusable>("Obj2"));

	// Borrow objects from the pool
	auto obj1 = pool.borrowObject();
	auto obj2 = pool.borrowObject();

	obj1->use();
	obj2->use();

	// Return the objects back to the pool
	pool.returnObject(std::move(obj1));
	pool.returnObject(std::move(obj2));

	// Borrow again to ensure returned objects are reused
	auto obj3 = pool.borrowObject();
	auto obj4 = pool.borrowObject();

	obj3->use();
	obj4->use();

	// Ensure the objects are not the same as the previously borrowed instances
	EXPECT_NE(obj1.get(), obj3.get());
	EXPECT_NE(obj2.get(), obj4.get());
}
