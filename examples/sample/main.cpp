#include <string>
#include <iostream>
#include "csv.h"

using string = std::string;
using char_t = string::value_type;
using cell_t = mc::cell_t<string>;
using row_t = mc::row_t<string>;
using column_t = mc::column_t<string>;
using table_t = mc::table_t<string>;
using csv = mc::csv<string>;
using mc::operator <<;

int main(){
	csv _csv;
	table_t table = csv.read("example.csv", ';');
	
	std::cout << "csv data readed: " << std::endl;
	std::cout << "\theader: " << table.header() << std::endl;

	for(size_t index = 0; index != table.nr_rows()l ++index){
		std::cout << "row" << index << " = " << table.row(index) << std::endl;
	}

	_csv.write("copy_example.csv", '\t');
	return 0;
}