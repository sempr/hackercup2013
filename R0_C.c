#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int k,n,a,b,c,r,K;
int m[200200];
int cnt[100100];
set<int> mm;
set<int>::iterator ii;

int solve(){
    int i,j,t,e;
    scanf("%d%d",&n,&k);
    scanf("%d%d%d%d",&a,&b,&c,&r);
    mm.clear();
    m[0]=a;
    for (i=1;i<k;i++)
        m[i] = int((1LL*b*m[i-1]+c)%r);
    memset(cnt,0,sizeof(cnt));    
    for (i=0;i<k;i++){
        if (m[i]<=k){
            cnt[m[i]]++;
        }
    }
    for (i=0;i<=k;i++) 
        if (cnt[i]==0) mm.insert(i);
    K = k+k+20;
    for (i=k;i<=K;i++){
        ii = mm.begin();
        m[i] = *ii;
        t = *ii;
        cnt[t]++;
        mm.erase(ii);
        j = m[i-k];
        if (j<=k){
            cnt[j]--;
            if (cnt[j]==0)
                mm.insert(j);
        }
        //printf("m[%d]=%d\n",i,m[i]);
    }
    // circle k+1, first m[k];
    return m[k+(n-k-1)%(k+1)];
}

int main(){
    int i,j,m,val,sum;
    scanf("%d\n",&m);
    for (i=1;i<=m;i++){
        printf("Case #%d: %d\n",i,solve());
    }
    return 0;
}

