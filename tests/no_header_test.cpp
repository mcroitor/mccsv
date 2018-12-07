#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "mccsv.h"

TEST_CASE("no_header test", "[csv]"){
    using mc::deprecated::operator <<;
    using mc::deprecated::cell_t;
    using mc::deprecated::column_t;
    using mc::deprecated::row_t;
    using mc::deprecated::csv;
    
    csv _csv("no_header.csv", ';', false);
    
    SECTION("check dimensions"){
        REQUIRE(_csv.nr_columns() == 3);
        REQUIRE(_csv.nr_rows() == 4);
    }
    
    SECTION("check header"){
        row_t header = _csv.header();
        REQUIRE(header[0] == L"column1");
        REQUIRE(header[1] == L"column2");
        REQUIRE(header[2] == L"column3");
    }
    
    SECTION("check column 1"){
        column_t column = _csv.column(1);
        REQUIRE(column[0] == L"2");
        REQUIRE(column[1] == L"5");
        REQUIRE(column[2] == L"8");
        REQUIRE(column[3] == L"11");
    }
    
    SECTION("check row 2"){
        row_t row = _csv.row(2);
        REQUIRE(row[0] == L"7");
        REQUIRE(row[1] == L"8");
        REQUIRE(row[2] == L"9");
    }
}