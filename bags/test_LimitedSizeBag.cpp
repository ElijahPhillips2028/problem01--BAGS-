#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "LimitedSizeBag.hpp"


TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  REQUIRE(b.add(5) == true);
  
  REQUIRE(b.remove(5) == true);
  REQUIRE(b.isEmpty() == true);
  REQUIRE(b.getCurrentSize() == 0);
  b.clear();
  REQUIRE(b.getFrequencyOf(5) == 0);
  REQUIRE(b.contains(5) == false);
}
