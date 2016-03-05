#pragma once

#include <string>

using namespace std;

class Element  // Define a linked list node 
{
public: int key;
		double x, y;
		string zipCode;
		Element *next;
		Element(int key_input = 0, string newZipCode="", double newX =0, double newY=0, Element *next_input=NULL) {
			key = key_input;
			zipCode = newZipCode;
			x = newX;
			y = newY;
			next = next_input;
		}
};


class HashTableS // separate chaining
{
	private:
		int m; // the size of the table
		Element ** T; // the hash table
		int Hash(string x); // the hash function
		const int RADIUS_MILES = 3961;

	public:
		HashTableS(int size);
		void Insert(string x, double y, double z); // insert a new element with key x and other info
		void Remove(string x); // remove an element whose key is x
		bool Search(string x); // search an element whose key is x and return true if found
		double ComputeDistance(string x1, string x2); // return the distance between two zip codes.
													  // assume both zip codes are valid ones.
		int CountTableEntry(int i); // return the number of elements in the ith slot of the hash table
		void PrintTableEntry(int i); // print the element in the hash table

	private:
		Element * FindElement(int index, string x);
		double HypotenousDistance(double x1, double y1, double x2, double y2);
};
