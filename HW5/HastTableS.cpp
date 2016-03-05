#include "HashTableS.h"
#include <string>
#include <iostream>

using namespace std;

HashTableS::HashTableS(int size)
{ 
	m = size;   
	T = new Element *[m]; 
	for (int i = 0; i <= m - 1; i++) {
		T[i] = NULL;
	}
}

int HashTableS::Hash(string s) {
	int value = NULL;

	// Modulate the zipe code by the size of the hash table
	value = stoi(s) % m;
	return value;
}

void HashTableS::Insert(string x, double y, double z) {
	int value = Hash(x);
	Element *temp = new Element(value, x, y, z,NULL);
	
	//Insert into array of Linked Lists
	if (T[value] == NULL) {
		T[value] = temp;
	}
	else {
		temp->next = T[value];
		T[value] = temp;
	}
}

int HashTableS::CountTableEntry(int i) {
	Element *here = T[i];
	int count = 0;

	while (here != NULL) {
		here = here->next;
		count++;
	}

	return count;
}

void HashTableS::PrintTableEntry(int i) {
	Element *here = T[i];

	cout << endl << endl;
	cout << "Key value entries: " << i << endl;

	while (here != NULL) {
		cout << "Zipcode: " << here->zipCode << "  X: " << here->x << "  Y: " << here->y << endl;
		here = here->next;
	}
}

bool HashTableS::Search(string x) {
	int value = Hash(x);

	Element *here = T[value];

	while (here != NULL) {
		if (here->zipCode.compare(x)==0) {
			return true;
		}
		else {
			here = here->next;
		}
	}

	return false;
}

void HashTableS::Remove(string x) {
	int value = Hash(x);

	if (T[value]->zipCode.compare(x) == 0) {
		if (T[value]->next == NULL) {
			delete T[value];
			T[value] = NULL;
		}
		else {
			Element *temp = T[value];
			T[value] = T[value]->next;
			delete temp;
			temp = NULL;
		}
	}
	else {
		Element *here = T[value];
		Element *prev = here;
		here = here->next;
		while (here != NULL) {
			if (here->zipCode.compare(x) == 0) {
				if (here->next == NULL) {
					delete here;
					here = NULL;
					prev->next = NULL;
				}
				else {
					prev->next = here->next;
					delete here;
					here = NULL;
				}
			}
			else {
				prev = here;
				here = here->next;
			}
		}
	}
}

double HashTableS::ComputeDistance(string x1, string x2) {
	int indexOne = Hash(x1);
	int indexTwo = Hash(x2);

	Element *elementOne = FindElement(indexOne, x1);
	Element *elementTwo = FindElement(indexTwo, x2);

	if (elementOne == NULL) {
		cout << endl << "ZIPCODE ONE DOES NOT EXISTS" << endl;
		return NULL;
	}
	else if (elementTwo == NULL) {
		cout << endl << "ZIPCODE TWO DOES NOT EXISTS" << endl;
		return NULL;
	}
	else {
		return HypotenousDistance(elementOne->x, elementOne->y, elementTwo->x, elementTwo->y);
	}
}

Element * HashTableS::FindElement(int index, string x) {
	Element *here = T[index];

	while (here != NULL) {
		if (here->zipCode.compare(x) == 0) {
			return here;
		}
		else {
			here = here->next;
		}
	}
	// That zip code does not exist
	return NULL;
}

double HashTableS::HypotenousDistance(double x1, double y1, double x2, double y2) {
	return RADIUS_MILES * (2 * asin(sqrt((sin((x2 - x1) / 2)*sin((x2 - x1) / 2)) - cos(x1)*cos(x2)*((sin((y2 - y1) / 2)*sin((y2 - y1) / 2))))));
}