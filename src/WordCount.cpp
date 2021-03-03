#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
int wordtest(char a)
{
    return ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'));
}
void readText(const char* filename) {
    ifstream ifile(filename);
    char para[100];
    int wordcount = 0;
    int linecount = 0;
    int i;
    int character=0;
    int line = 0;
    while (!ifile.eof()) {
        line++;
        ifile.getline(para, 99);
        i = 0;
        while (para[i]!='\0') {
            i++;
            character++;
            while (wordtest(para[i]))
            {
                i++;
                character++;
                if (!wordtest(para[i]))
                {
                    wordcount++;
                    
                }
            }
        }

    }
    ifile.close();
    cout << "字符数：" << character << endl;
    cout << "单词数：" << wordcount << endl;
    cout << "行数：" << line-1 << endl;
}
int main(int argc, char** argv)
{
    string address1 = argv[1];
    ifstream ifile(address1);
    string s = "";
    while (getline(ifile, s)) {
        cout << s << endl;
    }
    const char* address2 = address1.data();
    readText(address2);
}
