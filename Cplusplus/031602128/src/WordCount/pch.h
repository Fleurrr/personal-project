
#ifndef PCH_H
#define PCH_H
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<utility>
#include<set>
#include<map>
using namespace std;
const int N = 1000007;
#pragma warning(disable:4996)
#define de(x) cout<<#x<<" = "<<x<<endl
#define rep(i,a,b) for(int i=(a);i<(b);++i)
class  QWE_wordCount {
public:
	string line[N];
	string tmp;
	FILE *fp;
	bool error;
	set<pair<int, string> >qur;//利用set排序，单词次数为第一优先级，string字典序为第二优先级
	set<pair<int, string> >::iterator it;
	struct node {
		node *next[36];
		int gs;
	}*root;
	int num_line, eft_num, eft_char, eft_word,hh;//num_line 为文件总行数 eft_num为有效行数 eft_char为字符数 eft_word为有效单词数
	int Atoatoint(char c);   //将大写字符转化为小写字母，再hash到0~25，以及将0~9hash到26~35.
	char FAtoatoint(int c);  //是上个函数的反函数
	void qinsert(string s);   //字典树插入单词
	void MYscanf(char s[]);   // 输入总控制台
	int CountChar();          //统计字符数
	bool is_efct_char(char c); //判断是否是单词内的字符
	int CountWord();           //计算单词个数
	void dfs_getword(node u);   //搜索字典树
	void CountMxWord();        //计算出词频最大的十个单词
	void MYprint();         //输出总控制台
	void init();            //初始化函数
};
// TODO: 添加要在此处预编译的标头
#endif //PCH_H
