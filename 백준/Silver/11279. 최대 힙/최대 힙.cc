#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	vector<int> heap;
}Heap;

void initHeap(Heap& h);
int removeHeap(Heap& h);
void insertHeap(Heap& h, int data);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Heap h; initHeap(h);
	int testCase = 0; cin >> testCase;
	while (testCase--) {
		int oper; cin >> oper;
		if (oper == 0) cout << removeHeap(h) << '\n';
		else insertHeap(h, oper);
	}

	return 0;
}

void initHeap(Heap& h) { h.heap.push_back(-1); }

int removeHeap(Heap& h) {
	int heapSize = h.heap.size() - 1;
	if (heapSize == 0) return 0;

	int result = h.heap[1];
	h.heap[1] = h.heap[heapSize];
	h.heap.pop_back();

	int currentNodeIndex = 1;
	while (true) {
		int child1_index = currentNodeIndex * 2, child2_index = (currentNodeIndex * 2) + 1;
		int largest = currentNodeIndex;

		if (child1_index < h.heap.size() && h.heap[child1_index] > h.heap[largest]) largest = child1_index;
		if (child2_index < h.heap.size() && h.heap[child2_index] > h.heap[largest]) largest = child2_index;

		if (largest == currentNodeIndex) break;
		swap(h.heap[currentNodeIndex], h.heap[largest]);
		currentNodeIndex = largest;
	}
	return result;
}

void insertHeap(Heap& h, int data) {
	h.heap.push_back(data);

	int currentIndex = h.heap.size() - 1;
	while (currentIndex > 1 && h.heap[currentIndex] > h.heap[currentIndex / 2]) {
		swap(h.heap[currentIndex], h.heap[currentIndex / 2]);
		currentIndex = currentIndex / 2;
	}
}