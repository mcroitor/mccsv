#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "_types_.h"

TEST_CASE("init variables", "[types]") {

    SECTION("cell_t") {

        SECTION("string") {
            using cell_t = mc::cell_t<std::string>;
            REQUIRE(std::is_same<cell_t, std::string>::value);
            cell_t cell{"a word"};
            REQUIRE(cell == "a word");
        }

        SECTION("wstring") {
            using wcell_t = mc::cell_t<std::wstring>;
            REQUIRE(std::is_same<wcell_t, std::wstring>::value);
            wcell_t wcell{L"a word"};
            REQUIRE(wcell == L"a word");
        }

    }

    SECTION("row_t") {
        using row_t = mc::row_t<std::string>;
        REQUIRE(std::is_same<row_t, std::deque<std::string> >::value);
        row_t row = {"this", "is", "a", "row"};

        REQUIRE(row.size() == 4);
        REQUIRE(row[0] == "this");
        REQUIRE(row[1] == "is");
        REQUIRE(row[2] == "a");
        REQUIRE(row[3] == "row");
    }

    SECTION("column_t") {
        using column_t = mc::column_t<std::string>;
        column_t empty_column{"empty column"};

        REQUIRE(empty_column.name() == "empty column");
        REQUIRE(empty_column.size() == 0);

        column_t a_column = {"a column",
            {"yet", "another", "data"}};

        REQUIRE(a_column.name() == "a column");
        REQUIRE(a_column.size() == 3);
        REQUIRE(a_column[0] == "yet");
        REQUIRE(a_column[1] == "another");
        REQUIRE(a_column[2] == "data");

        a_column.insert("oops");
        REQUIRE(a_column.size() == 4);
        REQUIRE(a_column[3] == "oops");

        a_column.insert("oops", 1);
        REQUIRE(a_column.size() == 5);
        REQUIRE(a_column[0] == "yet");
        REQUIRE(a_column[1] == "oops");
        REQUIRE(a_column[2] == "another");
        REQUIRE(a_column[3] == "data");
        REQUIRE(a_column[4] == "oops");

    }

    SECTION("table_t") {
        using table_t = mc::table_t<std::string>;

        SECTION("default constructor") {
            table_t aTable;

            REQUIRE(aTable.nr_columns() == 0);
            REQUIRE(aTable.nr_rows() == 0);
        }
        
        SECTION("constructor with column headers") {
            table_t aTable({"first column", "second column"});

            REQUIRE(aTable.nr_columns() == 2);
            REQUIRE(aTable.nr_rows() == 0);
            REQUIRE(aTable.header()[0] == "first column");
            REQUIRE(aTable.header()[1] == "second column");
        }
    }
}