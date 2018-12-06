// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iterator>

#include "mccsv.h"

namespace mc {
    //private methods

    void csv::build_header(size_t nr_columns) {
        for (size_t index = 1; index <= nr_columns; ++index) {
            header_.push_back(L"column" + std::to_wstring(index));
        }
    }
    //public methods

    csv::csv(const std::string& filename, char delimiter, bool has_header) {
        read(filename, delimiter, has_header);
    }

    void csv::read(std::string filename, char delimiter, bool has_header) {
        clear();
        std::wifstream fin(filename.c_str());
        cell_type line;
        
        std::getline(fin, line);
        // prepare header
        row_t row = split(line, delimiter);
        build_header(row.size());
        if (has_header == true) {
            std::copy(row.begin(), row.end(), header_.begin());
        }
        
        for (cell_t column_name : header_) {
            table_.insert(std::make_pair(column_name, column_t()));
        }
        // read lines
        if (has_header == false) {
            size_t i = 0;
            for (i = 0; i != row.size(); ++i) {
                table_.at(header_[i]).push_back(row[i]);
            }
        }
        while (std::getline(fin, line)) {
            row_t row = split(line, delimiter);
            size_t i = 0;
            for (i = 0; i != row.size(); ++i) {
                table_.at(header_[i]).push_back(row[i]);
            }
        }
    }

    void csv::clear() {
        table_.clear();
        header_.clear();
    }

    row_t csv::header() const {
        return header_;
    }

    // TODO #1: assert error

    row_t csv::row(size_t row_index) const {
        row_t result;
        table_t::const_iterator i = table_.begin();
        while (i != table_.end()) {
            result.push_back(i->second[row_index]);
            ++i;
        }
        return result;
    }

    // TODO #2: assert error

    column_t csv::column(cell_t column_name) const {
        return table_.at(column_name);
    }

    column_t csv::column(size_t column_index) const {
        return table_.at(this->header()[column_index]);
    }

    // TODO #3: assert error

    cell_t csv::cell(cell_t column_name, size_t row_index) const {
        return column(column_name)[row_index];
    }

    cell_t csv::cell(size_t column_index, size_t row_index) const {
        return column(column_index)[row_index];
    }

    size_t csv::nr_columns() const {
        return this->table_.size();
    }

    size_t csv::nr_rows() const {
        if (nr_columns() == 0) {
            return 0;
        }
        return this->table_.begin()->second.size();
    }
    
    std::wostream& operator<<(std::wostream& out, const row_t& row){
        std::copy(row.begin(), row.end(), std::ostream_iterator<cell_type, wchar_t>(out, L";"));
        return out;
    }
}