sources = ['sub_tests.cpp']

sub_test_deps=[
  boost_dep
]
sub_tests= executable ('sub_tests',
    [ sources, test_main ], 
    include_directories: [inc],
    dependencies:[sub_test_deps+test_deps],
    link_with: [test_dep_libs])

test ('sub_tests', sub_tests,args: ['--gtest_repeat=1000'])
