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

# Enable the Doxygen module
find_package(Doxygen)

# Configure Doxygen options
set(DOXYGEN_PROJECT_NAME "Design Patterns Case Study - C++")
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/docs/doxygen)
set(DOXYGEN_XML_OUTPUT ${CMAKE_SOURCE_DIR}/docs/doxygen/xml)
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_GENERATE_XML YES)  # Required for Breathe
set(DOXYGEN_GENERATE_LATEX NO)
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_EXTRACT_PRIVATE YES)
set(DOXYGEN_EXTRACT_STATIC YES)
set(DOXYGEN_EXTRACT_LOCAL_CLASSES YES)
set(DOXYGEN_FULL_PATH_NAMES YES)
set(DOXYGEN_RECURSIVE YES)
set(DOXYGEN_STRIP_FROM_PATH ${CMAKE_SOURCE_DIR})
set(DOXYGEN_GENERATE_TREEVIEW YES)

# Restrict files to only C++ sources and headers
set(DOXYGEN_FILE_PATTERNS "*.cpp" "*.hpp")

if (DOXYGEN_FOUND)
	message(STATUS "-- Doxygen documentation enabled through 'doxygen' target.")

	# Add a target for generating documentation
	doxygen_add_docs(doc
		${CMAKE_SOURCE_DIR}/Creational
		${CMAKE_SOURCE_DIR}/Structural
		${CMAKE_SOURCE_DIR}/Behavioral
		COMMENT "Generating API documentation with Doxygen"
	)
endif()

# Collect all Java source files
file(GLOB_RECURSE JAVA_SOURCES
	"${CMAKE_SOURCE_DIR}/Creational/*.java"
	"${CMAKE_SOURCE_DIR}/Structural/*.java"
	"${CMAKE_SOURCE_DIR}/Behavioral/*.java"
)

# Filter out test files
list(FILTER JAVA_SOURCES EXCLUDE REGEX ".*Test\\.java$")

add_custom_target(javadoc
	COMMAND javadoc -d ${CMAKE_SOURCE_DIR}/docs/javadoc ${JAVA_SOURCES}
	COMMENT "Generating Java documentation with Javadoc"
	VERBATIM
)

add_custom_target(sphinx
	#COMMAND ${CMAKE_COMMAND} --build . --target doc  # Generate Doxygen docs
	COMMAND sphinx-build -b html ${CMAKE_SOURCE_DIR}/docs/source ${CMAKE_SOURCE_DIR}/docs/build
	COMMENT "Generating Python documentation with Sphinx"
	VERBATIM
)


add_custom_target(all_docs
	DEPENDS doc javadoc sphinx
	COMMENT "Generating documentation for all languages"
)