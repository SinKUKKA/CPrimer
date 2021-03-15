// test_3_15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

// 重建二叉树  已知前序遍历和中序遍历结果  输出后序遍历/广度遍历结果   多用指针

class BinartTree
{
public:
	int  m_Value;
	BinartTree* pLeft;
	BinartTree* pRight;
};

BinartTree* ConstructCore(int* StartPre, int* EndPre, int* StartIn, int* EndIn)
{
	BinartTree* root = new BinartTree();
	root->m_Value = StartPre[0];
	root->pLeft = nullptr;
	root->pRight = nullptr;
	int rootValue = StartPre[0];
	
	if (StartPre == EndPre)
	{
		if (StartIn == EndIn && *StartPre == *StartIn)
			return root;
		else
			throw std::exception("unvalid input");
	}

	int* rootIn = StartIn;
	while (rootIn <= EndIn && *rootIn != rootValue)
		rootIn++;

	if (rootIn == EndIn && *rootIn != rootValue)
		throw std::exception("unvalid input");

	int leftLength = rootIn - StartIn;
	int* LeftEndPre = StartPre + leftLength;
	if (leftLength > 0)
	{
		root->pLeft = ConstructCore(StartPre + 1, LeftEndPre, StartIn, rootIn - 1);
	}
	if (leftLength < EndIn - StartPre)
	{
		root->pRight = ConstructCore(LeftEndPre + 1, EndPre, rootIn + 1, EndIn);
	}
	return root;
}

BinartTree* Construct(int* PreOreder, int* InOreder, int length)
{
	if (PreOreder == nullptr || InOreder == nullptr || length <= 0)
		return nullptr;
	return ConstructCore(PreOreder, PreOreder + length - 1, InOreder, InOreder + length - 1);
}






// 一个保险函数用来检测输入是否正确 一个操作函数进行规划输出
/*
默写
前序
class TreeNote
{
    int value;
	TreeNote *pLeft;
	TreeNote *pRight;
};
void displayelem(TreeNote* plot)
{
    printf("%d",plot->value);
}
void func(TreeNote* root)
{
  if(root)     如果为空 访问上一层
  {
  displatelem(root);
  func(root->pLeft);
  func(root->pRight);
  }
  return;
}

中序
void func(TreeNote* root)
{
  if(root)
  {
  func(root->pLeft);
  display(root);
  func(root->pRight);
  }
  return;
 }

 后序
 void func(TreeNode* root)
 {
  if(root)
  {
  func(root->pLeft);
  func(root->pRight);
  display(root);
  }
  return;
  }

*/



int main()
{
	int a[8] = {1,2,4,7,3,5,6,8};
	int b[8] = {4,7,2,1,5,3,8,6};
	Construct(a, b, 8);
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
