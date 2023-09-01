#include <doctest/doctest.h>
#include <Visualis/Visualis.h>

using namespace Visualis;

TEST_CASE("Visualis") {
    CHECK(is_installed());
}   