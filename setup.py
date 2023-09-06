from setuptools import setup, find_packages
import os
import sys

# Add tools directory to PYTHONPATH
sys.path.append(os.path.join(os.path.dirname(__file__), 'tools'))

from build_parser import build_parser

# Run the parser build script
build_parser()

setup(
    name="shell",
    version="0.1",
    packages=find_packages(where="src"),
    package_dir={"": "src"},
    entry_points={
        "console_scripts": [
            "pysh=shell.__main__:main",
        ],
    },
    egg_info={"egg_base": "dist"},
    install_requires=[],
    extras_require={
        "test": ["pytest"],
    },
)
