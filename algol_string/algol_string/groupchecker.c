#define _CRT_SECURE_NO_WARNINGS     // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
	int n = 0;
	printf("���ڿ��� ������ �Է��ϼ���: ");
	scanf("%d", &n);

	int check['Z' - 'A'] = { 0 }; //���� ���ĺ� ���� ���� üũ
	int cnt_notgroup = 0; //�׷� �ܾ �ƴ� ��

	for (int i = 0; i < n; i++) {
		char *str = malloc(sizeof(char) * 100);    // char �迭 ���� �޸� �Ҵ�

		printf("���ڿ��� �Է��ϼ���: ");
		scanf("%s", str);      // ǥ�� �Է��� �޾Ƽ� �޸𸮰� �Ҵ�� ���ڿ� �����Ϳ� ����

		check[str[0] - 'a'] = i + 1; //��ó�� ���ĺ� ����
		for (int j = 1; str[j] != '\0'; j++) {
			if (str[j - 1] != str[j]) { //������ �ٸ��� 
				if (check[str[j] - 'a'] == i + 1) { //������ ���Դ� ���ĺ����� �˻�
					cnt_notgroup++;
					break;
				}
				else {
					check[str[j] - 'a'] = i + 1;
				}
			}
		}
		free(str);    // ���� �޸� ����
	}
	printf("�׷�ܾ��� �� : %d", n - cnt_notgroup);
	return 0;
}