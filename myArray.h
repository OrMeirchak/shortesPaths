#pragma once
#include <exception>
using namespace std;

class outOfIndexExeption : public exception {};
//the class represent generic array
template <class T>
class MyArray {
private:
	T *arr;
	int size;


public:

	MyArray(int size=0) {
		this->size = size;
		if (size) {
			arr = new T[size];
		}
		else {
			arr = nullptr;
		}
	}

	~MyArray() {
		if (arr) {
			delete [] arr;
		}
	}

	MyArray(const MyArray& other) : MyArray(other.size) {

		for (int i = 0; i < size; i++){
			arr[i] = other.arr[i];
		}
	}

	void makeEmpty(int size=0) {
		if (arr) {
			delete [] arr;
		}
		this->size = size;
		arr = new T[size];
	}

	T& operator[](int index) {
		if ((index < 0) || (index >= size)) {
			throw outOfIndexExeption();
		}
		else {
			return arr[index];
		}
	}

	const T& operator[](int index) const {
		if ((index < 0) || (index >= size)) {
			throw outOfIndexExeption();
		}
		else {
			return arr[index];
		}
	}
};
