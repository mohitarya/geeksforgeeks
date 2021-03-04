#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
    FILE *fp;
    FILE *fp1;
    char buf[8192];
    unsigned int bytes_read, bytes_written;
    fp = popen("uname -a", "r");
    if(fp)
    {
        bytes_read = fread(buf, sizeof(char), 8192, fp);
        if(bytes_read != 0)
        {
            cout << "uname -a Output ::: " << buf << endl;
        }
    }
    else
    {
        cout << "Error in Popen" << endl;
    }

    memset(buf, 0x0, sizeof(buf));

    fp1 = popen("od -c", "w");
    if(!fp1)
    {
        cout << "Error in popen call" << endl;
        throw "popen Failed";
    }
    else
    {
        sprintf(buf, "Hello Its Me::::::\n");
        bytes_written = fwrite(buf, sizeof(char), strlen(buf), fp1);
        if(bytes_written)
        {
            cout << "fwrite success"<< endl;
        }
        else
        {
            cout << "fwrite Fail" << endl;
        }
    }


    return 0;
}
