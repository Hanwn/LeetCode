> 简单总结一波关于枚举类型的问题


## 1指数型枚举

### 1.1子集

问法1：从1-n中选任意多个
> 也就是说从[1,2,3...n]中所有找出非空子集

```c++
class Solution
{
public:
	int n;
	void fun(int num){
		n = num;
		dfs(0,0);
	}
	void dfs(int u,int state){
		if(u == n){
			for(int i = 0;i<n;i++){
				if(state>>i&1){
					cout<<i+1<<" ";
				}
			}
			cout<<endl;
			return;
		}
		dfs(u+1,state);
		dfs(u+1,state|1<<u);
	}
	
};

```
问法2:找出[1,2,3...n]的所有子集
```c++
class Solution
{
public:
	vector<vector<int>> res;
	vector<vector<int>> fun(vector<int>& nums){
		vector<int> path;
		dfs(nums,path,0,0);
		return res;
	}
	void dfs(vector<int>& nums,vector<int>& path,int start,int state){
		if(start == nums.szie()){
			res.push_back(path);
			return;
		}
		dfs(nums,path,start+1,state);
		path.push_back(nums[start]);
		dfs(nums,path,start+1,state|1<<start);
		path.pop_back();
	}
	
};

```

### 1.2子集Ⅱ(含有重复元素)

```c++
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> path;
        dfs(nums,path,0);
        return res;
    }
    
    void dfs(vector<int>& nums,vector<int>& path,int begin){
        res.push_back(path);
        for(int i = begin;i<nums.size();i++){
            if(i==begin||nums[i] != nums[i-1]){
                path.push_back(nums[i]);
                dfs(nums,path,i+1);
                path.pop_back();
            }
        }
    }
};
```

## 2排列型枚举

### 2.1全排列

```c++
class Solution
{
public:
	vector<vector<int>> res;
	vector<vector<int>> fun(vector<int>& nums){
		vector<int> path;
		dfs(nums,path,0);
		return res;
	}
private:
	void dfs(vector<int>& nums,vector<int> path,int state){
		if(path.size() == nums.size()){
			res.push_back(path);
			return ;
		}
		for(int i = 0;i<nums.size();i++){
			if(!(state>>i&1)){
				path.push_back(nums[i]);
				dfs(nums,path,state | 1<<i);
				path.pop_back();
			}
		}
	}
	
};
```

### 2.2全排列(有重复元素)

```c++
class Solution {
public:
    vector<vector<int>> res;
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> path;
		dfs(nums, path, 0);
		return res;
	}
	void dfs(vector<int>& nums, vector<int> path,int state)
	{
		if (path.size() == nums.size()){
			res.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if ((state>>i)&1||i>0&&nums[i] == nums[i-1]&&!(state>>(i-1)&1)){
                continue; 
            }
			path.push_back(nums[i]);
			dfs(nums, path, state | 1<< i);
			path.pop_back();
		}
	}
};
```


## 3组合型枚举

### 3.1组合数
```c++
class Solution
{
public:
	vector<vector<int>> res;
	int n
	vector<vector<int>> fun(int m,int count){
		n = count;
		vector<int> nums;
		for(int i = 0;i<m;i++){
			nums.push_back(i+1);
		}
		dfs(nums,vector<int>(),0);
		return res;
	}
private:
	void dfs(vector<int>& nums,vector<int> path,int start){
		if(path.size() == n){
			res.push_back(path);
			return;
		}
		for(int i = start;i<nums.size();i++){
			path.push_back(nums[i]);
			dfs(nums,path,i+1);
			path.pop_back();
		}
	}
	
};
```

