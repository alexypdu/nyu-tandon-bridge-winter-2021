#include <iostream>
using namespace std;

int main() {
   char inLetter;
   int level;

   cout << "Please enter a lower-case letter:\n";
   cin >> inLetter;
   level = inLetter - 'a';

   for (int diff = 0; diff <= level; diff++) {
       for (int counter = 1; counter <= level - diff; counter ++) {
           cout << ' ';
       }

       for (int counter = 1; counter <= 2 * diff + 1; counter ++) {
           if (diff % 2 == 0) {
               cout << char('a' + diff);
           } else {
               cout << char('A' + diff);
           }
       }

       cout << endl;
   }

   return 0;
}
