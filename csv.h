/* 
 * File:   csv.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 07 decembrie 2018, 13:44
 */

#ifndef CSV_H
#define CSV_H

#include <fstream>

#include "_utils_.h"
#include "_types_.h"


namespace mc {

    template <typename STRING_TYPE>
    class csv {
    public:
        using string_t = STRING_TYPE;
        using char_t = typename string_t::value_type;
        using table_t = mc::table_t<string_t>;
        using column_t = typename table_t::column_type;

        table_t read(const string_t& filename, const char_t separator, const bool has_header = true) const {
            // TODO #: has_header not realised yet
            // TODO #: check correctness of CSV
            table_t table;
            string_t line;
            std::basic_ifstream<char_t> fin(filename);
            std::getline(fin, line);
            row_t<string_t> row = explode(line, separator);
            for (string_t header_name : row) {
                table.insert_column(column_t(header_name));
            }
            while (std::getline(fin, line)) {
                row = explode(line, separator);
                table.insert_row(row);
            }
            return table;
        }

        void write(const table_t& table, const string_t& filename, const char_t separator, const bool has_header = true) const {
            std::basic_ofstream<char_t> fout(filename);
            if (has_header == true) {
                fout << mc::implode(table.header(), separator) << std::endl;
            }
            for (size_t index = 0; index != table.nr_rows(); ++index) {
                fout << mc::implode(table.row(index), separator) << std::endl;
            }
        }
    };

    namespace s {
        using string = std::string;
        using char_t = string::value_type;
        using cell_t = mc::cell_t<string>;
        using row_t = mc::row_t<string>;
        using column_t = mc::column_t<string>;
        using table_t = mc::table_t<string>;
        using csv = csv<string>;
        using mc::operator<<;
    }

    namespace w {
        using string = std::wstring;
        using char_t = string::value_type;
        using cell_t = mc::cell_t<string>;
        using row_t = mc::row_t<string>;
        using column_t = mc::column_t<string>;
        using table_t = mc::table_t<string>;
        using csv = csv<string>;
        using mc::operator<<;
    }
}

#endif /* CSV_H */

