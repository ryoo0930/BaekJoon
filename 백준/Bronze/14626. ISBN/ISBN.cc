#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	string ISBM; cin >> ISBM;

	int check = 0;
	int index = 0;
	for (int i = 0; i < 13; i++) {
		if (ISBM[i] == '*') { index = i; continue; }
		int isbm = ISBM[i] - '0';

		if (i % 2 == 0) check += isbm;
		else check += (3 * isbm);
	}
	check %= 10;

	if (check == 0) cout << 0;
	else if (index % 2 == 0) {
		cout << 10 - check;
	}
	else {
		for (int i = 0; i <= 9; i++) {
			if ((check + (3 * i)) % 10 == 0) { cout << i; break; }
		}

	}

	return 0;
}