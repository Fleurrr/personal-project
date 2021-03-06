// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>
#include <iostream>
#include <fstream>
#include "CharNum.h"
#include "LineNum.h"
#include"WordNum.h"
#include "Word_Fre.h"
using namespace std;


int main(int argc, char *argv[])
{
	
	if (argv[1] == NULL)
	{
		
		printf("please input file!\n");
		return -1;

	}
	std::fstream file;
	file.open(argv[1]);
 if (!file) {
		
		printf("the file cannot open or no exist!\n");
		return -1;
	}
		
	file.close();

		FILE * stream;
		freopen_s(&stream, "result.txt", "w", stderr);
		int Char_Number = CharNum(argv[1]);
		int Lines_Number = LineNum(argv[1]);
		int Words_Number = WordNum(argv[1]);
		
		fprintf(stream,"characters: %d\n", Char_Number);
		fprintf(stream, "words: %d\n", Words_Number);
		fprintf(stream, "lines: %d\n", Lines_Number);
		
		
		Word_Fre(argv[1]);			//Word frequency statistics
		
	
	
	
	return 0;
}
