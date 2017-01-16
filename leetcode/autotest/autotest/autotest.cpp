// autotest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> a;
    a.push_back(1);
	for(auto i:a)
		cout<<i;//使用auto 可以遍历a
	for(auto &i:a)
	{    i=2;
	     cout<<i;//能够改变a
	}
	cout<<a[0];
	return 0;
}

