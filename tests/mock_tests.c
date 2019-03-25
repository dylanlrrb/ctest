#include "../ctest.h"

double foo = 7.1;
int bar = 6;
char baz = 't';
 
char * test_foo () {
  group_label("test foo:");

  assert_equality("foo should equal 7.1", "double", foo, 7.1);
  return 0;
}
 
char * test_bar () {
  group_label("test bar:");
  
  assert_inequality("bar should not equal 5", "int", bar, 5);
  assert_inequality("bar should not equal 3", "int", bar, 3);
  assert_less_than("bar should be less than 10", "int", bar, 10);
  assert_greater_than("bar should be greater than 4", "int", bar, 4);
  return 0;
}

char * test_baz () {
  group_label("test baz:");

  assert_equality("baz should  equal 't'", "char", baz, 't');
  return 0;
}

// -------------------

char * mock_test_suite () {
  run_test(test_foo);
  run_test(test_bar);
  run_test(test_baz);
  return 0;
}
