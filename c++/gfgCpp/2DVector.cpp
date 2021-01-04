#include <iostream>
#include <algorithm>
#include <vector>

// Compile Using
// gcc 2DVector.cpp -std=c++11 -lstdc++

using namespace std;


bool sortCol(const vector<int> &v1,
             const vector<int> &v2)
{
    return v1[1] < v2[1];
}

bool rsortCol(const vector<int> &v1,
             const vector<int> &v2)
{
    return v1[1] > v2[1];
}

bool sizecom(const vector<int> &v1,
             const vector<int> &v2)
{
    return v1.size() < v2.size();
}


int main()
{
    vector< vector<int> > vec2D{{1, 5, 3},
                         {50, 1, 2},
                         {6, 7, 8}};

    vector< vector<int> > vec2D1{{1, 5, 3},
                         {50, 1},
                         {6}};
  
    // Print a 2D vec
    for(int i=0; i < vec2D.size(); i++)
    {
        for(int j=0; j < vec2D[i].size(); j++)
        {
            cout << " " << vec2D[i][j];
        }
        cout << endl;
    }
    cout << "Row wise Sorting" << endl;

    // Sorting of 2D vect
    // Row wise sorting
    for(int i = 0; i< vec2D.size(); i++)
    {
        sort(vec2D[i].begin(), vec2D[i].end());
    }
    // Print a 2D vec
    for(int i=0; i < vec2D.size(); i++)
    {
        for(int j=0; j < vec2D[i].size(); j++)
        {
            cout << " " << vec2D[i][j];
        }
        cout << endl;
    }

    cout << "Column wise Sorting" << endl;
    sort(vec2D.begin(), vec2D.end(), sortCol);

    // Print a 2D vec
    for(int i=0; i < vec2D.size(); i++)
    {
        for(int j=0; j < vec2D[i].size(); j++)
        {
            cout << " " << vec2D[i][j];
        }
        cout << endl;
    }

    // Desending Order
    cout << "Row wise Desending order Sorting" << endl;

    // Sorting of 2D vect
    // Row wise sorting
    for(int i = 0; i< vec2D.size(); i++)
    {
        sort(vec2D[i].rbegin(), vec2D[i].rend());
    }
    // Print a 2D vec
    for(int i=0; i < vec2D.size(); i++)
    {
        for(int j=0; j < vec2D[i].size(); j++)
        {
            cout << " " << vec2D[i][j];
        }
        cout << endl;
    }

    cout << "Column wise Desending order Sorting" << endl;
    sort(vec2D.begin(), vec2D.end(), rsortCol);

    // Print a 2D vec
    for(int i=0; i < vec2D.size(); i++)
    {
        for(int j=0; j < vec2D[i].size(); j++)
        {
            cout << " " << vec2D[i][j];
        }
        cout << endl;
    }
    
    cout << "Column wise no of column in each row Sorting" << endl;
    sort(vec2D1.begin(), vec2D1.end(), sizecom);

    // Print a 2D vec
    for(int i=0; i < vec2D1.size(); i++)
    {
        for(int j=0; j < vec2D1[i].size(); j++)
        {
            cout << " " << vec2D1[i][j];
        }
        cout << endl;
    }


    return 0;
}
