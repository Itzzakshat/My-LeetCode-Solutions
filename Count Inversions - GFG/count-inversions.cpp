//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],long long *temp,long long s,long long  mid,long long e){
        long long i,j,k=0; long long int inv=0;
        i=s;
        k=s;
        j=mid;
        while(i<=mid-1 && j<=e){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }
            else {
                temp[k++]=arr[j++];
                inv+=mid-i;
            }
        }
            while(i<=mid-1){
                 temp[k++]=arr[i++];
            }
            while(j<=e){
                 temp[k++]=arr[j++];
            }
            
            for(int st=s;st<=e;st++){
                arr[st]=temp[st];
            }
            
            return inv;
        
    }
    long long int mergeSort(long long arr[],long long *temp,long long s,long long e){
        long long inv_cnt = 0;
        if(s<e){
            long long m = s + (e - s)/2;
            inv_cnt += mergeSort(arr,temp,s,m);
            inv_cnt += mergeSort(arr,temp,m+1,e);
            inv_cnt += merge(arr,temp,s,m+1,e);
        }
        return inv_cnt;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long *temp = new long long int[N];
        return mergeSort(arr,temp,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends