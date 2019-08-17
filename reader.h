#include<bits/stdc++.h>
#include"trieheader.h"
void read(Trie*&root,vector<string>& data){
string s;
ifstream LongWords("long.txt"); //inserts words from long.txt into data vector
if(LongWords.is_open()){
    while(LongWords>>s){
        data.push_back(s);
    }
    LongWords.close();
}
ifstream MediumWords("medium.txt"); //inserts words from short.txt into data vector
if(MediumWords.is_open()){
    while(MediumWords>>s){
        data.push_back(s);
    }
    MediumWords.close();
}
for(int i=0;i<data.size();i++){ // inserts all words from data vector into trie
    InsertInTrie(root,data[i],0);
}
}
