#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 #define ld long double
 #define vi vector<int>
 #define vll vector<ll>
 #define vvi vector < vi >
 #define pii pair<int,int>
 #define pll pair<long long, long long>
 #define mod 1000000007
 #define inf 1000000000000000001;
 #define all(c) c.begin(),c.end()
 #define mp(x,y) make_pair(x,y)
 #define mem(a,val) memset(a,val,sizeof(a))
 #define eb emplace_back
 #define pb push_back
 #define f first
 #define s second
#define PI acos(-1.0)
#define base complex<double>
void fft(vector<base> &a,bool invert)
{

    int n=a.size(),i,j;

    for(i=1,j=0;i<n;++i) //Bit reverse
    {
        int bit=n>>1;
        for(;j>=bit;bit>>=1)
            j=j-bit;
        j=j+bit;
        if(i<j)
            swap(a[i],a[j]);
    }


    for(int len=2;len<=n;len<<=1)
    {
        ld ang=2*PI/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for(i=0;i<n;i+=len)
        {
            base w(1);
            for(int j=0;j<len/2;++j)
            {
                base u=a[i+j],v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w=w*wlen;
            }
        }
    }

    if(invert)
    {
        for(i=0;i<n;++i)
            a[i]/=n;
    }
}
vector<ll> result,a,b;

void multiply(const vector<ll> &a,const vector<ll> &b)
{
    vector<base> fa(a.begin(),a.end()),fb(b.begin(),b.end());
    size_t n=1;
    int i;
    while(n<max(a.size(),b.size())) n<<=1;
    n<<=1;
    fa.resize(n),fb.resize(n);
    fft(fa,false);fft(fb,false);
    for(i=0;i<n;++i)
    {
        fa[i]=fa[i]*fb[i];
    }
    fft(fa,true);
    result.resize(n);
    for(i=0;i<n;++i)
        result[i]=(ll)(fa[i].real()+0.5);
}

ll result2[1000001];
vector<ll> aa,bb;
int main(int argv, char** argc){
    ll t;
    t = 1;
    // cin>>t;
    while(t--){
        memset(result2,0,sizeof(result2));
        string a;
        // cin>>a;
        a = argc[1];
        string b;
        // cin>>b;
        b = argc[2];
        ll fs = b.length();
        // while(b.length()<a.length()){
        //     b = "}"+b;
        // }
        ll n = a.length();
        aa.resize(n);
        bb.resize(n);
        for(ll i=0;i<n;i++){
            if(a[i] == 'A'){
                aa[i] = 1;
            }else{
                aa[i] = 0;
            }
        }
        for(ll i=0;i<b.length();i++){
            if(b[i] == 'A'){
                bb[b.length()-i-1] = 1;
            }else {
                bb[b.length()-i-1] = 0;
            }
        }
        multiply(aa,bb);
        for(ll i=0;i<n-fs;i++){
            result2[i] += result[i+n-1];
        }
        result.clear();
        for(ll i=0;i<n;i++){
            if(a[i] == 'C'){
                aa[i] = 1;
            }else{
                aa[i] = 0;
            }
        }
        
        for(ll i=0;i<b.length();i++){
            if(b[i] == 'C'){
                bb[b.length()-i-1] = 1;
            }else {
                bb[b.length()-i-1] = 0;
            }
        }
        multiply(aa,bb);
        for(ll i=0;i<n-fs;i++){
            result2[i] += result[i+n-1];
        }
        result.clear();
        for(ll i=0;i<n;i++){
            if(a[i] == 'T'){
                aa[i] = 1;
            }else{
                aa[i] = 0;
            }
        }
        
        for(ll i=0;i<b.length();i++){
            if(b[i] == 'T'){
                bb[b.length()-i-1] = 1;
            }else {
                bb[b.length()-i-1] = 0;
            }
        }
        multiply(aa,bb);
        for(ll i=0;i<n-fs;i++){
            result2[i] += result[i+n-1];
        }
        result.clear();
        for(ll i=0;i<n;i++){
            if(a[i] == 'G'){
                aa[i] = 1;
            }else{
                aa[i] = 0;
            }
        }
        for(ll i=0;i<b.length();i++){
            if(b[i] == 'G'){
                bb[b.length()-i-1] = 1;
            }else {
                bb[b.length()-i-1] = 0;
            }
        }
        multiply(aa,bb);
        ll maxx = 0;
        for(ll i=0;i<n-fs;i++){
            result2[i] += result[i+n-1];
            maxx = max(result2[i],maxx);
        }
        result.clear();
        cout<<fs-maxx<<endl;
    }
}
