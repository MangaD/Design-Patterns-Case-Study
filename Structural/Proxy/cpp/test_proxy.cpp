#include "proxy.hpp"
#include <gtest/gtest.h>

using namespace proxy_pattern;

/**
 * @brief Test Proxy access with authentication.
 */
TEST(ProxyPatternTest, AccessWithAuthentication) {
	Proxy proxy(true); // Authenticated user

	// Capture standard output
	testing::internal::CaptureStdout();
	proxy.request("Resource1");
	std::string output = testing::internal::GetCapturedStdout();

	// Verify output
	EXPECT_NE(output.find("Proxy: Initializing RealSubject."), std::string::npos);
	EXPECT_NE(output.find("Proxy: Delegating request to RealSubject."), std::string::npos);
	EXPECT_NE(output.find("RealSubject: Handling request for resource: Resource1"), std::string::npos);
}

/**
 * @brief Test Proxy access without authentication.
 */
TEST(ProxyPatternTest, AccessWithoutAuthentication) {
	Proxy proxy(false); // Unauthenticated user

	// Capture standard output
	testing::internal::CaptureStdout();
	proxy.request("Resource2");
	std::string output = testing::internal::GetCapturedStdout();

	// Verify output
	EXPECT_NE(output.find("Proxy: Access denied. Authentication required to access: Resource2"), std::string::npos);
}

/**
 * @brief Test Proxy lazy initialization.
 */
TEST(ProxyPatternTest, LazyInitialization) {
	Proxy proxy(true); // Authenticated user

	// Capture standard output
	testing::internal::CaptureStdout();
	proxy.request("Resource3"); // First access
	std::string output1 = testing::internal::GetCapturedStdout();

	// Verify initialization occurred
	EXPECT_NE(output1.find("Proxy: Initializing RealSubject."), std::string::npos);

	// Capture output for second access
	testing::internal::CaptureStdout();
	proxy.request("Resource4"); // Subsequent access
	std::string output2 = testing::internal::GetCapturedStdout();

	// Verify initialization does not occur again
	EXPECT_EQ(output2.find("Proxy: Initializing RealSubject."), std::string::npos);
}
