#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "_utils_.h"

TEST_CASE("split function with std::string", "[split]") {
    using mc::split;

    std::string pattern = "this is a string";
    std::deque<std::string> result = split(pattern, ' ');

    REQUIRE(result.size() == 4);
    REQUIRE(result[0] == "this");
    REQUIRE(result[1] == "is");
    REQUIRE(result[2] == "a");
    REQUIRE(result[3] == "string");
}

TEST_CASE("split function with std::wstring", "[split]") {
    using mc::split;

    std::wstring pattern = L"yet;another;string";
    std::deque<std::wstring> result = split(pattern, L';');

    REQUIRE(result.size() == 3);
    REQUIRE(result[0] == L"yet");
    REQUIRE(result[1] == L"another");
    REQUIRE(result[2] == L"string");
}