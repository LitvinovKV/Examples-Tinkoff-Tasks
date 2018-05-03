#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    float x = 0, y = 0;
            scanf("%f %f", &x , &y);

    if(x < 1) {
        cout << "Error! Incorrect enter: X must be >= 1" << endl;
        return 0;
    }
    if(y > 1000) {
        cout << "Error! Incorrect enter: Y must be <= 1000" << endl;
        return 0;
    }

    float  x1 = 0, y1 = 0, 
            x2 = 0, y2 = 0,
            x3 = 0, y3 = 0,
            x4 = 0, y4 = 0;

    scanf(" %f %f %f %f %f %f %f %f", 
                &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

    float propX = x / (x2 - x1);
    float propY = y / (y3 - y2);

    float resultX = x1 / (propX - 1) + x1;
    float resultY = y1 / (propY - 1) + y1;

    printf("Result X = %.3f\n", resultX);
    printf("Result X = %.3f\n", resultY);
    return 0;
}