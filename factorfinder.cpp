#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	cout << "Factor Finder\n";
	cout << "A number's factors are two numbers that, when multiplied with ";
	cout << "each other, produce the number.For example, 2 x 13 = 26, ";
	cout << "so 2 and 13 are factors of 26. 1 x 26 = 26, so 1 and 26 are also ";
	cout << "factors of 26. We say that 26 has four factors : 1, 2, 13, and 26.\n\n";
	cout << "If a number only has two factors(1 and itself), we call that a prime ";
	cout << "number. Otherwise, we call it a composite number.\n\n";
	cout << "Can you discover some prime numbers ?\n\n";
	while (true) {
		cout << "Enter a positive whole number to factor (or QUIT):\n";
		cout << "> ";
		string response = "";
		getline(cin, response);
		transform(response.begin(), response.end(), response.begin(), ::toupper);
		if (response == "QUIT") {
			break;
		}

		int number = 0;
		bool check = false;
		for (char c : response) {
			if (c >= '0' && c <= '9') {
				number = number * 10 + (c - '0');
			} else {
				check = true;
				break;
			}
		}
		if (check) {
			continue;
		}

		vector <int> factors;

		// Find the factors of number :
		for (int i = 1; i < sqrt(number) + 1; i++) {
			if (number % i == 0) { // If there's no remainder, it is a factor.
				factors.push_back(i);
				factors.push_back(number / i);
			}

		}

		// Convert to a set to get rid of duplicate factors :
		set <int> s;
		for (auto now : factors) {
			s.insert(now);
		}

		// Display the results :
		for (auto now : s) {
			cout << now << " ";
		}
		cout << endl;
	}

	return 0;
}