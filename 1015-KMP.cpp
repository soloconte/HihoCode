//
// Created by SoloConTe on 15/5/4.
//
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void calcNext(string p,vector<int> &next){
    int l=p.length();
    next=vector<int>(l,0);
    int k=0;
    for (int i=1;i<l;i++){
        while ((k>0)&&(p[i]!=p[k]))
            k=next[k-1];
        if (p[i]==p[k]) k++;
        next[i]=k;
    }
}

int KMP(string s,string p){
    vector<int> next;
    next.clear();
    calcNext(p,next);
    int ans=0;
    int k=0;
    int l1=s.length();
    int l2=p.length();
    for (int i=0;i<l1;i++){
        while ((k>0)&&(s[i]!=p[k]))
            k=next[k-1];
        if (s[i]==p[k]) k++;
        if (k==l2){
            ans++;
            k=next[k-1];
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        string s,p;
        cin>>p>>s;
        cout<<KMP(s,p)<<endl;
    }
    return 0;
}