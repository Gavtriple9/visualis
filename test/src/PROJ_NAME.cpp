#include <doctest/doctest.h>
#include <PROJ_NAME/PROJ_NAME.h>

TEST_CASE("PROJ_NAME") {
    CHECK(PROJ_NAME::greet() == "Hello World");
}