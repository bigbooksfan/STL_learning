#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<unsigned> values;				// Assembled values
vector<vector<unsigned>> valN;			// External values placeholder
unsigned min_val=100, maxL;

unsigned N;				// Number of arrays

vector<bool> eov;			// End of vector flags. TRUE - keep going, FALSE - reached the end
bool end_v = false;			// Overall flag. FALSE - at least one vector is in work. TRUE - all vectors out

bool te;				// Current values comparing with last added value. If TRUE - all values are not same with last added

vector<vector<unsigned>::iterator> itN;			// vector of iterators for running on income vectors

int i, k, n;					// Counters

void print_values() {				// vectors print

	for (i = 0; i < maxL; ++i) {
		for (n = 0; n < N; ++n) {
			if (i < valN[n].size()) cout << setw(4) << valN[n][i];
			else cout << setw(4) << " ";
		}
		cout << endl;
	}
}

bool moving_it() {					// moving iterators with same value with last added in assembled vector
	
	te=true;						// true - no same values, false - at least one value is same. Need to check iterators again and move necessaries

	for (n = 0; n < N; ++n) if (eov[n]) if (*itN[n] == values.back()) {			// every current value checking with ==
		++itN[n];
		te = false;
	}

	for (n = 0; n < N; ++n) if (itN[n] >= valN[n].end()) eov[n] = false;					// End of vectors flag checking

	return te;
	
}

unsigned add_min() {

	min_val = 100;

	for (n = 0; n < N; ++n) if (eov[n]) if (*itN[n] < min_val) min_val = *itN[n];				// finding minimum value of all current iterators

	for (n = 0; n < N; ++n) if (eov[n]) if (min_val == *itN[n]) ++itN[n];  // Moving iterators with current minimum value
	
	for (n = 0; n < N; ++n) if (itN[n] >= valN[n].end()) eov[n] = false;					// End of vectors flag checking

	return min_val;
}

int main() {

	srand(time(0));
	
	N = rand() % 15 + 5;			// number of vectors is set
	eov.resize(N);
	for (n = 0; n < N; ++n) eov[n] = true;		// flags preparing

	valN.resize(N);					// vector of vectors
	itN.resize(N);					// vector of iterators


	for (n = 0; n < N; ++n) {		// filling vectors with numbers 0-100
		k = rand() % 15 + 5; for (i = 0; i < k; i++) valN[n].push_back(rand() % 100);
	}
	
	for (n = 0; n < N; ++n) if (maxL < valN[n].size()) maxL = valN[n].size();		// taking maximum income vector lenght

	print_values();
	
	cout << "\n\n";

	for (n = 0; n < N; ++n) sort(valN[n].begin(), valN[n].end());			// sort vectors

	print_values();

	for (n = 0; n < N; ++n) itN[n] = valN[n].begin();						// iterators initialization
	
	values.reserve(20 * N);													// Memory reserve
	
	while (!end_v) {						// THE CYCLE
				
		values.push_back(add_min());		// put current minimum value in assemble

		while (!moving_it());				// checking same values

		end_v = true; for (n = 0; n < N; ++n) end_v *= !eov[n];   // end_v becomes TRUE when all eov[n] is false. Out of cycle
		
	}

	values.shrink_to_fit();					// memory release

	for (i = 0; i < values.size(); i++) cout << values[i] << " ";
	
	cout << endl << endl << clock();
}