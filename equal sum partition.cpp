#include <bits/stdc++.h>
using namespace std;

 
class Solution{
public:
    
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0,i,j;
        for(i=0;i<n;i++)
        sum+=arr[i];
        
        if(sum%2==1)
        return 0;
        
        bool part[sum/2+1][n+1];
        
        for (i = 0; i <= n; i++)
        part[0][i] = true;
 
        for (i = 1; i <= sum / 2; i++)
        part[i][0] = false;
 
    
        for (i = 1; i <= sum / 2; i++) {
        for (j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j]
                             || part[i - arr[j - 1]][j - 1];
        }
        }
 
        return part[sum/2][n];
    
    
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
} 