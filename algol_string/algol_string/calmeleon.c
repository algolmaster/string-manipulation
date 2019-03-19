#define _CRT_SECURE_NO_WARNINGS     // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <string.h>

char correct(char *str, int size, int n) {
	//if (S[i] == first && inx != -1 && i + inx < size - 1 && S[i + inx] == last) { //첫글자와 같고, 접두사 접미사가 있고, 마지막이 같으면
	for (int i = 1; i + n < size - 1; i++) {
		if (str[i] == str[0]) {
			int k = 1;
			for (k = 1; k <= n; k++) { //부분문자열 확인
				if (str[i + k] != str[k])
					break;
			}
			if (k == n + 1) return 1;
		}
	}
	return 0;
	//}
}

char compare(char *str, int n) { //n은 몇번째 인덱스까지 비교할것인지
	int str_size = strlen(str);
	int i = 0;
	for (i = 0; i <= n; i++) {
		if (str[i] != str[str_size - n + i - 1])
			break;
	}

	if (i == n + 1) return correct(str, str_size, n);
	return 0;
}

int main() {
	char *S = malloc(sizeof(char) * 100);    //알고자 하는 문자열

	printf("문자열 입력하세요: ");
	scanf("%s", S);      // 표준 입력을 받아서 메모리가 할당된 문자열 포인터에 저장
	int size = strlen(S);

	int check = -1; //부분문자열이 있는 인덱스

	char first = S[0];
	char last = S[size - 1];

	for (int i = 1; i < size - 1; i++) { //접미사, 접두사 점검
		if (S[i] == last && S[size - i - 1] == first) { //첫글자와 마지막글자끼리 같으면 전부 비교
			if (compare(S, i)) { //부분문자열 확인
				check = i;
			}
		}

	}

	if (check == -1) { //카멜레온이 아니라면
		printf("%d", check);
	}
	else {
		for (int j = 0; j <= check; j++)
			printf("%c", S[j]);
	}
	free(S);
	return 0;
}