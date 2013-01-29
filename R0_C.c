#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int k,n,a,b,c,r,K;
int m[200200];
int cnt[100100];

int solve(){
    int i,j,t,e;
    scanf("%d%d",&n,&k);
    scanf("%d%d%d%d",&a,&b,&c,&r);
    m[0]=a;
    for (i=1;i<k;i++) m[i] = int((1LL*b*m[i-1]+c)%r);
    memset(cnt,0,sizeof(cnt));    
    for (i=0;i<k;i++){
        if (m[i]<=k){
            cnt[m[i]]++;
        }
    }
    for (j=0;j<=k;j++) if (cnt[j]==0){
        m[k]=j; cnt[j]++;
        break;
    }
    K = k+k; t = 0; j++;
    for (i=k+1;i<=K;i++,t++){
        if (m[t]<=k) cnt[m[t]]--;
        while (cnt[j]>0) j++;
        if (m[t]<=j && cnt[m[t]]==0) m[i]=m[t];
        else{
            m[i]=j; j++;
        }
        cnt[m[i]]++;
    }
    //for (i=0;i<=K;i++) printf("m[%d]=%d\n",i,m[i]);
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

