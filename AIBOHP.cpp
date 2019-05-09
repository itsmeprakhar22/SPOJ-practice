#include <bits/stdc++.h>
#define int long long
using namespace std;

int lcs(string s,string r,int n){
	int** dp=new int*[n+1];
	for(int i=0;i<n+1;i++){
		dp[i]=new int[n+1];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0){
				dp[i][j]=0;
			}
			else{
				if(s[i-1]==r[j-1])
				dp[i][j]=1+dp[i-1][j-1];
				else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	int ans=dp[n][n];
	delete[] dp;
	return ans;
}


signed main(){
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		string r=s;
		reverse(r.begin(),r.end());
		int n=s.length();
		int l=lcs(s,r,n);
		cout<<n-l<<endl;
	}
}
