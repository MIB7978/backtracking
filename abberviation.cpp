// question

// Abbreviation Using Backtracking

// 1. You are given a word.
// 2. You have to generate all abbrevations of that word.

// Use recursion as suggested in question video

// Input Format
// A string representing a word
// Output Format
// Check the sample ouput and question video.
// Sample Input
// pep
// Sample Output
// pep
// pe1
// p1p
// p2
// 1ep
// 1e1
// 2p
// 3




#include<bits/stdc++.h>
using namespace std;



void f(string s,string res,int count ,int i)
{
    if(i==s.length())
    {
        if(count!=0)
        cout<< (res+to_string(count))<<endl;
        else 
        cout<<res<<endl;
    return;
    }
    
    if(count!=0)
    f(s,res+to_string(count)+s[i],count-count,i+1);
    else
    f(s,res+s[i],count,i+1);
    
    f(s,res,count+1,i+1);
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif


    string s;
    cin>>s;
    f(s,"",0,0);
}

// pep coding passed the all test case

