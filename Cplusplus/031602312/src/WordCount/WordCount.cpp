#include"stdafx.h"
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<unordered_map>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
string s;
int character, word, line;
unordered_map<string, int>mp;
vector<pair<int, string> >v;
bool cmp(pair<int, string> a, pair<int, string> b);
int count_character(string s);
int count_word(string s);
void sort_wordcount();

int main(int argc, char *argv[])
{
	ifstream file1;
	file1.open(argv[1]);
	if (!file1.is_open()) {
		cout << "文件打开失败";
		return 0;
	}
	character = 0;
	word = 0;
	line = 0;
	mp.clear();
	while (getline(file1, s))
	{
		if (s.empty()) continue;;
		line++;
		character += count_character(s);
		word += count_word(s);
	}
	cout << "characters: " << character << endl;
	cout << "words: " << word << endl;
	cout << "lines: " << line << endl;
	sort_wordcount();
	for (int i = 0; i < 10 && i < v.size(); i++)
	{
		cout << "<" << v[i].second << ">: " << v[i].first << endl;
	}
	return 0;
}

bool cmp(pair<int, string> a, pair<int, string> b)
{
	if (a.first != b.first)return a.first > b.first;
	else return a.second < b.second;
}
int count_character(string s)
{
	return(s.length());
}
bool iszimu(char c)
{
	if (c >= 'a'&&c <= 'z') return true;
	else if (c >= 'A'&&c <= 'Z') return true;
	else return false;
}
int count_word(string s)
{
	string word = "";
	int len = s.length(), cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i]==' '||!isdigit(s[i])&&!iszimu(s[i])||i==len-1)
		{
			if (word.length() >= 4 && word[0] != '\0' && !isdigit(word[0]) && !isdigit(word[1]) && !isdigit(word[2]) && !isdigit(word[3]))
			{
				mp[word]++;
				cnt++;
			}
			word = "";
		}
		else if (isdigit(s[i])) word += s[i];
		else
		{
			if (s[i] < 'a') s[i] += 32;
			word += s[i];
		}
	}
	return cnt;
}
void sort_wordcount()
{
	unordered_map<string, int>::iterator it;
	v.clear();
	for (it = mp.begin(); it != mp.end(); it++)
	{
		v.push_back(make_pair(it->second, it->first));
	}
	sort(v.begin(), v.end(), cmp);
}