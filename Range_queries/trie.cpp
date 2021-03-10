// Reference -> https://www.geeksforgeeks.org/trie-memory-optimization-using-hash-map/
// NOTE : 

#include<bits/stdc++.h>
using namespace std;


const int LIM = (int)1e7;
const int K = (int)(25);

typedef struct trie_tag{
    bool isEnd;
    map<char,trie_tag*> mp;

    trie_tag(){isEnd = false;}
}trie;

// Global delecration of root pointing to null
trie * root = NULL;

void insert(string str)
{   
    if(root == NULL)
        root = new trie;

    trie* curr = root;

    for(char ch : str)
    {
        if(curr -> mp.find(ch) == curr -> mp.end())
            curr -> mp[ch] = new trie;
        // As we want to move inside that part of trie
        curr = curr -> mp[ch];        
    }
    curr -> isEnd = true;
}

bool search(string str)
{
    trie *curr = root;

    if(curr == NULL)
        return false;

    for(char ch : str)
    {
        if(!curr -> mp[ch])
            return false;
        // As we want to move inside that part of trie
        curr = curr -> mp[ch];        
    }
    return curr -> isEnd;
}

// bool delete(string str)
// {
//     return 0;
// }

int main(void)
{
    vector<string> arr = {"AABAC","AAB","ABC","AEFDH","BCD"};

    for(auto it: arr)
        insert(it);
    
    if(search("AEFD"))
        cout << "PRESENT\n";
    else
        cout << "ABSENT\n";
}