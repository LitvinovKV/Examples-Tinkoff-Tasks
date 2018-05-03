#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

string reverse(string& str) {
    string reverseStr = "";
    for (int i = str.length() - 1; i >= 0; i--)
        reverseStr += str[i];
    return reverseStr;
}

int main() {
    string str = "";
    getline(cin, str);
    if (str.length() > pow(10, 5)) {
        cout << "Error! Incorrect length string : length must be <= 10^5" << endl;
        return 0;
    }

    vector<string> strings;
    int result = str.length();
    for (int i = 1; i < str.length(); i++) {
        //delete one character from the right
        if (str.length() - i != 1)
            strings.push_back(str.substr(0, str.length() - i));
        //delete one character from the left
        if (i + 1 != str.length())
            strings.push_back(str.substr(i, str.length() - i));
        //get between substr
        if (!(i >= str.length() - i - 1))
            strings.push_back(str.substr(i, str.length() - i - 1));
    }
    
    //count palindromic strings in vector
    for (int i = 0; i < strings.size(); i++) {
        if (strings[i].length() > 1) {
            if (strings[i] == reverse(strings[i]))
                result++;
        }
    }

    cout << "Result = " << result << endl;

    return 0;
}