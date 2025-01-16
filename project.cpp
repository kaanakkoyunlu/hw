#include <iostream>
#include <string>
using namespace std;

 
/*
    Abstraction: The concept of hiding details and showing only essential features.
            Goal is to reduce complexity and increase focus on what an object does, 
            rather than how it does it. 

    Polymorphism: The ability of a single object, function or method to take multiple forms. 
            Goal is to allow flexibility and reuse of methods

    Inheritance: One child class derives its properties and behaviors from another class (parent)
            Goal is to promote code reuse and establish a parent-child relationship

    Encapsulation: To protect some data of an object and provide controlled access through public methods
            (getters and setters)

    Class and Object: A blueprint or template for creating objects. It defines the properties and methods of object

    Virtual keyword: it ensures that the appropriate function in the derived class is called when using base class references or pointers.
    
*/



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
