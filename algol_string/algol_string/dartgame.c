#define _CRT_SECURE_NO_WARNINGS     // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{

	char *str = malloc(sizeof(char) * 100);    // 0~10�� ������ ���� S, D, T, *, #�� ������ ���ڿ�

	printf("dart Result �� �Է��ϼ���: ");
	scanf("%s", str);      // ǥ�� �Է��� �޾Ƽ� �޸𸮰� �Ҵ�� ���ڿ� �����Ϳ� ����

	int score[3] = { 0 }; //Ƚ���� ����
	int index = -1; //��ȸ���� ��Ÿ���� �ε���

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9') { //�����϶�
			index++;
			if (str[i + 1] == '0') { //10�϶� ��ū
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

		else { //��Ÿ��, ������
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

	printf("�� ���� : %d", score[0] + score[1] + score[2]);

	free(str);    // ���� �޸� ����
	return 0;
}