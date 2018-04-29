#include <iostream>
#include <string>


using namespace std;

int maxWordLength(string& str) {
    int maxLength = 0, count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        // A-Z a-z '\''
        if ( (int(str[i]) >= 65 && int(str[i]) <= 90) || 
             (int(str[i] >= 97) && int(str[i] <= 122)) || 
              int(str[i]) == 39 ) {
            count++;
        }
        else if (maxLength < count) {
            maxLength = count;
            count = 0;
        }
        else {
            count = 0;
        }
    }
    return maxLength;
}

void changeLog(string& str, int& maxLength) {
    for (int i = 0; i < str.length(); i++)
    {
        // A-Z
        if (int(str[i]) >= 65 && int(str[i]) <= 90) {
            int intChar = int(str[i]) + maxLength;
            if (intChar > 90)
                intChar = 64 + (intChar - 90);
            str[i] = char(intChar);
        }
        // a-z
        else if (int(str[i] >= 97) && int(str[i]) <= 122) {
            int intChar = int(str[i]) + maxLength;
            if (intChar > 123)
                intChar = 96 + (intChar - 122);
            str[i] = char(intChar);
        }
    }
}

int main() {
    string str;
    getline(cin, str);
    if (str.length() > 500) {
        cout << "Error! String length must be <= 500!";
        return 0;
    }
    
    int maxLength = maxWordLength(str);
    changeLog(str, maxLength);
    cout << str << endl;

    return 0;
}