# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# Configuration file for the Sphinx documentation builder.

import os
import shutil
import sys
import subprocess
from datetime import datetime

# Add the directory containing conf.py to the Python path
sys.path.insert(0, os.path.abspath(os.path.dirname(__file__)))

from generate_python_api import generate_python_api_rst
from generate_pattern_rst import generate_pattern_rst_files
from generate_cpp_rst import generate_cpp_rst

for category in ["Behavioral","Structural", "Creational"]:
	generate_pattern_rst_files(
		base_dir="../../",  # Adjust if needed based on the relative path
		category=category,
		output_dir="./"  # Current directory for generated .rst files
	)

# Add the root directory of the project and its subdirectories to the Python path
sys.path.insert(0, os.path.abspath('../../'))

generate_python_api_rst()

# -- Generate RST files for Markdown files ------------------------------

with open("./introduction.gen.rst", 'w') as introduction_rst_file:
	introduction_rst_file.write(".. toctree::\n")
	introduction_rst_file.write("   :hidden:\n\n")
	introduction_rst_file.write(".. include:: ../../README.md\n")
	introduction_rst_file.write("   :parser: myst_parser.sphinx_")

with open("./gof.gen.rst", 'w') as gof_rst_file:
	gof_rst_file.write(".. toctree::\n")
	gof_rst_file.write("   :hidden:\n\n")
	gof_rst_file.write(".. include:: ../../GoF.md\n")
	gof_rst_file.write("   :parser: myst_parser.sphinx_")

with open("./references.gen.rst", 'w') as references_rst_file:
	references_rst_file.write("References\n")
	references_rst_file.write("==========\n\n")
	references_rst_file.write("1. Gamma, E., Helm, R., Johnson, R., & Vlissides, J. (1994). *Design Patterns: Elements of Reusable Object-Oriented Software*. Addison-Wesley.\n")
	references_rst_file.write("2. Official Python Documentation: https://docs.python.org/3/\n")
	references_rst_file.write("3. Sphinx Documentation: https://www.sphinx-doc.org/\n")
	references_rst_file.write("4. GoogleTest Documentation: https://github.com/google/googletest\n")
	references_rst_file.write("5. Javadoc Documentation: https://docs.oracle.com/en/java/javase/17/docs/specs/javadoc.html\n")
	references_rst_file.write("6. Doxygen Documentation: https://www.doxygen.nl/\n")

# -- Run CMake to Generate Doxygen Documentation ------------------------------
def generate_doxygen_docs():
	# Define the build directory
	build_dir = os.path.abspath("../../build")

	# Ensure the build directory exists
	os.makedirs(build_dir, exist_ok=True)

	# Run CMake to configure and build the Doxygen target
	try:
		subprocess.check_call(["cmake", "-B", build_dir, "-S", os.path.abspath("../../")])
		subprocess.check_call(["cmake", "--build", build_dir, "--target", "doc"])
	except subprocess.CalledProcessError as e:
		print(f"Error while running CMake or building Doxygen: {e}")
		raise

generate_doxygen_docs()

# Generate C++ RST files
generate_cpp_rst(
	base_dir="../../",  # Adjust based on your directory structure
	output_dir="./",    # Output directory for .rst files
	suffix=".gen.rst"   # Custom suffix for generated files
)

# -- Run CMake to Generate JavaDoc Documentation ------------------------------
def generate_javadoc():
	"""
	Generate Javadoc documentation.
	"""
	# Define the build directory
	build_dir = os.path.abspath("../../build")

	# Ensure the build directory exists
	os.makedirs(build_dir, exist_ok=True)

	# Run CMake to configure and build the Doxygen target
	try:
		subprocess.check_call(["cmake", "-B", build_dir, "-S", os.path.abspath("../../")])
		subprocess.check_call(["cmake", "--build", build_dir, "--target", "javadoc"])
	except subprocess.CalledProcessError as e:
		print(f"Error while running CMake or building JavaDoc: {e}")
		raise

	# Copy the generated Javadoc to the build/html directory
	src_javadoc_dir = os.path.abspath("../javadoc")
	dest_javadoc_dir = os.path.join(os.path.abspath('..'), 'build', 'html', 'javadoc')
	if os.path.exists(dest_javadoc_dir):
		shutil.rmtree(dest_javadoc_dir)
	shutil.copytree(src_javadoc_dir, dest_javadoc_dir)
	print(f"Copied Javadoc to {dest_javadoc_dir}")

