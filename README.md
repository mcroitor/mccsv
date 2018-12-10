# csv library
A simple library for reading csv files. Is defined in mc namespace. 
## Example of usage:
```C++
#include "csv.h"

int main(){
    std::string filename = "example.csv";
    char delimiter = ';';
    mc::csv<std::string> _csv;
    table_t<std::string> table = _csv.read(filename, delimiter);

    for(mc::cell_t<std::string> cell: table.column(L"column_name")){
        std::cout << cell << " ";
    }
    return 0;
}
```
How to build?

## Library interface
```C++
template<typename STRING_TYPE>
using cell_t = STRING_TYPE;

template<typename STRING_TYPE>
using row_t = std::deque<STRING_TYPE>;

template<typename STRING_TYPE>
class column_t {
public:
    // type definitions
    using string = STRING_TYPE;
    using cell_type = string;
    using row_type = row_t<cell_type>;
    using char_type = typename cell_type::value_type;

    // methods
    column_t(cell_type header_name);
    column_t(cell_type header_name, row_type values);
    column_t(const column_t<cell_type>& column);
    virtual ~column_t();

    const cell_type name() const;
    const row_type values() const;
    const size_t size() const;
    const cell_type& operator[](size_t index) const;
    cell_type& operator[](size_t index);
    void insert(const cell_type& str, size_t before);
    void insert(const cell_type& str);
};

template<typename STRING_TYPE>
class table_t {
public:
    // type definitions
    using string = STRING_TYPE;
    using cell_type = string;
    using row_type = row_t<cell_type>;
    using column_type = column_t<cell_type>;
    using char_type = typename cell_type::value_type;

    // methods
    table_t();
    table_t(const table_t<STRING_TYPE>& table);
    table_t(row_type headers);
    ~table_t();
    const row_type& header() const;
    const column_type& column(size_t index) const;
    const column_type& column(string column_name) const;
    const column_type& operator[](string column_name) const;
    const column_type& operator[](size_t index) const;
    //        column_type& operator [](string column_name);
    //        column_type& operator [](size_t index);
    // slow method!
    const row_type row(size_t index) const;
    const cell_type& cell(size_t column_index, size_t row_index) const;
    const cell_type& cell(string column_name, size_t row_index);
    void insert_column(const column_type& column);
    void insert_column(const column_type& column, size_t position);
    // slow method!
    void insert_row(const row_type& row);
    void insert_row(const row_type& row, size_t position);
    size_t nr_columns() const;
    size_t nr_rows() const;;
    void clear();
};

template <typename STRING_TYPE>
class csv {
public:
    using string_t = STRING_TYPE;
    using char_t = typename string_t::value_type;
    using table_t = mc::table_t<string_t>;
    using column_t = typename table_t::column_type;

    table_t read(const string_t& filename, const char_t separator, const bool has_header = true) const;
    void write(const table_t& table, const string_t& filename, const char_t separator, const bool has_header = true) const;
};
```
