#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <string>

/**
 * @brief Namespace for the Composite pattern.
 */
namespace composite_pattern {

	/**
	* @brief The Component interface declares common operations for both simple and complex objects.
	*/
	class Component {
	public:
		virtual ~Component() = default;

		/**
		* @brief Performs the operation for the component.
		*/
		virtual void operation() const = 0;

		/**
		* @brief Adds a child component (only meaningful for Composite).
		*/
		virtual void add(std::shared_ptr<Component>) {
			// Default implementation for Leaf (no operation).
			throw std::logic_error("Add operation not supported on leaf.");
		}

		/**
		* @brief Removes a child component (only meaningful for Composite).
		*/
		virtual void remove(std::shared_ptr<Component>) {
			// Default implementation for Leaf (no operation).
			throw std::logic_error("Remove operation not supported on leaf.");
		}

		/**
		* @brief Checks if the component is a composite.
		* @return True if composite, otherwise false.
		*/
		virtual bool isComposite() const {
			return false;
		}
	};

	/**
	* @brief The Leaf class represents the end objects of a composition.
	*
	* A Leaf cannot have any children. It implements the base Component interface.
	*/
	class Leaf : public Component {
	private:
		std::string name; ///< The name of the leaf for identification.

	public:
		/**
		* @brief Constructs a Leaf with a given name.
		* @param name The name of the leaf.
		*/
		explicit Leaf(const std::string& name) : name(name) {}

		/**
		* @brief Performs the operation specific to the Leaf.
		*/
		void operation() const override {
			std::cout << "Leaf: " << name << " operation executed." << std::endl;
		}
	};

	/**
	* @brief The Composite class represents the complex components that may have children.
	*
	* A Composite object can have both Leaf and other Composite objects as children.
	*/
	class Composite : public Component {
	private:
		std::vector<std::shared_ptr<Component>> children; ///< List of child components.

	public:
		/**
		* @brief Adds a child component to the composite.
		* @param component The child component to add.
		*/
		void add(std::shared_ptr<Component> component) override {
			children.push_back(component);
		}

		/**
		* @brief Removes a child component from the composite.
		* @param component The child component to remove.
		*/
		void remove(std::shared_ptr<Component> component) override {
			children.erase(std::remove(children.begin(), children.end(), component), children.end());
		}

		/**
		* @brief Checks if the component is a composite.
		* @return True, as this is a Composite.
		*/
		bool isComposite() const override {
			return true;
		}

		/**
		* @brief Performs the operation for the composite and delegates to child components.
		*/
		void operation() const override {
			std::cout << "Composite: Executing operation for children:" << std::endl;
			for (const auto& child : children) {
				child->operation();
			}
		}
	};

}  // namespace composite_pattern

#endif // COMPOSITE_HPP
