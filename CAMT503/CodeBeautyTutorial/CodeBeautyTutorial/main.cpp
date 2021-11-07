//
//  main.cpp
//  CodeBeautyTutorial
//
//  Created by Charis Cat on 07/11/2021.
//

#include <iostream>
using std::string;

class Employee {
private: //properties are hidden/encapsulated within the class
    string Name;
    string Company;
    int Age;
    
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
};



int main() {

    Employee employee1 = Employee("Saldina", "YT-CodeBeauty", 25); //initialises values for individual objects in the class
    employee1.IntroduceYourself();
    
    Employee employee2 = Employee("John", "Amazon", 35);
    employee2.IntroduceYourself();
    
    employee1.setAge(9); //calling the setter
    std::cout << employee1.getName() << " is " << employee1.getAge() << " years old" << std::endl; //calling the getter
    
}

//Encapsulation - bundling data & methods of changing that data into one class. Other classes cannot directly change the data.

//Abstraction - hiding complex things behind a procedure that simplifies them
