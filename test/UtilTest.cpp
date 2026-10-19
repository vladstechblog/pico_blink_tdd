extern "C"
{
#include "Util.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Util){};

TEST(Util, AlwaysReturnsTrue){
  CHECK_TRUE(always_true());
}

