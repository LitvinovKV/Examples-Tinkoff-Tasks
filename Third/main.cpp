#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int factorial(int number) {
    if (number == 1) 
        return 1;
    else return factorial(number - 1) * number;
}

int main() {
    int N, M;
    scanf("%i %i", &N, &M);
    if (N > 16) {
        cout << "Error! Incorrect value : N must be <= 16";
        return 0;
    }
    else if (M > 16) {
        cout << "Error! Incorrect value : M must be <= 16";
        return 0;
    }

    int result = 1;
    for (int i = 0; i < M; i++)
        result *= pow(N - i, 2);
    result /= factorial(M);

    cout << "Result = " << result;
    
    return 0;
}