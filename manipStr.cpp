/*
* Class: CS 3305 Section 05
* Term: Spring 2020
* Name: Justin Swiderski
* Instructor: Pablo Ordonez
* Assignment: One
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

bool palindrome(const std::string& theStr);
void wordPlay(std::string, int& x);
void letterMatch(std::string str[], int n);
const int MAX_CHAR = 26;
int main()
{
	//std::string str[];
	std::string str1;
	std::string str2;
	std::string str3;
	std::string str4;
	std::string userStr;
	std::string newStr;
	// loop to retrieve and play with two strings
	for(int c=0; c<2; c++){
		std::cout << "Please enter word " << c+1 << " of 2: ";
		getline (std::cin, userStr);
		if(c<1){
		str1 = userStr;
		wordPlay(str1, c);
		}else{
			wordPlay(userStr, c);
			break;
			}
		}
	// campare member function from string class
	if(userStr.compare(str1) !=0){
		std::cout << "The words " << str1 << " and " << userStr << " do not match.\n";
		}else{
			std::cout << "The words " << str1 << " and " << userStr << " are the same.\n";
			}
	std::cout << "\nPlease enter four words and we'll find the letters that appear in all strings.\n";
	// loop to retrieve the four strings
	for(int c=0; c<4; c++){
		std::cout << "Please enter word " << c+1 << " of 4: ";
		getline (std::cin, userStr);
		if(c<1){
		str1 = userStr;
		} if(c<2){
			str2 = userStr;
			} if(c<3){
				str3 = userStr;
				}else{
					str4 = userStr;
					}
		}
	//std::cout << str1 << str2 << str3 << str4 << std::endl;
	std::string str[] = {str1, str2, str3, str4};
	int n = sizeof(str)/sizeof(str[0]);
	letterMatch(str, n);

	return EXIT_SUCCESS;
}
// function to test for palindrome - just returns true or false
bool palindrome(const std::string& theStr){
	if(theStr.empty()){
		return false;
		}
	int i = 0;
	int j = theStr.length()-1;
	while(i<j){
		if(theStr[i] != theStr[j]){
			return false;
			}
			i++;j--;
		}
		return true;
	}
// function Objectives 1-6
void wordPlay(std::string s, int& x){
	int n = x+1;
	std::cout << "Word " << n << " is: " << s << "\n";
	std::cout << "Your word reversed is: ";
	// cool public member function I found on cplusplus "reverse_iterator"
	for(std::string::reverse_iterator rit=s.rbegin(); rit!=s.rend(); ++rit){
		std::cout << *rit;
	}
	if(palindrome(s)){
		std::cout << "\nThis word is a palindrome.\n";
		}else{
			std::cout << "\nThis word is not a palindrome.\n";
			}
	std::cout << "The word is " << s.length() << " characters long.\n";
	int k = s.length();
	// another cool member function I found on cplusplus "substr"
	std::cout << "The first half of the word is " << s.substr(0,k/2) << std::endl;
	std::cout << "The first letter is " << s.at(0) << ".\n" << std::endl;
	}
// function to compare letters from each string passed through
void letterMatch(std::string str[], int n){
	// fill block of memory
	bool prim[MAX_CHAR];
	memset(prim, true, sizeof(prim));
	for(int i=0; i<n; i++){
		bool sec[MAX_CHAR] = {false};
		for(int j=0; str[i][j]; j++){
			// if character is a match then mark it
			if(prim[str[i][j] - 'a']){
				sec[str[i][j] - 'a'] = true;
				}
			}
		memcpy(prim, sec, MAX_CHAR);	//second array copied over to primary
		}
	// common char's printed
	for(int i=0; i<26; i++){
		if(prim[i]){
			printf("%c ", i + 'a');
			std::cout << std::endl;
			}
		}
	}
