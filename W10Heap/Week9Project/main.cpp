#include <iostream>
#include "minHeap.h"

int main() {
	// kth smallest element
	int n;
	int k;
	int arr[10000];
	MinHeap<int> minHeap;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
		minHeap.push(arr[i]);
	}
	std::cin >> k;
	for (int i = 0; i < k-1; ++i) {
		minHeap.pop();
	}
	std::cout << minHeap.top() << std::endl;


	return 0;
}