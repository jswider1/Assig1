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
#include <ctime>

// SIZE will determine the scope of the random numbers generator
const int SIZE = 100;
int gn,sn;
char ans;
int attempts;
const int guessMax = 3;
// random number generator function
void secretNumber();
// comparing generated # and guessed #
void compareNumbers(int x);

int main()
{
while(true){
	while(true){ // loop for new random number game
	std::cout << "Your are playing the secret number guessing game!" << std::endl;
	std::cout << "A random number from 1 to " << SIZE << " is now being generated." << std::endl;
	secretNumber();
	attempts = 0;
	while(sn != gn){ 
		std::cout << "Number of guesses remaining: "<< guessMax - attempts << ", good luck!" << std::endl;
		std::cout << "Please pick a number between 0 and " << SIZE << "." << std::endl;
		std::cin >> gn;
		std::cout << "\nYou chose " << gn << " for your number." << std::endl;
		attempts ++;
		compareNumbers(gn);
		while(sn != gn && attempts<guessMax){ // loop to keep guessing or to give up trying
			std::cout << "Would you like to keep guessing? (Y/N)" << std::endl;
			std::cin >> ans;
			std::cin.ignore();
			if(ans == 'n' || ans == 'N' || ans == 'y' || ans == 'Y'){
				break;
				}else{
					std::cout << "Please enter \'Y\' or \'N\'.\n";
					}
		}
		if(ans == 'n' || ans == 'N'){
			std::cout << "Quitter." << std::endl;
			break;
			}else
		if(attempts==guessMax && sn != gn){
			std::cout << "\nSorry, you ran out of attempts.\n";
			break;
			}else{
				std::cout << "\n";
				}
		}
			std::cout << "Would you like to play again with a new secret number? (Y/N)" << std::endl;
			std::cin >> ans;
			std::cin.ignore();
			if(ans == 'n' || ans == 'N' || ans == 'y' || ans == 'Y'){
				break;
				}else{
					std::cout << "Please enter \'Y\' or \'N\'. \n";
					}
		}
		if(ans == 'n' || ans == 'N'){
			std::cout << "Thank you for playing." << std::endl;
			break;
			}else{
				std::cout << std::endl;
				}
	}
	return EXIT_SUCCESS;
}

void secretNumber(){
	srand(time(NULL));
	sn = rand() % 100 + 1;
	// comment out to play the game for real, just here for testing
	std::cout << "\n ***for testing purposes*** " << sn << std::endl;
	}
	
void compareNumbers(int x){
	//attempts ++;
	if(x < 1 || x > SIZE){
		std::cout << "\nYou chose a number that is out of the scope of the randome generator." << std::endl;
	}
	else if(sn != x){
		std::cout << "\nYou did not choose the random secret number correctly." << std::endl;
	}
	else{
		std::cout <<"You made " << attempts << " attempts to find the secret number! \n     The secret number is "
		<< gn << ".\n        Congratulations!";
	}
	}
