#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    string address = argv[1];
    ifstream ifile(address);
    string s = "";
    while (getline(ifile, s)) {
        cout << s << endl;
    }
}

