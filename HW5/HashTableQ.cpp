#pragma once
#include <string>
#include "HashTableQ.h"
#include <iostream>

using namespace std;

HashTableQ::HashTableQ(int size) {
	m = size;
	T = new ElementQ[m];
	for (int i = 0; i <= m - 1; i++) {
		T[i].flag = 0;
		T[i].key = i;
	}
}

int HashTableQ::Hash(string x) {
	return (stoi(x) % m); 
}

void HashTableQ::Insert(string x, double y, double z) {
	int i = 0; 
	count++;
	while (true) {
		int k = QuadraticProbe(x, i);
		if(T[k].flag != 1) // flag: 0: empty; 1: active; 2: deleted 
		{ 
			T[k].zipCode = x;    
			T[k].x = y;
			T[k].y = z;
			T[k].flag = 1;     
			return; 
		} 
		else i ++; 
	}
}

int HashTableQ::QuadraticProbe(string x, int i) {
	return (Hash(x) + i*i) % m;
}

bool HashTableQ::Search(string x) {
	int i = 0;
	int flag = 1;
	while (flag == 1) {
		int k = QuadraticProbe(x, i);
		if (T[k].zipCode.compare(x) == 0) {
			return true;
		}
		else if (T[k].flag == 0) {
			flag = T[k].flag;
		}
		else {
			i++;
		}
	}

	return false;
}

void HashTableQ::Remove(string x) {
	int i = 0;
	int flag = 1;
	bool found = false;
	while (flag == 1 && !found) {
		int k = QuadraticProbe(x, i);
		if (T[k].zipCode.compare(x) == 0) {
			T[k].flag = 2;
			T[k].zipCode = "";
			T[k].x = 0;
			T[k].y = 0;
			flag = 2;
		}
		else if (T[k].flag != 1) {
			flag = T[k].flag;
		}
		else {
			i++;
		}
	}
}

double HashTableQ::ComputeDistance(string x1, string x2) {
	int indexOne = Hash(x1);
	int indexTwo = Hash(x2);

	ElementQ elementOne = FindElement(indexOne, x1);
	ElementQ elementTwo = FindElement(indexTwo, x2);

	return Haversine(elementOne.x, elementOne.y, elementTwo.x, elementTwo.y);
	
}

ElementQ HashTableQ::FindElement(int index, string x) {
	int i = 0;
	int flag = 1;
	while (flag == 1) {
		int k = QuadraticProbe(x, i);
		if (T[k].zipCode.compare(x) == 0) {
			return T[k];
		}
		else if (T[k].flag == 0) {
			flag = T[k].flag;
			i++;
		}
		else {
			i++;
		}
	}

	return NULL;
}

double HashTableQ::Haversine(double x1, double y1, double x2, double y2) {
	double pi = 3.1415926535897;
	return (RADIUS_MILES * 2 * asin(sqrt(pow(sin((x2*(pi / 180) - x1*(pi / 180)) / 2.0), 2.0) + cos(x1*(pi / 180))*cos(x2*(pi / 180))*pow(sin((y2*(pi / 180) - y1*(pi / 180)) / 2.0), 2.0))));
}

void HashTableQ::PrintTableEntry(int i) {
	ElementQ here = T[i];

	cout << endl << endl;
	cout << "Key value entries: " << i << endl;

	cout << "Zipcode: " << here.zipCode << "  X: " << here.x << "  Y: " << here.y << endl;
	
}

void HashTableQ::PrintTableEntry() {
	int here = 0;
	while (here < m) {
		if (T[here].flag == 1) {
			PrintTableEntry(here);
		}
		here++;
	}
}
