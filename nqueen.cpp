
#include<bits/stdc++.h>
using namespace std;


int chess[10][10];
int n;
int col[100];
int rd[200];
int ld[200];
vector<vector<string>> s;

// bool issafe(int i,int j)
// {
// 	int l,m;
// 	l=i;
// 	m=j;
// 	while(i>=0 && j>=0)
// 	{
// 		if(chess[i][j])
// 			return false;

// 		i--;
// 		j--;
// 	}
// 	i=l;
// 	j=m;
// 	while(i>=0)
// 	{
// 		if(chess[i][j])
// 			return false;
// 		i--;
// 	}
   
//    i=l;
//    j=m;
// 	while(i>=0 && j<n)
// 	{
// 		if(chess[i][j])
// 			return false;
// 		i--;
// 		j++;
// 	}
// 	return true;
// }


// void f(int i)
// {
// 	if(i==n)
// 	{
// 		     vector<string> v;
//          for(int i=0;i<n;i++)
//          {
//          	  string p = "";
//          	for(int j=0;j<n;j++){
//          		cout<<chess[i][j]<<" ";
//             if(chess[i][j]==0)
//             	p+='.';
//             else
//             	p+='Q';
//          	}
//          	v.push_back(p);
//          	cout<<endl;
//          }
//          s.push_back(v);
//          cout<<endl<<endl;
//          return;
// 	}

// 	for(int j=0;j<n;j++)
// 	{
// 		 if(issafe(i,j))
// 		 {
// 		 	chess[i][j]=1;
// 		 	f(i+1);
// 		 }
// 		 chess[i][j]=0;

// 	}
	
// }
// naive approach passed in leetode 


void f1(int i)
{
	  if(i==n)
	  {
        

		     vector<string> v;
         for(int i=0;i<n;i++)
         {
         	  string p = "";
         	for(int j=0;j<n;j++){
         		cout<<chess[i][j]<<" ";
            if(chess[i][j]==0)
            	p+='.';
            else
            	p+='Q';
         	}
         	v.push_back(p);
         	cout<<endl;
         }
         s.push_back(v);
         cout<<endl<<endl;
         return;
	  	
	  }

	  for(int j=0;j<n;j++)
	  {
	  	  if(col[j]==0 && ld[i+j]==0 && rd[i-j+n-1]==0)
	  	  {
	  	  	  chess[i][j]=1;
	  	      col[j]=1;
	  	      ld[i+j]=1;
	  	      rd[i-j+n-1]=1;
	  	      f1(i+1);         	
	  	      col[j]=0;
	  	      ld[i+j]=0;
	  	      rd[i-j+n-1]=0;  
	  	  }
	  	  chess[i][j] = 0;
	  }
}

// branch and bound texhnique

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    cin>>n;
  f(0);
  cout<<endl<<endl;
  for(auto i:s)
  {
  	  for(auto j:i)
  	  	cout<<j<<",";
  	  cout<<endl;
  }
}