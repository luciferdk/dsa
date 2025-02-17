                Algorithm
step1 : take user input;
step2 : initilaze an array[] array should initialize to whole ascii variable and value 0 to avoid garbage value;
step3 : run loop and count the frequency of the user string and store on that array[];
step4 : run loop and use if condition that frequenc[i]>0 to avoid unual print and then display the requency;




#include <iostream>
#include <string>
using namespace std;
int main() {
    string input;
    cout << "Enter a string: ";
    getline(std::cin, input);

    int frequency[256] = {0};  // Array to store frequency of each ASCII character

    // Count the frequency of each character
 for (char ch : input) {
    frequency[(unsigned char)ch]++;  // Increase the count for this character
}
              
              //OR

for (int i = 0; i < input.length(); i++) {
    char ch = input[i];  // Get the character at position i
    frequency[(unsigned char)ch]++;  // Increase the count for this character
}



    // Display the frequency of each character
    cout << "Character frequencies:\n";
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            cout << (char)i << ": " << frequency[i] << "\n";
        }
    }

    return 0;
}

