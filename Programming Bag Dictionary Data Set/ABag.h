/*
* File:   ABag.h
* Author: Prof Terri Sipantzi
*
* You may use this template to implement your ABag. 
*/

#ifndef ABAG_H
#define	ABAG_H

#include "book.h"
#include "bagADT.h"

template <typename E>
class ABag : public Bag<E> {
public:
	ABag() {}
	ABag(int size) {
		used = 0;
		capacity = size;
		data = new E[size];
	}
	~ABag() {

	}
	// constructors/destructor

	bool addItem(const E& item) {
		if (used == capacity) return false;
		data[used++] =item;
		return true;
	}
	bool remove(E& item) {
		for (int i = 0; i < used; i++) {
			if (data[i]==item) {
				item =data[i];
				memset(&data[i], 0, sizeof(E)); //i mean, do we really need to do this?
				used--;
				return true;
			}
		}
		return false;
	}
	bool removeTop(E& returnValue) {
		if (used) {
			returnValue =data[--used];
			memset(&data[used], 0, sizeof(E)); //maybe not necessary
			return true;
		}
		return used;
	}
	bool find(E& returnValue) const {
		for (int i = 0; i < used; i++) {
			if (data[i]==returnValue) {
				returnValue =data[i];
				return true;
			}
		}
		return false;
	}
	bool inspectTop(E& item) const {
		if (used) {
			item =data[used - 1];
			return true;
		}
		return false;
	}
	void emptyBag() {
		memset(data, 0, used * sizeof(E)); //huh
		used = 0;
	}
	bool operator+=(const E& addend) {
		return addItem(addend);
	}
	int size() const { return used; }
	int bagCapacity() const { return capacity; }
	// bag methods: addItem, remove, operator+=, size, etc.

private:
	E* data;            // an array of items
	int used;           // number of items the data array currently holds
	int capacity;       // the number of items the bag can hold (size of array)
};

#endif	/* ABAG_H */

