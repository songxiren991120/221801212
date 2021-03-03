#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
int wordtest(char a)
{
    return ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'));
}
void readText(const char* filename) {
    ifstream ifile(filename);
    char para[100];
    int wordcount = 0;
    while (!ifile.eof()) {
        ifile.getline(para, 99);
        int i = 0;
        while (para[i]!='\0') {
            i++;
            while (wordtest(para[i]))
            {
                i++;
                if (!wordtest(para[i]))
                {
                    wordcount++;
                }
            }
        }

    }
    ifile.close();
    cout << "单词：" << wordcount << endl;
}
int main(int argc, char** argv)
{
    string address = argv[1];
    ifstream ifile(address);
    string s = "";
    while (getline(ifile, s)) {
        cout << s << endl;
    }
    const char* address2 = address.data();
    readText(address2);
}
