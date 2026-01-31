#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "DynamicBag.hpp"


TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;
  REQUIRE(b.add(5) == true);
  REQUIRE(b.remove(5) == true);
  REQUIRE(b.isEmpty() == true);
  REQUIRE(b.getCurrentSize() == 0);
  b.clear();
  REQUIRE(b.getFrequencyOf(5) == 0);
  REQUIRE(b.contains(5) == false);
}
