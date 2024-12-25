import logging
import os
import xml.etree.ElementTree as ET

logging.basicConfig(level=logging.INFO, format="%(asctime)s - %(levelname)s - %(message)s")

PATTERN_CATEGORIES = ["Behavioral", "Creational", "Structural"]

def categorize_file(file_path):
	"""
	Categorize a file based on the 'location' element in the XML file.

	Args:
		file_path (str): Path to the XML file.

	Returns:
		str: The category (Behavioral, Creational, Structural).
	"""
	try:
		tree = ET.parse(file_path)
		root = tree.getroot()

		# Look for the 'location' element inside the 'compounddef'
		compounddef = root.find("./compounddef")
		if compounddef is not None:
			location = compounddef.find("./location")
			if location is not None:
				file_location = location.get("file", "").lower()
				for category in PATTERN_CATEGORIES:
					if category.lower() in file_location:
						return category
	except ET.ParseError:
		logging.warning(f"Could not parse {file_path}. Skipping categorization.")
	except Exception as e:
		logging.error(f"Unexpected error while processing {file_path}: {e}")

	logging.error("Failed to categorize file.")
	raise


def generate_cpp_rst(base_dir, output_dir, suffix=".gen.rst"):
	"""
	Generate .rst files for C++ namespaces, files, and classes from Doxygen XML.
	Organize documentation under Behavioral, Creational, and Structural categories.
	"""
	xml_dir = os.path.abspath(os.path.join(base_dir, "docs/doxygen/xml"))
	output_dir = os.path.abspath(output_dir)

	# Ensure output directory exists
	os.makedirs(output_dir, exist_ok=True)

	# Prepare categorized dictionaries
	categorized_files = {category: [] for category in PATTERN_CATEGORIES}

	# Parse files and categorize them
	for file in os.listdir(xml_dir):
		file_path = os.path.join(xml_dir, file)

		if file.endswith("8hpp.xml") or file.endswith("8cpp.xml"):
			category = categorize_file(file_path)
			title = file.replace("8hpp.xml", " Header").replace("8cpp.xml", " Source").replace("_", " ").title()
			categorized_files[category].append((file.replace(".xml", ""), title))

	for category in categorized_files:
		categorized_files[category].sort()

	for category in PATTERN_CATEGORIES:
		category_dir = os.path.join(output_dir, category)

		# Ensure the subdirectory for the category exists
		os.makedirs(category_dir, exist_ok=True)

		logging.info(f"Generating documentation for {category} patterns...")

		# Generate .rst files for categorized files
		classes, namespaces = generate_file_rst(
			categorized_files[category],
			xml_dir,
			category_dir,
			suffix
		)
		classes = sorted(classes, key=lambda x: x[1])
		namespaces = sorted(namespaces)

		# Generate .rst files for categorized classes and namespaces
		generate_class_rst(classes, category_dir, suffix)
		generate_namespace_rst(namespaces, category_dir, suffix)

		# Generate a summary .rst file for each category
		generate_summary_rst(
			namespaces,
			categorized_files[category],
			classes,
			category_dir,
			suffix,
			title=f"{category} Patterns"
		)

	generate_api_index_rst(output_dir)


def generate_file_rst(files, xml_dir, output_dir, suffix):
	"""Generate .rst files for files."""
	classes: set[tuple[str, str]] = set()
	namespaces: set[str] = set()

	for file, title in files:

		if not os.path.exists(os.path.join(xml_dir, f"{file}.xml")):
			logging.warning(f"Warning: Missing XML file for {file}")
			continue

		rst_path = os.path.join(output_dir, f"{file}{suffix}")
		file_path = os.path.join(xml_dir, f"{file}.xml")

		try:
			tree = ET.parse(file_path)
			root = tree.getroot()
			compounddef = root.find("./compounddef")
			inner_classes = compounddef.findall("./innerclass") if compounddef else []
			inner_namespaces = compounddef.findall("./innernamespace") if compounddef else []

			with open(rst_path, "w") as f:
				f.write(f"{title}\n")
				f.write(f"{'=' * len(title)}\n\n")
				f.write(f".. doxygenfile:: {file.replace('__', '_').replace('_8', '.')}\n")
				f.write("   :project: Design Patterns C++\n")
				f.write("   :no-link:\n\n")

				if inner_classes:
					f.write("Inner Classes\n")
					f.write("-------------\n\n")
					f.write(".. toctree::\n")
					f.write("   :maxdepth: 1\n\n")
					for inner_class in inner_classes:
						refid = inner_class.get("refid")
						if refid:
							classes.add((refid, inner_class.text))
							f.write(f"   {refid}{suffix.replace('.rst', '')}\n")

				if inner_namespaces:
					f.write("\nInner Namespaces\n")
					f.write("----------------\n\n")
					f.write(".. toctree::\n")
					f.write("   :maxdepth: 1\n\n")
					for inner_namespace in inner_namespaces:
						refid = inner_namespace.get("refid")
						if refid:
							namespaces.add((refid, inner_namespace.text))
							f.write(f"   {refid}{suffix.replace('.rst', '')}\n")

			logging.info(f"Generated file: {rst_path}")

		except ET.ParseError as e:
			logging.error(f"Error parsing XML file {file_path}: {e}")
		except Exception as e:
			logging.error(f"Unexpected error while processing {file_path}: {e}")

	return classes, namespaces


