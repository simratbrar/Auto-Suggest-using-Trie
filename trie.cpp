#include<bits/stdc++.h>
#include"reader.h" //adding words to trie using data files
#include"trieheader.h"   //trie functions
using namespace std;
const int mod=1e9+7;
vector<string> data;
int main(){
string s;
Trie* root=new Trie();
read(root,data);
while(1){
    cin>>s; //enter string EXIT to exit the program
    for(int i=0;i<s.length();i++){ //convert string to lowercase
        if(s[i]<97)
            s[i]+=32;
    }
    if(s.length()<3){
        cout<<"Data too much to display"<<endl;
    }
    else{
        cout<<"The suggestions are given below:"<<endl;
        SearchTrie(root,s,0,data);
        cout<<endl;
    }
    if(s=="EXIT")
        break;
}
}
