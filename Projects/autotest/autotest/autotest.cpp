// autotest.cpp : �������̨Ӧ�ó������ڵ㡣
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
		cout<<i;//ʹ��auto ���Ա���a
	for(auto &i:a)
	{    i=2;
	     cout<<i;//�ܹ��ı�a
	}
	cout<<a[0];
	return 0;
}

