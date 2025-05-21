//LRU ALGO
#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k;
    int frames,p_count,hitcount =0;
    cout<<"how many frames- ";
    cin>>frames;
    cout<<"enter number of string- ";
    cin>>p_count;
    vector<int> str(p_count);
    vector <int> hit(p_count);
    cout<<"enter strings- ";
    for(i=0; i<p_count;i++){
        cin>>str[i];
    }
    vector<vector<int>> a(frames);
    for(i= 0; i< frames; i++){
        a[i] = vector<int>(p_count,-1);
    }
    
    map <int, int> mp;    
    for(i=0;i<m;i++){
        vector<pair<int,int>> c;
        for(auto q: mp){
            c.push_back({q.second,q.first});
        }
        sort(c.begin(),c.end());
        bool hasrun=false;
        for(j=0;j<n;j++){
            if(a[j][i]==p[i]){
                hit++;
                hi[i]=1;
                mp[p[i]]=1;
                hasrun=true;
                break;
            }
            if(a[j][i]==-1){
                for(k=i;k<m;k++)
                    a[j][k]=p[i];
                mp[p[i]]++;
                hasrun=true;
                break;
            }
        }
        if(j==n||hasrun==false){
            for(j=0;j<n;j++){
                if(a[j][i]==c[c.size()-1].second){
                    mp.erase(a[j][i]);
                    for(k=i;k<m;k++)
                        a[j][k]=p[i];
                    mp[p[i]]++;
                    break;
                }
            }
        }
        for(auto q:mp){
            if(q.first!=p[i]){
                mp[q.first]++;
            }
        }
    }
    cout<<"Process ";
    for(i=0;i<m;i++){
        cout<<p[i]<<" ";
    }
    cout<<'\n';
    for(i=0;i<n;i++){
        cout<<"Frame "<<i<<" ";
        for(j=0;j<m;j++){
            if(a[i][j]==-1)
                cout<<"E ";
                else 
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
    for(i=0;i<m;i++){
        if(hi[i]==0)
        cout<<"  ";
        else
        cout<<hi[i]<<" ";
    }
    cout<<"\n";
    cout<<"Hit "<<hit<<'\n'<<"Page Fault "<<m-hit<<'\n';
    return 0;
}