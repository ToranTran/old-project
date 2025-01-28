#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Add all occurences of goal value
int CheckSingles(vector<int>& diceValues, int goal) {
   int sum = 0;
   for(unsigned int i = 0; i < diceValues.size(); i++) {
      if(diceValues[i] == goal) {
         sum += diceValues[i];
      }
   }
   return sum;
}

// Check for three of a kind (score = 30)
int CheckThreeOfKind(vector<int>& diceValues) {
   int count = 0;
   for(unsigned int i = 0; i < diceValues.size() - 1; i++) {
      if(diceValues[i] == diceValues[i + 1]) {
         count++;
      }
   }
   if(count == 2) {
      return 30;
   }
   return -1;
}


// Check for four of a kind (score = 40)
int CheckFourOfKind(vector<int>& diceValues) {
   int count = 0;
   for(unsigned int i = 0; i < diceValues.size() - 1; i++) {
      if(diceValues[i] == diceValues[i + 1]) {
         count++;
      }
   }
   if(count == 3) {
      return 40;
   }
   return -1;
}

// Check for five of a kind (score = 50)
int CheckFiveOfKind(vector<int>& diceValues) {
   int count = 0;
   for(unsigned int i = 0; i < diceValues.size() - 1; i++) {
      if(diceValues[i] == diceValues[i + 1]) {
         count++;
      }
   }
   if(count == 4) {
      return 50;
   }
   return -1;
}

// Check for full house (score = 35)
int CheckFullHouse(vector<int>& diceValues) {
   if((diceValues[0]==diceValues[1] && diceValues[2]==diceValues[4]) || (diceValues[0]==diceValues[2] && diceValues[2]==diceValues[4])) {
        return 35;
   }
   return -1;
}

// Check for straight (score = 45)
int CheckStraight(vector<int>& diceValues) {
   int count = 0;
   for(unsigned int i = 0; i < diceValues.size() - 1; i++) {
      if(diceValues[i] == diceValues[i + 1] - 1) {
         count++;
      }
   }
   if(count == 4) {
      return 45;
   }
   return -1;
}

// Find high score
int FindHighScore(vector<int>& diceValues) {
   if(CheckThreeOfKind(diceValues) != -1) {
      return CheckThreeOfKind(diceValues);
   }
   else if(CheckFourOfKind(diceValues) != -1) {
      return CheckFourOfKind(diceValues);
   }
   else if(CheckFiveOfKind(diceValues) != -1) {
      return CheckFiveOfKind(diceValues);
   }
   else if(CheckFullHouse(diceValues) != -1) {
      return CheckFullHouse(diceValues);
   }
   else if(CheckStraight(diceValues) != -1) {
      return CheckStraight(diceValues);
   }
   int sum = 0;
   for(int i = 0; i <= 6; i++) {
      if(CheckSingles(diceValues, i) > sum) {
         sum = CheckSingles(diceValues, i);
      }
   }
   return sum;
}

int main() {
   vector<int> diceValues(5);
   int highScore = 0;

   // Fill array with five values from input
   for(int i = 0; i < 5; ++i) {
      cin >> diceValues.at(i);
   }

   // Place values in ascending order
   sort(diceValues.begin(), diceValues.end());
    for(int i = 0; i < diceValues.size(); i++) {
        cout << diceValues[i] << " ";
    }
    cout << endl;

   // Find high score and output
   highScore = FindHighScore(diceValues);
   cout << "High score: " << highScore << endl;

   return 0;
}
