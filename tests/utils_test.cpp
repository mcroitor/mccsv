#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "_utils_.h"

TEST_CASE("split function with std::string", "[split]") {
    using mc::explode;

    std::string pattern = "this is a string";
    std::deque<std::string> result = explode(pattern, ' ');

    REQUIRE(result.size() == 4);
    REQUIRE(result[0] == "this");
    REQUIRE(result[1] == "is");
    REQUIRE(result[2] == "a");
    REQUIRE(result[3] == "string");
}

TEST_CASE("split function with std::wstring", "[split]") {
    using mc::explode;

    std::wstring pattern = L"yet;another;string";
    std::deque<std::wstring> result = explode(pattern, L';');

    REQUIRE(result.size() == 3);
    REQUIRE(result[0] == L"yet");
    REQUIRE(result[1] == L"another");
    REQUIRE(result[2] == L"string");
}

TEST_CASE("merge function with std::string", "[merge]") {
    std::deque<std::string> pattern = {"this", "is", "a", "string"};
    std::string result = mc::implode(pattern, ' ');

    REQUIRE(result == "this is a string");
}

TEST_CASE("merge function with std::wstring", "[merge]") {
    std::deque<std::wstring> pattern = {L"this", L"is", L"a", L"string"};
    std::wstring result = mc::implode(pattern, L' ');

    REQUIRE(result == L"this is a string");
}