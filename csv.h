/* 
 * File:   csv.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 07 decembrie 2018, 13:44
 */

#ifndef CSV_H
#define CSV_H

#include <fstream>

#include "_types_.h"


namespace mc {

    template <typename STRING_TYPE = std::wstring>
    class csv {
    public:
        using string_t = STRING_TYPE;
        using char_t = typename string_t::value_type;
        using table_t = mc::table_t<string_t>;

        table_t read(const string_t& filename, const char_t separator, const bool has_header = true) const {
            // TODO #: has_header not used yet
            table_t table;
            string_t line;
            std::basic_ifstream<char_t> fin(filename);
            std::getline(fin, line);
            row_t row = split(line, separator);
            for (char_t header_name : row) {
                table.insert_column(table_t::column_type(header_name));
            }
            while (std::getline(fin, line)) {
                row = split(line, separator);
                table.insert_row(row);
            }
            return table;
        }

        void write(const table_t& table, const string_t& filename, const char_t separator, const bool has_header = true) const {
            std::basic_ofstream<char_t> fout(filename);
        }
    };
}

#endif /* CSV_H */

