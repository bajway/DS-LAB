#include<iostream>
using namespace std;

class Box
{
    int* data;
    public:
        //constructor
        Box(int initialValue = 0){
            data = new int(initialValue);
            cout << "Constructor called" << endl;
        }
        //destructor
        ~Box(){
            delete data;
            cout << "Destructor called" << endl;
        }
        //copy
        Box(const Box &obj){
            data = new int(*obj.data);
            cout << "Copy constructor" << endl;
        }
        
        Box& operator =(const Box& obj){
            if(this != &obj)
            {
                delete data;
                data = new int(*obj.data);
                cout << "Copy assignment" << endl;
            }
            return *this;
        }
        
        void setValue(int newValue){
            *data = newValue;
        }
        
        int getValue(){
            return *data;
        }
};

int main(){
    Box box1(100);
    Box box2 = box1;
    Box box3;
    box3 = box1;
    cout<<"Box1: " << box1.getValue() << endl;
    cout<<"Box2: " << box2.getValue() << endl;
    cout<<"Box3: " << box3.getValue() << endl;
    
    cout << "After Change:" << endl;
    
    box1.setValue(1);
    cout<<"Box1: " << box1.getValue() << endl;
    cout<<"Box2: " << box2.getValue() << endl;
    cout<<"Box3: " << box3.getValue() << endl;
    return 0;
}
