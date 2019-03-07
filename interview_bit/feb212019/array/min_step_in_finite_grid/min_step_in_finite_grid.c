#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Integer
 */
 int get_move_count(int pointA, int pointB)
 {
    if((pointA >= 0 && pointB >= 0) || (pointA < 0 && pointB < 0))
    {
        // PointA and PointB are in the same co-ordinate
        return (abs(abs(pointA) - abs(pointB)));
    }
    else
    {
        // Points are in different co-ordinate
        return (abs(pointA) + abs(pointB));
    }
 }
 
 int get_new_XorY_co(int pointA, int pointB, int mc)
 {
    if(pointA > pointB)            // For X axis moving left side, for X axis Moving downward
    {
        return pointA - mc; 
    }
    else if(pointA < pointB)
    {
        return pointA + mc;
    }
    else
    {
        return pointA;
    }
 }
 
int coverPoints(int* A, int n1, int* B, int n2) {
    
    unsigned int mc = 0;
    int i, x1, y1, x2, y2, tempX, tempY, tempMc, tempXDMc, tempYDMc;
    /* Handeling the error length of A is not equal to B */
    if(n1 != n2)
    {
        return 0;
    }
    for(i = 1; i < n1; i++)
    {
        x1 = A[i - 1];
        y1 = B[i - 1];
        x2 = A[i];
        y2 = B[i];
        tempX = x1;
        tempY = y1;
        
        // Next co-ordinates are same as the previous co-ordinates
        if(x1 == x2 && y1 == y2)
        {
            continue;
        }
        while(tempX != x2 || tempY != y2)
        {
            // Move diagonally or straight line
            if((tempY == y2) && (tempX != x2))
            {
                // Moving in the x direction straight line
                tempMc = get_move_count(tempX, x2);
                tempX = x2;
                tempY = get_new_XorY_co(tempY, y2, tempMc);
                mc += tempMc;
            }
            else if((tempX == x2) && (tempY != y2))
            {
                // Moving in the Y direction Straight line
                tempMc = get_move_count(tempY, y2);
                tempY = y2;
                tempX = get_new_XorY_co(tempX, x2, tempMc);
                mc += tempMc;
            }
            else if(tempX == x2 && tempY == y2)
            {
                continue;
            }
            else
            {
                // Move Diagonally
                tempXDMc = get_move_count(tempX, x2);
                tempYDMc = get_move_count(tempY, y2);
                if(tempXDMc < tempYDMc)
                {
                    // Move Diagonally to reach x2
                    tempX = x2;
                    tempY = get_new_XorY_co(tempY, y2, tempXDMc);
                    mc += tempXDMc;
                }
                else if(tempYDMc < tempXDMc)
                {
                    tempY = y2;
                    tempX = get_new_XorY_co(tempX, x2, tempYDMc);
                    mc += tempYDMc;
                }
                else if(tempXDMc == tempYDMc)
                {
                    tempX = x2;
                    tempY = y2;
                    mc += tempXDMc;
                }
            }
        }
    }
    return mc;
}

int main()
{
    int A[3] = {0, 1, -1};
    int B[3] = {0, 5, -2};
    return 0;
}

