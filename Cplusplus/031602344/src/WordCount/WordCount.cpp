#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <map>
using namespace std;
struct word_node			// 词频
{
	string word;
	int fre;
	word_node() {}
	word_node(string _word, int _fre) :word(_word), fre(_fre) {};
	bool operator < (word_node & b)
	{
		if (fre == b.fre)
			return (word.compare(b.word) < 0);
		return fre > b.fre;
	}
};
int main(int argc, char* argv[])
{
	regex word_regex("[A-Za-z][A-Za-z][A-Za-z][A-Za-z][A-Za-z0-9]+");		//正则表达式

	//string filename;														//读文件
	//cin >> filename;
	ifstream in(argv[1], ios::in);

	string line;
	string word;
	vector<string> lines;
	vector<string> words;
	map<string, int> word_count_map;
	int character = 0;
	if (!in.good())
		cout << "cannot open file" << endl;
	else
	{
		string line;
		string word;
		vector<string> lines;
		int words = 0;
		int characters = 0;
		while (!in.eof())
		{
			getline(in, line);
			if (line.size() != 0)
			{
				lines.push_back(line);
				characters += line.size();
				sregex_iterator pos(line.cbegin(), line.cend(), word_regex);
				sregex_iterator end;
				for (; pos != end; ++pos)
				{
					transform(word.begin(), word.end(), word.begin(), ::tolower);
					string word = pos->str();
					words++;
					if (word_count_map.count(word) == 0)
						word_count_map[word] = 1;
					else word_count_map[word] += 1;
				}

				//words.push_back(pos->str());
			}
		}
		/*cout << "characters:" << characters << endl;
		cout << "words:" << words << endl;
		cout << "lines:" << lines.size() << endl;*/

		vector<word_node> word_node_list;

		auto it = word_count_map.begin();
		for (; it != word_count_map.end(); it++)
			word_node_list.push_back(word_node(it->first, it->second));

		sort(word_node_list.begin(), word_node_list.end());

		int should_show = min(10, int(word_node_list.size()));

		for (int i = 0; i < should_show; i++)
		{
			cout << word_node_list[i].word << ": " << word_node_list[i].fre << endl;
		}
		ofstream outfile;
		outfile.open("result.txt");
		outfile << "characters:" << characters << endl;
		outfile << "words:" << words << endl;
		outfile << "lines:" << lines.size() << endl;
		for (int i = 0; i < should_show; i++)
			outfile << word_node_list[i].word << ": " << word_node_list[i].fre << endl;
		outfile.close();
	}
}