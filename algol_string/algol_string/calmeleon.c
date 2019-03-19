#define _CRT_SECURE_NO_WARNINGS     // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����
#include <string.h>

char correct(char *str, int size, int n) {
	//if (S[i] == first && inx != -1 && i + inx < size - 1 && S[i + inx] == last) { //ù���ڿ� ����, ���λ� ���̻簡 �ְ�, �������� ������
	for (int i = 1; i + n < size - 1; i++) {
		if (str[i] == str[0]) {
			int k = 1;
			for (k = 1; k <= n; k++) { //�κй��ڿ� Ȯ��
				if (str[i + k] != str[k])
					break;
			}
			if (k == n + 1) return 1;
		}
	}
	return 0;
	//}
}

char compare(char *str, int n) { //n�� ���° �ε������� ���Ұ�����
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
	char *S = malloc(sizeof(char) * 100);    //�˰��� �ϴ� ���ڿ�

	printf("���ڿ� �Է��ϼ���: ");
	scanf("%s", S);      // ǥ�� �Է��� �޾Ƽ� �޸𸮰� �Ҵ�� ���ڿ� �����Ϳ� ����
	int size = strlen(S);

	int check = -1; //�κй��ڿ��� �ִ� �ε���

	char first = S[0];
	char last = S[size - 1];

	for (int i = 1; i < size - 1; i++) { //���̻�, ���λ� ����
		if (S[i] == last && S[size - i - 1] == first) { //ù���ڿ� ���������ڳ��� ������ ���� ��
			if (compare(S, i)) { //�κй��ڿ� Ȯ��
				check = i;
			}
		}

	}

	if (check == -1) { //ī�᷹���� �ƴ϶��
		printf("%d", check);
	}
	else {
		for (int j = 0; j <= check; j++)
			printf("%c", S[j]);
	}
	free(S);
	return 0;
}