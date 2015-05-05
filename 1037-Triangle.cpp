//
// Created by SoloConTe on 15/5/5.
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int ticket[200][200];
    memset(ticket,0, sizeof(ticket));
    for (int i=1;i<n+1;i++)
        for (int j=1;j<i+1;j++)
            scanf("%d",&ticket[i][j]);
    vector<int> ans(n+1,0);

    for (int i=1;i<n+1;i++){
        for (int j=i;j>0;j--){
            ans[j]=max(ans[j-1],ans[j]);
            ans[j]+=ticket[i][j];
        }
    }
    int maxt=0;
    for (int i=1;i<n+1;i++)
        if (ans[i]>maxt)
            maxt=ans[i];
    cout<<maxt<<endl;
    return 0;
}