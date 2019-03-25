#include "../ctest.h"
#include "../deps/arith.h"

char *
test_sum ()
{
  group_label("Addition tests:");

  
  assert_equality (
    "1 + 1 should equal two",
    "float",
    sum(1., 1.),
    2.
  );

  xassert_equality (
    "10 + 10 should equal 20",
    "float",
    sum(10., 10.),
    20.
  );
  return 0;
}

char *
test_sub ()
{
  group_label("Subtraction tests:");

  assert_equality (
    "5 - 3 should equal 2",
    "float",
    sub(5., 3.),
    2.
  );

  assert_equality (
    "10 - 100 should equal -90",
    "float",
    sub(10., 100.),
    -90.
  );
  return 0;
}

char *
test_div ()
{
  group_label("Division tests:");

  assert_equality (
    "5 / 2 should equal 2.5",
    "float",
    div(5., 2.),
    2.5
  );

  assert_equality (
    "12 / 6 should equal 2",
    "float",
    div(12., 6.),
    2.
  );
  return 0;
}

char *
test_multi ()
{
  group_label("Multiplication tests:");

  assert_equality (
    "10 * 8 should equal 80",
    "float",
    mult(10, 8),
    80.
  );

  assert_equality (
    "10 * -8 should equal -80",
    "float",
    mult(10., -8.),
    -80.
  );
  return 0;
}

char *
test_mod ()
{
  group_label("Modulo tests:");
  
  assert_equality (
    "7 % 3 should equal 1",
    "int",
    mod(7, 3),
    1
  );

  assert_equality (
    "1000 % 2 should equal 0",
    "int",
    mod(1000, 2),
    0
  );
  return 0;
}

//--------------------------

char *
arith_test_suite ()
{
  run_test(test_sum);
  run_test(test_sub);
  run_test(test_div);
  run_test(test_multi);
  run_test(test_mod);
  return 0;
}
