import os
import re

def generate_python_api_rst():
	# Define base directories for patterns
	base_dirs = {
		'Behavioral': [
			'ChainOfResponsibility',
			'Command',
			'Interpreter',
			'Iterator',
			'Mediator',
			'Memento',
			'Observer',
			'State',
			'Strategy',
			'TemplateMethod',
			'Visitor',
		],
		'Structural': [
			'Adapter',
			'Bridge',
			'Composite',
			'Decorator',
			'Facade',
			'Flyweight',
			'Proxy',
		],
		'Creational': [
			'AbstractFactory',
			'Builder',
			'FactoryMethod',
			'ObjectPool',
			'Prototype',
			'Singleton',
		],
	}

	# Helper function to convert PascalCase to snake_case
	def to_snake_case(name):
		return re.sub(r'(?<!^)(?=[A-Z])', '_', name).lower()

	# Paths to root directories
	root_dir = os.path.abspath('../../')
	docs_dir = os.path.join(root_dir, 'docs/source')

	# Prepare main python_api.rst content
	python_api_rst_content = [
		"Python API Documentation",
		"=========================",
		"",
	]

	# Generate individual .rst files and categorize
	for category, patterns in base_dirs.items():
		python_api_rst_content.append(f"{category} Patterns")
		python_api_rst_content.append(f"{'-' * len(f'{category} Patterns')}")
		python_api_rst_content.append("")
		python_api_rst_content.append(".. toctree::")
		python_api_rst_content.append("   :maxdepth: 2")
		python_api_rst_content.append("")
		
		for pattern in patterns:
			pattern_dir = os.path.join(root_dir, category, pattern, 'python')
			if not os.path.exists(pattern_dir):
				continue

			# Convert pattern name to snake_case
			snake_case_name = to_snake_case(pattern)

			# Define .rst file for the pattern
			pattern_rst_file = os.path.join(docs_dir, f"{snake_case_name}_api.rst")
			with open(pattern_rst_file, 'w') as rst_file:
				# Write content for individual pattern .rst
				rst_file.write(f"{pattern} API Documentation\n")
				rst_file.write(f"{'=' * (len(pattern) + 20)}\n\n")
				rst_file.write(f".. automodule:: {category}.{pattern}.python.{snake_case_name}\n")
				rst_file.write("   :members:\n")
				rst_file.write("   :undoc-members:\n")
				rst_file.write("   :show-inheritance:\n")
				rst_file.write("\n")

			# Add to main python_api.rst
			relative_rst_path = os.path.relpath(pattern_rst_file, docs_dir)
			python_api_rst_content.append(f"   {relative_rst_path.replace('.rst', '')}")

		python_api_rst_content.append("")  # Add spacing between categories

	# Write the main python_api.rst file
	python_api_rst_path = os.path.join(docs_dir, 'python_api.rst')
	with open(python_api_rst_path, 'w') as python_api_rst_file:
		python_api_rst_file.write("\n".join(python_api_rst_content))
