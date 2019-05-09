import java.util.*;
import java.lang.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{ int t,m,n;
		Scanner in=new Scanner(System.in);
		t=in.nextInt();
		
		for(int i=1;i<=t;i++)
		{ int a=in.nextInt();
		int b=in.nextInt();
			for(int p=a;p<=b;p++)
		  { if(isPrime(p))
		  	System.out.println(p);
		  }}
		
 			in.close();
	}
	public static boolean isPrime(int no)
    {
        if(no==1)
            return false;
        int y=(int) Math.sqrt(no);
       for(int j=2;j<=y;j++)
       {
           if(no%j==0)
               return false;
       }
       return true;
		
	}
}
