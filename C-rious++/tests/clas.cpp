#include <iostream>
#include <stdio.h>

using namespace std;

class Animal
{
public:
    string name;
    string color;
    int legs;
    Animal(int leg_num){
        legs = leg_num;
    };
};

int main(){

    Animal Dog(4);

    Dog.name = "Doggy";
    Dog.color = "Black";

    cout << "I am a dog. My name is " << Dog.name << ", I am " << Dog.color << " and have " << Dog.legs << " legs.";

    return 0;
}