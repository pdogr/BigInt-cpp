sources = ['add_tests.cpp']

add_test_deps=[
  boost_dep
]
add_tests= executable ('add_tests',
    [ sources, test_main ], 
    include_directories: [inc],
    dependencies:[add_test_deps+test_deps],
    link_with: [test_dep_libs])

test ('add_tests', add_tests,args: ['--gtest_repeat=1000'])
