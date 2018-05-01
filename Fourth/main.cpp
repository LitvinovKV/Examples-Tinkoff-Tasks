#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <cstring>

using namespace std;

int searchRect(char** arr, int& rect_i, int& rect_j, int& N, int& M) {
    //rect_i - line start rect, rect_j - row start rect
    int count_j = 0, count_i = 0;
    
    //count the number of zeros in a row
    for (int j = rect_j; j < M; j += 2) {
        if (arr[rect_i][j] == '0')
            count_j++;
    }
    
    //count the number of rows with the same number of zeros
    for (int i = rect_i + 1; i < N; i++) {
        int countline = 0;
        for (int j = rect_j; j < M; j += 2)
        {
            if (arr[i][j] == '0')
                countline++;
            else break;
        }
        if (countline == count_j)
            count_i++;
        else break;
    }

    //change '0' to '1' in rect
    for (int i = rect_i; i <= rect_i + count_i; i++) {
        int count = 0;
        while(count / 2 != count_j) {
            arr[i][rect_j + count] = '1';
            count += 2;
        }
        
    }
    return 1;
}

int main() {
    int N, M;
    scanf("%i %i", &N, &M);
    M = M + (M - 1);

    if (N < 1) {
        cout << "Error! Incorrect enter : N must be >= 1" << endl;
        return 0; 
    }
    if (M > 12) {
        cout << "Error! Incorrect enter : M must be <= 12" << endl;
        return 0;
    }

    char** arr = new char*[N];
    for(int i = 0; i < N; i++)
        arr[i] = new char[M];

    for (int i = 0; i < N; i++)
        scanf(" %[^\n]", arr[i]);

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j += 2) {
            if (arr[i][j] == '0') { //start rect
                result += searchRect(arr, i, j, N, M);
            }
        }
    }

    cout << "Count Rect = " << result << endl;


    for (int i = 0; i < N; i++)
        delete[] arr[i];
    delete[] arr;
    arr = nullptr;

        return 0;
}