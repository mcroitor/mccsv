
#ifndef CSV_H
#define CSV_H

#include <map>
#include <deque>
#include <string>

#define DLL_EXPORT __declspec(dllexport)
namespace mc{
    typedef std::wstring string;
    
    typedef string cell_t;
    typedef std::deque<cell_t> column_t;
    typedef std::deque<cell_t> row_t;
    
    // TODO #: map sorts elements, rewrite deque<pair>
    typedef std::map<cell_t, column_t> table_t;
    
    class DLL_EXPORT csv{
        table_t table_;
        // speed up
        row_t header_;
        
        void build_header(size_t /* nr_columns */);
    public:
        csv(const std::string& /* filename */, char /* delimiter */ = ';', bool /* has_header */ = true);
        void read(std::string /* filename */, char /* delimiter */ = ';', bool /* has_header */ = true);
        void clear();
        row_t header() const;
        row_t row(size_t /* row_index */) const;
        column_t column(cell_t /* column_name */) const;
        column_t column(size_t /* column_index */) const; 
        cell_t cell(cell_t /* column_name */, size_t /* row_index */) const;
        cell_t cell(size_t /* column_index */, size_t /* row_index */) const;
        
        size_t nr_columns() const;
        size_t nr_rows() const;
    };
    
    std::wostream& operator<<(std::wostream& /* out */, const row_t& /* row */);
}

#endif /* CSV_H */

