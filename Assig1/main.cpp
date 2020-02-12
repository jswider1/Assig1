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

int main(int argc, char **argv) {
	// array of DataSet "Instances"
	DataSet data[3][4];
	
	// total size, min, max and average value of 3 DataSet
	double avgSize = 0.0, avgMin = 0.0, avgMax = 0.0, avgAll = 0.0;
	
	// initializes random number generator
	time_t t;
	srand((unsigned) time(&t));

	for(int i=0; i<3; i++) {
		for(int j=0, k=10; j<4; j++) {
			data[i][j] = DataSet(k);
			k *= 10;
		}
	}
	// print each set
	for(int i=0; i<3; i++) {
		std::cout << "Set " << i+1 << std::endl;
		for(int j=0; j<4; j++) {
			// print 4 values of DataSet 
			printf("%d\t %d\t %d\t %.1lf\n", data[i][j].getSize(), data[i][j].getMin(), data[i][j].getMax(), data[i][j].getAvg());
			
			// get sum of 4 values for average set
			avgSize += data[i][j].getSize();
			avgMin += data[i][j].getMin();
			avgMax += data[i][j].getMax();
			avgAll += data[i][j].getAvg();
		} printf("\n");
	}
	// calculate average values
	avgSize /= 12.0, avgMin /= 12.0, avgMax /= 12.0, avgAll /= 12.0;
	
	printf("Averages of the three sets of data: \n%.1lf\t %.1lf\t %.1lf\t %.1lf\n\n", avgSize, avgMin, avgMax, avgAll);
	
	return 0;
}
