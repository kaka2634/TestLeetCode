// RansomNoteTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<unordered_map>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> magazineMap(0);
        for(int i=0;i<magazine.length();i++)
        {
			magazineMap[magazine[i]]++;
		}
			for(int j=0;j<ransomNote.length();j++)
        if (magazineMap[ransomNote[j]]>0)
		{
			magazineMap[ransomNote[j]]--;
		    cout<<magazine[j];
		}
		else return false;
        
        return true;
        
        
    };

int _tmain(int argc, _TCHAR* argv[])
{
	string str1,str2;
	cin>>str1>>str2;
	cout<<canConstruct(str1,str2);

	return 0;
}

