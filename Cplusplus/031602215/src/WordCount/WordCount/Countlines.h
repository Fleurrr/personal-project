#pragma once
#include <iostream>
#include <fstream>
using namespace std;


int Countlines(char *filename)
{	//
	ifstream infile;
	if (filename == nullptr)  //为了vs调试方便
	{
		infile.open("input.txt");
	}
	else infile.open(filename);

	char c;
	int row_count = 0,flag1=0,flag2=0;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c; 
		if (c != 10 && c!=' '&&c!='\t') //空格、回车、水平制表符排除
		{
			flag1 = 1;
		}
		if (infile.eof()&& flag1==1) row_count++;
		if (c == 10)
		{	
	//		
			//cout << "1" << endl;
			if (flag1 == 1)
			{
				flag1 = 0;
				row_count++;
			}
		}
	}
	infile.close();
	return row_count ;
}