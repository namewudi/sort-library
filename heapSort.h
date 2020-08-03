#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct noElemPop: public exception{
public:
	char const* what ()const override {
		return "堆为空,无法调用pop()";
	}
};
struct noElemTop : public exception {
public:
	char const* what()const override {
		return "堆为空,无法调用top()";
	}
};

template<typename T, typename C = vector<T>, typename F = less<T>>
class Heap {
private:
	C elems;
	F cmp;
	int lChild(int i) {
		return i * 2 + 1;
	}
	int rChild(int i) {
		return i * 2 + 2;
	}
	int parent(int i) {
		return (i - 1) >> 1;
	}
	void percolateUp() {
		int i = this->size() - 1;
		while (true) {
			if (!validIndex(parent(i))) break;
			if (cmp(elems[i], elems[parent(i)])) {
				swap(elems[i], elems[parent(i)]);
				i = parent(i);
			}
			else break;
		}
	}
	bool validIndex(int i) {
		if (i >= 0 && i < this->size()) return true;
		return false;
	}
	void percolateDown(int idx) {
		int m = this->size();
		int i = idx;
		int son;
		while (true) {
			if (!validIndex(lChild(i))) break;
			if (!validIndex(rChild(i))) {
				son = lChild(i);
			}
			else {
				son = cmp(elems[lChild(i)], elems[rChild(i)]) ? lChild(i) : rChild(i);
			}
			if (cmp(elems[son], elems[i])) {
				swap(elems[son], elems[i]);
				i = son;
			}
			else break;
		}
	}
	void buildHeap() {
		for (int i = this->size() - 1; i >= 0; i--) {
			percolateDown(i);
		}
	}

public:
	Heap() {};
	Heap(int n) {
		elems.reserve(n);
	}
	Heap(C& v) {
		elems = v;
		buildHeap();
	}
	int size() {
		return elems.size();
	}
	void push(T p) {
		elems.push_back(p);
		percolateUp();
	}
	T top() {
		try {
			if (elems.empty()) {
				throw noElemTop();
			}
			return elems.front();
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}

	}
	void pop() {
		try {
			if (elems.empty()) {
				throw noElemPop();
			}
			elems[0] = elems.back();
			elems.pop_back();
			percolateDown(0);
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}

	}
	bool empty() {
		return elems.empty();
	}
};

template<typename T, typename F>
void heapSort(vector<T>& v, int begin, int end) {
	vector<T> buff;
	buff.assign(v.begin() + begin, v.begin() + end);
	Heap<T,vector<T>, F> h(buff);
	for (int i = begin; i < end; i++) {
		v[i] = h.top();
		h.pop();
	}
}
template<typename T>
void heapSort(vector<T>& v, int begin, int end) {
	heapSort<T, less<T>>(v, begin, end);
}