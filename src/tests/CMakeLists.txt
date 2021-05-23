cmake_minimum_required(VERSION 2.8.12)

set(Sources 
	matrix_tests.cpp
)

add_executable(tests ${Sources})
target_link_libraries(tests PUBLIC gtest_main Mathsml)
add_test(
	NAME tests
	COMMAND tests
)