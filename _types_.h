/* 
 * File:   _types_.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 06 decembrie 2018, 13:54
 */

#ifndef _TYPES__H
#define _TYPES__H

#include <deque>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iterator>

namespace mc {
    template<typename STRING_TYPE>
    using cell_t = STRING_TYPE;

    template<typename STRING_TYPE>
    using row_t = std::deque<STRING_TYPE>;

    std::ostream& operator<<(std::ostream& out, const row_t<std::string>& row);

    std::wostream& operator<<(std::wostream& out, const row_t<std::wstring>& row);

    template<typename STRING_TYPE>
    class column_t {
    public:
        // type definitions
        using string = STRING_TYPE;
        using cell_type = string;
        using row_type = row_t<cell_type>;
        using char_type = typename cell_type::value_type;
    private:
        // properties
        STRING_TYPE name_;
        row_type values_;
    public:
        // methods

        column_t(cell_type header_name) : name_(header_name), values_() {
        }

        column_t(cell_type header_name, row_type values) : name_(header_name), values_(values) {
        }

        column_t(const column_t<cell_type>& column) : name_(column.name()), values_(column.values()) {
        }

        virtual ~column_t() {
        }

        const cell_type name() const {
            return name_;
        }

        const row_type values() const {
            return values_;
        }

        const size_t size() const {
            return values_.size();
        }

        const cell_type& operator[](size_t index) const {
            return values_[index];
        }

        cell_type& operator[](size_t index) {
            return values_[index];
        }

        void insert(const cell_type& str, size_t before) {
            values_.insert(values_.begin() + before, str);
        }

        void insert(const cell_type& str) {
            values_.push_back(str);
        }
        
        void erase(size_t index){
            values_.erase(values_.begin() + index);
        }
    };

    std::ostream& operator<<(std::ostream& out, const column_t<std::string>& column);

    std::wostream& operator<<(std::wostream& out, const column_t<std::wstring>& column);

    template<typename STRING_TYPE>
    class table_t {
    public:
        // type definitions
        using string = STRING_TYPE;
        using cell_type = string;
        using row_type = row_t<cell_type>;
        using column_type = column_t<cell_type>;
        using char_type = typename cell_type::value_type;
    private:
        // properties
        std::deque<column_type> columns_;
        row_type header_;
    public:
        // methods

        table_t() {
        }

        table_t(const table_t<STRING_TYPE>& table) :
        header_(table.header_), columns_(table.columns_) {
        }

        table_t(row_type headers) {
            header_.assign(headers.begin(), headers.end());
            for (string header_name : header_) {
                columns_.push_back(column_type(header_name));
            }
        }

        ~table_t() {
        }

        const row_type& header() const {
            return header_;
        }

        const column_type& column(size_t index) const {
            if (columns_.size() <= index) {
                throw std::out_of_range("out of range");
            }
            return columns_[index];
        }

        const column_type& column(string column_name) const {
            auto index = std::find(header_.begin(), header_.end(), column_name);
            if (index == header_.end()) {
                throw std::out_of_range("out of range");
            }
            return columns_[index - header_.begin()];
        }

        const column_type& operator[](string column_name) const {
            return column(column_name);
        }

        const column_type& operator[](size_t index) const {
            return column(index);
        }
        //        column_type& operator [](string column_name);
        //        column_type& operator [](size_t index);

        // slow method!

        const row_type row(size_t index) const {
            row_type result;
            for (const column_type& column : columns_) {
                result.push_back(column[index]);
            }
            return result;
        }

        const cell_type& cell(size_t column_index, size_t row_index) const {
            return column(column_index)[row_index];
        }

        const cell_type& cell(string column_name, size_t row_index) const {
            return column(column_name)[row_index];
        }

        void insert_column(const column_type& column) {
            header_.push_back(column.name());
            columns_.push_back(column);
        }

        void insert_column(const column_type& column, size_t position) {
            if(column.size() != nr_rows()){
                throw std::out_of_range("incopatible column size, waiting " + 
                        std::to_string(nr_rows()) + 
                        ", received " + 
                        std::to_string(column.size()) + 
                        " elements");
            }
            header_.insert(columns_.begin() + position, column.name());
            columns_.insert(columns_.begin() + position, column);
        }

        // remove all columns with name <b>column_name</b>

        void delete_column(const string& column_name) {
            std::remove(header_.begin(), header_.end(), column_name);
            std::remove(columns_.begin(), columns_.end(), [column_name](const column_type & column) {
                return column.name() == column_name;
            });
        }

        void delete_column(size_t position) {
            header_.erase(header_.begin() + position);
            columns_.erase(columns_.begin() + position);
        }
        // slow method!

        void insert_row(const row_type& row) {
            for (size_t index = 0; index != nr_columns(); ++index) {
                columns_[index].insert(row[index]);
            }
        }

        void insert_row(const row_type& row, size_t position) {
            for (size_t index = 0; index != nr_columns(); ++index) {
                columns_[index].insert(row[index], position);
            }
        }

        void delete_row(size_t position) {
            if(nr_rows() < position){
                throw std::out_of_range("remove out of range error!");
            }
            for (size_t index = 0; index != nr_columns(); ++index) {
                columns_[index].erase(position);
            }
        }

        size_t nr_columns() const {
            return columns_.size();
        }

        size_t nr_rows() const {
            if (columns_.empty()) {
                return 0;
            }
            return columns_[0].size();
        }

        void clear() {
            columns_.clear();
            header_.clear();
        }
    };
}

#endif /* _TYPES__H */

