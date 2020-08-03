#pragma once
#include<iostream>
#include<vector>
using namespace std;


template<typename T, typename F>
void selectionSort(vector<T>& v, int begin, int end, F cmp) {
	T temp;
	int bestIdx;
	for (int i = begin; i < end; i++) {
		bestIdx = i;
		for (int j = i + 1; j < end; j++) {
			if (cmp(v[j], v[bestIdx])) bestIdx = j;
		}
		swap(v[bestIdx], v[i]);
	}
}
template<typename T>
void selectionSort(vector<T>& v, int begin, int end) {
	selectionSort(v, begin, end, less<>());
}