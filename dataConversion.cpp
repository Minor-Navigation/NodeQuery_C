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

typedef struct nodeInd{
public:
	ll id,ptr,adjPtr;
	int size;
} nodeInd;

fstream f,f1;
ll no_nodes=0;
nodeInd in;
ll queryNode(ll id)
{

    ll s=0,e=no_nodes-1,m;
    while(s<=e)
    {
        m=(s+e)/2;
        f.seekg(m*sizeof(nodeInd));f.seekp(m*sizeof(nodeInd));
        f.read((char*)&in,sizeof(nodeInd));
        //cout<<in.id<<" ";
        if(in.id==id)
        {
            //cout<<"Found";
            
            return (m*sizeof(nodeInd));
        }
        if(in.id<id)
            s=m+1;
        else
            e=m-1;

    }
    return -1;

}


int main()
{
	
   // freopen("input.txt", "r", stdin); 
    freopen("data.temp", "w", stdout);

    ll id,ptr;
    char s1[27];
    int size;
	
	
	f.open("NodeIndex.ind",ios::in | ios::out);	
    
    int t=10;
    while(!f.eof())
    {
    	if(f.read(s1,27)){
    		cout<<s1<<endl;

    	}    	
    }
    f.close();
    freopen("data.temp", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    f.open("NodeIndexNew.ind",ios::in | ios::out | ios::trunc | ios::binary);	
   // cout<<"temp data done"<<endl;
    while(cin>>id>>ptr>>size)
    {
    	in.id=id;
    	in.adjPtr=-1;
    	in.ptr=ptr;
    	in.size=size;
    	f.write((char*)&in,sizeof(nodeInd));
       // cout<<f.tellp()<<endl;
    }
    f.close();
    f.open("NodeIndexNew.ind",ios::in | ios::out | ios::binary);
   	f.seekg(0,ios::end);
    no_nodes=f.tellg();
    no_nodes/=sizeof(nodeInd);
    

    ifstream fin("AdjacencyListFile.txt");
    freopen("AdjacencyListFile.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    


    f1.open("adjacency.dat",ios::in | ios::out | ios::binary);
    double lon,lat;
    ll f1_ptr=0;
    while(fin>>id>>lon>>lat>>size)
    {
    	ptr=queryNode(id);
    	cout<<id<<" "<<ptr<<endl;
    	if(ptr!=-1)
		{
			f1_ptr=f1.tellp();
			in.adjPtr=f1_ptr;

			f.seekg(ptr);f.seekp(ptr);
        	f.write((char*)&in,sizeof(nodeInd));

        	f1<<id<<" ";
        	f1<<lon<<" ";
        	f1<<lat<<" ";
        	f1<<size<<" ";
        	while(size--)
        	{
        		fin>>id;
        		f1<<id<<" ";
        		f1<<queryNode(id)<<" ";
        	}

    	}
    }



    return 0;
}
