#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "csv.h"

TEST_CASE("no_header test", "[csv][.]"){
    using mc::operator <<;
    using cell_t = mc::cell_t<std::string>;
    using column_t = mc::column_t<std::string>;
    using row_t = mc::row_t<std::string>;
    using table_t = mc::table_t<std::string>;
    using csv_processor = mc::csv<std::string>;
    
    csv_processor _csv;
    table_t table = _csv.read("no_header.csv", ';', false);
    
    SECTION("check dimensions"){
        REQUIRE(table.nr_columns() == 3);
        REQUIRE(table.nr_rows() == 4);
    }
    
    SECTION("check header"){
        row_t header = table.header();
        REQUIRE(header[0] == "column1");
        REQUIRE(header[1] == "column2");
        REQUIRE(header[2] == "column3");
    }
    
    SECTION("check column 1"){
        column_t column = table.column(1);
        REQUIRE(column[0] == "2");
        REQUIRE(column[1] == "5");
        REQUIRE(column[2] == "8");
        REQUIRE(column[3] == "11");
    }
    
    SECTION("check row 2"){
        row_t row = table.row(2);
        REQUIRE(row[0] == "7");
        REQUIRE(row[1] == "8");
        REQUIRE(row[2] == "9");
    }
}