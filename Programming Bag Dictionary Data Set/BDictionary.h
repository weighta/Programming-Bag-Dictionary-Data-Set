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
private: //I like private on the top
	ABag<KVpair<Key, E>>* dictionary; //declare an array (IE pointer) to the bag with items in it
public:
	/// <summary>
	/// Let the constructor take in a size argument for a bag size, and from there, the types in kvPair<Key, E> can work on their own
	/// </summary>
	/// <param name="size">The size of the bag ABag</param>
	BDictionary(const int size) {
		dictionary = new ABag<KVpair<Key, E>>(size); //create a bag with the size specified in the parameter
	}
	~BDictionary() { //deconstructor
		delete dictionary; //memory management
	}
	/// <summary>
	/// we can clear the bag simply by refering to the base class's clear and emptying the bag
	/// </summary>
	void clear() {
		dictionary->emptyBag();
	}
	/// <summary>
	/// insert an item into the bag with the Key and Value by reference
	/// </summary>
	/// <param name="k">Key</param>
	/// <param name="e">Value</param>
	/// <returns></returns>
	bool insert(const Key& k, const E& e) {
		KVpair<Key, E> pair(k, e); //To simplify things, let's create a pair so this type matches the type E in the base class ABag
		//No need to assign what was inserted!
		return dictionary->addItem(pair); //we'll still refer to the base class's addItem
	}
	/// <summary>
	/// Removes an item from the bag
	/// </summary>
	/// <param name="k">the key value</param>
	/// <param name="rtnVal">the value (which will change by reference)</param>
	/// <returns></returns>
	bool remove(const Key& k, E& rtnVal) {
		KVpair<Key, E> pair(k, rtnVal); //To remove the item, we need another KVpair<Key, E> type to match the input parameter for ABag::remove()
		if (dictionary->remove(pair)) { //First, let's see if the item successfully removes before assigning rtnValue with pair.Value()
			rtnVal = pair.value(); //We will grab the value we removed
			return true; //Then, we'll know it successfully removed it.
		}
		return false; //if it couldnt be located or removed, then return false
	}
	/// <summary>
	/// Removes the top item out of the bag
	/// </summary>
	/// <param name="returnValue">The value passed by reference to return</param>
	/// <returns></returns>
	bool removeAny(E& returnValue) {
		KVpair<Key, E> pair; //Trivial but not really; even without a Key we can still declare a pair, and then...
		if (dictionary->inspectTop(pair)) { //we can assign the pair using ABag's inspectTop function
			returnValue = pair.value(); //Now it's easy, since all we need to do is assign the returnValue with KVpair<Key, E>::value();
			return dictionary->removeTop(pair); //this will also return the bool on if it was successfully removed, which by definition, is inherintly true
		}
		return false; //if none to remove, then return false
	}
	/// <summary>
	/// Finds an item in the bag and returns true if successful
	/// </summary>
	/// <param name="k">The key for finding the item</param>
	/// <param name="returnValue">the actual value itself for finding the item, which will be returned</param>
	/// <returns></returns>
	bool find(const Key& k, E& returnValue) const {
		KVpair<Key, E> pair(k, returnValue); //First create a KVpair
		if (dictionary->find(pair)) { //Make sure the pair exists
			returnValue = pair.value(); //IFF it exists, then assign the return value
			return true; //it exists, so return true
		}
		return false; //otherwise false
	}
	/// <summary>
	/// return the size of the bag. Note the function is set to const since we are promising the compiler we will not change the function past this point
	/// </summary>
	/// <returns></returns>
	int size() const { return dictionary->size(); }
};
#endif