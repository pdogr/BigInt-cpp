all_test_deps = []
all_test_dep_libs = []
all_test_sources = []

cxx = meson.get_compiler('cpp')

gtest_dep = gtest_proj.get_variable('gtest_dep')
threads_dep=dependency('threads')

boost_dep=dependency('boost',
    version: '>=1.76')

test_deps=[
  gtest_dep,
  threads_dep
]

test_dep_libs=[
  library('test_utils',
  sources:['test_utils.cpp','test_utils.h']),
  bigint_lib
]

test_main=files('tests_main.cpp')

subdir('init_tests')
subdir('add_tests')
subdir('sub_tests')
subdir('mul_tests')
subdir('cmp_tests')

project_test_sources += test_main
all_test_deps+=test_deps
all_test_dep_libs+=test_dep_libs

