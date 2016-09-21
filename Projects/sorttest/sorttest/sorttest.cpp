// sorttest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <fstream>
using namespace std;

template<typename Comparable>
void insertsort(vector<Comparable>& a) // must use & for change a;
{
    int j;// declare first 
	for(int i = 1;i < a.size(); i++)//i for 1;
	{
		Comparable tmp = a[i];
		for (j = i; j > 0 && a[j-1] > tmp; j--)
			a[j]=a[j-1];
		a[j]=tmp;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int k;
	vector<int> a;
	while(fin>>k)
		a.push_back(k);   
	insertsort(a);
	for(auto v:a) fout<<v;
	fin.close();
	fout.close();
	return 0;
}

