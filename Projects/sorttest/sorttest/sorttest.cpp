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
		for (j = i; j > 0 && a[j-1] > tmp; j=j-1)
			a[j]=a[j-1];
		a[j]=tmp;
	}
};

template <typename Comparable>
void shellsort(vector<Comparable>& a) // change insert minus 1 to minus gap!
{
	Comparable tmp;//dont forget tmp is Comparable!
	int i,j;
	for(int gap=a.size()/2;gap>0;gap/=2)
	{
		for (i = gap;i<a.size();i++) //i start from gap!
		{
			tmp = a[i];
			j = i;
			for (;j>=gap&&tmp<a[j-gap];j-=gap)//compare with gap!
			a[j] = a[j-gap];
		a[j]=tmp;
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int k;
	vector<int> a;
	while(fin>>k)
		a.push_back(k);   
	//insertsort(a);
	shellsort(a);
	for(auto v:a) fout<<v;
	fin.close();
	fout.close();
	return 0;
}

