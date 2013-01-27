#include <stdio.h>
#include <algorithm>

using namespace std;

char s[128];
bool opt[128][128];
int L;

bool dp(){
    int i,j,k;
    memset(opt,0,sizeof(opt));
    L = strlen(s);
    opt[0][0]=1;
    for (k=0;k<L;k++){
        for (i=0;i<L;i++){
            if (!opt[k][i]) continue;
            
            if (s[k]=='('){
                opt[k+1][i+1] = 1;
            }else if (s[k]==')'){
                if (i>0) opt[k+1][i-1] = 1;
            }else if (s[k]==':'){
                if (s[k+1]=='(' || s[k+1]==')') opt[k+2][i] = 1;
                opt[k+1][i]=1;
            }else{
                opt[k+1][i]=1;
            }
        }
    }
    if (opt[L][0]) return 1;
    else return 0;
}

int main(){
    int i,j,m,val,sum;
    scanf("%d\n",&m);
    for (i=1;i<=m;i++){
        fgets(s,512,stdin);
        printf("Case #%d: %s\n",i,dp()?"YES":"NO");
    }
    return 0;
}

