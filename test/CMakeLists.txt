include(include_local_cpputest_git_repo.cmake)

add_executable(appTestRunner appTestRunner.cpp ../src/App.c ../src/Util.c)
target_include_directories(appTestRunner PUBLIC ../src/include include)
target_link_libraries(
  appTestRunner
  PUBLIC
  CppUTest
  CppUTestExt
)
