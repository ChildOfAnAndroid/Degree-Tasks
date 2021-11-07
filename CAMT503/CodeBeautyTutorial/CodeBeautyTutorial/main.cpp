//
//  main.cpp
//  CodeBeautyTutorial
//
//  Created by Charis Cat on 07/11/2021.
//

#include <iostream>
using std::string;

class AbstractEmployee {
    //contract has only one rule, whatever class signs contract must implement the below method
    virtual void AskForPromotion()=0; //virtual function/abstract function
};

class Employee:AbstractEmployee {
private: //properties are hidden/encapsulated within the class
    string Company;
    int Age;
    
protected: //accessible from derived classes
    string Name;
    
public:
    //Setter
    void setName(string name){
        Name = name;
    }
    
    //Getter
    string getName() {
        return Name;
    }
    
    void setCompany(string company) {
        Company = company;
    }
    
    string getCompany() {
        return Company;
    }
    
    void setAge(int age) {
        if(age >= 18) //validation rules, cannot change age to be under 18 as employees are always 18 or older
        Age = age;
    }
    
    int getAge() {
        return Age;
    }
    
    void IntroduceYourself(){
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }
    Employee(string name, string company, int age) { //constructor has the same name as the class
        Name = name;
        Company = company;
        Age = age;
    }
    
    //Calling the virtual function
    void AskForPromotion(){
        //People older than 30 get promoted
        if(Age >= 30)
            std::cout << Name << " got promoted" << std::endl;
        else
            std::cout << Name << ", sorry no promotion for you!" << std::endl;
    }
    
    virtual void Work() { //Virtual functions search for identical functions in their child classes and then implement the furthest derived form of the function
        std::cout << Name << " is checking email, checking task backlog, performing those tasks..." << std::endl;
    }
};

class Developer:public Employee { //colon then putting the parent class after means developer is now a child class of employee
    //developer now has all of the properties that employee has
    //can use public before parent class to inherit the properties publically
    
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage)
        :Employee(name, company, age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void FixBug() {
        std::cout << getName() << " fixed a bug using " << FavProgrammingLanguage << std::endl;
    }
    void Work() {
        std::cout << Name << " is writing a " << FavProgrammingLanguage << " program" << std::endl;
    }
};

class Teacher:public Employee {
public:
    string Subject;
    void PrepareLesson() {
        std::cout << Name << " is preparing a " << Subject <<  " lesson" << std::endl;
    }
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }
    void Work() {
        std::cout << Name << " is teaching a " << Subject << " class" << std::endl;
    }
};

int main() {

    Employee employee1 = Employee("Saldina", "YT-CodeBeauty", 25); //initialises values for individual objects in the class
    employee1.IntroduceYourself();
    
    Employee employee2 = Employee("John", "Amazon", 35);
    employee2.IntroduceYourself();
    
    employee1.setAge(9); //calling the setter, wont change if age is under 18
    std::cout << employee1.getName() << " is " << employee1.getAge() << " years old" << std::endl; //calling the getter
    
    employee1.AskForPromotion();
    employee2.AskForPromotion();
    
    Developer d = Developer("Charis", "Tindie", 26, "C++");
    
    d.FixBug();
    
    d.Work();
    
    d.AskForPromotion();
    
    Teacher t = Teacher ("Satvik", "Plymouth University", 28, "Programming");
    
    t.PrepareLesson();
    
    t.Work();
    
    t.AskForPromotion();
    
    // The most common use of polymorphism is when a parent class reference is used to refer to a child class object.
    
    Employee* e1 = &d; //pointer of parent class holds reference of child class object
    Employee* e2 = &t;
    
    e1->Work(); // -> is used when you want to access members using a pointer, used instead of . symbol when pointers are involved
    e2->Work();
    
}

//Encapsulation - bundling data & methods of changing that data into one class. Other classes cannot directly change the data.

//Abstraction - hiding complex things behind a procedure that simplifies them

//Inheritance - parent vs child class. parent class has members, child class can inherit members from parent class.

//Polymorphism - The ability of an object or method to have many forms. The most common use of polymorphism is when a parent class reference is used to refer to a child class object.
