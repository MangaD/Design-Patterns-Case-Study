#ifndef PROTOTYPE_HPP
#define PROTOTYPE_HPP

#include <string>
#include <memory>

/**
 * @brief Namespace for the Prototype pattern.
 */
namespace prototype_pattern {

	/**
	* @class Prototype
	* @brief Abstract base class for the Prototype pattern.
	*
	* The Prototype class defines an interface for cloning objects and displaying their details.
	*/
	class Prototype {
	public:
		/// @brief Virtual destructor for proper cleanup in derived classes.
		virtual ~Prototype() = default;

		/**
		* @brief Creates a clone of the current object.
		* 
		* This method is implemented by derived classes to return a copy of the current object.
		* 
		* @return A unique pointer to the cloned object.
		*/
		virtual std::unique_ptr<Prototype> clone() const = 0;

		/**
		* @brief Displays the details of the prototype.
		* 
		* This method is implemented by derived classes to provide a textual representation of the object.
		*/
		virtual void display() const = 0;
	};

	/**
	* @class ConcretePrototype1
	* @brief A concrete implementation of the Prototype interface.
	*
	* ConcretePrototype1 represents a specific prototype with a string attribute.
	*/
	class ConcretePrototype1 : public Prototype {
	private:
		std::string attribute; ///< A string attribute unique to this prototype.

	public:
		/**
		* @brief Constructor to initialize the attribute.
		* 
		* @param attribute The value to initialize the prototype's attribute.
		*/
		explicit ConcretePrototype1(const std::string& attribute);

		/**
		* @copydoc Prototype::clone()
		* 
		* @details Creates a new instance of ConcretePrototype1 by copying the current object's attribute.
		*/
		std::unique_ptr<Prototype> clone() const override;

		/**
		* @copydoc Prototype::display()
		* 
		* @details Outputs the value of the attribute.
		*/
		void display() const override;
	};

	/**
	* @class ConcretePrototype2
	* @brief Another concrete implementation of the Prototype interface.
	*
	* ConcretePrototype2 represents a specific prototype with an integer attribute.
	*/
	class ConcretePrototype2 : public Prototype {
	private:
		int attribute; ///< An integer attribute unique to this prototype.

	public:
		/**
		* @brief Constructor to initialize the attribute.
		* 
		* @param attribute The value to initialize the prototype's attribute.
		*/
		explicit ConcretePrototype2(int attribute);

		/**
		* @copydoc Prototype::clone()
		* 
		* @details Creates a new instance of ConcretePrototype2 by copying the current object's attribute.
		*/
		std::unique_ptr<Prototype> clone() const override;

		/**
		* @copydoc Prototype::display()
		* 
		* @details Outputs the value of the attribute.
		*/
		void display() const override;
	};

}  // namespace prototype

#endif // PROTOTYPE_HPP
