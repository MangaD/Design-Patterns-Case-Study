import os

def generate_pattern_rst_files(base_dir, category, output_dir):
	"""
	Generate individual .rst files for each design pattern and the main category file.

	:param base_dir: The base directory containing the design patterns.
	:param category: The category name (e.g., Behavioral, Structural, Creational).
	:param output_dir: The directory to write the generated .rst files.
	"""
	category_dir = os.path.join(base_dir, category)
	patterns = sorted(os.listdir(category_dir))
	patterns = [p for p in patterns if os.path.isdir(os.path.join(category_dir, p))]

	# Create directory for .rst files if it doesn't exist
	os.makedirs(output_dir, exist_ok=True)

	# Generate individual .rst files
	for pattern in patterns:
		pattern_rst_path = os.path.join(output_dir, f"{pattern.lower()}_pattern.rst")
		with open(pattern_rst_path, 'w') as pattern_rst_file:
			pattern_rst_file.write(".. toctree::\n")
			pattern_rst_file.write("   :hidden:\n\n")
			pattern_rst_file.write(f".. include:: ../../{category}/{pattern}/README.md\n")
			pattern_rst_file.write("   :parser: myst_parser.sphinx_\n")

	# Generate the category .rst file
	category_rst_path = os.path.join(output_dir, f"{category.lower()}_patterns.rst")
	with open(category_rst_path, 'w') as category_rst_file:
		category_rst_file.write(f"{category} Patterns\n")
		category_rst_file.write("=" * (len(category) + 9) + "\n\n")
		category_rst_file.write(f"These patterns focus on {get_category_description(category)}.\n\n")
		category_rst_file.write(".. toctree::\n")
		category_rst_file.write("   :maxdepth: 1\n\n")

		for pattern in patterns:
			category_rst_file.write(f"   {pattern.lower()}_pattern\n")


def get_category_description(category):
	"""
	Return a brief description for each category.

	:param category: The category name.
	:return: A description string.
	"""
	descriptions = {
		"Behavioral": "communication between objects",
		"Structural": "structural relationships and composition",
		"Creational": "object creation mechanisms",
	}
	return descriptions.get(category, "various design aspects")


if __name__ == "__main__":
	# Base directory for the design patterns
	base_dir = os.path.abspath("../../")
	output_dir = os.path.abspath("./")  # Current directory for generated .rst files

	# Generate .rst files for each category
	for category in ["Behavioral", "Structural", "Creational"]:
		generate_pattern_rst_files(base_dir, category, output_dir)
