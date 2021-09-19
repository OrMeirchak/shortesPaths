#pragma once
#include "List.h"
//the function represent generic queue impliment by list
template <class T>
class Queue {


private:
	List<T> list;

public:

	void enqueue(T newItem) {
		list.add(newItem);
	}

	T dequeue() {
		return list.deleteHead();
		}

	bool isEmpty() {
		return list.isEmpty();
		}

	void makeEmpty() {
		list.makeEmpty();
	}

};
