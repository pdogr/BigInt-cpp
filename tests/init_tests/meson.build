sources=[
  'init_tests.cpp'
]

init_tests=executable('init_tests',
    [sources,test_main],
    include_directories: inc,
    dependencies: [test_deps],
    link_with: [test_dep_libs]
)

test('init_tests',init_tests)

