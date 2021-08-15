#include<bits/stdc++.h>
using namespace std;

// Problem Link : https://leetcode.com/problems/word-search-ii/
// Code taken from : https://gist.github.com/SuryaPratapK/6329c354704632725dccc7ec5900d199

class Solution {    
    struct node{    //TrieNode
        char c;
        int ends;
        string word;
        node *child[26];
    };
    struct node *getNode(char c)    //get newnode
    {
        node *newnode = new node;
        newnode->c = c;
        newnode->ends = 0;
        newnode->word = "";
        for(int i=0;i<26;++i)
            newnode->child[i] = NULL;
        return newnode;
    }
    node *root = getNode('/');  //root
    
    //Trie INSERT
    void insert(string s)
    {
        node *curr=root;
        int index,i=0;
        while(s[i])
        {
            index = s[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index] = getNode(s[i]);
            
            curr=curr->child[index];
            i+=1;
        }
        curr->ends += 1;
        curr->word = s;
    }
    
    void solve(vector<vector<char>>& board,int i,int j,int r,int c,vector<string>& ans,node *curr)
    {
        //Base case
        //If the trie doesn't have the current char OR cell is Visited
        int index = board[i][j]-'a';
        if(board[i][j]=='$' || curr->child[index]==NULL)  
            return;
        
        curr = curr->child[index];
        if(curr->ends > 0)
        {
            ans.push_back(curr->word);
            curr->ends -=1;
        }
        
        //Body
        char ch = board[i][j];   //Store current char
        board[i][j] = '$';  //Mark current node visited
        
        if(i>0)     //TOP
            solve(board,i-1,j,r,c,ans,curr);
        if(i<r-1)   //DOWN
            solve(board,i+1,j,r,c,ans,curr);
        if(j>0)     //LEFT
            solve(board,i,j-1,r,c,ans,curr);
        if(j<c-1)   //RIGHT
            solve(board,i,j+1,r,c,ans,curr);
        
        board[i][j] = ch;    //Mark current node as Unvisited by restoring the value
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {        
        int r=board.size();
        int c=board[0].size();
        
        //Insert all words in TRIE
        for(int i=0;i<words.size();++i)
            insert(words[i]);
        
        //Now search words
        vector<string> ans;
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
                solve(board,i,j,r,c,ans,root);
        }
        return ans;
    }
};
