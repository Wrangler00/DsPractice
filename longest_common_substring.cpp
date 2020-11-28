class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        if(len<2)   return s;
        
        string st = string(s.rbegin(),s.rend());
        int maxx=1,x=-1,y=-1;
        
        vector<vector<int>> dp(len+1,vector<int>(len+1,0));
        
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                if(s[i-1] == st[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    if(dp[i][j]>maxx){
                        x=i;
                        y=j;
                        maxx = dp[i][j];
                    }
                }
            }
        }
        
        
        if(maxx==1){
            return string(1,s[0]);
        }
        // cout<<maxx<<endl;
        string ans="";
        --x;--y;
        while(x>=0 && y>=0 && s[x]==st[y]){
            ans=string(1,s[x])+ans;
            --x;
            --y;
        }
        return ans;
    }
};
