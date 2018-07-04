from distutils.core import setup, Extension

module = Extension('module', sources=['./module.cpp'])

setup(name='module',
	  version='1.0',
	  description="Module for calculating tanh",
	  ext_modules=[module])