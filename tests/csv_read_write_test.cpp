#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "csv.h"

TEST_CASE("test read data", "[csv]") {
    using csv_processor = mc::csv_processor<std::string>;
    using table_t = mc::table_t<std::string>;
    
    csv_processor _csv;
    table_t table;
    REQUIRE_NOTHROW(table = _csv.read("example.csv", ';'));
}

TEST_CASE("test write data", "[csv]") {
    using csv_processor = mc::csv_processor<std::string>;
    using table_t = mc::table_t<std::string>;
    
    table_t table({"column1", "column2", "column3", "column4"});
    table.insert_row({"cell11", "cell12", "cell13", "cell14"});
    table.insert_row({"cell21", "cell22", "cell23", "cell24"});
    table.insert_row({"cell31", "cell32", "cell33", "cell34"});
    
    csv_processor _csv;
    REQUIRE_NOTHROW(_csv.write(table, "example_write.csv", ';'));
}