#include "header.h"

// int main(){
//     double f = 1024.625, r=1;
//     int n=6;
//     for(int i=0; i<n; i++){
//         r*=f;
//     }
//     printf("r  = %lf\n",r/f);
//     return 0;
// }

int main(){
    int n=5;
    long long unsigned int wh1,wh2;
    double fr1,fr2;
    struct pFloat f = {1024, 0.625}, r = {1,0.0};
    for(int i=0; i<n; i++){
        r = multiply(r,f);
    }
    printf("whole = %llu\nfract = %0.20lf\n", r.whole, r.fract);
    return 0;
}