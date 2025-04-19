#include<iostream>
#include<vector>
#include<string>
using namespace std;

int naiveString(string str, string patt)
{
 int m=str.size();
 int n=patt.size();
 int foundIdx=-1;
 if(m>=n)
 {
  for(int i=0;i<m-n;i++)
  {
   string x="";
   if(patt[0]==str[i])
   {
    for(int j=i;j<n+i;j++)
    {
     x+=str[j];
    }
    if(patt==x)
    {
     foundIdx=i; 
     break;
    }
   }
 }
 }
 return foundIdx;
} 

int main()
{
 string str,patt;
 cout<<"Enter the string: ";
 cin>>str;
 cout<<"Enter the pattern: ";
 cin>>patt;
 int result=naiveString(str,patt);
 if(result!=-1)
 {
  cout<<"The pattern matched at index "<<result<<endl;
 }
 else
 {
  cout<<"Sorry! Match not found";
 }

 return 0;
}

