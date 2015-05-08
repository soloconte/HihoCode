//
// Created by SoloConTe on 15/5/8.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> dp(m+1,0);

    for (int i=0;i<n;i++){
        int need,value;
        scanf("%d%d",&need,&value);
        for (int j=m;j>=0;j--){
            int k=1;
            while (j>=need*k){
                dp[j]=max(dp[j],dp[j-need*k]+value*k);
                k++;
            }
        }
    }
    int ans=0;
    for (int i=0;i<=m;i++)
        if (ans<dp[i])
            ans=dp[i];
    cout<<ans<<endl;
    return 0;
}
