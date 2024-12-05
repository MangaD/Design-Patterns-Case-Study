#ifndef PROXY_HPP
#define PROXY_HPP

#include <iostream>
#include <memory>
#include <string>

namespace proxy_pattern {

	/**
	 * @brief The Subject interface defines the common operations for the Proxy and RealSubject.
	 */
	class Subject {
	public:
		virtual ~Subject() = default;

		/**
		 * @brief Handles the request in a format expected by the client.
		 */
		virtual void request(const std::string& resource) const = 0;
	};

	/**
	 * @brief The RealSubject performs the actual work of handling requests.
	 */
	class RealSubject : public Subject {
	public:
		/**
		 * @brief Handles the request and simulates actual processing.
		 * @param resource The resource being accessed.
		 */
		void request(const std::string& resource) const override {
			std::cout << "RealSubject: Handling request for resource: " << resource << std::endl;
		}
	};

	/**
	 * @brief The Proxy controls access to the RealSubject.
	 *
	 * The Proxy adds additional functionality such as authentication or lazy initialization.
	 */
	class Proxy : public Subject {
	private:
		std::unique_ptr<RealSubject> realSubject; ///< The RealSubject instance, initialized lazily.
		bool isAuthenticated;                     ///< Indicates if the user is authenticated.

	public:
		/**
		 * @brief Constructor initializes the Proxy with authentication status.
		 * @param isAuthenticated Whether the client is authenticated.
		 */
		explicit Proxy(bool isAuthenticated)
			: realSubject(nullptr), isAuthenticated(isAuthenticated) {}

		/**
		 * @brief Handles the request by checking authentication and delegating to RealSubject.
		 * @param resource The resource being requested.
		 */
		void request(const std::string& resource) const override {
			if (!isAuthenticated) {
				std::cout << "Proxy: Access denied. Authentication required to access: " << resource << std::endl;
				return;
			}

			if (!realSubject) {
				std::cout << "Proxy: Initializing RealSubject." << std::endl;
				const_cast<Proxy*>(this)->realSubject = std::make_unique<RealSubject>();
			}

			std::cout << "Proxy: Delegating request to RealSubject." << std::endl;
			realSubject->request(resource);
		}
	};

} // namespace proxy_pattern

#endif // PROXY_HPP
