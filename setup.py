from distutils.core import setup, Extension


sfc_module = Extension('scoulib',
                       include_dirs=['./include/scoulib/'],
                       sources=['python/scoulib.c', 'src/hello.c'])

setup(name='scoulib', version='0.0.1',
      description='An extension module for sediment acoustics',
      ext_modules=[sfc_module]
      )
