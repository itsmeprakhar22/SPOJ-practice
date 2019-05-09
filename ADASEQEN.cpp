#include<bits/stdc++.h>
using namespace std;

int total=0;
int lcs(string s1, int m, string s2, int n, int* cost){
	int dp[m+1][n+1];
	memset(dp, 0, sizeof(dp));

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
				if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1] + cost[s1[i-1]];
				}
				else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[m][n];
}

int main(){
	int m,n; cin>>m>>n;
	int cost[26];
	for(int i='a';i<='z';i++)
	cin>>cost[i];
	cout<<endl;
	string s1,s2; cin>>s1>>s2;
  
	int x=lcs(s1, m, s2, n, cost);
	cout<<x<<endl;
	
}
