#include <CppUTest/CommandLineTestRunner.h>
#include "UtilTest.cpp"

int main(int argc, char* argv[]){
  return CommandLineTestRunner::RunAllTests(argc, argv);
}
