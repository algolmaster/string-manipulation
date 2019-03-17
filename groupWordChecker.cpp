/**
 * @file groupWordChecker.cpp
 * @data 20219/03/16
 * @author 최서정 github.com/cchloe2311
 * @brief 백준 #1316, 그룹단어체커 문제
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        int alphabet[26] = {0};
        bool isGroupWord = true;

        alphabet[input[0] - 97]++;
        for (int j = 1; j < input.size(); j++) {
            int index = input[j] - 97;

            if ((alphabet[index] != 0) && input[j - 1] != input[j]) {
                isGroupWord = false;
                break;
            }
            else {
                alphabet[index]++;
            }
        }

        if (isGroupWord) count++;
    }

    cout << count;
}