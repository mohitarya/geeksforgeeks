#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X[] = {0, 1, 2, 3, 4, 5};
    int Y[] = {0, 1, 2, 3, 4, 5};
    int n1 = 6;
    int n2 = 6;
    coverPoints(X, n1, Y, n2);
    return 0;    
}

int coverPoints(int* X, int n1, int* Y, int n2)
{
    int i, steps = 0, ret = 1, ix, iy, px, py, cx, cy;
    px = *(X);
    py = *(Y);
    for(i = 1; i < n1; i++)
    {
        cx = *(X + i);
        cy = *(Y + i);
        ret = chk_xy(px, py, cx, cy, &steps);
        if(ret = 0){
            px = cx;
            py = cy;
            continue;
        }else{
            ix = px;
            iy = py;
            while ((ix != cx) && (iy != cy)){
                if((ix > cx) && (iy < cy)){
                    ix--; iy++; 
                }else if((ix < cx) && (iy < cy)){
                    ix++; iy++;
                }else if ((ix > cx) && (iy > cy)){
                    ix--; iy--;
                }else if ((ix < cx) && (iy > cy)){
                    ix++; iy--;
                }
                steps++;
                ret = chk_xy(ix, iy, cx, cy, &steps);
                if(ret == 0){
                    px = cx;
                    py = cy;
                    break;
                }
                continue;
            }
            px = cx;
            py = cy;
        }
    }
    printf("No of steps = %d\n", steps);
}
int chk_xy(int px, int py, int cx, int cy, int *steps)
{
    int ret;
    //if any of the X and Y cordinate match with the previous cordinate
    if(px == cx){
        *steps += abs(abs(cy) - abs(py));
        ret = 0;
    } else if (py == cy){
        *steps += abs(abs(cx) - abs(px));
        ret = 0;
    }else{
        ret = 1;
    }
    return ret;
}
