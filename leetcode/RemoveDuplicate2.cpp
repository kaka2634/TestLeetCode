#include <iostream>
#include <vector>
using namespace std;

int main()
{
        vector<int> nums;
        int n,m;
        cin>>n;
        for (int i=0; i<n; i++)
        {
                cin>>m;
                nums.push_back(m);
        }
        int i,j=0,k=0;
        i=1;
        while(i<n)
        {
                if(nums[i]==nums[j])
                {
                        if(k==0)
                        {
                                nums[++j]=nums[i];
                                k++;
                        }
                }

                else
                {
                        nums[++j]=nums[i];
                        k=0;
                }
                i++;
        }
        cout<<j+1;
        for (int i=0; i<j+1; i++)
        {
                cout<<nums[i];
        }
        return 0;
}
