#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        int haha;
        Node(int v, int h){
            Node::value = v;
            haha = h;
        }
};

class Bode : public Node{
    public:
        // Very Very Important: constructor inheritence
        using Node::Node;
};

int main(){ 
    Bode* a = new Bode(4,5);

    cout << a->value << a->haha <<endl;

    delete a;
    return 0;
}