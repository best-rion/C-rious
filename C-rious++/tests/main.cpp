#include <iostream>

using namespace std;
struct numbers{
        int a,f;
};
int main(){
    numbers num1;

    int *k = new int(4);

    *k = 3;

    cout << *k << endl;

    return 0;
}