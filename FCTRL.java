import java.util.*;
import java.lang.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{ Scanner in=new Scanner(System.in);
	int c1=in.nextInt();
for(int c=1;c<=c1;c++)
{ 
int n=in.nextInt();
int t,s=0,x=1;
for(int p=1;;p++)
{t=(int)(n/Math.pow(5,x));
x++; 
s=s+t;
if(t==0)
break;}

System.out.println(s);
}
		
	}
}
