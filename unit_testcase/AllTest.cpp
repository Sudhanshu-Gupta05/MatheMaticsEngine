/*
 * AllTest.cpp
 *
 *  Created on: 28-Jan-2018
 *      Author: sudhanshu
 */


#include <stdio.h>
#include "gtest/gtest.h"

int no_of_params;
char **parameters;

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  no_of_params = argc;
  parameters = argv;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

