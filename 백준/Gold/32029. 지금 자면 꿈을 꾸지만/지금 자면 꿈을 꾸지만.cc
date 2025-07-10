#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, A = 0, B = 0;
	cin >> N >> A >> B;

	vector<int> report;
	for (int i = 0; i < N; i++) { 
		int temp = 0; cin >> temp;
		report.push_back(temp); 
	}
	sort(report.begin(), report.end());

	int result = 0;
	for (int X = 0; X < A; X++) {
		int sleep = B * X;

		for (int i = 0; i < N; i++) {
			int count = 0; int currentTime = 0;
			for (int j = 0; j < i; j++) {
				currentTime += A;
				if (currentTime > report[j]) { currentTime -= A; continue; }
				count++;
			}
			currentTime += sleep;
			for (int j = i; j < N; j++) {
				currentTime += (A - X);
				if (currentTime > report[j]) { currentTime -= (A - X); continue; }
				count++;
			}
			result = max(result, count);
		}
	}
	cout << result;

	return 0;
}