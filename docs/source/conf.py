# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# Configuration file for the Sphinx documentation builder.

import os
import sys
from datetime import datetime

# Add the directory containing conf.py to the Python path
sys.path.insert(0, os.path.abspath(os.path.dirname(__file__)))

from generate_python_api import generate_python_api_rst

# Add the root directory of the project and its subdirectories to the Python path
sys.path.insert(0, os.path.abspath('../../'))

# Add paths for each design pattern's Python directory
pattern_paths = [
	'../../Behavioral/ChainOfResponsibility/python',
	'../../Behavioral/Command/python',
	'../../Behavioral/Iterator/python',
	'../../Behavioral/Mediator/python',
	'../../Behavioral/Memento/python',
	'../../Behavioral/Observer/python',
	'../../Behavioral/State/python',
	'../../Behavioral/Strategy/python',
	'../../Behavioral/TemplateMethod/python',
	'../../Behavioral/Visitor/python',
	'../../Structural/Adapter/python',
	'../../Structural/Bridge/python',
	'../../Structural/Composite/python',
	'../../Structural/Decorator/python',
	'../../Structural/Facade/python',
	'../../Structural/Flyweight/python',
	'../../Structural/Proxy/python',
	'../../Creational/AbstractFactory/python',
	'../../Creational/Builder/python',
	'../../Creational/FactoryMethod/python',
	'../../Creational/ObjectPool/python',
	'../../Creational/Prototype/python',
	'../../Creational/Singleton/python',
]

# Append all paths dynamically
for path in pattern_paths:
	sys.path.insert(0, os.path.abspath(path))

generate_python_api_rst()

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
add_module_names = False # Remove module names from class signatures

# Napoleon settings
napoleon_google_docstring = True
napoleon_numpy_docstring = False

# HTML theme options
html_theme = 'sphinx_rtd_theme'
html_theme_options = {
	'navigation_depth': 4,
}

html_static_path = ['_static']  # Leave _static for additional static files

html_js_files = [
	'custom.js',  # Add your custom JavaScript file
]

# -- Intersphinx mapping -----------------------------------------------------
intersphinx_mapping = {
	'python': ('https://docs.python.org/3', None),
}

# Default role for inline code
default_role = 'code'

# -- Custom scripts ----------------------------------------------------------

# Build Javadoc
#javadoc_output = os.path.abspath('../../docs/javadoc')
#javadoc_cmd = [
	#'javadoc',
	#'-d', javadoc_output,
	#'-sourcepath', '../../Creational ../../Structural ../../Behavioral',
	#'-subpackages', '.'
#]
#subprocess.call(javadoc_cmd)

# Build Doxygen
#doxygen_output = os.path.abspath('../../docs/doxygen')
#subprocess.call(['doxygen'], cwd='../../')
