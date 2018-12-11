#include "csv.h"

namespace mc {

    std::ostream& operator<<(std::ostream& out, const row_t<std::string>& row) {
        std::copy(row.begin(), row.end(), std::ostream_iterator<std::string>(out, " "));
        return out;
    }

    std::wostream& operator<<(std::wostream& out, const row_t<std::wstring>& row) {
        std::copy(row.begin(), row.end(), std::ostream_iterator < std::wstring, wchar_t>(out, L" "));
        return out;
    }
    
        std::ostream& operator<<(std::ostream& out, const column_t<std::string>& column) {
        out << column.name() << ": [";
        for(std::string cell: column.values()){
            out << cell << " ";
        }
        out << "]";
        return out;
    }

    std::wostream& operator<<(std::wostream& out, const column_t<std::wstring>& column) {
        out << column.name() << L": [";
        for(std::wstring cell: column.values()){
            out << cell << L" ";
        }
        return out;
    }
}