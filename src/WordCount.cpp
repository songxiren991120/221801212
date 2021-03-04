#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
string duan="";
struct Record {
    string word;
    int count;
};
static bool sortType(const Record& v1, const Record& v2)
{
    return v1.count > v2.count;//降序排序
}

int wordtest(char a)
{
    return ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'));
}
void readText(const char* filename) {
    ifstream ifile(filename);
    char para[10000];
    int wordcount = 0;
    int linecount = 0;
    int i;
    int j = 0;
    int character=0;
    int line = 0;
    while (!ifile.eof()) {
        line++;
        ifile.getline(para, 10000);
        i = 0;
        while (para[i]!='\0') {
            character++;
            
            
            while (wordtest(para[i]))
            {
                duan = duan + para[i];
                i++;
                j++;
                
                if (!wordtest(para[i]))
                {
                    if (j >= 4) {
                        wordcount++;
                        duan += " ";
                        j = 0;
                    }
                    
                }
            }
            
            i++;
            
        }

    }
    ifile.close();
    cout << "字符数：" << character << endl;
    cout << "单词数：" << wordcount << endl;
    cout << "行数：" << line-1<< endl;
    cout << duan<<endl;
}
void wordDis(){
    vector<Record> _words;
    istringstream iss(duan);
    string word;
    int i;
    while (iss >> word) 
    {
        for (i = 0; i < _words.size(); ++i) {
            if (word == _words[i].word)
            {
                ++_words[i].count;
                break;
            }
        }
        if (i == _words.size()) {
            Record record;
            record.word = word;
            record.count = 1;
            _words.push_back(record);
        }
    }

    sort(_words.begin(), _words.end(), sortType);//排序并输出
    for (i = 0; i < 10; ++i) {
        cout << _words[i].word << _words[i].count<<endl;
    }

}
int main(int argc, char** argv)
{
    string address1 = argv[1];
    //ifstream ifile(address1);
    //string s = "";
    //while (getline(ifile, s)) {
    //    cout << s << endl;
    //}
    const char* address2 = address1.data();
    readText(address2);
    wordDis();
}
