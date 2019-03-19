#include <iostream>
#include <string>

using namespace std;

int main() {

	int i, j, k;
	int num  = 1, num2;
	int index = 0;
	int check = 0;

	cin >> num;

	num2 = num;

	string* str = new string[num];
		
	for (i = 0; i < num; i++) {
		cin >> str[i];
	}
	
	for (i = 0; i < num; i++) {
				
		int length = str[i].length();
		char* temp = new char[length];
		index = 0;

		for (j = 0; j < str[i].length(); j++) {

			check = 0;
			
			if (j == 0)	temp[index++] = str[i][j];
			else {
				if(str[i][j] != str[i][j-1]) 
				{
					for (k = 0; k < index; k++) {
						if (temp[k] == str[i][j]) {
							check = 1;
							break;
						}
					}

					if (check == 0) {
						temp[index++] = str[i][j];
					}

				}			
			}
			if (check == 1) {
				num2 -= 1;
				break;
			}	
		}
	}

	cout << num2 << endl;
	return 0;
}