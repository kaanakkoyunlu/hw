#include <iostream>
#include <string>
using namespace std;

//Abstraction used
class Rides {

public:

    //pure virtual functions (abstraction)
    virtual string sound() =0;
    virtual ~Rides() =0; //destructor

    //encapsulation: Provides access to 'name' through setter and getter
    void setName(string name) {

        this->name=name;
    }
    string getName() {
        return name;
    }

//Encapsulation: Private member variable
private:
    string name;
};

//Definition of virtual destructor (abstraction)
Rides::~Rides() {
    
}

//A Class inheriting from Rides (Class & Inheritance)
class Racing : public Rides {

public: 
        //override function demonstrates polymorphism         
        string sound() {

            return "VUUWWWWWNN";
        }
        //Destructor to clean up (Polymorphism)
        ~Racing() {
            cout<<"Racing destroyed"<<endl;
        }
};

class offRoad : public Rides {

public: 
        string sound() {

            return "RRRRRRR";
        }
        ~offRoad() {
            cout<<"Offroad destroyed"<<endl;
        }
};

int main() {

    //Polymorphism: Base Class pointers pointing to derived class objects
    Rides* v4 = new Racing(); 
    Rides* kdm = new offRoad();
    
    v4->setName("v4");
    kdm->setName("kdm");
    cout<<v4->getName()<<" makes the sound " + v4->sound()<<endl;
    cout<<kdm->getName()<<" makes the sound " + kdm->sound()<<endl;

    delete v4;
    delete kdm;
    return 0;
}
