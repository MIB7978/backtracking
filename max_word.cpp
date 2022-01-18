class Solution {
public:
    
    int f(vector<string>& words ,  vector<int>&farr,  vector<int>& score,int i)
    {
        if(i  == words.size())
            return 0;
        int a = f(words,farr,score,i+1);
        
        int b = 0;
        int flag =0;
        
        string s = words[i];
        for(auto j:s)
        {
            if(farr[j-'a']==0)
            {
                flag=1;
                
            
            }
            farr[j-'a']--;
            b +=score[j-'a'];
        }
        
        int sr = 0;
        if(flag==0)
        {
            sr = b+f(words,farr,score,i+1);
        }
        for(auto j:s)
            farr[j-'a']++;
        return max(a,sr);
            
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        vector<int> farr(26,0);
        for(auto i:letters)
            farr[i-'a']++;
        
     
        return f(words,farr,score,0);
    }
};