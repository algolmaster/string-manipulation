//
//  chameleonSubstring.cpp
//  AlgolMaster
//
//  Created by 신예지 on 19/03/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string inputString;
    cin >> inputString;
    
    string prefix, suffix;
    vector<string> fix; //가능한 prefix, suffix
    
    string findFix; //찾은 fix
    
    for(int i=inputString.length()-1; i>2; i--) {
        if(inputString[i] == inputString[0]) {
            prefix = inputString.substr(0, inputString.length()-i);
            suffix = inputString.substr(i, inputString.length()-i);
            if(prefix == suffix) {
                fix.push_back(prefix);
            }
        }
    }
    
    if(fix.empty()) {
        cout << "-1" << endl;
    }
    
    else {
        findFix = fix[0];
        for(int i=1; i<fix.size(); i++) {
            if(inputString.find(fix[i], 1)!= inputString.length()-fix[i].length() && findFix.size()<fix[i].size())
                findFix = fix[i];
        }
        cout << findFix <<endl;
    }
}
