#define _CRT_SECURE_NO_WARNINGS     // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

int main()
{

	char *str = malloc(sizeof(char) * 100);    // 0~10의 정수와 문자 S, D, T, *, #로 구성된 문자열

	printf("dart Result 를 입력하세요: ");
	scanf("%s", str);      // 표준 입력을 받아서 메모리가 할당된 문자열 포인터에 저장

	int score[3] = { 0 }; //횟수별 점수
	int index = -1; //몇회차를 나타내는 인덱스

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9') { //숫자일때
			index++;
			if (str[i + 1] == '0') { //10일때 토큰
				score[index] = 10;
				i++;
			}
			else {
				score[index] = str[i] - '0';
			}
		}

		else if (str[i] == 'S' || str[i] == 'D' || str[i] == 'T') {
			switch (str[i]) {
			case 'D':
				score[index] *= score[index];
				break;
			case 'T':
				score[index] *= (score[index] * score[index]);
				break;
			}
		}

		else { //스타상, 아차상
			switch (str[i]) {
			case '*':
				score[index] *= 2;
				if (index != 0)
					score[index - 1] *= 2;
				break;
			case '#':
				score[index] *= -1;
				break;
			}
		}
	}

	printf("총 점수 : %d", score[0] + score[1] + score[2]);

	free(str);    // 동적 메모리 해제
	return 0;
}