/* file: ctest.h  */
#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_GRAY    "\e[1;30m"
#define ANSI_COLOR_RESET   "\x1b[0m"

extern int tests_run;
extern int tests_passed;
extern int tests_failed;
extern int tests_skipped; 

#define ctest(func) \
  func(); \
  printf("\n----------\n" ANSI_COLOR_CYAN "Tests Executed: %d\n" ANSI_COLOR_RESET, tests_run); \
  printf(ANSI_COLOR_GRAY "Tests Skipped: %d\n" ANSI_COLOR_RESET, tests_skipped); \
  printf(ANSI_COLOR_GREEN "Tests Passed: %d\n" ANSI_COLOR_RESET, tests_passed); \
  printf(ANSI_COLOR_RED "Tests Failed: %d\n" ANSI_COLOR_RESET "----------\n", tests_failed); \
  if (tests_failed > 0) return 1; if (tests_failed == 0) \
    return 0

#define group_label(title) do { \
  printf(ANSI_COLOR_BLUE "  %s\n" ANSI_COLOR_RESET, title); } \
while (0)

#define run_suite(title, func) do { \
  printf("\n" ANSI_COLOR_BLUE "%s\n" ANSI_COLOR_RESET, title); \
  func(); } \
while (0)

#define print_actual(actual, type) do { \
  if (type == "int") printf(ANSI_COLOR_RED "           Actual value: %d\n" ANSI_COLOR_RESET, actual); \
  if (type == "char") printf(ANSI_COLOR_RED "          Actual value: %c\n" ANSI_COLOR_RESET, actual); \
  if (type == "double" || type == "float") printf(ANSI_COLOR_RED "          Actual value: %lf\n" ANSI_COLOR_RESET, actual); \
} while (0)

#define assert_equality(message, type, actual, expected) do { \
  tests_run++; \
  if (!(actual == expected)) printf(ANSI_COLOR_RED "    (failed) %s\n" ANSI_COLOR_RESET, message); \
  if (!(actual == expected)) print_actual(actual, type); \
  if (!(actual == expected)) tests_failed++; \
  if ((actual == expected)) printf(ANSI_COLOR_GREEN "    %s\n" ANSI_COLOR_RESET, message); \
  if ((actual == expected)) tests_passed++;} \
while (0)

#define xassert_equality(message, type, actual, expected) do { \
  printf(ANSI_COLOR_GRAY "    (skipped) %s\n" ANSI_COLOR_RESET, message); \
  tests_skipped++; } \
while (0)

#define assert_inequality(message, type, actual, expected) do { \
  tests_run++; \
  if ((actual == expected)) printf(ANSI_COLOR_RED "    (failed) %s\n" ANSI_COLOR_RESET, message); \
  if ((actual == expected)) print_actual(actual, type); \
  if ((actual == expected)) tests_failed++; \
  if (!(actual == expected)) printf(ANSI_COLOR_GREEN "    %s\n" ANSI_COLOR_RESET, message); \
  if (!(actual == expected)) tests_passed++;} \
while (0)

#define xassert_inequality(message, type, actual, expected) do { \
  printf(ANSI_COLOR_GRAY "    (skipped) %s\n" ANSI_COLOR_RESET, message); \
  tests_skipped++; } \
while (0)

#define assert_greater_than(message, type, actual, expected) do { \
  tests_run++; \
  if (!(actual > expected)) printf(ANSI_COLOR_RED "    (failed) %s\n" ANSI_COLOR_RESET, message); \
  if (!(actual > expected)) print_actual(actual, type); \
  if (!(actual > expected)) tests_failed++; \
  if ((actual > expected)) printf(ANSI_COLOR_GREEN "    %s\n" ANSI_COLOR_RESET, message); \
  if ((actual > expected)) tests_passed++;} \
while (0)

#define xassert_greater_than(message, type, actual, expected) do { \
  printf(ANSI_COLOR_GRAY "    (skipped) %s\n" ANSI_COLOR_RESET, message); \
  tests_skipped++; } \
while (0)

#define assert_less_than(message, type, actual, expected) do { \
  tests_run++; \
  if (!(actual < expected)) printf(ANSI_COLOR_RED "    (failed) %s\n" ANSI_COLOR_RESET, message); \
  if (!(actual < expected)) print_actual(actual, type); \
  if (!(actual < expected)) tests_failed++; \
  if ((actual < expected)) printf(ANSI_COLOR_GREEN "    %s\n" ANSI_COLOR_RESET, message); \
  if ((actual < expected)) tests_passed++;} \
while (0)

#define xassert_less_than(message, type, actual, expected) do { \
  printf(ANSI_COLOR_GRAY "    (skipped) %s\n" ANSI_COLOR_RESET, message); \
  tests_skipped++; } \
while (0)

#define run_test(test) do { \
  char *message = test(); \
  if (message) return message; } \
while (0)
