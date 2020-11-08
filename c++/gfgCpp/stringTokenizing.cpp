#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line = "Hello My name is Mohit";
    // Define a vector to hold the string 
    vector <string> tokens;

    // String Stream Class
    stringstream check1(line);

    string inter;

    while(getline(check1, inter, ' ')){
        tokens.push_back(inter);
    }
    // Print the tocken vector
    for(int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i] << endl;
    }
    return 0;
}
