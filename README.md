# CTest

This repo contains a simple test framework ctest.h

It also contains example usage for writing basic tests and testing some dependencies which can be used as a template for writing unit tests

run `make test` to run the tests or `make test-ci` to run regardless changes to dependencies

Example tests are in the /tests directory. The makefile also outlines some useful targets/recipies for running the tests

Add an 'x' to the begining of any assetion to skip it in the test suite (e.g assert_equality -> xassert_equality)

`watch` will have to be installed for the continuous tesing/ compilation recipes to work properly (e.g. `make test-watch`): https://github.com/dylanlrrb/watch

PR's are welcome!
