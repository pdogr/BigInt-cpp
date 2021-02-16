sources = ['cmp_tests.cpp']

cmp_test_deps=[
  boost_dep
]
cmp_tests= executable ('cmp_tests',
    [ sources, test_main ], 
    include_directories: [inc],
    dependencies:[cmp_test_deps+test_deps],
    link_with: [test_dep_libs])

test ('cmp_tests', cmp_tests,args: ['--gtest_repeat=1000'])
