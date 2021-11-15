#include<iostream>
using namespace std;

int cntbits(int x){
    int cnt = 0;
    while(x>0){
        x = x & (x - 1);
        cnt++;
    }
    return cnt;
}

int getbits(int x,int y){
    int cnt = 0;
    for(int i = x ; i <= y ; i++){
        cnt += cntbits(i);
    }
    return cnt;
}

int main(){
    int q,a,b;
    cin>>q;
    int ans[10000];
    for(int i = 0 ; i < q ; i++){
        cin>>a>>b;
        ans[i] = getbits(a,b);
    }
    for(int i = 0 ; i < q; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}