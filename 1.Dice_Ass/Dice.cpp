#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() { 
//write a program to roll a dice to get two random value btw 1 - 6
srand(time(0));
int dice1 = (rand() % 6) + 1;
int dice2 = (rand() % 6) + 1;
cout << "Dice 1: " << dice1 << endl;
cout << "Dice 2: " << dice2 << endl;
return 0;
}
  
