#pragma once
#include<iostream>
#include<vector>
using namespace std;


template<typename T, typename F>
void insertSort(vector<T>& v, int begin, int end, F cmp) {
	T temp;
	int j;
	for (int i = begin + 1; i < end; i++) {
		temp = v[i];
		for (j = i - 1; j >= begin && cmp(temp, v[j]); j--) {
			v[j + 1] = v[j];
		}
		v[j + 1] = temp;
	}
}
template<typename T>
void insertSort(vector<T>& v, int begin, int end) {
	insertSort(v, begin, end, less<>());
}