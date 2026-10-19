include(include_local_cpputest_git_repo.cmake)

add_executable(appTestRunner appTestRunner.cpp ../src/App.c)
target_include_directories(appTestRunner PUBLIC ../src/include include)
target_link_libraries(
  appTestRunner
  PUBLIC
  CppUTest
  CppUTestExt
)

add_executable(utilTestRunner utilTestRunner.cpp ../src/Util.c)
target_include_directories(utilTestRunner PUBLIC ../src/include)
target_link_libraries(
  utilTestRunner
  PUBLIC
  CppUTest
  CppUTestExt
)
