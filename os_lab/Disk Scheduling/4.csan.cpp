//csan
////98 183 37 122 14 124 65 67
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n,m,sum=0,x,y,h;
    cout<<"enter last size- ";
    cin>>m;
    cout<<"\nhow many queue- ";
    cin>>n;
    cout<<"\nenter quene- ";
    vector <int> a(n),b;
    for(i=0; i<n; i++){
        cin>>a[i];
    }
    for(i=0; i<n; i++){
    if(a[i] >m){
           cout<<"\nUnknown position "<<a[i]<<"\n";
           return 0;
        }
    }
    cout<<"\n head point- ";
    cin>>h;
    //int temp=h;
    a.push_back(h);
    a.push_back(m);
    a.push_back(0);
    sort(a.begin(),a.end());
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    k=i;
    if(k<n/2){
        for(i=k;i<a.size();i++){
            b.push_back(a[i]);
        }
        for(i=0;i<=k-1;i++){
            b.push_back(a[i]);
        }
    }
    else{    
        for(i=k;i>=0;i--){
            b.push_back(a[i]);
        }
        for(i=a.size()-1;i>=k+1; i--){
            b.push_back(a[i]);
        }
    }
    
    int temp=b[0];
    cout<< "\n path- ";
    cout<<temp;
    for(i=1; i<b.size();i++){
        cout<<" "<<b[i];
        sum+= abs(b[i]- temp);
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
	// 98 183 37 122 14 124 65 67
	cout<<endl<< " Total head movements = "<<sum<<" cylinders." <<endl;
    return 0;
}


