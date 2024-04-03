/*
* File:   bagtestmain.cpp
* Author: Prof Sipantzi -- CSIS 215 -- Programming Assignment 1 -- Bag Dictionary
*
* Created on July 14, 2012, 11:45 AM
* Updated pointers to smart pointers in ABag and BDictionary on 12/14/2018
*
* In this assignment BDictionary.h and ABag.h need changed
*
*/

/*
* Alexander P. Weight
* Professor Jason Christian
* CSIS215: Algorithms and Data Structures (D02)
* April 1, 2024
*/


#include <string> //I don't know about this, I would avoid string entirely
#include <sstream>
#include "ABag.h"
#include "BDictionary.h"
#include "macros.h"

//using namespace std; -- this can be hard later on, so just in case let's call std in a macro and simplify the whole line with say(m)

const size_t DICTIONARY_SIZE = 20;

void PauseScreen(); //Used to pause screen output

/*
* Tests BDictionary with int and string objects only.
*/
int main(int argc, char** argv) {
	sayl("<Student Name> -- CSIS 215 Programming Assignment 1 -- Bag Dictionary\n");

	BDictionary<int, string> myIntStrDict(DICTIONARY_SIZE);
	BDictionary<string, int> myStrIntDict(DICTIONARY_SIZE);

	// myIntStrDict tests
	// INSERT: myIntStrDict
	sayl("Testing dictionary with <int, string> KV Pair");
	for (int i = 1; i <= DICTIONARY_SIZE; i++) {
		std::stringstream sn;
		sn << "Beth " << i * 10;
		myIntStrDict.insert(i * 10, sn.str());
	}
	sayl("INSERT: Size of myIntStrDict is " << myIntStrDict.size());

	// REMOVEANY: myIntStrDict
	string strData;
	if (myIntStrDict.removeAny(strData)) {
		sayl("REMOVEANY: My string data is " << strData);
	}
	else {
		sayl("RemoveAny() failed -- dictionary is empty.");
	}
	sayl("Size of myIntStrDict is " << myIntStrDict.size());

	// FIND: test for myIntStrDict.find
	int intKey = 40;
	if (myIntStrDict.find(intKey, strData)) {
		sayl("FIND: My data at key==" << intKey << " is: " << strData);
		sayl("Size of myIntStrDict is " << myIntStrDict.size());
	}
	else {
		sayl("Could not find a record at " << intKey);
	}

	// REMOVE: myIntStrDict
	intKey = 60;
	if (myIntStrDict.remove(intKey, strData)) {
		sayl("REMOVE: Removed key " << intKey << " which was " << strData);
	}
	else {
		sayl("Could not find key " << intKey);
	}
	sayl("Size of my dictionary is " << myIntStrDict.size());

	// CLEAR: myIntStrDict
	myIntStrDict.clear();
	sayl("CLEAR: Size of myIntStrDict is " << myIntStrDict.size() << "\n");

	/* end myIntStrDict tests ---------------------------------------------*/

	// myStrIntDict tests
	// INSERT: myStrIntDict
	sayl("Testing dictionary with <string, int> KV Pair");
	myStrIntDict.insert("Terri", 57);
	myStrIntDict.insert("Beth", 53);
	myStrIntDict.insert("Jeremy", 19);
	myStrIntDict.insert("Nathan", 17);
	myStrIntDict.insert("Zipper", 2);
	myStrIntDict.insert("Button", 1);
	myStrIntDict.insert("Kiwi", 7);
	myStrIntDict.insert("Masoala", 10);

	sayl("INSERT: Size of myStrIntDict is " << myStrIntDict.size());

	// REMOVEANY: myStrIntDict
	int intData;
	if (myStrIntDict.removeAny(intData)) {
		sayl("REMOVEANY: My int data is " << intData);
	}
	else {
		sayl("RemoveAny() failed -- dictionary is empty.");
	}
	sayl("Size of myIntStrDict is " << myStrIntDict.size());

	// FIND: myStrIntDict.find
	string strKey = "Kiwi";
	if (myStrIntDict.find(strKey, intData)) {
		sayl("FIND: " << strKey << "\'s age is " << intData);
		sayl("Size of myStrIntDict is " << myStrIntDict.size());
	}
	else {
		sayl("Could not find a record at " << strKey);
	}

	// REMOVE: myStrIntDict
	strKey = "Button";
	if (myStrIntDict.remove(strKey, intData)) {
		sayl("REMOVE: Removed key " << strKey << " which was " << intData);
	}
	else {
		sayl("Could not find key " << strKey);
	}
	sayl("Size of my dictionary is " << myStrIntDict.size());

	// CLEAR: myStrIntDict
	myStrIntDict.clear();
	sayl("CLEAR: Size of myStrIntDict is " << myStrIntDict.size() << "\n");

	/* end myStrIntDict tests ---------------------------------------------*/

	/* Demonstrate any Bag functions that were not used/demonstrated in the implemention
	of your BDictionary and ABag using a Bag of KVpairs<int, string>. */

	//Let's see we have insert, removeany, remove, find, and size, and clear, but we can try different types

	ABag<KVpair<char, int>> myBag(3); //Used to test bag functions not previously demonstrated
	KVpair<char, int> pair('\23', 23);
	sayl("Adding pair with <char, int>:");
	myBag.addItem(pair);
	sayl("Number of myBag items: " << myBag.size());
	myBag.removeTop(pair);
	sayl("Number of myBag items after removal: " << myBag.size());

	PauseScreen();

	return 0;
}

//Used to pause the screen wherever desired
void PauseScreen()
{
	char ch;
	say("\nPress the Enter key to continue ... ");
	std::cin.get(ch);
}