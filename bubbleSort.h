#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<typename T, typename F>
void bubbleSort(vector<T>& v, int begin, int end, F cmp) {
	bool flag;
	for (int i = begin; i < end; i++) {
		flag = true;
		for (int j = begin + 1; j < end - (i - begin); j++) {
			if (cmp(v[j], v[j - 1])) {
				swap(v[j - 1], v[j]);
				flag = false;
			}
		}
		if (flag) break;
	}
}

template<typename T>
void bubbleSort(vector<T>& v, int begin, int end) {
	bubbleSort(v, begin, end, less<>());
}
