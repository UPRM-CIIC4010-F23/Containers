#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {

private:
    int id;
    string firstName;
    string lastName;
    float gpa;

public:
    Student(int id, string fn, string ln, float g) : id(id), firstName(fn), lastName(ln), gpa(g) {}

    int getId() const { return id; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    float getGpa() const { return gpa; }


    // operator< required by sort without parameters
    
};



int main() {

    vector<Student> testStudents;
    testStudents.push_back(Student(10, "Bienve", "Velez", 3.5));
    testStudents.push_back(Student(13, "María", "Ramos", 3.7));
    testStudents.push_back(Student(65, "Jomard", "Concepción", 3.1));
    testStudents.push_back(Student(60, "Angel", "García", 3.0));
    testStudents.push_back(Student(25, "Robdiel", "Meléndez", 3.3));
    testStudents.push_back(Student(20, "Eithan", "Capella", 3.1));
    testStudents.push_back(Student(70, "Alanis", "Negroni", 4.0));
    testStudents.push_back(Student(31, "Jann", "García", 2.9));
    testStudents.push_back(Student(30, "José", "Cordero", 3.9));
    testStudents.push_back(Student(50, "Joel", "Alvarado", 3.45));
    testStudents.push_back(Student(51, "Juan", "Rivera", 3.2));
    testStudents.push_back(Student(71, "Jose", "Ortiz", 4.0));



    cout << "Count of Vector Students: " << testStudents.size() << endl;

    // Sort students by id using operator<

   
    // Sort increasingly by GPA using standalone comparator function

    
    // Sort decreasingly by GPA using standalone comparator function

    
    // Sort increasingly by GPA using lambda expression


    // Sort increasingly by lastname using lambda expression


    // Find Student with last name "García"


    // Find second Student with last name "García"

    
    // Find third Student with last name "García"


    // Count how many students have GPA >= 3.5


    // Round every GPA using for_each

    
    cout << "The End" << endl;
}
