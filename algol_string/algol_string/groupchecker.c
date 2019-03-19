#define _CRT_SECURE_NO_WARNINGS     // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

int main()
{
	int n = 0;
	printf("문자열의 갯수를 입력하세요: ");
	scanf("%d", &n);

	int check['Z' - 'A'] = { 0 }; //이전 알파벳 존재 유무 체크
	int cnt_notgroup = 0; //그룹 단어가 아닌 수

	for (int i = 0; i < n; i++) {
		char *str = malloc(sizeof(char) * 100);    // char 배열 동적 메모리 할당

		printf("문자열을 입력하세요: ");
		scanf("%s", str);      // 표준 입력을 받아서 메모리가 할당된 문자열 포인터에 저장

		check[str[0] - 'a'] = i + 1; //맨처음 알파벳 저장
		for (int j = 1; str[j] != '\0'; j++) {
			if (str[j - 1] != str[j]) { //이전과 다르면 
				if (check[str[j] - 'a'] == i + 1) { //이전에 나왔던 알파벳인지 검사
					cnt_notgroup++;
					break;
				}
				else {
					check[str[j] - 'a'] = i + 1;
				}
			}
		}
		free(str);    // 동적 메모리 해제
	}
	printf("그룹단어의 수 : %d", n - cnt_notgroup);
	return 0;
}