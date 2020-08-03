#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T, typename F>
void bucketSort(vector<T>& v, int begin, int end, F cmp) {
	T _min = v[0], _max = v[0];
	for (auto elem : v) {
		_min = min(_min, elem);
		_max = max(_max, elem);
	}
	int diff = _min;
	int m = _max - _min + 1;
	vector<T> buff(m, 0);
	int idx;
	for (int i = begin; i < end; i++) {
		idx = v[i] - diff;
		buff[idx]++;
	}
	
	if (cmp(1, 2)) {
		idx = begin;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < buff[i]; j++) {
				v[idx++] = (T)(i + diff);
			}
		}
	}
	else {
		idx = end - 1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < buff[i]; j++) {
				v[idx--] = (T)(i + diff);
			}
		}
	}
}

template<typename T>
void bucketSort(vector<T>& v, int begin, int end) {
	bucketSort(v, begin, end, less<>());
}