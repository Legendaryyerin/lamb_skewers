#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<cstddef>
#include <fstream>


#define FILENAME_LEN 4096
#define MAX_LENGTH 4096

using namespace std;

char resultPath[FILENAME_LEN];
//char filename[50];
char Myname_filename[50];
char Myname[20];
char filelist[50];


void filestream() { //파일 작성하기
	
	char contents[50];
	char filename[50];
	
	printf("작성자 이름을 입력해주세요.");
	scanf("%s", &Myname);
	printf("%d 글자군요!\n", strlen(Myname));



	//filename scanf 받기
	
	printf("filename을 입력하세요.\n");
	scanf("%s", filename);
	//printf("before sprintf : %s\n", filename);

	strcpy(Myname_filename, filename); //mynameis함수에서도 filename사용하기 위해 전역변수myname_filename에도 filename값 복사해놓기

	char resultPath[FILENAME_LEN];
	sprintf(resultPath, "C:\\Users\\user\\Desktop\\c\\2308_C_project\\filelist\\%s - %s.txt", Myname, filename);
	// 오른쪽 filename 배열이 가진 데이터를 (파일이름).txt 형태로 바꿔서 왼쪽 filename에 저장
	//file내용 scanf 받기
	//주의 : 파일 경로 설정시, 주드라이버인 C:\에는 생성이 정상적으로 이뤄지지 않음. 하위 디렉터리 이용하기.
	
	//printf("len : %d\n", strlen(resultPath));
	//printf("name : %s\n", resultPath);
	

	FILE* fp = fopen(resultPath, "w");
	

	if (fp == NULL) {
		fprintf(stderr, "fopen error\n");
		exit(1);
	}

	printf("file contents 를 입력해주세요.\n");
	scanf("%s", &contents);
	fprintf(fp, "%s\n", &contents);


	if (fp == NULL) {
		printf("file open error!");
		exit(0);
	}

	fclose(fp);
}



 void print_filelist() {

	WIN32_FIND_DATAA data;
	std::vector<std::string>file_list;
	std::vector<std::string>dir_list;
	
	try {
		HANDLE hFind = FindFirstFileA("C:\\Users\\user\\Desktop\\c\\2308_C_project\\filelist\\*", &data); //첫번째 파일을 찾아 핸들 리턴
		if (hFind == INVALID_HANDLE_VALUE)
			throw std::runtime_error("FindFirstFile 실패"); //예외처리

		while (FindNextFileA(hFind, &data)) {
			if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && //디렉터리라면
				!(data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)) //시스템파일은제외
			{
				dir_list.push_back(std::string(data.cFileName));
			}
			else if ((data.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE) && //파일이라면
				!(data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)) //시스템파일은제외
			{
				file_list.push_back(std::string(data.cFileName));
			}
		}
		FindClose(hFind); //핸들 닫아주기
	}
	catch (std::runtime_error e) {
		std::cerr << e.what() << std::endl;
		//return 0; <-불필요해보임
	}

	//출력으로 확인하기
	std::cout << "파일리스트" << std::endl;
	for (std::string str : file_list) {
		std::cout << str << std::endl;
	}
	/*
	std::cout << "디렉터리리스트" << std::endl;
	for (std::string str : dir_list) {
		std::cout << str << std::endl;
	}
	*/

}


 void My_list() {
	 //작성자 이름으로 자기 글만 볼 수 있게 함



	 char dest[20];
	 int num;
	 char change_file[50]; //수정하고자하는 파일네임 받으려고 생성한 변수

	 while (true) {
		 printf("선택해주세요.\n1.내가 작성한 글 확인하기\n2. 내가 작성한 글 수정하기\n3. 나가기\n");
		 scanf("%d", &num);

		 if (num == 1) {



			 printf("검색하려는 작성자 이름을 입력하세요.\n");
			 scanf("%s", &dest);

			 WIN32_FIND_DATAA data;
			 std::vector<std::string>file_list;
			 std::vector<std::string>dir_list;

			 try {
				 HANDLE hFind = FindFirstFileA("C:\\Users\\user\\Desktop\\c\\2308_C_project\\filelist\\*", &data); //첫번째 파일을 찾아 핸들 리턴
				 if (hFind == INVALID_HANDLE_VALUE)
					 throw std::runtime_error("FindFirstFile 실패"); //예외처리

				 while (FindNextFileA(hFind, &data)) {
					 if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && //디렉터리라면
						 !(data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)) //시스템파일은제외
					 {
						 dir_list.push_back(std::string(data.cFileName));
					 }
					 else if ((data.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE) && //파일이라면
						 !(data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)) //시스템파일은제외
					 {
						 file_list.push_back(std::string(data.cFileName));
					 }
				 }
				 FindClose(hFind); //핸들 닫아주기
			 }
			 catch (std::runtime_error e) {
				 std::cerr << e.what() << std::endl;
				 //return 0; <-불필요해보임
			 }
			 std::vector<std::string>::iterator it;

			 for (it = file_list.begin(); it != file_list.end(); it++) {
				 if (!strncmp(it->c_str(), dest, strlen(dest))) {
					 cout << *it << endl;

				 }
			 }


		 }

		 if (num == 2) {


			 printf("확인하고자 하시는 파일의 제목을 입력해주세요.\n");
			 scanf("%s", &change_file);

			 WIN32_FIND_DATAA data;
			 std::vector<std::string>file_list;
			 std::vector<std::string>dir_list;

			 try {
				 HANDLE hFind = FindFirstFileA("C:\\Users\\user\\Desktop\\c\\2308_C_project\\filelist\\*", &data); //첫번째 파일을 찾아 핸들 리턴
				 if (hFind == INVALID_HANDLE_VALUE)
					 throw std::runtime_error("FindFirstFile 실패"); //예외처리

				 while (FindNextFileA(hFind, &data)) {
					 if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && //디렉터리라면
						 !(data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)) //시스템파일은제외
					 {
						 dir_list.push_back(std::string(data.cFileName));
					 }
					 else if ((data.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE) && //파일이라면
						 !(data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)) //시스템파일은제외
					 {
						 file_list.push_back(std::string(data.cFileName));
					 }
				 }
				 FindClose(hFind); //핸들 닫아주기
			 }
			 catch (std::runtime_error e) {
				 std::cerr << e.what() << std::endl;
				 //return 0; <-불필요해보임
			 }
			 std::vector<std::string>::iterator it;

			 for (it = file_list.begin(); it != file_list.end(); it++) {
				 if (!strncmp(it->c_str(), dest, strlen(dest))) {
					 cout << *it << endl;

				 }
			 }

			 //printf("%s", Myname_filename);
			 //내가 볼 때는, Myname_filename이 아직 안 찾아진듯
			 //myname_filename이 아직 설정이 안 된 듯


			 char* ptr = strtok(Myname_filename, ":"); //구분자는 " : "
			 printf("ptr : %s\n", ptr);
			 while (ptr != NULL) {  // " : "기준으로 자르고
				 if (ptr == change_file) {  // 앞에꺼가 myname과 같으면
					 printf("name : %s\n", change_file);   //뒤에 filename출력

					 
					 FILE *p_file;
					 char str[4096]; //파일 내용 4096까지만 출력가능

					 //파일열기 시도
					 p_file = fopen(change_file, "r");
					 if (p_file != NULL) {
						 //파일 열기에 성공한 경우!
						 if (fgets(str, 4096, p_file) != NULL) {
							 //파일 읽기에 성공한 경우, 해당 문자열을 출력.
							 printf("%s", str);
						 }
						 else {
							 //파일에서 파일 읽기를 실패한 경우!
							 printf("파일에서 문자열을 읽을 수 없습니다. \n");
						 }
						 fclose(p_file); //파일 다 사용했으면 파일 닫기
					 }
					 else {
						 printf("fopen error\n");
						 break;
					 }

					 /*
					 ifstream ifs(Myname_filename);
					 if (ifs.fail()) {
						 cerr << "file open Error!" << endl;
						 exit(0);
					 }

					 char line[256] = { 0, };
					 while (ifs.getline(line, 256)) {
						 cout << line << endl;
					 }
					 */
				 }
				 //ptr = strtok(NULL, ":");
			 }

			 /*
			 ifstream file("%s.txt", &change_file);
			 istreambuf_iterator<char> begin(file), end;

			 cout << string(begin, end);
			 */

		 }
		 if (num == 3) {
			 break;
		 }

	 }


	 /*
	 char* ptr = strtok(Myname_filename, ":"); //구분자는 " : "
	 while (ptr != NULL) {  // " : "기준으로 자르고
		 if (ptr == dest) {  // 앞에꺼가 myname과 같으면
			 printf("%s\n", &Myname_filename);   //뒤에 filename출력
		 }
		 ptr = strtok(NULL, ":");
	 }
	 */


 }



 int main() {

	 //filestream();
	 while (true) {
	 printf("안녕하세요! 애린마켓입니다~\n");
	 printf("다음 중에 선택해주세요.\n");
	 printf("1. 마켓 구경하기\n2. 마켓 내, 내 글 리스트와 내용 확인하기 \n3. 글 작성하기\n4. 종료하기\n");

	 int number;
	 char filecontents_change[30];
	 scanf("%d", &number);

	 

		 if (number == 4) {
			 printf("프로그램을 종료합니다.");
			 break;
		 }

		 if (number == 1) {
			 print_filelist(); //전체 리스트만 뽑는거
			 //break;
		 }
		 else if (number == 2) {
			 
			 My_list(); //내 글 리스트업 확인시켜주기
			 
			 //break;
			
		 }
		 else if (number == 3) {
			 filestream(); //파일 작성하는거
			 printf("파일 이름 : %s", &Myname_filename);
			 //break;
		 }
		 else {
			 printf("다시 입력해라. 화나게 하지 마라.");
			 
		 }
		 break;
	 }
	 return 0;
 }

//해야할 것
// 전체 파일 리스트 중 내 글만 뽑는 것. (변수 두 개 설정 후 a | b 로 글제목 작성함. 
//a=작성자, b=글제목. a==scanf로 받은 값인지 확인 후 그것만 뽑기