# Ensure the javadoc directory exists before building
def ensure_javadoc_dir():
	javadoc_dir = os.path.join(os.path.abspath('.'), 'javadoc')
	if not os.path.exists(javadoc_dir):
		os.makedirs(javadoc_dir)

ensure_javadoc_dir()

# Call the Javadoc generation function
generate_javadoc()

# -- Project information -----------------------------------------------------
project = 'Design Patterns Case Study'
author = 'David Gonçalves'
copyright = f'{datetime.now().year}, {author}'
release = '1.0.0'

# -- General configuration ---------------------------------------------------

extensions = [
	'myst_parser',              # Markdown support
	'sphinx.ext.autodoc',       # Auto-generate Python documentation
	'sphinx_autodoc_typehints', # Automatically document type hints
	'sphinx.ext.napoleon',      # Support for NumPy/Google style docstrings
	'sphinx.ext.viewcode',      # Source code links
	'sphinx.ext.todo',          # TODOs in the documentation
	'sphinx.ext.intersphinx',   # Cross-referencing with external docs
	'breathe'                   # Integrate Doxygen with Sphinx
]

myst_enable_extensions = [
	"linkify",      # Convert URLs to clickable links
	"substitution", # Enable text substitution
]

myst_heading_anchors = 3           # Create anchors for headings up to level 3
myst_title_to_header = True        # Use the title as the main heading
myst_update_mathjax = False        # Ensures no conflicting MathJax settings
myst_links_external_new_tab = True # Open links in a new tab

# Autodoc settings
autodoc_member_order = 'bysource'
autodoc_default_options = {
	'members': True,
	'undoc-members': False,
	'show-inheritance': True,
}
autodoc_typehints = "description"  # Show type hints both in the signature and in the description
add_module_names = False    # Remove module names from class signatures

# Napoleon settings for Google-style docstrings
napoleon_google_docstring = True
napoleon_numpy_docstring = False
napoleon_include_init_with_doc = True
napoleon_include_private_with_doc = False
napoleon_use_param = False # already generated by sphinx_autodoc_typehints
napoleon_use_rtype = False # already generated by sphinx_autodoc_typehints

# Breathe configuration
breathe_projects = {
	"Design Patterns C++": os.path.abspath("../doxygen/xml")  # Path to Doxygen XML
}
breathe_default_project = "Design Patterns C++"

# HTML theme options
html_theme = 'sphinx_rtd_theme'
html_theme_options = {
	'navigation_depth': 4,
}

html_static_path = ['_static']  # Leave _static for additional static files

html_js_files = [
	'custom.js',  # Add your custom JavaScript file
]

html_extra_path = ["javadoc"]

# https://sphinx-rtd-theme.readthedocs.io/en/latest/configuring.html
html_context = {
	"display_github": True,                       # Enable the GitHub link
	"github_user": "MangaD",                      # GitHub username
	"github_repo": "Design-Patterns-Case-Study",  # GitHub repository name
	"github_version": "main",                     # Branch name
	"conf_py_path": "/docs/source/",              # Path to the documentation root
	"github_url": "https://github.com/MangaD/Design-Patterns-Case-Study",
	"gitlab_url": "https://gitlab.com/MangaD/design-patterns-case-study"
}

# -- Intersphinx mapping -----------------------------------------------------
intersphinx_mapping = {
	'python': ('https://docs.python.org/3', None),
}

# Default role for inline code
default_role = 'code'
