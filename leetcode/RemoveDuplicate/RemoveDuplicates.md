
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int i=0,j=1;
    if (nums.size()==0) return 0;
    while(i<nums.size())
     {
        if(nums[i]!=nums[i+1])
         {
             nums[j]=nums[i+1];
             j++;
         }
         i++;
     }
    return j;
    }
};
```
错误原因：不能使用i+1来判断，这样一来会越界，二来j也多判断一次返回值j也就是错的。所以j应该是小于i，i来探路，j接收赋值。改为：

```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int i=1,j=0;
    if (nums.size()==0) return 0;
    while(i<nums.size())
     {
        if(nums[i]!=nums[j]) 	//i是来探路的，j是后面的值，这样保证新数组肯定是正确的
         {
             nums[++j]=nums[i];
         }
         i++;
     }
    return j+1; //j是新数组的下标，因而大小需要+1
    }
};
```

