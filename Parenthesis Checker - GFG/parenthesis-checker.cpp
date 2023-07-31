//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>st;
        
        for(auto &c:x){
            if(st.empty()){
                st.push(c);
            }else if( (st.top()=='(' && c==')') || (st.top()=='{' && c=='}') || (st.top()=='[' && c==']')){
                st.pop();
            }else st.push(c);
        }
        
        if(st.empty()) return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends