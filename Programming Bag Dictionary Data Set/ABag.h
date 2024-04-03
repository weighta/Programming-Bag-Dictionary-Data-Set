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
private: //I prefer privates on top
	E* data; //We'll make a pointer for this, and based on the constructor later define how many datas we want
	int used; //This will be how much of the data gets used
	int capacity; //The max capacity defined at compile time
public:
	/// <summary>
	/// This will be the main constructor, since it doesnt really make sense to instantiate the bag unless it has a fixed capacity
	/// </summary>
	/// <param name="size">The max capacity of the bag</param>
	ABag(int size) {
		used = 0; //We'll set used to 0, since it's necessary regarding nothing has been used yet
		capacity = size; //The bag's capacity will be the parameter passed
		data = new E[size]; //The data will become the size of the data inself
	}
	~ABag() {
		delete data; //just remove data since it is still on the heap
	}
	/// <summary>
	/// Adds an item to the bag and returns true if successful
	/// </summary>
	/// <param name="item">the item to add</param>
	/// <returns></returns>
	bool addItem(const E& item) {
		if (used == capacity) return false; //We can do this since no other line will execute if the bag is full and return false
		data[used++] =item; //we will assign a data (KVpair) with the item using the ' =' operator overload
		return true; //then we know it added, so return true
	}
	/// <summary>
	/// Removes an item from the bag
	/// </summary>
	/// <param name="item">the item we want to remove from the bag</param>
	/// <returns></returns>
	bool remove(E& item) {
		for (int i = 0; i < used; i++) { //Loop through all contents of the bag, but only to the used amount
			if (data[i]==item) { //we will use the '==' operator overload to check if the kvpair is the same
				item =data[i]; //the item can become what we were removing
				used--; //decrement used since we have now "removed" an item
				return true; //therefor, the operation was successful
			}
		}
		return false; //remove was unsucessful
	}
	/// <summary>
	/// removes the top item in the bag
	/// </summary>
	/// <param name="returnValue">The value which will be set to the top item</param>
	/// <returns></returns>
	bool removeTop(E& returnValue) {
		if (used) { //if not zero then there's items in the bag
			returnValue =data[--used]; //assign the top item being removed, note "--used" is used since we can decrement the value while retrieving it with n-1
			return true; //return true if the item was successfully removed
		}
		return used; //by definition, this will be false
	}
	/// <summary>
	/// Finds an item in the bag and assigns it
	/// </summary>
	/// <param name="returnValue">the value we will assign what we are looking for by the key</param>
	/// <returns></returns>
	bool find(E& returnValue) const {
		for (int i = 0; i < used; i++) { //loop through what exists in the bag
			if (data[i]==returnValue) { //if we have found the data with operator overload '==' on KVpair, then:
				returnValue =data[i]; //we will assign the return value's value with the data we found which had equal keys
				return true; //so we return true
			}
		}
		return false; //otherwise false
	}
	/// <summary>
	/// This will pull the top element in the bag and be useful later
	/// </summary>
	/// <param name="item">the item we are assigning</param>
	/// <returns></returns>
	bool inspectTop(E& item) const {
		if (used) { //if not zero, items exist in the bag
			item =data[used - 1]; //we need to assign item with n-1 index due to the count of items in the bag not being the same as the position of the last item in the bag
			return true; //return true, since we successfully retrieved the top element
		}
		return false; //otherwise false
	}
	void emptyBag() {
		used = 0; //this is all we need to do for several reasons:
		//The values in the bag are still there, but there's no reason to zero the data out since they'll just be re-assigned later anyway
		//This works instead of waisting time memsetting them zero when theres no purpose of actually doing so, hence saving resources on the hardware
	}
	/// <summary>
	/// Operator overload to add an item with '+='
	/// </summary>
	/// <param name="addend"></param>
	/// <returns></returns>
	bool operator+=(const E& addend) {
		return addItem(addend); //returns true if the item was successfully added while still adding the item
	}
	int size() const { return used; } //return the size of the bag
	int bagCapacity() const { return capacity; } //return the capacity of the bag
};

#endif

