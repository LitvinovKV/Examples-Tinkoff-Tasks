#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
    int N, M;
    scanf("%i %i", &N, &M);

    if ( (N < 1) || (N > pow(10, 9)) ) {
        cout << "Error! Incorrect enter - N!" << endl;
        return 0;
    }
    if ( (M < 0) || (M > pow(10, 9)) ) {
        cout << "Error! Incorrect enter - M!" << endl;
        return 0;
    }

    int result = ((N - M) / 2) - M;
    cout <<  result << endl;

    return 0;
}