sources = ['mul_tests.cpp']

mul_test_deps=[
  boost_dep
]
mul_tests= executable ('mul_tests',
    [ sources, test_main ], 
    include_directories: [inc],
    dependencies:[mul_test_deps+test_deps],
    link_with: [test_dep_libs])

test ('mul_tests', mul_tests,args: ['--gtest_repeat=1000'])
