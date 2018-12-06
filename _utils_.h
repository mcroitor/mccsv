/* 
 * File:   _utils_.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 06 decembrie 2018, 10:35
 */

#ifndef _UTILS__H
#define _UTILS__H

#include <deque>
#include <sstream>


/**
 * defines some string manipulations
 */

namespace mc{
    template<typename STRING_TYPE>
    std::deque<STRING_TYPE> split(STRING_TYPE str, typename STRING_TYPE::value_type sep){
        using CHAR_TYPE = typename STRING_TYPE::value_type;
        std::deque<STRING_TYPE> result;
        STRING_TYPE value;
        std::basic_istringstream<CHAR_TYPE> strin(str);
        while (strin.eof() == false) {
            std::getline(strin, value, sep);
            result.push_back(value);
        }
        return result;
    }
}

#endif /* _UTILS__H */

