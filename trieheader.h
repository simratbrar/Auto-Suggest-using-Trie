#include<string.h>
using namespace std;
#pragma once
class Trie{
public:
    Trie* nodes[26]; //pointers to child nodes
    int prefix;      // number of prefixes ending here
    int words;       // number of words ending here
    Trie(){         //initialization
        for(int i=0;i<26;i++)
            nodes[i]=NULL;
        prefix=0;
        words=0;
    }
};
void InsertInTrie(Trie*&node,string& s,int i){ //insert function to insert a word in trie
    if(i==s.length()){
        node->words++;
        return;
    }
    char c=s[i];
    if(node->nodes[c-97]==NULL){
        node->nodes[c-97]=new Trie();
    }
    node->prefix++;
    InsertInTrie(node->nodes[c-97],s,i+1);
}
void RecursePrint(Trie*&node,string s){ // recursively prints all words with prefix ending at node (dfs)
    if(node->words)
        cout<<s<<endl;
    for(int j=0;j<26;j++){
        if(node->nodes[j]!=NULL){
            s.push_back(j+97);
            RecursePrint(node->nodes[j],s);
            s.pop_back();
        }
    }
}
int Compute(string& ToSearch,string& Compare){ //calculates levenshtein's distance between a string from dataset and the entered string
    int n=ToSearch.length();
    int m=Compare.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                dp[i][j]=j;
                continue;
            }
            else if(j==0){
                dp[i][j]=i;
                continue;
            }
            else{
                if(ToSearch[i-1]==Compare[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
    }
    return dp[n][m];
}
void EditDistance(string& s,vector<string> &data){ // checks levenshtein distance with all words in data
    for(int i=0;i<data.size();i++){
        if(Compute(s,data[i])<=4)
            cout<<data[i]<<endl;
    }
}
void SearchTrie(Trie* node,string &s,int i,vector<string> &data){ //will suggest words having string s as prefix if no word is found it will suggest words
    if(i==s.length()){                                            // levenshtein distance less than s.length()/2
        RecursePrint(node,s);
        return ;
    }
    char c=s[i];
    if(node->nodes[c-97]==NULL){
        EditDistance(s,data);
        return ;
    }
    SearchTrie(node->nodes[c-97],s,i+1,data);
}
