// 删除字符重复项.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 涉及位置可以使用堆栈算法 涉及出现次数可以使用hash表或者普通map实现

#include "pch.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

string removeDuplicates(string s)
{
	string stk;
	map<char, int> charcnt;
	for (char ch : s)
	{
		if (!stk.empty() && stk.back() == ch)
		{
			if (charcnt[ch] != 2)
			{
				stk.push_back(ch);
				charcnt[ch]=charcnt[ch]+1;
			}
			else if (charcnt[ch] == 2)
			{
				stk.pop_back();
				stk.pop_back();
			}
		}
		else
		{
			stk.push_back(ch);
			charcnt[ch] = charcnt[ch] + 1;
		}
	}
	return stk;
}

int main()
{
	string str;
	cin >> str;
    std::cout << removeDuplicates(str); 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
