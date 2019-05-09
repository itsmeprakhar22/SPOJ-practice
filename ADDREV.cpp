#include <bits/stdc++.h>
#define int unsigned long long int
using namespace std;

signed main() {
	
	// your code here
	int t; cin>>t;
	while(t--){
		int m,n; cin>>m>>n;
		while(m%10==0)
		m/=10;
		while(n%10==0)
		n/=10;
		
		int a=0,b=0;
		while(m>0){
			a=a*10 + (m%10);
			m/=10;
		}
		while(n>0){
			b=b*10 + (n%10);
			n/=10;
		}
		a=a+b;
		b=0;
		while(a>0){
			b=b*10 +(a%10);
			a/=10;
			
		}
		cout<<b<<endl;
		
	}

	return 0;
}
