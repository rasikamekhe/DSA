/* A palindrome is a string of character that‘s the same forward and backward. Typically,
punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a
droop” is a palindrome, as can be seen by examining the characters “poor danisina
droop” and observing that they are the same forward and backward. One way to check
for a palindrome is to reverse the characters in the string and then compare with them
the original-in a palindrome, the sequence will be identical. Write C++ program with
functions-
a)To print original string followed by reversed string using stack
b)To check whether given string is palindrome or not */


#include <iostream>
#include <cstring> // For strlen, strcmp
#include <cctype>  // For islower, isupper
#define MAX 50
using namespace std;

class STACK {
private:
    char a[MAX]; // Array to simulate the stack
    int top;     
    // Constructor 
    STACK() {
        top = -1;
    }

    // Method to push a character onto the stack
    void push(char c) {
        if (top >= MAX - 1) { // Check for stack overflow
            cout << "\nStack Overflow! Cannot push more characters.";
            return;
        }
        top++;          // Increment the top pointer
        a[top] = c;     // Add the character to the stack
        cout << c << " is pushed into the STACK!\n";
    }

    // Method to reverse and print the string using the stack
    void reverse() {
        cout << "\nReverse string is: ";
        // Traverse the stack from top to bottom
        for (int i = top; i >= 0; i--) {
            cout << a[i]; // Print characters in reverse order
        }
        cout << endl;
    }

    // Method to convert the string:
    // 1. Removes non-alphabetic characters
    // 2. Converts uppercase to lowercase
    void convert(char str[]) {
        int k = 0;
        int len = strlen(str); // Calculate the length of the input string
        for (int j = 0; j < len; j++) {
            if (isalpha(str[j])) {  // Check if the character is alphabetic
                str[k++] = tolower(str[j]); // Convert to lowercase and store
            }
        }
        str[k] = '\0'; // Null-terminate the processed string
        cout << "\nConverted String: " << str << "\n";
    }

    // Method to check if the string in the stack is a palindrome
    void palindrome() {
        bool isPalindrome = true; // Flag to track palindrome status
        // Compare characters from the start and end of the stack
        for (int i = 0, j = top; i < j; i++, j--) {
            if (a[i] != a[j]) { // If any pair of characters doesn't match
                isPalindrome = false; // Mark as not a palindrome
                break; // Exit the loop early
            }
        }
        // Print the result
        if (isPalindrome) {
            cout << "\nSTRING IS PALINDROME!!\n";
        } else {
            cout << "\nSTRING IS NOT PALINDROME!!!\n";
        }
    }
};

int main() {
    STACK obj;        // Create a STACK object
    char str[MAX];    // Array to hold the input string

    // Prompt the user for input
    cout << "\nEnter string to be reversed and check if it is a palindrome or not:\n\n";
    cin.getline(str, MAX); // Read the input string (supports spaces)

    obj.convert(str); // Convert the input string (lowercase, no non-alphabetic characters)

    // Push each character of the converted string onto the stack
    int i = 0;
    while (str[i] != '\0') {
        obj.push(str[i]); // Push each character
        i++;
    }

    obj.palindrome(); // Check if the string is a palindrome
    obj.reverse();    // Display the reversed string

    return 0; // End of program
}
