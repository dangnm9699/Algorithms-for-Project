#include <bits/stdc++.h>
#

using namespace std;

int n,m;
int res=INT_MAX;
vector<int>* route;
vector<int>* result,* tempRes;
vector<int> tempR, tempRo;
int tt;
int** c;
int* load;
int** cc;
int ccmin;
int bestOpt;
int* x;
int* mark;
int s;
int best=INT_MAX;
int* d;

void tryOpt(int k, int sum){
    if(k==s){
        if(sum+cc[x[s-1]][0]<bestOpt){
            bestOpt = sum+cc[x[s-1]][0];
            tempRes[tt]=tempRo;
        }
        return;
    }
    for(int i=1;i<s;i++){
        if(!mark[i]){
            if(sum+cc[x[k-1]][i]+ccmin*(s-k)<bestOpt){
                mark[i]=1;
                x[k]=i;
                tempRo.push_back(tempR[i]);
                tryOpt(k+1, sum+cc[x[k-1]][i]);
                tempRo.pop_back();
                mark[i]=0;
            }
        }
    }
}


int findOpt(vector<int> &r){
    tempR = r;
    ccmin=INT_MAX;
    bestOpt=INT_MAX;
    s = r.size();
    cc = new int*[s];
    x = new int[s];
    mark = new int[s];
    for(int i=0;i<s;i++) cc[i]=new int[s];
    for(int i=0;i<s;i++) {
        mark[i]=0;
        for(int j=0;j<s;j++){
            i==j?cc[i][j]=0:cc[i][j]=1999999;
        }
    }
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            cc[i][j]=c[r[i]][r[j]];
            ccmin=min(ccmin,cc[i][j]);
        }
    }
    x[0]=0;
    mark[0]=1;
    tempRo.push_back(0);
    tryOpt(1,0);
    return bestOpt;
}

void findPlace(int k){
    if(k==n+1){
        int temp=0;
        tempRes=new vector<int>[m+1];
        for(int i=1;i<=m;i++) {
            if(!route[i].back()) return;
            tempRo.clear();
            tt=i;
            temp=max(temp, findOpt(route[i]));
        }
        if(temp<best) {
            best=temp;
            result=new vector<int>[m+1];
            result=tempRes;
        }
        return;
    }
    for(int i=1;i<=m;i++){
        if(load[i]>=d[k]){
            load[i]-=d[k];
            route[i].push_back(k);
            findPlace(k+1);
            load[i]+=d[k];
            route[i].pop_back();
        }
    }
}

int main(){
    cin>>n>>m;
    d = new int[n+1];
    for(int i=1;i<=n;i++) d[i]=1;
    route = new vector<int>[m+1];
    result= new vector<int>[m+1];
    c = new int*[n+1];
    load = new int[m+1];
    for(int i=0;i<=n;i++) c[i] = new int[n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cin >> c[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        load[i]=100;
        route[i].push_back(0);
    }
    findPlace(1);
    cout<<best<<endl;
    for(int i=1;i<=m;i++){
        cout << result[i][0];
        for(int j=1;j<result[i].size();j++){
            cout << "->" << result[i][j];
        }
        cout <<"->0"<<endl;
    }
    return 0;
}
