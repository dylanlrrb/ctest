#include "../ctest.h"
#include "./mock_tests.h"
#include "./arith_tests.h"

int tests_run = 0;
int tests_passed = 0;
int tests_failed = 0;
int tests_skipped = 0;
 
static int all_tests() {
  run_suite("Basic tests", mock_test_suite);
  run_suite("Arithmatic function tests", arith_test_suite);
  return 0;
}

int main(int argc, char **argv) {
  ctest(all_tests);
  // don't actually need a return value when using ctest macro
}