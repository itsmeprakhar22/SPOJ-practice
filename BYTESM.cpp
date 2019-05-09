#include <bits/stdc++.h>
using namespace std;

int main() {
	
	// your code here
	int t; cin>>t;
	while(t--){
		int h,w; cin>>h>>w;
		int arr[h+9][w+9];
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++)
			cin>>arr[i][j];
		}
		
		int ma=-1;
		for(int i=0;i<w;i++)
		ma=max(arr[0][i] , ma);
		
		for(int i=1;i<h;i++){
			ma=-1;
			for(int j=0;j<w;j++){
				if(j>0 && j<w-1)
                    arr[i][j] = max(arr[i-1][j] + arr[i][j] , max(arr[i-1][j-1]+arr[i][j] , arr[i-1][j+1]+arr[i][j]));
                else if(j>0)
                    arr[i][j] = max(arr[i-1][j]+arr[i][j] ,arr[i-1][j-1]+arr[i][j]);
                else if(j<w-1)
                    arr[i][j] = max(arr[i-1][j]+arr[i][j],arr[i-1][j+1]+arr[i][j]);
                ma = max(arr[i][j] , ma);
				
			}
		}
		cout<<ma<<endl;
	}

	return 0;
}
