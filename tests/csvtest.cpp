/* 
 * File:   csvtest.cpp
 * Author: mcroitor
 *
 * Created on 26 decembrie 2017, 17:00
 */

#include <cstdlib>
#include <iostream>
#include "csv.h"

/*
 * Simple C++ Test Suite
 */

using string = std::string;
typedef mc::csv<string> csv;
using mc::operator<<;

void testRead() {
    std::string filename = "example.csv";
    auto separator = ';';
    csv _csv;
    auto table = _csv.read(filename, separator);
    if (table.nr_columns() != 3) {
        std::cout << "%TEST_FAILED% time=0 testname=testCsv (csvtest) message=invalid columns number" << std::endl;
        return;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testCsv (csvtest) message=passed" << std::endl;
    }
    if (table.nr_rows() != 4) {
        std::cout << "%TEST_FAILED% time=0 testname=testCsv (csvtest) message=invalid rows number" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testCsv (csvtest) message=passed" << std::endl;
    }
}

void testClear() {
    std::string filename = "example.csv";
    auto separator = ';';
    csv _csv;
    auto table = _csv.read(filename, separator);
    table.clear();
    if (table.nr_columns() != 0 || table.nr_rows() != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testClear (csvtest) message=invalid data clearing" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testClear (csvtest) message=passed" << std::endl;
    }
}

void testHeader() {
    std::string filename = "example.csv";
    auto separator = ';';
    csv _csv;
    auto table = _csv.read(filename, separator);
    auto result = table.header();
    if (result.size() != 3) {
        std::cout << "%TEST_FAILED% time=0 testname=testHeader (csvtest) message=invalid columns number" << std::endl;
        std::cout << "result.size() = " << result.size() << std::endl;
        return;
    }
    if (result[0] != "first" || result[1] != "second" || result[2] != "third") {
        std::cout << "%TEST_FAILED% time=0 testname=testHeader (csvtest) message=invalid header reading" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testHeader (csvtest) message=passed" << std::endl;
    }
}

void testRow() {
    size_t p0 = 1;
    std::string filename = "example.csv";
    auto separator = ';';
    csv _csv;
    auto table = _csv.read(filename, separator);
    auto result = table.row(p0);
    if (result.size() != 3) {
        std::cout << "%TEST_FAILED% time=0 testname=testRow (csvtest) message=invalid number of elements in row" << std::endl;
        return;
    }
    if (result[0] != "4" || result[1] != "5" || result[2] != "6") {
        std::cout << "%TEST_FAILED% time=0 testname=testRow (csvtest) message=invalid row reading" << std::endl;
        std::cout << result << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testRow (csvtest) message=passed" << std::endl;
    }
}

void testColumn() {
    string header_name = "second";
    std::string filename = "example.csv";
    auto separator = ';';
    csv _csv;
    auto table = _csv.read(filename, separator);
    auto result = table.column(header_name);
    if (result.size() != 4) {
        std::cout << "%TEST_FAILED% time=0 testname=testColumn (csvtest) message=invalid number of elements in column" << std::endl;
        return;
    }
    if (result[0] != "2" || result[1] != "5" || result[2] != "8" || result[3] != "11") {
        std::cout << "%TEST_FAILED% time=0 testname=testColumn (csvtest) message=invalid column reading" << std::endl;
        std::cout << result << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testColumn (csvtest) message=passed" << std::endl;
    }
}

void testColumn2() {
    size_t column_index = 0;
    std::string filename = "example.csv";
    auto separator = ';';
    csv _csv;
    auto table = _csv.read(filename, separator);
    auto result = table.column(column_index);
    if (result.size() != 4) {
        std::cout << "%TEST_FAILED% time=0 testname=testColumn2 (csvtest) message=invalid number of elements in column" << std::endl;
        return;
    }
    if (result[0] != "1" || result[1] != "4" || result[2] != "7" || result[3] != "10") {
        std::cout << "%TEST_FAILED% time=0 testname=testColumn2 (csvtest) message=invalid column reading" << std::endl;
        std::cout << result << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testColumn2 (csvtest) message=passed" << std::endl;
    }
}

void testCell() {
    string column_name = "first";
    size_t row_index = 2;
    std::string filename = "example.csv";
    auto separator = ';';
    csv _csv;
    auto table = _csv.read(filename, separator);
    auto result = table.cell(column_name, row_index);
    if (result != "7") {
        std::cout << "%TEST_FAILED% time=0 testname=testCell (csvtest) message=invalid cell reading" << std::endl;
        std::cout << result << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testCell (csvtest) message=passed" << std::endl;
    }
}

void testCell2() {
    size_t column_index = 2;
    size_t row_index = 3;
    std::string filename = "example.csv";
    auto separator = ';';
    csv _csv;
    auto table = _csv.read(filename, separator);
    auto result = table.cell(column_index, row_index);
    if (result != "12") {
        std::cout << "%TEST_FAILED% time=0 testname=testCell2 (csvtest) message=invalid cell reading" << std::endl;
        std::cout << result << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testCell2 (csvtest) message=passed" << std::endl;
    }
}

void testNr_columns() {
    std::string filename = "example.csv";
    auto separator = ';';
    csv _csv;
    auto table = _csv.read(filename, separator);
    size_t result = table.nr_columns();
    if (result != 3) {
        std::cout << "%TEST_FAILED% time=0 testname=testNr_columns (csvtest) message=nr of columns error" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testNr_columns (csvtest) message=passed" << std::endl;
    }
}

void testNr_rows() {
    std::string filename = "example.csv";
    auto separator = ';';
    csv _csv;
    auto table = _csv.read(filename, separator);
    size_t result = table.nr_rows();
    if (result != 4) {
        std::cout << "%TEST_FAILED% time=0 testname=testNr_rows (csvtest) message=nr of rows error" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testNr_rows (csvtest) message=passed" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% csvtest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testRead (csvtest)" << std::endl;
    testRead();
    std::cout << "%TEST_FINISHED% time=0 testRead (csvtest)" << std::endl;

    std::cout << "%TEST_STARTED% testClear (csvtest)" << std::endl;
    testClear();
    std::cout << "%TEST_FINISHED% time=0 testClear (csvtest)" << std::endl;

    std::cout << "%TEST_STARTED% testHeader (csvtest)" << std::endl;
    testHeader();
    std::cout << "%TEST_FINISHED% time=0 testHeader (csvtest)" << std::endl;

    std::cout << "%TEST_STARTED% testRow (csvtest)" << std::endl;
    testRow();
    std::cout << "%TEST_FINISHED% time=0 testRow (csvtest)" << std::endl;

    std::cout << "%TEST_STARTED% testColumn (csvtest)" << std::endl;
    testColumn();
    std::cout << "%TEST_FINISHED% time=0 testColumn (csvtest)" << std::endl;

    std::cout << "%TEST_STARTED% testColumn2 (csvtest)" << std::endl;
    testColumn2();
    std::cout << "%TEST_FINISHED% time=0 testColumn2 (csvtest)" << std::endl;

    std::cout << "%TEST_STARTED% testCell (csvtest)" << std::endl;
    testCell();
    std::cout << "%TEST_FINISHED% time=0 testCell (csvtest)" << std::endl;

    std::cout << "%TEST_STARTED% testCell2 (csvtest)" << std::endl;
    testCell2();
    std::cout << "%TEST_FINISHED% time=0 testCell2 (csvtest)" << std::endl;

    std::cout << "%TEST_STARTED% testNr_columns (csvtest)" << std::endl;
    testNr_columns();
    std::cout << "%TEST_FINISHED% time=0 testNr_columns (csvtest)" << std::endl;

    std::cout << "%TEST_STARTED% testNr_rows (csvtest)" << std::endl;
    testNr_rows();
    std::cout << "%TEST_FINISHED% time=0 testNr_rows (csvtest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