def generate_namespace_rst(namespaces, output_dir, suffix):
	"""Generate .rst files for namespaces."""
	for namespace in namespaces:
		rst_path = os.path.join(output_dir, f"{namespace[0].replace('::', '__')}{suffix}")
		title = namespace[1] or f"Unnamed Namespace ({namespace[0]})"

		# Ensure unique .rst file generation
		if os.path.exists(rst_path):
			logging.info(f"Namespace file {rst_path} already exists, skipping...")
			continue

		with open(rst_path, "w") as f:
			f.write(f"{title}\n")
			f.write(f"{'=' * len(title)}\n\n")
			f.write(f".. doxygennamespace:: {title}\n")
			f.write("   :project: Design Patterns C++\n")
			f.write("   :members:\n")  # Optionally include members directive if needed for namespaces

		logging.info(f"Generated namespace file: {rst_path}")


def generate_class_rst(classes, output_dir, suffix):
	"""Generate .rst files for classes."""
	for cls in classes:
		rst_path = os.path.join(output_dir, f"{cls[0].replace('::', '__')}{suffix}")
		title = cls[1]

		# Skip if the .rst file already exists
		if os.path.exists(rst_path):
			logging.info(f"Class file {rst_path} already exists, skipping...")
			continue

		# Generate the .rst file
		with open(rst_path, "w") as f:
			f.write(f"{title}\n")
			f.write(f"{'=' * len(title)}\n\n")
			f.write(f".. doxygenclass:: {title}\n")
			f.write("   :project: Design Patterns C++\n")
			f.write("   :members:\n")

		logging.info(f"Generated class file: {rst_path}")


def generate_summary_rst(namespaces, files, classes, output_dir, suffix, title="Documentation Summary"):
	"""Generate a summary .rst file."""
	summary_rst_path = os.path.join(output_dir, f"{title.replace(' ', '_').lower()}{suffix}")
	with open(summary_rst_path, "w") as f:
		f.write(f"{title}\n")
		f.write(f"{'=' * len(title)}\n\n")

		# Include namespaces
		f.write("Namespaces\n")
		f.write("----------\n\n")
		f.write(".. toctree::\n")
		f.write("   :maxdepth: 1\n\n")
		for namespace in namespaces:
			namespace_rst_name = f"{namespace[0].replace('::', '__')}{suffix}"
			namespace_path = os.path.join(output_dir, namespace_rst_name)
			if os.path.exists(namespace_path):  # Only include existing files
				f.write(f"   {namespace_rst_name.replace('.rst', '')}\n")
			else:
				logging.warning(f"Warning: Namespace .rst file missing for {namespace}")

		# Include files
		f.write("\nFiles\n")
		f.write("-----\n\n")
		f.write(".. toctree::\n")
		f.write("   :maxdepth: 1\n\n")
		for file, _ in files:
			file_path = os.path.join(output_dir, f"{file}{suffix}")
			if os.path.exists(file_path):  # Only include existing files
				f.write(f"   {file}{suffix.replace('.rst', '')}\n")
			else:
				logging.warning(f"Warning: File .rst missing for {file}")

		# Include classes
		f.write("\nClasses\n")
		f.write("-------\n\n")
		f.write(".. toctree::\n")
		f.write("   :maxdepth: 1\n\n")
		for cls in classes:
			class_rst_name = cls[0].replace("::", "__")
			class_path = os.path.join(output_dir, f"{class_rst_name}{suffix}")
			if os.path.exists(class_path):  # Only include existing files
				f.write(f"   {class_rst_name}{suffix.replace('.rst', '')}\n")
			else:
				logging.warning(f"Warning: Class .rst file missing for {cls}")

	logging.info(f"Generated summary file: {summary_rst_path}")


def generate_api_index_rst(output_dir):
	"""
	Generate an index.rst for the categorized C++ API documentation.

	Args:
		output_dir (str): The directory where the index file should be created.
	"""
	# Define the file path for the generated .rst file
	api_index_path = os.path.join(output_dir, "cpp_api_index.gen.rst")

	# Write the content to the .rst file
	with open(api_index_path, "w") as f:
		f.write("C++ API Documentation\n")
		f.write("======================\n\n")
		f.write("The following sections contain categorized C++ patterns:\n\n")
		f.write(".. toctree::\n")
		f.write("   :caption: C++ API Documentation\n")
		f.write("   :maxdepth: 1\n")
		f.write("   :titlesonly:\n\n")
		f.write("   Behavioral Patterns <Behavioral/behavioral_patterns.gen>\n")
		f.write("   Creational Patterns <Creational/creational_patterns.gen>\n")
		f.write("   Structural Patterns <Structural/structural_patterns.gen>\n")

	logging.info(f"Generated API index file: {api_index_path}")
