#include <bits/stdc++.h>
#define int long long int
using namespace std;

int exchange(int n, int* dp){
	if(n<10)
	return n;
	
	if(n<1000000){
		if(dp[n])
		return dp[n];
		else{
			int s=exchange(n/2,dp) + exchange(n/3,dp)+ exchange(n/4,dp);
			dp[n]=max(n,s);
			return dp[n];
		}
	}
	int s=exchange(n/2,dp) + exchange(n/3,dp)+ exchange(n/4,dp);
	return max(s,n);
}

signed main(){
	int x;
	while(cin>>x){
		int dp[1000000];
		memset(dp, 0, sizeof(dp));
		cout<<exchange(x,dp)<<endl;
	}
}
