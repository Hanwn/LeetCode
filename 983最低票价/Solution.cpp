//解法1：
class Solution{
	public:
		int mincostTicets(vector<int>&days,vector<int>& costs){
			unordered_map<int> traval(days.begin(),days.end());
			vector<int> dp(366);
			for(int i = 1;i<366;i++){
				if(traval.find(i) == traval.end()){
					traval[i] = traval[i-1];
				}else{
					traval[i] = min({ dp[i-1]+costs[0], dp[max(0,i-7)]+costs[1], dp[max(0,i-30)]+costs[2] });
				}
			}
			return dp[365];
		}
};
//解法2

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> traval(days.begin(),days.end());
        vector<int> dp(30);
        for(int i = days.front();i<days.back()+1;i++){
            if(traval.find(i) == traval.end()){
                dp[i%30] = dp[(i-1)%30];
            }else{
                dp[i%30] = min( { dp[(i-1)%30] + costs[0] , dp[max(0,i-7)%30] + costs[1] , dp[max(0,i-30)%30]+ costs[2] } );
            }
        }
        return dp[days.back()%30];
    }
};


Reference：https://leetcode.com/problems/minimum-cost-for-tickets/discuss/226659/Two-DP-solutions-with-pictures