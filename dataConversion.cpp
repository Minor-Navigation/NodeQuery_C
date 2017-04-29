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
	ll id,ptr;
	int size;
} nodeInd;

int main()
{
	
   // freopen("input.txt", "r", stdin); 
    freopen("data.txt", "w", stdout);

    ll id,ptr;
    char s1[27];
    int size;
	nodeInd in;
	fstream f;
	
	f.open("NodeIndex.ind",ios::in | ios::out);	
    
    int t=10;
    while(!f.eof())
    {
    	if(f.read(s1,27)){
    		cout<<s1<<endl;

    	}    	
    }
    f.close();
    freopen("data.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    f.open("NodeIndexNew.ind",ios::in | ios::out | ios::trunc | ios::binary);	
   // cout<<"temp data done"<<endl;
    while(cin>>id>>ptr>>size)
    {
    	in.id=id;
    	in.ptr=ptr;
    	in.size=size;
    	f.write((char*)&in,sizeof(nodeInd));
       // cout<<f.tellp()<<endl;


    }



    return 0;
}
