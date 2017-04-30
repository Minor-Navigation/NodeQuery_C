#include <bits/stdc++.h>
using namespace std;

#define min(a,b) ((a<b) ? (a) : (b))
#define max(a,b) ((a>b) ? (a) : (b))
#define abs(a) ((a>0) ? (a) : ((-1)*a))
#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORL(i,n) for(long long i=0;i<n;i++)
#define MOD 1000000007
#define PI 3.141592653589
#define pb push_back
#define mp make_pair
int dp[5009][5009]={0};
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define fileio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define MAX_CHILD 5
#define null NULL
#define square(a) a*a

class nodeInd{
public:
	ll id,ptr,adjPtr;
	int size;
};

class nodeData {
public:
    ll id;
    double lon,lat;
    vector<ll> adj,adjPtr;
    char* otherData;
} nd;
nodeData queryNode(ll id)
{

    fstream f,f1,f2;
    
    f.open("NodeIndexNew.ind",ios::in | ios::out | ios::binary); 
    f1.open("CompleteNodeData.dat",ios::in | ios::out | ios::binary); 
    f2.open("adjacency.dat",ios::in | ios::out | ios::binary); 
    char *res = NULL;

    f.seekg(0,ios::end);
    ll no_nodes=f.tellg();
    nodeInd in;
    no_nodes/=sizeof(nodeInd);
    int size;
    ll temp;
    ll s=0,e=no_nodes-1,m;
    while(s<=e)
    {
        m=(s+e)/2;
        f.seekg(m*sizeof(nodeInd));f.seekp(m*sizeof(nodeInd));
        f.read((char*)&in,sizeof(nodeInd));
        if(in.id==id)
        {
            //cout<<"Found";
            nd.otherData= new char[in.size];
            f1.seekg(in.ptr);f1.seekp(in.ptr);
            f1.read(nd.otherData,in.size);

            f2.seekg(in.adjPtr);f2.seekp(in.adjPtr);
            f2>>nd.id>>nd.lon>>nd.lat>>size;
            while(size--)
            {
                f2>>temp;
                nd.adj.pb(temp);
                f2>>temp;
                nd.adjPtr.pb(temp);
            }

            return nd;
        }
        if(in.id<id)
            s=m+1;
        else
            e=m-1;

    }
    cout<<"Not Found";
    return NULL;

}

int main()
{
	
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    nodeData nd1;
    if(nd1 = queryNode(58049719))
    {
        cout<<nd.id<<" "<<nd.lon<<" "<<nd.lat<<" "<<nd.adj.size()<<endl;
        cout<<nd.otherData<<endl;
    }    
    


 //    ll id,ptr;
 //    char s1[27];
 //    int size;
	// nodeInd in;
	
    
 //    int t=10;
 //    while(!f.eof())
 //    {
 //    	if(f.read(s1,27)){
 //    		cout<<s1<<endl;

 //    	}    	
 //    }
 //    f.close();
 //    freopen("data.txt", "r", stdin); 
 //    freopen("output.txt", "w", stdout);
 //    f.open("NodeIndexNew.ind",ios::in | ios::out | ios::trunc);	
 //    cout<<"temp data done"<<endl;
 //    while(cin>>id>>ptr>>size)
 //    {
 //    	in.id=id;
 //    	in.ptr=ptr;
 //    	in.size=size;
 //    	f.write((char*)&in,sizeof(in));

 //    }



    return 0;
}
