#include <map>
#include <sstream>
#include <fstream>
#include <iostream>

#include "mccsv.h"

namespace mc {

    void print_row(const mc::row_t& row) {
        size_t i = 0;
        for (; i != row.size(); ++i) {
            std::wcout << row.at(i) << L"\t";
        }
        std::wcout << std::endl;
    }

    row_t split(string text, char delimiter) {
        row_t result;
        string value;
        std::wistringstream strin(text);
        while (strin.eof() == false) {
            std::getline(strin, value, (wchar_t)delimiter);
            result.push_back(value);
        }
        return result;
    }

    csv::csv(const std::string& filename, char delimiter) {
        read(filename, delimiter);
    }

    // TODO #: assert errors

    void csv::read(std::string filename, char delimiter) {
        //setlocale(LC_ALL, "Russian");
        clear();
        std::wifstream fin(filename.c_str());
        // read header
        string line;
        std::getline(fin, line);
        row_t header = split(line, delimiter);
        std::cout << ">>> nr. of columns = " << header.size() << std::endl;
        for (cell_t column_name : header) {
            table.insert(std::make_pair(column_name, row_t()));
        }
        // read lines
//        size_t index = 1;

        while (std::getline(fin, line)) {
//            std::cout << ">>> line = " << index << std::endl;
//            ++index;
//            std::wcout << L">>> source = " << line << std::endl;
            row_t row = split(line, delimiter);
            
            size_t i = 0;
            for(i = 0; i != row.size(); ++i){
                table.at(header.at(i)).push_back(row[i]);
            }
        }
    }

    void csv::clear() {
        table.clear();
    }

    row_t csv::header() const {
        row_t keys;
        table_t::const_iterator i = table.begin();
        while (i != table.end()) {
            keys.push_back(i->first);
            ++i;
        }
        return keys;
    }

    // TODO #1: assert error

    row_t csv::row(size_t row_index) const {
        row_t result;
        table_t::const_iterator i = table.begin();
        while (i != table.end()) {
            result.push_back(i->second[row_index]);
            ++i;
        }
        return result;
    }

    // TODO #2: assert error

    column_t csv::column(cell_t column_name) const {
        return table.at(column_name);
    }

    // TODO #3: assert error

    cell_t csv::cell(cell_t column_name, size_t row_index) const {
        return column(column_name)[row_index];
    }

    size_t csv::nr_columns() const {
        return this->table.size();
    }

    size_t csv::nr_rows() const {
        return this->table.begin()->second.size();
    }
}