#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> v;
	int size = 0; cin >> size;
	for (int i = 0; i < size; i++) {
		int startTime = 0, endTime = 0; cin >> startTime >> endTime;
		v.push_back(make_pair(startTime, endTime));
	}
	sort(v.begin(), v.end(), compare);

	int result = 0;
	int last = 0;
	for (int i = 0; i < size; i++) {
		int start = v[i].first, end = v[i].second;
		if (start >= last) {
			result++;
			last = end;
		}
	}
	cout << result;

	return 0;
}
