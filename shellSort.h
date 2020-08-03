#pragma once
#include<iostream>
#include<vector>
using namespace std;


template<typename T, typename F>
void shellSort(vector<T>& v, int begin, int end, F cmp) {
	int h = 1;
	int temp;
	while (h < (end - begin) / 3) h = 3 * h + 1;
	while (h >= 1) {
		for (int i = begin + h; i < end; i++) {
			temp = v[i];
			int j;
			for (j = i - h; (j >= begin) && cmp(temp, v[j]); j -= h)
				v[j + h] = v[j];
			v[j + h] = temp;
		}
		h /= 3;
	}
}
template<typename T>
void shellSort(vector<T>& v, int begin, int end) {
	shellSort(v, begin, end, less<>());
}