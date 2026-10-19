#include <CppUTest/CommandLineTestRunner.h>
#include "AppTest.cpp"
#include "UtilTest.cpp"

int main(int argc, char* argv[]){
  return CommandLineTestRunner::RunAllTests(argc, argv);
}
