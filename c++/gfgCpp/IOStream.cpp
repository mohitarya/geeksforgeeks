#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    //istream_iterator<int> cin_it(cin);
    //istream_iterator<int> eos;

    //ostream_iterator<int> cout_it(cout, " ");

    //copy(cin_it, eos, cout_it);
    
    // Vector to store the string
    vector<string> string_v;

    //File stream object
    ifstream fis("testFile.txt");

    // Get Input Stream and End of stream iterator
    //
    istream_iterator<string> fin_it(fis);
    istream_iterator<string> eos;

    ostream_iterator<string> cout_it(cout, " ");

    copy(fin_it, eos, back_inserter(string_v));

    sort(string_v.begin(), string_v.end());

    copy(string_v.begin(), string_v.end(), cout_it);
    cout << endl;
    return 0;
}
