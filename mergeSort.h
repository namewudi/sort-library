#pragma once


#include<iostream>
#include<vector>
using namespace std;

template<typename T, typename F>
void mergeSort(vector<T>& v, int begin, int end, F cmp) {
	if (end <= (begin + 1)) return;
	int mid = (begin + end) >> 1;
	mergeSort(v, begin, mid, cmp);
	mergeSort(v, mid, end, cmp);
	vector<T> buff(v);
	int l = begin, r = mid, cur = l;
	while (l < mid || r < end) {
		if (r == end || (l < mid && !cmp(v[r], buff[l]))) {
			v[cur++] = buff[l++];
		}
		else {
			v[cur++] = v[r++];
		}
	}
}
template<typename T>
void mergeSort(vector<T>& v, int begin, int end) {
	mergeSort(v, begin, end, less<>());
}