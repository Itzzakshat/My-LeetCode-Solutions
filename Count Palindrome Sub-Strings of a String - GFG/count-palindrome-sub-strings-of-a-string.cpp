//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int CountPS(char s[], int n)
{
    int dp[n][n];
    
    for(int i = 0; i < n;i++){
        dp[i][i] = 1;
    }
    int cnt= 0;
    for(int i = 0;i < n-1;i++){
        dp[i][i+1] = (s[i]==s[i+1]);
        if(dp[i][i+1]) cnt++;
    }
    
    
    
    for(int i = n-3;i>=0;i--){
        for(int j = i+2; j<n;j++){
            dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
            if(dp[i][j]) cnt++;
        }
    }
    return cnt;
    
    
}