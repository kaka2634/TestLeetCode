// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	vector<char> postfix;
    vector<char> opera;
	vector<int> num;
	for(int i=0;i<s.length();i++)
	{
		if(47<s[i]&&s[i]<58) postfix.push_back(s[i]);//不能写成47<s[i]<58
		else
			switch (s[i])
		{
			case '*':
				while(!opera.empty()&&*(--opera.end())!='+'&&*(--opera.end())!='(') //不能颠倒判断顺序不然如果是空的则访问end--会溢出
				{
				postfix.push_back(*(--opera.end()));	
				opera.pop_back();
				}	
				opera.push_back(s[i]);
			    break;
			case '(':
				opera.push_back(s[i]);
				break;
			case '+':
				while(!opera.empty()&&*(--opera.end())!='(')
				{
				postfix.push_back(*(--opera.end()));	
				opera.pop_back();
				}	
				opera.push_back(s[i]);
				break;
			case ')':
				while(*(--opera.end())!='(')
				{
				postfix.push_back(*(--opera.end()));	
				opera.pop_back();
				if(opera.empty()) cout<<"error";
				}	
				opera.pop_back();
				break;
			default:
				cout<<"error";
				break;
		}
	}			
	    while(!opera.empty())
				{
				postfix.push_back(*(--opera.end()));	
				opera.pop_back();
				}	
	for(int i=0;i<postfix.size();i++)
	cout<<postfix[i];
	return 0;
}

