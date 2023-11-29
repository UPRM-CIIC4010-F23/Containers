#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Student {

    private:
    int id;
    string firstName;
    string lastName;

    public:
    int getId() const { return id; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    Student(int id, string fn, string ln): id(id), firstName(fn), lastName(ln) {}

    bool operator< (const Student &s) const { return this->getId() < s.getId(); }

};


int main() {

    queue<int> numbers;

    numbers.push(10);
    numbers.push(13);
    numbers.push(65);
    numbers.push(60);
    numbers.push(25);
    numbers.push(20);
    numbers.push(70);
    numbers.push(31);
    numbers.push(51);
    numbers.push(30);
    numbers.push(50);
    numbers.push(71);
    
    // CODE HERE


    priority_queue<int> numbers2;

    numbers2.push(10);
    numbers2.push(13);
    numbers2.push(65);
    numbers2.push(60);
    numbers2.push(25);
    numbers2.push(20);
    numbers2.push(70);
    numbers2.push(31);
    numbers2.push(51);
    numbers2.push(30);
    numbers2.push(50);
    numbers2.push(71);
    
    // CODE HERE




    priority_queue<Student> testStudents;
    testStudents.push(Student(10, "Bienve", "Velez"));
    testStudents.push(Student(13, "María", "Ramos"));
    testStudents.push(Student(65, "Jomard", "Concepción"));
    testStudents.push(Student(60, "Angel", "García"));
    testStudents.push(Student(25, "Robdiel", "Meléndez"));
    testStudents.push(Student(20, "Eithan", "Capella"));
    testStudents.push(Student(70, "Alanis", "Negroni"));
    testStudents.push(Student(31, "Jann", "García"));
    testStudents.push(Student(30, "José", "Cordero"));
    testStudents.push(Student(50, "Joel", "Alvarado"));
    testStudents.push(Student(51, "Juan", "Rivera"));
    testStudents.push(Student(71, "Jose", "Ortiz"));

    // CODE HERE

   

    return 0; 
}