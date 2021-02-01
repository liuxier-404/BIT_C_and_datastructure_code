#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<cmath>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
int domitory_x[100010];  
int domitory_y[100010];  
int target_x[100010];  
int target_y[100010];  
int jian[100010];  
int jia[100010];  
int end1[100010];  
  
int cmp(const void *a,const void *b) {  
    return  (*(int *)a - *(int *)b);  
}  
int main() {  
    int n, m;     
    scanf("%d %d",&n,&m);  
    int c,C;  
    scanf("%d",&C);  
    for (c = 0; c < C;c++) {  
        scanf("%d %d",&domitory_x[c],&domitory_y[c]);  
    }  
    int d, D;  
    scanf("%d",&D);  
    for (d = 0; d < D;d++) {  
        scanf("%d %d", &target_x[d], &target_y[d]);  
    }  
    for (c = 0; c < C;c++) {  
        jian[c] = domitory_x[c] - domitory_y[c];  
        jia[c] = domitory_x[c] + domitory_y[c];  
    }  
    sort(jian,jian + C);  
    sort(jia, jia + C);  
      
      
  
    int op = 0;  
    for (d = 0; d < D; d++) {  
        op = 0;  
        if (jian[C-1]-(target_x[d]-target_y[d])>op) {  
            op = jian[C - 1] - (target_x[d] - target_y[d]);  
        }  
        if ((target_x[d]-target_y[d])-jian[0]>op) {  
            op= (target_x[d] - target_y[d]) - jian[0];  
        }  
        if (jia[C-1]-target_x[d]-target_y[d]>op) {  
            op = jia[C - 1] - target_x[d] - target_y[d];  
        }  
        if (target_x[d]+target_y[d]-jia[0]>op) {  
            op = target_x[d] + target_y[d] - jia[0];  
        }  
        end1[d] = op;  
  
    }  
    sort(end1, end1 + D);  
    printf("%d\n",end1[0]);  
    return 0;  
}

