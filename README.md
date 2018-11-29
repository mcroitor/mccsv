# csv library
A simple library for reading csv files. Is defined in mc namespace. 
## Example of usage:
```C++
std::string filename = "example.csv";
char delimiter = ';';
mc::csv _csv(filename, delimiter);
/* // equivalent with
mc::csv _csv;
_csv.read(filename, delimiter);
*/
for(mc::cell_t cell: _csv.column("column_name")){
    std::cout << cell << " ";
}
```
## Library interface
```C++
typedef std::wstring string;

typedef string cell_t;
typedef std::deque<cell_t> column_t;
typedef std::deque<cell_t> row_t;
typedef std::map<cell_t, column_t> table_t;

void print_row(const row_t& );

class DLL_EXPORT csv{
    table_t table;

public:
    csv(const std::string& /* filename */, char /* delimiter*/ = ';');
    void read(std::string /* filename */, char /* delimiter*/ = ';');
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
```
