#pragma once
#include<iostream>
#include<vector>
using namespace std;


template<typename T, typename F>
void quickSort(vector<T>& v, int begin, int end, F cmp) {
	if (end - begin < 2) return;
	swap(v[begin], v[rand() % (end - begin) + begin]);
	T base = v[begin];
	int l = begin, r = end - 1;
	while (l < r) {
		while (l < r && !cmp(v[r], base)) r--;
		if (l < r) v[l] = v[r];
		while (l < r && (cmp(v[l], base) || ((!cmp(v[l], base)) && (!cmp(base, v[l]))))) l++;
		if (l < r) v[r] = v[l];
	}
	v[l] = base;
	quickSort(v, begin, l, cmp);
	quickSort(v, l + 1, end, cmp);
}
template<typename T>
void quickSort(vector<T>& v, int begin, int end) {
	quickSort(v, begin, end, less<>());
}