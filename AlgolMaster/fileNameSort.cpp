//
//  fileNameSort.cpp
//  AlgolMaster
//
//  Created by 신예지 on 19/03/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> inputVector, alphVector, alphDupVector;
    vector<int> numberVector, numberDupVector;
    int vectorSize;
    
    while (true)
    {
        string input;
        getline(cin, input);
        
        if (input == "\0") break;
        
        inputVector.push_back(input);
    }
    
    vectorSize = inputVector.size();
    
    for (int i = 0; i < vectorSize; i++)
    {
        int strSize = inputVector[i].size(), j = 0;
        string a;
        a = inputVector[i][j];
        while (true)
        {
            if (inputVector[i][++j] >= '0' && inputVector[i][j] <= '9')
                break;
            else
                a += inputVector[i][j];
        }
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        alphVector.push_back(a);
        alphDupVector.push_back(a);
        
        a = inputVector[i][j];
        while (true)
        {
            if (inputVector[i][++j] >= '0' && inputVector[i][j] <= '9')
                a += inputVector[i][j];
            else
                break;
        }
        numberVector.push_back(stoi(a));
    }
    
    sort(alphVector.begin(), alphVector.end());
    
    for (int i = 0; i < vectorSize; i++)
    {
        for (int j = i; j < vectorSize; j++)
        {
            if (alphVector[i] == alphDupVector[j])
            {
                if (i == j) break;
                string tmp;
                tmp = alphDupVector[j];
                int tmp2 = numberVector[j];
                alphDupVector[j] = alphDupVector[i];
                alphDupVector[i] = tmp;
                tmp = inputVector[j];
                inputVector[j] = inputVector[i];
                inputVector[i] = tmp;
                numberVector[j] = numberVector[i];
                numberVector[i] = tmp2;
                break;
            }
        }
    }
    
    numberDupVector = numberVector;
    
    for (int i = 0; i < vectorSize; i++)
    {
        int cnt = i+1;
        
        while(true)
        {
            if (cnt == vectorSize)
            {
                cnt--;
                break;
            }
            if (alphVector[i] == alphVector[cnt])
                cnt++;
            else
            {
                cnt--; break;
            }
        }
        
        if (i != cnt)
        {
            sort(numberVector.begin()+i, numberVector.begin()+cnt+1);
            
            for (int j = i; j <= cnt; j++)
            {
                for (int k = j; k <= cnt; k++)
                {
                    if (numberVector[j] == numberDupVector[k])
                    {
                        if (j == k) break;
                        int tmp = numberDupVector[k];
                        string tmp2;
                        tmp2 = inputVector[k];
                        numberDupVector[k] = numberDupVector[j];
                        numberDupVector[j] = tmp;
                        inputVector[k] = inputVector[j];
                        inputVector[j] = tmp2;
                        break;
                    }
                }
            }
        }
        i = cnt;
    }
    
    for (int i = 0; i < vectorSize; i++)
        cout << inputVector[i] << "  ";
    
    return 0;
}
