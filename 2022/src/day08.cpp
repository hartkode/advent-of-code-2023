#include <cstddef>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

vector<string>
read_file(string_view filename)
{
	fstream        input{ filename };
	vector<string> data;

	for ( string line; getline(input, line); ) {
		data.emplace_back(line);
	}

	return data;
}

void
part1(const vector<string>& data)
{
	set<tuple<size_t, size_t>> positions;

	char max_so_far = 0;

	auto update = [&](size_t row, size_t col) {
		if ( data[row][col] > max_so_far ) {
			positions.emplace(row, col);
			max_so_far = data[row][col];
		}
	};

	for ( size_t row = 0; row != data.size(); ++row ) {
		max_so_far = 0;
		for ( size_t col = 0; col != data[row].size(); ++col ) {
			update(row, col);
		}

		max_so_far = 0;
		for ( size_t col = data[row].size(); col-- > 0; ) {
			update(row, col);
		}
	}

	for ( size_t col = 0; col != data[0].size(); ++col ) {
		max_so_far = 0;
		for ( size_t row = 0; row != data.size(); ++row ) {
			update(row, col);
		}

		max_so_far = 0;
		for ( size_t row = data.size(); row-- > 0; ) {
			update(row, col);
		}
	}

	cout << positions.size() << endl;
}

int
main()
{
	const auto grid = read_file("data/day08.txt");
	part1(grid);
}
