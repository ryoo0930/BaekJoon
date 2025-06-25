#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{   
	int stairSize = 0; cin >> stairSize;
	int* stair = new int[stairSize];
	int* score = new int[stairSize];
	for (int i = 0; i < stairSize; i++) cin >> stair[i];


	if (stairSize == 1) { cout << stair[0]; return 0; }
	else if (stairSize == 2) { cout << stair[0] + stair[1]; return 0; }
	else if (stairSize == 3) { cout << max(stair[0] + stair[2], stair[1] + stair[2]); return 0; }

	score[0] = stair[0];
	score[1] = stair[0] + stair[1];
	score[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
	for (int i = 3; i < stairSize; i++) {
		score[i] = max(score[i - 2] + stair[i], score[i - 3] + stair[i - 1] + stair[i]);
	}
	cout << score[stairSize - 1];

	return 0;
}