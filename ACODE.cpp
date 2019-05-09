#include <bits/stdc++.h>
#define int long
using namespace std;

int alpha(int* a,int size,int* arr){
        arr[0]=1;
    for(int i=1;i<size;i++){
        if(a[i]>0)
            arr[i]=arr[i-1];
        if(a[i-1]*10+a[i]<=26 && a[i-1]*10+a[i]>=10)
        {
            if(i>1)
            arr[i]+=arr[i-2];
            else
                arr[i]+=1;
        }
        if(a[i-1]==0){
            if(a[i-2]==0)
                return 0;
            arr[i]=arr[i-1];
        }
        arr[i]=arr[i];
    }
    return arr[size-1]; 
}

signed main()
{
    string s=""; 
    while(1)
    {
    cin>>s; 
    if(s=="0")
    break;
    int flag=0;
    int n=s.length();
    for(int i=0;i<n;i++){
		if(!isdigit(s[i]))
		{
			cout<<"0"<<endl;
			flag=1;
			break;
		}
	}
    if(flag==0){
    int* input=new int[n];
    for(int i=0;i<n;i++)
    {    input[i]=s[i]-'0';
    }
    int* arr=new int[n+1];
      for(int i=0;i<=n;i++)
          arr[i]=0;
    cout<<alpha(input,n,arr)<<endl;
    }
   }
    return 0;
}
