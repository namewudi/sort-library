#include<iostream>
#include<vector>
#include"sortLib.h"

using namespace std;

int main() {
	/*vector<int> v;
	int end = 15;
	for (int i = 0; i < end; i++) {
		v.push_back(rand() % 16);
	}*/
	vector<char> v;
	int end = 15;
	for (int i = 0; i < end; i++) {
		v.push_back(rand() % 16 + 'a');
	}

	//bubbleSort(v, 0, end, less<>());
	//mergeSort(v, 0, end);
	//quickSort(v, 0, end);
	//heapSort(v, 0, end);
	//insertSort(v, 0, end);
	//selectionSort(v, 0, end);
	//bucketSort(v, 0, end);
	//shellSort(v, 0, end);

	for (auto elem : v) {
		cout << elem << ' ';
	}
	return 0;
}