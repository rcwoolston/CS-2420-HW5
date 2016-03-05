#pragma once
#include <string>
#include "HashTableQ.h"

using namespace std;

HashTableQ::HashTableQ(int size) {
	m = size;
	T = new ElementQ[m];
	for (int i = 0; i <= m - 1; i++) {
		T[i].flag = 0;
		T[i].key = i;
	}
}

int HashTableQ::Hash(int x) { 
	return x % m; 
}

void HashTableQ::Insert(string x, double y, double z) {
	int i = 0; 
	while (i < m) {
		int k = QuadraticProbe(stoi(x), i);
		if(T[k].flag != 1) // flag: 0: empty; 1: active; 2: deleted 
		{ 
			T[k].zipCode = x;    
			//T[k].key = Hash(stoi(x));
			T[k].x = y;
			T[k].y = z;
			T[k].flag = 1;     
			return; 
		} 
		else i ++; 
	}
}

int HashTableQ::QuadraticProbe(int x, int i) {
	return (Hash(x) + i*i) % m;
}

bool HashTableQ::Search(string x) {
	int i = 0;
	int flag = 1;
	while (flag == 1) {
		int k = QuadraticProbe(stoi(x), i);
		if (T[k].zipCode.compare(x) == 0) {
			return true;
		}
		else if (T[k].flag != 1) {
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
	while (flag == 1) {
		int k = QuadraticProbe(stoi(x), i);
		if (T[k].zipCode.compare(x) == 0) {
			T[k].flag = 2;
			T[k].zipCode = "";
			T[k].x = 0;
			T[k].y = 0;
			//T[k].key=
		}
		else if (T[k].flag != 1) {
			flag = T[k].flag;
		}
		else {
			i++;
		}
	}
}