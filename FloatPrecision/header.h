#include <stdio.h>

struct pFloat{
    long long unsigned int whole;
    double fract; // 0 to 1 MAX precision
};

struct pFloat multiply(struct pFloat a, struct pFloat b){
    struct pFloat r;
    long long unsigned int wh1,wh2;
    double fr1,fr2;
    wh1 = (long long unsigned int) (a.whole*b.fract);
    wh2 = (long long unsigned int) (b.whole*a.fract);
    fr1 = a.whole*b.fract - wh1;
    fr2 = b.whole*a.fract - wh2;

    r.whole = a.whole*b.whole + wh1 + wh2;
    r.fract = a.fract*b.fract + fr1 + fr2;

    if(r.fract >= 1){
        r.whole = r.whole + (int) r.fract;
        r.fract = r.fract - (int) r.fract;
    }
    return r;
}

struct pFloat divide(struct pFloat a, double b){
    struct pFloat r;
    double fr;
    fr = a.whole / b;
    r.whole = (long long unsigned int) fr;
    r.fract = fr - r.whole + a.fract / b;
    if(r.fract >= 1){
        r.whole = r.whole + (int) r.fract;
        r.fract = r.fract - (int) r.fract;
    }
    return r;
}