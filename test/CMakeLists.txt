include(include_local_cpputest_git_repo.cmake)

add_executable(appTestRunner appTestRunner.cpp)
target_link_libraries(
  appTestRunner
  PUBLIC
  CppUTest
  App
)
