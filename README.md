# python-cpp-example
Template of Python Package Extended with C/C++

## Description
This repository shows how to create a Python package and extend it with custom C/C++ code.

## Installation Instructions
```
git clone https://github.com/arakhmat/python-cpp-example;
cd python-cpp-example;
<sudo> python setup.py install <--user>
```
### Test the Installation
```
cd tests
python -m unittest discover -v
```
### Run Command Line Scripts
```
pysplit -s 'blue,red,green' --sep ','
pyjoin -w 'red' 'blue' 'green' -sep ','
```
### Import as Package
```
from pystring import pysplit, pyjoin

s = 'blue,red,green'
sep = ','

words = pysplit(s, sep)
joined_s = pyjoin(words, sep)
```

## Useful Links
### Python 3
[Extending Python with C or C++](https://docs.python.org/3/extending/extending.html)\
[C API](https://docs.python.org/3/c-api/)\
[Parse Arguments From Python in C](https://docs.python.org/3/c-api/arg.html)\
[Return Value from C to Python](https://docs.python.org/3/c-api/arg.html#building-valuesrg/3/c-api/arg.html)

### Python 2
[Extending Python with C or C++](https://docs.python.org/2/extending/extending.html)\
[C API](https://docs.python.org/2/c-api/)\
[Parse Arguments From Python in C](https://docs.python.org/2.0/ext/parseTuple.html)\
[Return Value from C to Python](https://docs.python.org/2.0/ext/buildValue.html)
