#include "pch.h"
#include <iostream>
#include<string>
#include<stdio.h>
#include"CountChar.h"
#include"topten.h"
#include"CountWords.h"
#include"CountLines.h"
#include<cstdlib>
#include<fstream>
#include<algorithm>
#include<map>
using namespace std;

map<string, int> M;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
	return a.first > b.first;
}

int main()
{
	//for (int i = 0; i < 10000; i++) //用于测试
	//{
	ofstream fileOutput;
	//char filename[105]= "test.txt";//用于测试
	cout << "input the filename: ";
	cin >> filename;
	fileOutput.open("result.txt", ios::app);
	fileOutput << "characters: " << CountChar(filename) << endl;
	fileOutput << "lines: " << CountLines(filename) << endl;
	fileOutput << "words: " << CountWords(filename) << endl;
	topten(filename);
	int count = 10;
	vector<pair<string, int> > ans;
	for (auto u : M) {
		ans.push_back(u);
	}
	sort(ans.begin(), ans.end(), cmp);
	for (auto u : ans)
	{
		if (count)  fileOutput << u.first << " " << u.second << endl;
		else break;
	}
	//}
	return 0;
}