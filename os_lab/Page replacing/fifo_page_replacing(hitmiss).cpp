
#include<bits/stdc++.h>
using namespace std;
int main(){
    int i, j, k, hitCount = 0;
    int frames, p_count;
    //1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
    //7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1,2, 0, 1, 7, 0, 1
    cout<<"how many frames-";
    cin>> frames;
    cout<<"enter number of string-";
    cin>> p_count;
    vector <int> str(p_count);
    vector <int> hit(p_count);
    
    cout<<"enter string- ";
    for(i=0; i<p_count; i++){
        cin>>str[i];
    }
    vector<vector<int>> a(frames);
    for(i = 0; i < frames; i++){
        a[i] = vector<int>(p_count,-1);
    }
    
    map <int,int> mp;    
    
    for(i =0; i<p_count; i++){
        vector<pair<int,int>> c;
        
        for(auto x: mp)
        {
            c.push_back({x.second, x.first});
        }
        
        sort(c.begin(),c.end());
        
        bool hasCompleted = false;
        
        for(j=0; j <frames; j++){
            if(a[j][i] == str[i])
            {
                hitCount++;
                hit[i] = true;
                
                mp[str[i]]++;
                hasCompleted = true;
                break;
            }
            if(a[j][i] == -1)
            {
                for(k=i ; k<p_count; k++)
                    a[j][k] = str[i];
                    
                mp[str[i]]++;
                hasCompleted = true;
                break;
            }
        }
        if(j==frames || hasCompleted==false){
            for(j=0;j<frames; j++){
                if(a[j][i]== c[c.size()-1].second){
                    mp.erase(a[j][i]);
                    
                    for(k=i; k< p_count ; k++)
                        a[j][k]= str[i];
                        
                    mp[str[i]]++;
                    break;
                }
            }
        }
        for(auto x:mp){
            if(x.first != str[i]){
                mp[x.first]++;
            }
        }
    }
    //table
    cout <<" \tformating   "<<endl;
    cout <<" string=     ";
    for(i= 0; i<p_count; i++){
        cout<< str[i] << "  ";
    }
    cout << endl;
    
    for(i=0; i<frames; i++){
        cout<<" frame" << i << "      ";
        for(j=0; j< p_count; j++){
            if(a[i][j] == -1)
                cout<< "   ";
                else 
            cout<< a[i][j] << "  ";
        }
        cout<< endl;
    }
    
    cout<< "Page Fault=  ";
    for(i=0; i<p_count; i++){
        
        // page fault occurs if hit[i] == True
        if(hit[i])
            cout << "H  ";
        else
            cout << "M  ";
    }
    cout << "\n\n";
    
    cout << "Miss " << p_count - hitCount << endl;
    cout << "Hit " << hitCount << endl;
    
    return 0;
}