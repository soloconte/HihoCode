//
// Created by SoloConTe on 15/5/5.
//
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int need[510],value[510];
    for (int i=0;i<n;i++)
        scanf("%d%d",&need[i],&value[i]);
    vector<int> dp(m+1,0);
    for (int i=0;i<n;i++){
        for (int j=m;j>=0;j--){
            if ((j>=need[i])&&(dp[j-need[i]]+value[i]>dp[j]))
                dp[j]=dp[j-need[i]]+value[i];
        }
    }
    int ans=0;
    for (int i=0;i<=m;i++)
        if (dp[i]>ans)
            ans=dp[i];
    cout<<ans<<endl;
    return 0;
}
