void yamyam() { //메모리 동적할당 함수. 파일내용 4096씩 버릴 필요없고, 전체는 4096으로 냅두고 그 내부에서 동적할당으로 줘서 메모리낭비하지 않도록. 변경해도 좋을 듯.

	int num;
	int* pArr;
	int average = 0;
	printf("몇 명의 수료생을 저장하고 싶습니까?");
	scanf("%d", &num);

	//0개를 넣으면, 프로그램 종료
	if (num == 0) {
		printf("저장할 수료생이 없습니다. 프로그램을 종료합니다.");
		exit(1);
	}

	//과목 갯수 만큼 메모리 동적 할당.
	pArr = (int*)malloc(sizeof(int) * num);

	//동적 할당 실패
	if (pArr == NULL) {
		printf("malloc error");
		Sleep(5000);
	}

	//점수를 받고 저장합니다.
	for (int i = 0; i < num; ++i) {
		printf("[%d/%d]점수 입력 : ", i + 1, num);
		scanf("%d", &pArr[i]);
	}

	//출력
	for (int i = 0; i < num; ++i) {
		printf("%d번째 과목의 점수 : %d\n", i + 1, pArr[i]);
	}

	//평균 출력
	for (int i = 0; i < num; ++i) {
		average += pArr[i];
	}

	//정수로 나누어지기 때문에, 소수점 이하는 버려집니다.
	average /= num;
	printf("평균 : %d\n", average);

	//동적할당 해제
	free(pArr);

	system("pause");

}
