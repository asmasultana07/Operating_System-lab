//optimal

#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k;
    int frames,p_count,hitcount =0;
    cout<<"how many frames- ";
    cin>>frames;
    cout<<"enter the number of string- ";
    cin>>p_count;
    vector<int> str(p_count);
    
    cout<<"enter strings- ";
    for(i=0; i<p_count;i++){
        cin>>str[i];
    }
    vector<vector<int>> a(frames);
    for(i= 0; i< frames; i++){
        a[i] = vector<int>(p_count,-1);
    }
    map <int, int> mp;    
    for(i=0; i<p_count;i++){
        vector<int> op;
        vector<pair<int,int>> c;
        for(auto x: mp){
            c.push_back({x.second,x.first});
        }
        for(int x=i+1; x<p_count; x++){
            for(j=0; j<frames; j++){
                if(a[j][i]==str[x]){
                    op.push_back(str[x]);
                }            
            }
        }
        sort(op.begin(),op.end());
        op.erase(unique(op.begin(),op.end()),op.end());
        bool dontCall=true;        
        if(op.size()==frames){
            dontCall=false;
        }
        sort(c.begin(),c.end());
        bool hasrun=false;
        for(j=0; j<frames;j++){
            if(a[j][i]==str[i]){
                mp[str[i]]++;
                hasrun=true;
                break;
            }
            if(a[j][i]== -1){
                for(k=i;k<p_count;k++)
                    a[j][k]=str[i];
                mp[str[i]]++;
                hasrun=true;
                break;
            }
        }
        if(j==frames ||hasrun==false){
            for(j=0; j<frames;j++){
                if(dontCall==true){
                    if(a[j][i]==c[c.size()-1].second){
                        mp.erase(a[j][i]);
                        for(k=i;k<p_count;k++)
                            a[j][k]=str[i];
                        mp[str[i]]++;
                        break;
                    }
                }
                else if(dontCall==false){
                    if(a[j][i]== op[op.size()-1]){
                        mp.erase(a[j][i]);
                        for(k=i; k<p_count;k++)
                            a[j][k]=str[i];
                        mp[str[i]]++;
                        break;
                    }
                }
            }
        }
        for(auto x:mp){
            if(x.first!= str[i]){
                mp[x.first]++;
            }
        }
    }
    int hit=0;
    vector<int> hitv(p_count);
    for(i=1; i<p_count;i++){
        for(j=0; j<frames;j++){
            if(str[i]==a[j][i-1]){
                hit++;
                hitv[i] =1;
                break;            
            }
        }
    }
    //table
    cout<<" \tformating "<<endl;
    cout<<" string=\t";
    for(i=0;i<p_count;i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
    
    for(i=0;i<frames;i++){
        cout<<" frame"<<i<<" \t";
        for(j=0;j< p_count;j++){
            if(a[i][j]==-1)
                cout<<"  ";
                else 
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"page fault=\t";
    for(i=0; i<p_count; i++){
        
        // page fault occurs if hit[i] == True
        if(hitv[i])
            cout << "H ";
        else
            cout << "M ";
    }
   
    cout<<"\n";
    cout<<"Hit= "<<hit<<'\n'<<"Miss= "<<p_count-hit<<'\n';
    return 0;
}