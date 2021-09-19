#pragma once
#include <iostream>
#include <exception>
using namespace std;

class itemDoesntExistException : public exception {};

//the class represent generic chained list
template <class T>

class List {

public:
	struct Item {
		T data;

		Item* next;

		Item(T newData) {
			data = newData;
			next = nullptr;
		}
	};
private:
	Item* head;
	Item* tail;

public:


	List() {
		head = nullptr;
		tail = nullptr;
	}

	~List() {
		Item* ptr;

		while (head) {
			ptr = head;
			head = head->next;
			delete ptr;
		}
	}

	List(const List& other) : List(){
		Item* p = other.getHead();
		
		while (p) {
			add(p->data);
			p = p->next;
		}
	}

	void operator=(const List& other) {
		if (other.isEmpty()) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			Item* p = other.getHead();

			while (p) {
				add(p->data);
				p = p->next;
			}
		}
	}

	void add(T newData) {
		Item *newItem = new Item(newData);
		if (tail) {
			tail->next = newItem;
		}
		if (!head) {
			head = newItem;
		}
		tail = newItem;
	}

	void makeEmpty() {

		while (head) {
			Item* temp = head;
			head = head->next;
			delete temp;
		}
		head = nullptr;
		tail = nullptr;
	}

	T deleteItem(T item) {
		Item* p = head;
		Item* pBack = nullptr;
		T removedData;

		while (p) {
			if (p->data == item) {
				
				if (p == tail) {
					tail = pBack;
				}

				if (p == head) {
					head = p->next;
				}
				else {
					pBack->next = p->next;
				}
				removedData = p->data;
				delete p;
				return removedData;
				
			}
			pBack = p;
			p = p->next;
		}

		throw itemDoesntExistException();
	}

	T deleteHead() {
		if (isEmpty()) {
			throw itemDoesntExistException();
		}
		else {

			Item *temp = head;
			T removedData = head->data;
			head = head->next;
			delete temp;
			if (tail == temp) {
				tail = nullptr;
			}
			return removedData;
		}
	}

	bool isExist(T item) const {

		Item* p = head;

		while (p) {
			if (p->data == item) {
				return true;
			}

			p = p->next;
		}

		return false;

	}

	 bool isEmpty() const {
		return (!head);
	}

	Item *getHead() const {
		return head;
	}


	//for debugging
	void printList() {
		Item* p = head;

		while (p) {
			cout << "data : " << p->data << endl;
			cout << "next : " << p->next << endl;

				p = p->next;
		}
	}
};
