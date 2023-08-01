//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    int n = s.size();
    unordered_map<int,int>umap;
    
    int l = 0;
    int ans = 0;
    for(int r = 0; r < n;r++){
        umap[s[r]]++;
        while(umap[s[r]]>1){
            umap[s[l]]--;
            l++;
        }
        
        ans = max(ans,r-l+1);
    }
    return ans;
}