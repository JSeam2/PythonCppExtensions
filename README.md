# C Extensions For Python
## Build and Run
To build you can do the following.

1. This will install into your python library package
```
$ pip install .
```

2. Alternatively, for testing we can build locally. 
```
$ python setup.py build
```

3. To build inplace such that the files can be found n the same folder as module.cpp
```
$ python setup.py build_ext --inplace
```

If the build is successful you should be able to do the following
```
$ python
>>> import module
>>> module.fast_tanh(2)
0.9640275800758167
```

## References
 1. https://docs.microsoft.com/en-us/visualstudio/python/working-with-c-cpp-python-in-visual-studio
 2. https://www.youtube.com/watch?v=a65JdvOaygM
 3. https://github.com/mattfowler/PythonCExtensions