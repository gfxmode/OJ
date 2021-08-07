//
// Created by John on 2020/6/21.
//

#ifndef UNTITLED_STRINGUTILS_H
#define UNTITLED_STRINGUTILS_H

#include <string>
#include <vector>

using namespace std;

void splitStrToVector(vector<string>& vecSplit, const string& strInput, const string& sep) {
    string str2 = strInput;
    while (str2.find(sep) != string::npos) {
        int found = str2.find(sep);
        vecSplit.push_back(str2.substr(0, found));
        str2 = str2.substr(found + 1);
    }

    vecSplit.push_back(str2);
    return;
}

#endif //UNTITLED_STRINGUTILS_H
