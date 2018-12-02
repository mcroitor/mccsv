/* 
 * File:   csvtest.cpp
 * Author: mcroitor
 *
 * Created on 26 decembrie 2017, 17:00
 */

#include <cstdlib>
#include <iostream>
#include "mccsv.h"

/*
 * Simple C++ Test Suite
 */

using string = mc::string;

void testRead() {
    std::string filename = "example.csv";
    char separator = ';';
    mc::csv _csv(filename, separator);
    if (_csv.nr_columns() != 3) {
        std::cout << "%TEST_FAILED% time=0 testname=testCsv (csvtest) message=incorrect nr. of columns" << std::endl;
        return;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testCsv (csvtest) message=passed" << std::endl;
    }
    if (_csv.nr_rows() != 4) {
        std::cout << "%TEST_FAILED% time=0 testname=testCsv (csvtest) message=incorrect nr. or fows" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testCsv (csvtest) message=passed" << std::endl;
    }
}

void testClear() {
    std::string filename = "example.csv";
    char separator = ';';
    mc::csv _csv(filename, separator);
    _csv.clear();
    if (_csv.nr_columns() != 0 || _csv.nr_rows() != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testClear (csvtest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testClear (csvtest) message=passed" << std::endl;
    }
}

void testHeader() {
    std::string filename = "example.csv";
    char separator = ';';
    mc::csv _csv(filename, separator);
    mc::row_t result = _csv.header();
    if (result[0] != L"first" || result[1] != L"second" || result[2] != L"third") {
        std::cout << "%TEST_FAILED% time=0 testname=testHeader (csvtest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testHeader (csvtest) message=passed" << std::endl;
    }
}

void testRow() {
    size_t p0 = 1;
    std::string filename = "example.csv";
    char separator = ';';
    mc::csv _csv(filename, separator);
    mc::row_t result = _csv.row(p0);
    if (result[0] != L"4" || result[1] != L"5" || result[2] != L"6") {
        std::cout << "%TEST_FAILED% time=0 testname=testRow (csvtest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testRow (csvtest) message=passed" << std::endl;
    }
}

void testColumn() {
    string header_name = L"second";
    std::string filename = "example.csv";
    char separator = ';';
    mc::csv _csv(filename, separator);
    mc::column_t result = _csv.column(header_name);
    if (result.size() != 4) {
        std::cout << "%TEST_FAILED% time=0 testname=testColumn (csvtest) message=error message sample" << std::endl;
        return;
    }
    if (result[0] != L"2" || result[1] != L"5" || result[2] != L"8" || result[3] != L"11") {
        std::cout << "%TEST_FAILED% time=0 testname=testColumn (csvtest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testColumn (csvtest) message=passed" << std::endl;
    }
}

void testColumn2() {
    size_t column_index = 0;
    std::string filename = "example.csv";
    char separator = ';';
    mc::csv _csv(filename, separator);
    mc::column_t result = _csv.column(column_index);
    if (result[0] != L"1" || result[1] != L"4" || result[2] != L"7" || result[3] != L"10") {
        std::cout << "%TEST_FAILED% time=0 testname=testColumn2 (csvtest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testColumn2 (csvtest) message=passed" << std::endl;
    }
}

void testCell() {
    string column_name = L"first";
    size_t row_index = 2;
    std::string filename = "example.csv";
    char separator = ';';
    mc::csv _csv(filename, separator);
    mc::cell_t result = _csv.cell(column_name, row_index);
    if (result != L"7") {
        std::cout << "%TEST_FAILED% time=0 testname=testCell (csvtest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testCell (csvtest) message=passed" << std::endl;
    }
}

void testCell2() {
    size_t column_index = 2;
    size_t row_index = 3;
    std::string filename = "example.csv";
    char separator = ';';
    mc::csv _csv(filename, separator);
    mc::cell_t result = _csv.cell(column_index, row_index);
    if (result != L"12") {
        std::cout << "%TEST_FAILED% time=0 testname=testCell2 (csvtest) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testCell2 (csvtest) message=passed" << std::endl;
    }
}

void testNr_columns() {
    std::string filename = "example.csv";
    char separator = ';';
    mc::csv _csv(filename, separator);
    size_t result = _csv.nr_columns();
    if (result != 3) {
        std::cout << "%TEST_FAILED% time=0 testname=testNr_columns (csvtest) message=nr of columns error" << std::endl;
    } else {
        std::cout << "%TEST_SUCCESSFULL% time=0 testname=testNr_columns (csvtest) message=passed" << std::endl;
    }
}

void testNr_rows() {
    std::string filename = "example.csv";
    char separator = ';';
    mc::csv _csv(filename, separator);
    size_t result = _csv.nr_rows();
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

