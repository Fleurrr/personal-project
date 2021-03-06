// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include<stdio.h>
#include"char_count.h"
#include"top_ten.h"
#include"word_count.h"
#include"line_count.h"
#include<cstdlib>
#include<fstream>
#include<algorithm>
#include<map>
using namespace std;
int main(int argc, char *argv[])				//int argc, char *argv[]
{
//	for (int i = 0; i < 1; i++)
//	{
//		char *argv[2];
//		char char_tmp1[] = "WordCount.exe";
//		char char_tmp2[] = "test.txt";
//		argv[0] = char_tmp1;
//		argv[1] = char_tmp2;
	if (argc >= 3)
	{
		printf("You can only input like \"WordCount.exe input.txt\", it can only read one input file.\n");
	}
	else
	{
		int ch_cnt = 0;								//统计文件中的字符总数（排除换行符）
		int word_cnt;								//统计文件中的单词数
		int line_cnt;								//统计文件的行数
		Top_Ten words[10];
		ch_cnt = Ch_Count(argv[1]);
		word_cnt = Word_Count(argv[1]);
		line_cnt = Lines_Count(argv[1]);
		Top_Tenwords(words, argv[1]);
		ofstream out_file;
		out_file.open("result.txt");
		if (!out_file)
		{
			cout << "Can't open file :result.txt. " << "\nUsage:countch filename" << endl;
			exit(0);
		}
		out_file << "characters: " << ch_cnt << endl;
		out_file << "words: " << word_cnt << endl;
		out_file << "lines: " << line_cnt << endl;
		for (int j = 0; j < 10; j++)
		{
			if (words[j].word != "")
			{
				out_file << words[j] << endl;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}