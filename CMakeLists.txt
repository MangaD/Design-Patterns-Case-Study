cmake_minimum_required(VERSION 3.10)

# Project name and global settings
project(DesignPatterns LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include GoogleTest
enable_testing()
find_package(GTest REQUIRED)

# Helper function to add a design pattern
function(add_design_pattern pattern_name category)
	# Convert pattern name from UpperCamelCase to snake_case
	string(REGEX REPLACE "([a-z0-9])([A-Z])" "\\1_\\2" snake_case_pattern_name "${pattern_name}")
	string(TOLOWER "${snake_case_pattern_name}" snake_case_pattern_name)

	# Define source and test directories
	set(SRC_DIR ${CMAKE_SOURCE_DIR}/${category}/${pattern_name}/cpp)
	set(SOURCES ${SRC_DIR}/${snake_case_pattern_name}.cpp)
	set(TEST_SOURCES ${SRC_DIR}/test_${snake_case_pattern_name}.cpp)

	# Add the test executable
	add_executable(${snake_case_pattern_name}_test ${TEST_SOURCES} ${SOURCES})
	target_link_libraries(${snake_case_pattern_name}_test PRIVATE GTest::GTest GTest::Main)
	target_compile_options(${snake_case_pattern_name}_test PRIVATE -Wall -Wextra -Werror)

	# Register tests
	add_test(NAME ${snake_case_pattern_name}_Tests COMMAND ${snake_case_pattern_name}_test)
endfunction()

# Add design patterns
add_design_pattern(Singleton Creational)
add_design_pattern(FactoryMethod Creational)
add_design_pattern(AbstractFactory Creational)
add_design_pattern(Builder Creational)
add_design_pattern(Prototype Creational)
# Add more patterns as needed
# Example: add_design_pattern(Bridge Structural)
