#include <iostream>
#include <string>

using namespace std;

int main() {

	int i, j;
	int num = 0;
	int index_num = 0;
	//int *index;
	//int index[100] = {'\0'};
	string str = {};
	int check = 0;
	int count;
	
	cin>>str;
	
	//index배열 동적할당 및 초기화
	int *index = new int[str.length()];
	for (i = 0; i < str.length(); i++) {
		index[i] = - 1;
	}
	
	//같은 문자 index 구하기
	for (i = 1; i < str.length(); i++) {
		if (str[i] == str[0]) {
			index_num += 1;
			index[num] = i;
			num += 1;
		}
	}

	//갯수만큼 동적할당
	char **T = new char*[num];
	for (i = 0; i < num; i++) {
		T[i] = new char[str.length() + 1];
	}

	//배열 초기화
	for (i = 0; i < num; i++) {
		for (j = 0; j < (str.length() + 1); j++) {
			T[i][j] = '\0';
		}	
	}

	//T의 길이 구하기

	for (i = 0; i < num; i++) {
		check = 0;
	
		for (j = 0; j < str.length()- index[i] + 1; j++) {
			if (str[index[i]+ j] == str[check]) {
				T[i][check] = str[check];
				check += 1;
				//cout << T[i][check++];
			}
			else {
				index[i] = check;
				//cout << index[i];
				break;
			}
		}
		//	cout << T[i];
	}

	int *check_one = new int[num];

	//접미사 접두사가 맞는지 확인
	for (i = 0; i < num; i++) {
		count = index[i];
		for (j = (index[i] - 1); j >= 0; j--) {
	
			if (T[i][j] == str[str.length() + j - index[i]]) {
				count -= 1;
			}
		}
		check_one[i] = count;
		//cout << check_one[i];
	}

	//check_array 동적할당 및 초기화
	int *check_array = new int(str.length());
	for (i = 0; i < str.length(); i++) {
		check_array[j] = 0;	
	}

	int how_many = 0;;
	int count2;
	int k;
	for (i = 0; i < num; i++) {
		
		if (check_one[i] == 0) {
			char *temp =  new char(index[i]);
			for (j = 0; j <= str.length() - index[i]; j++) {
				how_many = 0;
				//T[i][j] = f->i->x
				//012 123 234 
				count2 = 0;
				count = 0;
				for (k = j; k < j + index[i]; k++) {
					if ((T[i][count2++]) == str[k]) {
						count += 1;
					}
					else {
						check_array[j] = 0;
						break;
					}
				}
				if (count == index[i]) {
					check_array[j] = 1;
				}
				

			}
		}
		for (k = 0; k < str.length(); k++) {
			if (check_array[k] == 1) {
				how_many += 1;
			}
		}

		if (how_many >= 3) {
			check_one[i] = 0;
		}
		else {
			check_one[i] = 1;
		}

	/*	for (k = 0; k < str.length() - index[i] + 2; k++) {
			printf("%d ", check_array[k]);
		}
	*/	

		//cout << check_one[i];
	}	

	int str_length = -1;
	int final_index = -1;
	
	for (i = 0; i < num; i++) {
		if (check_one[i] == 0) {
			if (str_length <= index[i]) {
				final_index = i;
				str_length = index[i];
			}
		}
	}

	if (final_index == -1) {
		cout << -1;
		return 0;
	}

	for (i = 0; i < index[final_index]; i++) {
		cout << T[final_index][i];
	}


	return 0;
}