#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'searchSuggestions' function below.
 *
 * The function is expected to return a 2D_STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY repository
 *  2. STRING customerQuery
 */

class TrieNode{
    public:
    bool isend;
    vector<TrieNode*> children;
    
    TrieNode(){
        isend=false;
        children = vector<TrieNode*>(26,nullptr);
    }
};

class Trie{
    private:
        TrieNode* root=nullptr;
    public:
        void insert(string s){
            if(root==nullptr){
                root = new TrieNode();
            }
            TrieNode* node=root;
            for(char &ch:s){
                ch = tolower(ch);
                if(node->children[ch-'a']==nullptr){
                    node->children[ch-'a'] = new TrieNode();
                }
                node = node->children[ch-'a'];
            }
            node->isend=true;
        }
        
        void dfs(TrieNode* node,vector<string> &v,string s){
            if(node==nullptr || v.size()==3)   return;
            if(node->isend){
                v.push_back(s);
                if((int)v.size()==3)    return;
            }
            
            for(int i=0;i<26;i++){
                dfs(node->children[i],v,s+char('a'+i));
            }
            return;
        }
        vector<string> find(string s){
            vector<string> ans;
            
            TrieNode* node=root;
            
            for(char &ch:s){
                if(node==nullptr){
                    return ans;
                }else{
                    node = node->children[ch-'a'];
                }
            }
            
            if(node==nullptr)   return ans;
            
            
            dfs(node,ans,s);
            return ans;
        }
};

vector<vector<string>> searchSuggestions(vector<string> repo, string q) {
    Trie* t = new Trie();
    for(string &s: repo){
        t->insert(s);
    }
    
    vector<vector<string>> ans;
    string st="";
    for(char &ch:q){
        ch = tolower(ch);
        st+=ch;
        if(st.length()>=2){
            vector<string> tmp = t->find(st);
            ans.push_back(tmp);
        }
    }
    return ans;
}

int main(){
    return 0;
}