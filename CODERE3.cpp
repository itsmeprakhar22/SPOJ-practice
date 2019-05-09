#include <bits/stdc++.h>
using namespace std;

int lbs(int* a, int n){
	int* di=new int[n];
	int* dd=new int[n];
	for (int i = 0; i < n; i++) 
	di[i]=1;
	for (int i = 0; i < n; i++) 
	dd[i]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				di[i]=max(di[i], di[j]+1);
			}
		}
	}
	for(int i=n-2;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(a[i]>a[j]){
				dd[i]=max(dd[i], dd[j]+1);
			}
		}
	}

	int max = di[0] + dd[0] - 1; 
   for (int i = 1; i < n; i++) 
     if (di[i] + dd[i] - 1 > max) 
         max = di[i] + dd[i] - 1; 
   return max; 
}


int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int* a=new int[n];
		for(int i=0;i<n;i++) cin>>a[i];
		cout<<lbs(a,n)<<endl;
	}
}
