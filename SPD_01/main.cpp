#define FILENAME "data.txt"

#include <iostream>
#include "rpg_data.h"

using namespace std;

float grade(int cmax_length) {
	if (cmax_length <= 100000) return 5.0;
	else if (cmax_length > 100000 and cmax_length <= 100010) return 5.0;
	else if (cmax_length > 100010 and cmax_length <= 100381) return 4.5;
	else if (cmax_length > 100381 and cmax_length <= 100926) return 4.0;
	else if (cmax_length > 100926 and cmax_length <= 103378) return 3.5;
	else if (cmax_length > 103378 and cmax_length <= 127362) return 3.0;
	else if (cmax_length > 127362 and cmax_length <= 168306) return 2.5;
	else return 2.0;
}

void Save_To_File(std::string filename) {
	ofstream File(filename);

}

int main() {
	Data d1, d2, d3, d4;

	Data Data_list[4] = { d1, d2, d3, d4 };
	string Data_number[4] = {"data.1", "data.2", "data.3", "data.4"};

	int sum = 0;
	//Data d5;

	//d5.Add(FILENAME, "data.5");
	//std::cout << d5.cmax();

	for (int i = 0; i < 4; i++) {
		Data_list[i].Add(FILENAME, Data_number[i]);
		std::cout << '\n';
		std::cout << Data_number[i] << '\n';
		std::cout << Data_list[i].cmax() << '\n';
		Data_list[i].Show_order();
		std::cout << '\n';
		sum += Data_list[i].cmax();
	}

	std::cout << "Suma dlugosci: " << sum << '\n';;
	std::cout << "Ocena: " << grade(sum);

	return 0;

	// Imiê nazwisko, suma d³ugoœci, jaka kolejnoœæ
	// jaka ocena siê nale¿y <- sprawko
}