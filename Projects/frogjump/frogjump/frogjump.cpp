// frogjump.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;


 bool canCross(vector<int>& stones) {
     map<int,vector<int>> hsmap;
	 int k=1;
	 if (stones[1]==1) hsmap[1].push_back(1); 
	 else return false;
     if (stones.size()>2)
     {
     for(int i=1;i<stones.size()-1;i++)
	 {
		for(int j=i+1;j<stones.size();j++)
		{
			k=stones[j]-stones[i];
            for(int m=0;m<hsmap[i].size();m++)
				if(hsmap[i][m]==k||hsmap[i][m]==k-1||hsmap[i][m]==k+1)
					 hsmap[j].push_back(k);
		}
	 }
	   map<int,vector<int>>::iterator it= hsmap.find(stones.size()-1);
	   if(it == hsmap.end()) {
		   return false;
        }
       else {
		   return true;
        }
     }
 };
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> stones;
	int n,tmp;
	cin>>n;
	for(int i=0;i<n;i++)
  {
	  cin>>tmp;
	  stones.push_back(tmp);
  }
	cout<<canCross(stones);
	return 0;
}

