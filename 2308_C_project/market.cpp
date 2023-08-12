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


void filestream() { //���� �ۼ��ϱ�
	
	char contents[50];
	char filename[50];
	
	printf("�ۼ��� �̸��� �Է����ּ���.");
	scanf("%s", &Myname);
	printf("%d ���ڱ���!\n", strlen(Myname));



	//filename scanf �ޱ�
	
	printf("filename�� �Է��ϼ���.\n");
	scanf("%s", filename);
	//printf("before sprintf : %s\n", filename);

	strcpy(Myname_filename, filename); //mynameis�Լ������� filename����ϱ� ���� ��������myname_filename���� filename�� �����س���

	char resultPath[FILENAME_LEN];
	sprintf(resultPath, "C:\\Users\\user\\Desktop\\c\\2308_C_project\\filelist\\%s - %s.txt", Myname, filename);
	// ������ filename �迭�� ���� �����͸� (�����̸�).txt ���·� �ٲ㼭 ���� filename�� ����
	//file���� scanf �ޱ�
	//���� : ���� ��� ������, �ֵ���̹��� C:\���� ������ ���������� �̷����� ����. ���� ���͸� �̿��ϱ�.
	
	//printf("len : %d\n", strlen(resultPath));
	//printf("name : %s\n", resultPath);
	

	FILE* fp = fopen(resultPath, "w");
	

	if (fp == NULL) {
		fprintf(stderr, "fopen error\n");
		exit(1);
	}

	printf("file contents �� �Է����ּ���.\n");
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
		HANDLE hFind = FindFirstFileA("C:\\Users\\user\\Desktop\\c\\2308_C_project\\filelist\\*", &data); //ù��° ������ ã�� �ڵ� ����
		if (hFind == INVALID_HANDLE_VALUE)
			throw std::runtime_error("FindFirstFile ����"); //����ó��

		while (FindNextFileA(hFind, &data)) {
			if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && //���͸����
				!(data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)) //�ý�������������
			{
				dir_list.push_back(std::string(data.cFileName));
			}
			else if ((data.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE) && //�����̶��
				!(data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)) //�ý�������������
			{
				file_list.push_back(std::string(data.cFileName));
			}
		}
		FindClose(hFind); //�ڵ� �ݾ��ֱ�
	}
	catch (std::runtime_error e) {
		std::cerr << e.what() << std::endl;
		//return 0; <-���ʿ��غ���
	}

	//������� Ȯ���ϱ�
	std::cout << "���ϸ���Ʈ" << std::endl;
	for (std::string str : file_list) {
		std::cout << str << std::endl;
	}
	/*
	std::cout << "���͸�����Ʈ" << std::endl;
	for (std::string str : dir_list) {
		std::cout << str << std::endl;
	}
	*/

}


 void My_list() {
	 //�ۼ��� �̸����� �ڱ� �۸� �� �� �ְ� ��



	 char dest[20];
	 int num;
	 char change_file[50]; //�����ϰ����ϴ� ���ϳ��� �������� ������ ����

	 while (true) {
		 printf("�������ּ���.\n1.���� �ۼ��� �� Ȯ���ϱ�\n2. ���� �ۼ��� �� �����ϱ�\n3. ������\n");
		 scanf("%d", &num);

		 if (num == 1) {



			 printf("�˻��Ϸ��� �ۼ��� �̸��� �Է��ϼ���.\n");
			 scanf("%s", &dest);

			 WIN32_FIND_DATAA data;
			 std::vector<std::string>file_list;
			 std::vector<std::string>dir_list;

			 try {
				 HANDLE hFind = FindFirstFileA("C:\\Users\\user\\Desktop\\c\\2308_C_project\\filelist\\*", &data); //ù��° ������ ã�� �ڵ� ����
				 if (hFind == INVALID_HANDLE_VALUE)
					 throw std::runtime_error("FindFirstFile ����"); //����ó��

				 while (FindNextFileA(hFind, &data)) {
					 if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && //���͸����
						 !(data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)) //�ý�������������
					 {
						 dir_list.push_back(std::string(data.cFileName));
					 }
					 else if ((data.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE) && //�����̶��
						 !(data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)) //�ý�������������
					 {
						 file_list.push_back(std::string(data.cFileName));
					 }
				 }
				 FindClose(hFind); //�ڵ� �ݾ��ֱ�
			 }
			 catch (std::runtime_error e) {
				 std::cerr << e.what() << std::endl;
				 //return 0; <-���ʿ��غ���
			 }
			 std::vector<std::string>::iterator it;

			 for (it = file_list.begin(); it != file_list.end(); it++) {
				 if (!strncmp(it->c_str(), dest, strlen(dest))) {
					 cout << *it << endl;

				 }
			 }


		 }

		 if (num == 2) {


			 printf("Ȯ���ϰ��� �Ͻô� ������ ������ �Է����ּ���.\n");
			 scanf("%s", &change_file);

			 WIN32_FIND_DATAA data;
			 std::vector<std::string>file_list;
			 std::vector<std::string>dir_list;

			 try {
				 HANDLE hFind = FindFirstFileA("C:\\Users\\user\\Desktop\\c\\2308_C_project\\filelist\\*", &data); //ù��° ������ ã�� �ڵ� ����
				 if (hFind == INVALID_HANDLE_VALUE)
					 throw std::runtime_error("FindFirstFile ����"); //����ó��

				 while (FindNextFileA(hFind, &data)) {
					 if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && //���͸����
						 !(data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)) //�ý�������������
					 {
						 dir_list.push_back(std::string(data.cFileName));
					 }
					 else if ((data.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE) && //�����̶��
						 !(data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM)) //�ý�������������
					 {
						 file_list.push_back(std::string(data.cFileName));
					 }
				 }
				 FindClose(hFind); //�ڵ� �ݾ��ֱ�
			 }
			 catch (std::runtime_error e) {
				 std::cerr << e.what() << std::endl;
				 //return 0; <-���ʿ��غ���
			 }
			 std::vector<std::string>::iterator it;

			 for (it = file_list.begin(); it != file_list.end(); it++) {
				 if (!strncmp(it->c_str(), dest, strlen(dest))) {
					 cout << *it << endl;

				 }
			 }

			 //printf("%s", Myname_filename);
			 //���� �� ����, Myname_filename�� ���� �� ã������
			 //myname_filename�� ���� ������ �� �� ��


			 char* ptr = strtok(Myname_filename, ":"); //�����ڴ� " : "
			 printf("ptr : %s\n", ptr);
			 while (ptr != NULL) {  // " : "�������� �ڸ���
				 if (ptr == change_file) {  // �տ����� myname�� ������
					 printf("name : %s\n", change_file);   //�ڿ� filename���

					 
					 FILE *p_file;
					 char str[4096]; //���� ���� 4096������ ��°���

					 //���Ͽ��� �õ�
					 p_file = fopen(change_file, "r");
					 if (p_file != NULL) {
						 //���� ���⿡ ������ ���!
						 if (fgets(str, 4096, p_file) != NULL) {
							 //���� �б⿡ ������ ���, �ش� ���ڿ��� ���.
							 printf("%s", str);
						 }
						 else {
							 //���Ͽ��� ���� �б⸦ ������ ���!
							 printf("���Ͽ��� ���ڿ��� ���� �� �����ϴ�. \n");
						 }
						 fclose(p_file); //���� �� ��������� ���� �ݱ�
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
	 char* ptr = strtok(Myname_filename, ":"); //�����ڴ� " : "
	 while (ptr != NULL) {  // " : "�������� �ڸ���
		 if (ptr == dest) {  // �տ����� myname�� ������
			 printf("%s\n", &Myname_filename);   //�ڿ� filename���
		 }
		 ptr = strtok(NULL, ":");
	 }
	 */


 }



 int main() {

	 //filestream();
	 while (true) {
	 printf("�ȳ��ϼ���! �ָ������Դϴ�~\n");
	 printf("���� �߿� �������ּ���.\n");
	 printf("1. ���� �����ϱ�\n2. ���� ��, �� �� ����Ʈ�� ���� Ȯ���ϱ� \n3. �� �ۼ��ϱ�\n4. �����ϱ�\n");

	 int number;
	 char filecontents_change[30];
	 scanf("%d", &number);

	 

		 if (number == 4) {
			 printf("���α׷��� �����մϴ�.");
			 break;
		 }

		 if (number == 1) {
			 print_filelist(); //��ü ����Ʈ�� �̴°�
			 //break;
		 }
		 else if (number == 2) {
			 
			 My_list(); //�� �� ����Ʈ�� Ȯ�ν����ֱ�
			 
			 //break;
			
		 }
		 else if (number == 3) {
			 filestream(); //���� �ۼ��ϴ°�
			 printf("���� �̸� : %s", &Myname_filename);
			 //break;
		 }
		 else {
			 printf("�ٽ� �Է��ض�. ȭ���� ���� ����.");
			 
		 }
		 break;
	 }
	 return 0;
 }

//�ؾ��� ��
// ��ü ���� ����Ʈ �� �� �۸� �̴� ��. (���� �� �� ���� �� a | b �� ������ �ۼ���. 
//a=�ۼ���, b=������. a==scanf�� ���� ������ Ȯ�� �� �װ͸� �̱