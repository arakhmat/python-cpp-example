from distutils.core import setup, Extension
import glob

cppstring = Extension(
    'cppstring',
    define_macros=[],
    include_dirs=['include', '/usr/local/include'],
    libraries=[],
    library_dirs=['/usr/local/lib'],
    sources=glob.glob('src/*.cpp'),
    extra_compile_args=['-MMD', '-MP', '-g', '-std=c++11'])

setup(
    name='cppstring',
    version='1.0',
    description='Example package',
    scripts=['scripts/pysplit', 'scripts/pyjoin'],
    packages=['pystring'],
    ext_modules=[cppstring])
