//
// Created by SoloConTe on 15/5/5.
//
//Manacher Algorithm

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string preProcess(const string &s){
    string ans;
    ans.clear();
    ans="^#";
    for (auto ch:s)
        ans=ans+ch+'#';
    ans+='$';  // using '^' and '$' to avoid border detection
    return ans;
}
int LPS(const string &s){
    string ss=preProcess(s);
    int l=ss.length();
    int c=0,r=0;
    vector<int> len(l,0);  // Half of the length, Spread in one direction
    int maxl,maxi;
    maxl=0;
    for (int i=1;i<l-1;i++){  // no need to process '^' and '$'
        if (ss[i]!='#') len[i]=1;
        int symi=2*c-i;
        if (r>i)
            len[i]=min(r-i,len[symi]);
        else len[i]=0;
        while (ss[i-len[i]]==ss[i+len[i]]) len[i]++;
        if (ss[i+len[i]]>r){
            c=i;
            r=i+len[i];
        }
        if (len[i]>maxl){
            maxl=len[i];
            maxi=i;
        }
    }
    return maxl-1;
}

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        cout<<LPS(s)<<endl;
    }
    return 0;
}