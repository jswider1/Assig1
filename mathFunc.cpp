/*
* Class: CS 3305 Section 05
* Term: Spring 2020
* Name: Justin Swiderski
* Instructor: Pablo Ordonez
* Assignment: One
*/
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "math.h"
#include <algorithm>
using namespace std;

int sum(int x, int y);
double sqr(double z);
double pow(double t, double s);
int max(int arr1[]);
int min(int arr2[]);
int avg(int arr3[]);
void functionChoice(string str);
int main()
{
char ans;
while(true){
	while(true){
	string reply;
	cout << "Which math function would you now like to perform?\n";
	cout << "Please choose from the following list: \n";
	cout << "	1.  Simple Sum (2 variables) - \"sum\" \n";
    cout << "	2.  Square Root (1 variable) - \"sqr\" \n";
    cout << "	3.  Number raised to a power (2 variables - the number and the power) - \"pow\" \n";
    cout << "	4.  Max (5 variables - return the maximal value) - \"max\" \n";
    cout << "	5.  Min (5 variables - return the minimal value) - \"min\" \n";
    cout << "	6.  Average (5 variables - return the average) - \"avg\" \n";
	cin >> reply;
	functionChoice(reply);
	
		cout << "Would you like to perform another function? (Y/N)" << std::endl;
			cin >> ans;
			cin.ignore();
			if(ans == 'n' || ans == 'N' || ans == 'y' || ans == 'Y'){
				break;
				}else{
					cout << "Please enter \'Y\' or \'N\'. \n";
					}
		}
		if(ans == 'n' || ans == 'N'){
			cout << "Bye!" << std::endl;
			break;
			}else{
				cout << std::endl;
				}
	}
	//return EXIT_SUCCESS;
	return 0;
}
void functionChoice(string str){
	int num1, num2, nums, numb, nume;
	int arr1y[5]; int arr2y[5]; int arr3y[5];

	if(str == "sum"){
		cout << "Please enter the first number to be added: ";
		cin >> num1;
		cout << "Please enter the second number to be added: ";
		cin >> num2;
		int sumNum =sum(num1, num2);
		cout << sumNum << endl;
		}else if(str == "sqr"){
			cout << "Please enter the number for which you want the square root: ";
			cin >> nums;
			int sqrNum = sqr(nums);
			cout << sqrNum << endl;
			}else if(str == "pow"){
				cout << "Please enter the base number: ";
				cin >> numb;
				cout << "Please enther the exponent: ";
				cin >> nume;
				double powNum = pow(numb, nume);
				cout << powNum << endl;
				}else if(str == "max"){
					for(int i=0; i<5; i++){
						cout << "Please enter " << i+1 << " of 5: ";
						cin >> arr1y[i];
						}
					// Found this function on cplusplus...if I couldn't get my function to work
					//cout << "\nMax number from the list is " 
					//	 << *max_element(arr1y, arr1y +5) << ". \n\n";
					int maxNum = max(arr1y);
					cout << maxNum << endl;
					}else if(str == "min"){
						for(int i=1; i<=5; i++){
							cout << "Please enter " << i << " of 5: ";
							cin >> arr2y[i];
							}
						int minNum = min(arr2y);
						cout << minNum << endl;
						}else if(str == "avg"){
							for(int i=1; i<=5; i++){
								cout << "Please enter " << i << " of 5: ";
								cin >> arr3y[i];
								}
							int avgNum = avg(arr3y);
							cout << avgNum << endl;
							}else{
								cout << "Please enter \"sum\", \"sqr\", \"pow\", \"max\", \"min\", or \"avg\" to choose a function. \n";
								}
	}
int sum(int x, int y){
	int sumNum = x+y;
	cout << "The sum of the numbers entered is ";
	return sumNum;
	}
double sqr(double z){
	double sqrNum = sqrt(z);
	cout << "The square root of the number entered is ";
	return sqrNum;
	}
double pow(double t, double s){
	double newNum = t;
	for(int i=2; i<=s; i++){
		newNum = newNum*t;
		}
	cout << t << " to the power of " << s << " is ";
	return newNum;
	}
int max(int *arr1){
	for(int i=0; i<5; ++i){
		//cout << arr1[i] << endl; //error checking
		if(arr1[0] < arr1[i])
           arr1[0] = arr1[i];
		}
	cout << "Max number from list is ";
	return arr1[0];
	}
int min(int *arr2){
	for(int i=1; i<=5; ++i){
		if(arr2[0] > arr2[i])
			arr2[0] = arr2[i];
		}
	cout << "Min number from list is ";
	return arr2[0];
	}
int avg(int *arr3){
	int sum=0;
	int avg;
	for(int i=1; i<=5; i++){
		//cout << arr3[i] << endl; //error checking
		sum += arr3[i];
		}
	avg = sum/5;
	cout << "Average of list entered is ";
	return avg;
	}
