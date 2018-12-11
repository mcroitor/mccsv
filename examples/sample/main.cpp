#include <string>
#include <iostream>
#include "csv.h"

using string = std::string;
using csv = mc::csv<string>;
using mc::operator <<;

int main(){
	csv _csv;
	auto table = _csv.read("example.csv", ';');
	
	std::cout << "csv data readed: " << std::endl;
	std::cout << "\theader: " << table.header() << std::endl;

	for(size_t index = 0; index != table.nr_rows(); ++index){
		std::cout << "\trow" << index << ": " << table.row(index) << std::endl;
	}

	_csv.write(table, "copy_example.csv", '\t');
	return 0;
}