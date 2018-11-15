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

void testCsv() {
    std::string p0 = "example.csv";
    char p1 = ';';
    mc::csv _csv(p0, p1);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testCsv (csvtest) message=error message sample" << std::endl;
    }
}

void testRead() {
    std::string p0;
    char p1;
    mc::csv _csv;
    _csv.read(p0, p1);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testRead (csvtest) message=error message sample" << std::endl;
    }
}

void testClear() {
    mc::csv _csv;
    _csv.clear();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testClear (csvtest) message=error message sample" << std::endl;
    }
}

void testHeader() {
    mc::csv _csv;
    mc::row_t result = _csv.header();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testHeader (csvtest) message=error message sample" << std::endl;
    }
}

void testRow() {
    size_t p0;
    mc::csv _csv;
    mc::row_t result = _csv.row(p0);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testRow (csvtest) message=error message sample" << std::endl;
    }
}

void testColumn() {
    std::string p0;
    mc::csv _csv;
    mc::column_t result = _csv.column(p0);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testColumn (csvtest) message=error message sample" << std::endl;
    }
}

void testColumn2() {
    size_t p0;
    mc::csv _csv;
    mc::column_t result = _csv.column(p0);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testColumn2 (csvtest) message=error message sample" << std::endl;
    }
}

void testCell() {
    std::string p0;
    size_t p1;
    mc::csv _csv;
    mc::cell_t result = _csv.cell(p0, p1);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testCell (csvtest) message=error message sample" << std::endl;
    }
}

void testCell2() {
    size_t p0;
    size_t p1;
    mc::csv _csv;
    mc::cell_t result = _csv.cell(p0, p1);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testCell2 (csvtest) message=error message sample" << std::endl;
    }
}

void testNr_columns() {
    mc::csv _csv;
    size_t result = _csv.nr_columns();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testNr_columns (csvtest) message=error message sample" << std::endl;
    }
}

void testNr_rows() {
    mc::csv _csv;
    size_t result = _csv.nr_rows();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testNr_rows (csvtest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% csvtest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testCsv (csvtest)" << std::endl;
    testCsv();
    std::cout << "%TEST_FINISHED% time=0 testCsv (csvtest)" << std::endl;

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

