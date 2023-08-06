//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //dp[i][j] denotes till j capacity tak i tak ke weights lene par kitna max ban skta h
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int cap, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
       
       for(int i = 1; i <= n;i++){
           for(int j = 1; j<=cap;j++){
               if(j >= wt[i-1]){
                   dp[i][j] = max(dp[i-1][j],val[i-1] + dp[i-1][j - wt[i-1]]);
               }else dp[i][j] = dp[i-1][j];
           }
       }
       return dp[n][cap];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends