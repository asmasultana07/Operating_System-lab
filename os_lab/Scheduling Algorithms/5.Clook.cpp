//clook

#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k,n,m,sum=0,x,y,h;

    cout<<"how many queue- ";
    cin>>n;
    cout<<"enter queue- ";
    vector <int> a(n),b;
    for(i=0;i<n;i++){
        cin>>a[i];
    }


    cout<<"\nhead position- ";
    cin>>h;
    a.push_back(h); // just h push but here h,high,low set
    sort(a.begin(),a.end());
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }

     k=i;
    if(k<n/2){
        for(i=k; i<a.size(); i++){
            b.push_back(a[i]);
        }
        for(i=0; i<=k-1; i++){
            b.push_back(a[i]);
        }
    }
    else{
        for(i=k; i>=0; i--){
            b.push_back(a[i]);
        }
        for(i=a.size(); i>=k+1; i--){
            b.push_back(a[i]);
        }
    }
    int temp=b[0];
    cout<<endl<<" path-> ";
    cout<<temp;
    for(i=1; i<b.size();i++){
        cout<<" "<<b[i]<<' ';
        sum+=abs(b[i]-temp);
        temp=b[i];
    }

    cout << endl<<" total distance : ";
    	for (i=0; i<b.size()-1; i++)
    	{
    		int mx = max(b[i], b[i+1]);
    		int mn = min(b[i], b[i+1]);
    		cout<< "(" <<mx<< "-"<<mn<< ")";
    		if (i<b.size()-2)
    			cout<< "+";
	}


    cout<<"\n Total head movements = "<<sum<<" cylinders.";
    return 0;
}
