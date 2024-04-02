/*
* File:   BDictionary.h -- implement a dictionary use an array-based bag
* Author: Prof Terri Sipantzi
*
* You may use this template to implement your Dictionary
*/


#ifndef BDICTIONARY_H
#define	BDICTIONARY_H

#include "ABag.h"
#include "dictionaryADT.h"
#include "kvpair.h"

template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E> {
public:
	BDictionary(const int size) {
		dictionary = new ABag<KVpair<Key, E>>(size);
	}
	~BDictionary() {

	}
	// constructors/destructor
	
	void clear() {
		dictionary->emptyBag();
	}
	bool insert(const Key& k, const E& e) {
		KVpair<Key, E> pair(k, e);
		//pair.Key=k; // k: The key for the record being inserted
		//pair.E = e; // e: The record being inserted
		return dictionary->addItem(pair);
	}
	bool remove(const Key& k, E& rtnVal) {
		if (this->find(k, rtnVal)) {
			//dictionary->remove(rtnVal);
			return true;
		}
		return false;
	}
	bool removeAny(E& returnValue) {
		if (dictionary->size() != 0) { //if not zero
			//this->remove(dictionary[0], returnValue);
			return true;
		}
		return false;
	}
	bool find(const Key& k, E& returnValue) const {
		//if (dictionary->find(k)){}
		for (int i = 0; i < dictionary->size(); i++) {
			//if (dictionary[i].find(k))
			//{
			//	return true;
			//}
		}
		return false;
	}
	int size() { return dictionary->size(); }
	// methods: clear, insert, remove, removeAny, find, size, etc.

private:
	ABag<KVpair<Key, E>>* dictionary;
	//Pointer to a ABag object.  You'll need to instantiate the bag in your constructor:
	// dictionary = new ABag<KVpair<Key, E>>(size) or something similar depending on how
	// you've implemented your ABag constructor(s).
	//This pointer gives you access to the bag which stores your data and provides the 
	//functions you need to build your dictionary.

};
#endif	/* BDICTIONARY_H */