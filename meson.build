project('BigInt-cpp', 'cpp',
    version : '1.0',
    license : [ 'MIT'],
    meson_version : '>= 0.56.0',
    default_options : [ 'warning_level=3', 'buildtype=debugoptimized', 'cpp_std=c++17' ]
)


library_path = []
project_sources = []
project_header_files = []
project_test_sources = []

inc=[include_directories('include')]
subdir('include')
subdir('src')

bigint_lib=library('bigint',
      sources: project_sources,
      include_directories: inc)

if get_option('enable-tests')
  gtest_proj = subproject('gtest')
  subdir('tests')
endif


