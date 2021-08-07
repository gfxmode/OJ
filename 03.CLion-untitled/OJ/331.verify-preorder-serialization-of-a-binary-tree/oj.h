//
// Created by John on 2020/6/21.
// URL: https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/
//

#ifndef UNTITLED_OJ_H
#define UNTITLED_OJ_H

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> vecSplit;
        splitStrToVector(vecSplit, preorder, ",");
        cout<< vecSplit.size() << endl;
    }

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
};

#endif //UNTITLED_OJ_H
