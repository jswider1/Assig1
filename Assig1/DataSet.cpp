// Class: CS 3305 Section 05
// Term: Spring 2020
// Name: Justin Swiderski
// Instructor: Pablo Ordonez
// Assignment: One

#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include "DataSet.h"

// empty contructor as requested by prof.
DataSet::DataSet() {}

// overloaded constructor "where all the magic happens"
DataSet::DataSet(int Size) {
	// clear and set a size of DataSet
	size = Size;
	v.clear();
	// set intitial value
	sum = 0;
	
	// build a DataSet
	for(int i=0; i<size; i++) {
		v.push_back(rand() % 10000 +1);
		// calculation of sum while generating the set
		sum += v[i];
	}
	// sort a DataSet so it's easier to find the max and min
	sort(v.begin(), v.end());
	// set a min value and max value
	mn = v[0], mx = v[size -1];
	// calculate average value from sum value
	avg = (double)sum / (double)size;
}

// destructor
DataSet::~DataSet() {
	// clearing vector
	v.clear();
}
// get size of Dataset
int DataSet::getSize() const{
	return size;
}
// get i-th value of DataSet
int DataSet::getVal(int i) const{
	return v[i];
}
// get min value of DataSet
int DataSet::getMin() const{
		return mn;
}
// get max value of DataSet
int DataSet::getMax() const{
		return mx;
}
// get average value of DataSet
double DataSet::getAvg() const{
		return avg;
}
// get sum value of DataSet
int DataSet::getSum() const{
		return sum;
}
