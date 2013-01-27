#include <stdio.h>
#include <algorithm>

using namespace std;

char s[512];
int c[26];

int get_value(char x){
    if (x>='a' && x<='z') return x-'a';
    if (x>='A' && x<='Z') return x-'A';
    return -1;
}

int main(){
    int i,j,m,val,sum;
    scanf("%d\n",&m);
    for (i=1;i<=m;i++){
        fgets(s,512,stdin);
        memset(c,0,sizeof(c));
        for (j=strlen(s)-1;j>=0;j--){
            val = get_value(s[j]);
            if (val>=0) c[val]++;
        }
        sort(c,c+26);
        sum = 0;
        for (j=25;j>=0;j--){
            sum += (j+1) * c[j];
        }
        printf("Case #%d: %d\n",i,sum);
    }
    return 0;
}

