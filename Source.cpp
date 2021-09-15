#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

vector<unsigned> values, values_sort, val1, val2, val3;
int n = 20, size123;	// Длина вектора
unsigned min_val=0;

vector<unsigned>::iterator it1, it2, it3, itv;

int i;					// Счётчик
int k;

void print_values() {

	for (i = 0; i < val1.size() || i < val2.size() || i < val3.size(); i++) {      // Вывод значений векторов
		if (i < val1.size()) cout << val1[i]; cout << "\t";
		if (i < val2.size()) cout << val2[i]; cout << "\t";
		if (i < val3.size()) cout << val3[i]; cout << "\t" << endl;
	}
}

int main() {

	srand(time(0));
	
	k = rand() % 15 + 5;	for (i = 0; i < k; i++) val1.push_back(rand() % 100);
	k = rand() % 15 + 5;	for (i = 0; i < k; i++) val2.push_back(rand() % 100);
	k = rand() % 15 + 5;	for (i = 0; i < k; i++) val3.push_back(rand() % 100);


	print_values();
	
	cout << "\n\n";

	sort(val1.begin(), val1.end());
	sort(val2.begin(), val2.end());
	sort(val3.begin(), val3.end());

	print_values();

	it1 = val1.begin();
	it2 = val2.begin();
	it3 = val3.begin();
	
	values.reserve(val1.size()+val2.size()+val3.size());
	
	//itv = values.begin();
	
	min_val = 100;


	if (*it1 <= min_val) {
		min_val = *it1;
	}

	if (*it2 <= min_val) {
		min_val = *it2;
	}

	if (*it3 <= min_val) {
		min_val = *it3;
	}

	values.push_back(min_val);


/*	for (i = 0; i < val1.size() || i < val2.size() || i < val3.size(); i++)*/ 
	while (it1 <= val1.end() || it2 <= val2.end() || it3 <= val3.end()) {

		min_val = 100;

		if (it1 <= val1.end()) while (*it1 == values.back()) it1++; cout << *it1 << " ";
		if (it2 <= val2.end()) while (*it2 == values.back()) it2++; cout << *it2 << " ";
		if (it3 <= val3.end()) while (*it3 == values.back()) it3++; cout << *it3 << " ";

		cout << endl;



		if (it1 < val1.end()) if (*it1 < min_val) min_val = *it1;
		if (it2 < val2.end()) if (*it2 < min_val) min_val = *it2;
		if (it3 < val3.end()) if (*it3 < min_val) min_val = *it3;

		//if (*it1 < min_val && it1 < val1.end()) min_val = *it1;
//		if (*it2 < min_val && it2 < val2.end()) min_val = *it2;
//		if (*it3 < min_val && it3 < val3.end()) min_val = *it3;

		values.push_back(min_val);
		cout << "Added " << values.back() << endl;
	}


	for (i = 0; i < values.size(); i++) {
		cout << values[i] << " ";
	}



	//cout << clock();
}