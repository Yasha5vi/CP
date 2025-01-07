    // Trie
#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public: 
        TrieNode* root;
        
        Trie(){
            root = new TrieNode('\0');
        }

        void insert(string word){
            TrieNode* curr = root;
            for(char c:word){
                int index = c-'a';
                if(!curr->children[index]){
                    curr->children[index] = new TrieNode(c);
                }else{
                    curr = curr->children[index];
                }
            }
            curr->isTerminal = true;
        }

        bool search(string word) {
            TrieNode* curr = root;
            for (char c : word) {
                int index = c - 'a';
                if (!curr->children[index]) {
                    return false; 
                }
                curr = curr->children[index];
            }
            return curr->isTerminal; 
        }


        void removeUtil(TrieNode* root,string word){
            if(word.length()==0){
                if(!root->isTerminal)   
                    cout<<"Word Not Present"<<endl;
                else root->isTerminal = false;
                return;
            }
            int index = word[0]-'a';
            TrieNode* child;
            if(root->children[index] != NULL){
                child = root->children[index];
            }
            else{
                cout<<"Word Not Present"<<endl;
                return;
            }
            return removeUtil(child,word.substr(1));
        }
        void remove(string word){
            removeUtil(root,word);
        }
};
