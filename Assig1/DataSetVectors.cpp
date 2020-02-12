//Class: CS 3305 Section 05
//Term: Spring 2020
//Name: Justin Swiderski
//Instructor: Pablo Ordonez
//Assignment: One

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class DataSet{
	private :
		// a vector for random numbers in this DataSet
		vector<int> v;
		
		// average, sum, max, min and size values of DataSet
		double avg;
		int sum, mx, mn, size;
		
	public :
		// constructor
		DataSet() {}
		DataSet(int Size) {
			// clear and set a size of DataSet
			size = Size;
			v.clear();
			// set initial value of sum
			sum = 0;
			
			// build a DataSet
			for(int i = 0; i < size; i ++) {		
				// generate a number of DataSet from 1 to 1000
				v.push_back(rand()  % 10000 + 1);
				// calculation of sum
				sum += v[i];
			}
			// sort a DataSet
			sort(v.begin(), v.end());
			
			// set a min value and max value (min value is first value and max value is last value because a DataSet was sorted. )
			mn = v[0], mx = v[size - 1];
			
			// calculation average value from sum value
			avg = (double)sum / (double)size;
		}
		
		// get size of DataSet
		int getSize() const{
			return size;
		}
		
		// get i-th value of DataSet
		int getVal(int i) const{
			return v[i];
		}
		
		// get min value of DataSet
		int getMin() const{
			return mn;
		}
		
		// get max value of DataSet
		int getMax() const{
			return mx;
		}
		
		// get average value of DataSet
		double getAvg() const{
			return avg;
		}
		
		// get sum value of DataSet
		int getSum() const{
			return sum;
		}
		
		// destructor
		~DataSet(){
			v.clear();
		}
};

int main(int argc, char** argv) {
	// array of DataSet "Instances"
	DataSet data[3][4];
	
	// total size, min, max and average value of 3 DataSet
	double avgSize = 0.0, avgMin = 0.0, avgMax = 0.0, avgAll = 0.0;
	
	
	// Intializes random number generator
	time_t t;
   	srand((unsigned) time(&t));
   	
	for(int i = 0; i < 3; i ++) {
		for(int j = 0, k = 10; j < 4; j ++) {
			data[i][j] = DataSet(k);
			k *= 10;
		}
	}
	
	for(int i = 0; i < 3; i ++) {
		// print each set
		cout << "Set" << i + 1 << endl;
		for(int j = 0; j < 4; j ++) {
			// print 4 values of DataSet
			printf("%d\t %d\t %d\t %.1lf\n", data[i][j].getSize(), data[i][j].getMin(), data[i][j].getMax(), data[i][j].getAvg());
			
			// get sum of 4 values for average set
			avgSize += data[i][j].getSize();
			avgMin += data[i][j].getMin();
			avgMax += data[i][j].getMax();
			avgAll += data[i][j].getAvg();
		} printf("\n");
	}
	
	// calculation average values
	avgSize /= 12.0, avgMin /= 12.0, avgMax /= 12.0, avgAll /= 12.0;

	
	printf("Averages of three sets of data:\n%.1lf\t %.1lf\t %.1lf\t %.1lf\n\n", avgSize, avgMin, avgMax, avgAll);
	
	return 0;
}
