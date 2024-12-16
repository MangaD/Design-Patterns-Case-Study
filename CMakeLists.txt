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

	# Collect all source and test files in the directory
	file(GLOB SOURCES "${SRC_DIR}/*.cpp")

	# Add the test executable
	add_executable(${snake_case_pattern_name}_test ${SOURCES})
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
add_design_pattern(ObjectPool Creational)
add_design_pattern(Adapter Structural)
add_design_pattern(Bridge Structural)
add_design_pattern(Composite Structural)
add_design_pattern(Decorator Structural)
add_design_pattern(Facade Structural)
add_design_pattern(Flyweight Structural)
add_design_pattern(Proxy Structural)
add_design_pattern(ChainOfResponsibility Behavioral)
add_design_pattern(Command Behavioral)
add_design_pattern(Iterator Behavioral)
add_design_pattern(Mediator Behavioral)
add_design_pattern(Memento Behavioral)
add_design_pattern(Observer Behavioral)
add_design_pattern(State Behavioral)
add_design_pattern(Strategy Behavioral)
add_design_pattern(TemplateMethod Behavioral)
add_design_pattern(Visitor Behavioral)
# Add more patterns as needed
# Example: add_design_pattern(Bridge Structural)
