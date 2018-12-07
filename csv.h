/* 
 * File:   csv.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 07 decembrie 2018, 13:44
 */

#ifndef CSV_H
#define CSV_H

#include "_types_.h"


namespace mc{
    template <typename STRING_TYPE = std::wstring>
    class csv{
    public:
        using string_t = STRING_TYPE;
        using char_t = string_t::value_type;
        using table_t = mc::table_t<string_t>;
        table_t read(const string_t& filename, const char_t separator, const bool has_header = true) const{
            table_t table;
            return table;
        }
        void write(const table_t& table, const string_t& filename, const char_t separator, const bool has_header = true) const{

        }
    };
}

#endif /* CSV_H */

