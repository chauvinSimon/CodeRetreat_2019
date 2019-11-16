#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("Testing Hello World") {
  std::string message{"Hello World"};
  CHECK(message == "Hello World");
}
