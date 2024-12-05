#ifndef FLYWEIGHT_HPP
#define FLYWEIGHT_HPP

#include <string>
#include <unordered_map>
#include <iostream>
#include <memory>

/**
 * @brief Abstract Flyweight defines the interface for concrete flyweights.
 */
class Flyweight {
public:
	virtual ~Flyweight() = default;

	/**
	 * @brief Operation performed by the Flyweight.
	 * @param extrinsicState The extrinsic state passed by the client.
	 */
	virtual void operation(const std::string& extrinsicState) const = 0;
};

/**
 * @brief ConcreteFlyweight implements the Flyweight interface.
 *
 * It contains the intrinsic state, which is shared between multiple objects.
 */
class ConcreteFlyweight : public Flyweight {
private:
	std::string intrinsicState; ///< The intrinsic state of the Flyweight.

public:
	/**
	 * @brief Constructor to initialize the intrinsic state.
	 * @param state The intrinsic state of the Flyweight.
	 */
	explicit ConcreteFlyweight(const std::string& state) : intrinsicState(state) {}

	/**
	 * @brief Implements the Flyweight operation using both intrinsic and extrinsic states.
	 * @param extrinsicState The extrinsic state passed by the client.
	 */
	void operation(const std::string& extrinsicState) const override {
		std::cout << "ConcreteFlyweight with intrinsic state: " << intrinsicState
		          << " and extrinsic state: " << extrinsicState << std::endl;
	}
};

/**
 * @brief FlyweightFactory manages the Flyweight objects and ensures their reuse.
 */
class FlyweightFactory {
private:
	std::unordered_map<std::string, std::shared_ptr<Flyweight>> flyweights; ///< Map of intrinsic state to Flyweight instances.

public:
	/**
	 * @brief Retrieves a Flyweight instance with the given intrinsic state.
	 *        If no such instance exists, it creates one.
	 * @param intrinsicState The intrinsic state of the Flyweight.
	 * @return A shared pointer to the Flyweight instance.
	 */
	std::shared_ptr<Flyweight> getFlyweight(const std::string& intrinsicState) {
		auto it = flyweights.find(intrinsicState);
		if (it == flyweights.end()) {
			auto flyweight = std::make_shared<ConcreteFlyweight>(intrinsicState);
			flyweights[intrinsicState] = flyweight;
			std::cout << "Creating new Flyweight with intrinsic state: " << intrinsicState << std::endl;
			return flyweight;
		}
		std::cout << "Reusing existing Flyweight with intrinsic state: " << intrinsicState << std::endl;
		return it->second;
	}

	/**
	 * @brief Displays all intrinsic states managed by the factory.
	 */
	void listFlyweights() const {
		std::cout << "Flyweights in factory: ";
		for (const auto& pair : flyweights) {
			std::cout << pair.first << " ";
		}
		std::cout << std::endl;
	}
};

#endif // FLYWEIGHT_HPP
