// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>
#include <iostream>
#include <fstream>
#include "CharCount.h"
#include "LineCount.h"
#include "Word_Fre.h"
#include "WordNum.h"
using namespace std;


int main(int argc, char *argv[])
{
	

	int Char_Count = CharCount(argv[1]);
	int Lines_Count = LineCount(argv[1]);
	int Words_Count = WordNum(argv[1]);
	ofstream outfile("result.txt", ios::out);
	printf("characters: %d\n", Char_Count);
	printf("words: %d\n", Words_Count);
	printf("lines: %d\n", Lines_Count);
	outfile << "characters: " << Char_Count << endl;
	outfile << "words: " << Words_Count << endl;
	outfile << "lines: " << Lines_Count << endl;
	Word_Fre(argv[1]);			

	
	return 0;
}
