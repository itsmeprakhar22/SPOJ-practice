/*package whatever //do not write package name here */

import java.util.*;
import java.math.*;
import java.io.*;

class Main
{
public static void main(String[] args)
{
Scanner in=new Scanner(System.in);
for(int i=1;i<=10;i++)
{
String a= in.nextLine();
String b=in.nextLine();
BigInteger A,B,D,t;
t=BigInteger.valueOf(2);
A= new BigInteger(a);
B= new BigInteger(b);
D=A.subtract(B);
A=D.divide(t);
B=(D.divide(t)).add(B);
System.out.println(B);
System.out.println(A);
}
}
}
