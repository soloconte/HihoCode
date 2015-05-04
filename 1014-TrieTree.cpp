//
// Created by SoloConTe on 15/5/4.
//

#include <cstdio>
#include <iostream>

using namespace std;

class TrieNode{
public:
    TrieNode* tns[26];
    int count;
    TrieNode():count(0){
        for (int i=0;i<26;i++)
            tns[i]=NULL;
    }
};

class TrieTree{
public:
    TrieNode *root;
    TrieTree(TrieNode *tn):root(tn){}
    void insert(string s);
    int search(string s);
};

void TrieTree::insert(string s) {
    TrieNode *tn=root;
    for (auto ch:s){
        tn->count++;
        int idx= static_cast<int>(ch-'a');
        if (tn->tns[idx]) tn=tn->tns[idx];
        else{
            tn->tns[idx]=new TrieNode();
            tn=tn->tns[idx];
        }
    }
    tn->count++;
}

int TrieTree::search(string s) {
    TrieNode *tn=root;
    for (auto ch:s){
        int idx= static_cast<int>(ch-'a');
        if (tn->tns[idx])
            tn=tn->tns[idx];
        else return 0;
    }
    return tn->count;
}

int main(){
    int n,m;
    cin>>n;
    TrieNode *root=new TrieNode();
    TrieTree tree(root);
    for (int i=0;i<n;i++){
        char ch[11];
        scanf("%s",ch);
        tree.insert(ch);
    }
    cin>>m;
    for (int i=0;i<m;i++){
        char ch[11];
        scanf("%s",ch);
        printf("%d\n",tree.search(ch));
    }
    return 0;
}
