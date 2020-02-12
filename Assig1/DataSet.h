// Class: CS 3305 Section 05
// Term: Spring 2020
// Name: Justin Swiderski
// Instructor: Pablo Ordonez
// Assignment: One

#ifndef _DATASET_H_
#define _DATASET_H_

#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

//using namespace std;

class DataSet{
	private:
		// a vector for random numbers in this DataSet
		std::vector<int> v;
		// average, sum, max, min and size values of DataSet
		double avg;
		int sum, mx, mn, size;
		
	public:
		// empty constructor as requested
		DataSet();
		// overloaded constructor "where all the magic happens"
		DataSet(int Size);
		// destructor
		~DataSet();
		// get size of DataSet
		int getSize() const;
		// get i-th value of DataSet
		int getVal(int i) const;
		// get min value of DataSet
		int getMin() const;
		// get max value of DataSet
		int getMax() const;
		// get average value of DataSet
		double getAvg() const;
		// get sum value of DataSet
		int getSum() const;
};

#endif // _DATASET_H_
