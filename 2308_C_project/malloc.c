void yamyam() { //�޸� �����Ҵ� �Լ�. ���ϳ��� 4096�� ���� �ʿ����, ��ü�� 4096���� ���ΰ� �� ���ο��� �����Ҵ����� �༭ �޸𸮳������� �ʵ���. �����ص� ���� ��.

	int num;
	int* pArr;
	int average = 0;
	printf("�� ���� ������� �����ϰ� �ͽ��ϱ�?");
	scanf("%d", &num);

	//0���� ������, ���α׷� ����
	if (num == 0) {
		printf("������ ������� �����ϴ�. ���α׷��� �����մϴ�.");
		exit(1);
	}

	//���� ���� ��ŭ �޸� ���� �Ҵ�.
	pArr = (int*)malloc(sizeof(int) * num);

	//���� �Ҵ� ����
	if (pArr == NULL) {
		printf("malloc error");
		Sleep(5000);
	}

	//������ �ް� �����մϴ�.
	for (int i = 0; i < num; ++i) {
		printf("[%d/%d]���� �Է� : ", i + 1, num);
		scanf("%d", &pArr[i]);
	}

	//���
	for (int i = 0; i < num; ++i) {
		printf("%d��° ������ ���� : %d\n", i + 1, pArr[i]);
	}

	//��� ���
	for (int i = 0; i < num; ++i) {
		average += pArr[i];
	}

	//������ ���������� ������, �Ҽ��� ���ϴ� �������ϴ�.
	average /= num;
	printf("��� : %d\n", average);

	//�����Ҵ� ����
	free(pArr);

	system("pause");

}
