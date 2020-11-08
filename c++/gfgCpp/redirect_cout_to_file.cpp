#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // AIM === Redirect Cout to a file
    // open a file in out mode (Data can be written to the file)
    // Save the default cout buffer
    // Get the stream buffer of the file
    // redirct stream buffer of cout to the file buffer
    // Write something to file
    // Reset every thing
    // Write something to cout
    // It should print on Monitor

    fstream file;

    file.open("cout.txt", ios::out);

    streambuf* stream_buf_cout = cout.rdbuf();
    
    // Stream Buf of the file
    streambuf* stream_buf_file = file.rdbuf();

    // Set cout rdbuf to file buf
    cout.rdbuf(stream_buf_file);

    // Write some thing to cout it should redirct to file
    cout << "This Line written to the file" << endl;

    // Redirct cout streambuffer to default one
    cout.rdbuf(stream_buf_cout);

    cout << "This line written to screen" << endl;

    file.close();
    return 0;
}
