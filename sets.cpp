#include <iostream>
#include <string>
#include <vector>
#include <set>

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

int countUnique(const vector<Student> &students)
{
    // CODE HERE
    set<Student> uniqueStudents; 
    for (Student s: students){
        uniqueStudents.insert(s);
    }
    return uniqueStudents.size() ; 
}

int main() {

    vector<Student> testStudents;

    testStudents.push_back(Student(10, "Bienve", "Velez"));
    testStudents.push_back(Student(13, "María", "Ramos"));
    testStudents.push_back(Student(65, "Jomard", "Concepción"));
    testStudents.push_back(Student(60, "Angel", "García"));
    testStudents.push_back(Student(25, "Robdiel", "Meléndez"));
    testStudents.push_back(Student(25, "Robdiel", "Meléndez"));
    testStudents.push_back(Student(20, "Eithan", "Capella"));
    testStudents.push_back(Student(70, "Alanis", "Negroni"));
    testStudents.push_back(Student(13, "María", "Ramos"));
    testStudents.push_back(Student(31, "Jann", "García"));
    testStudents.push_back(Student(51, "Juan", "Rivera"));
    testStudents.push_back(Student(31, "Angel", "García"));
    testStudents.push_back(Student(60, "Angel", "García"));
    testStudents.push_back(Student(30, "José", "Cordero"));
    testStudents.push_back(Student(30, "José", "Ortiz"));
    testStudents.push_back(Student(50, "Joel", "Alvarado"));
    testStudents.push_back(Student(60, "Jann", "García"));
    testStudents.push_back(Student(51, "Juan", "Rivera"));
    testStudents.push_back(Student(71, "Jose", "Ortiz"));
    testStudents.push_back(Student(71, "Jose", "Cordero"));

    cout << "Count of Vector Students: " << testStudents.size() << endl;
    cout << "Count of Unique Students: " << countUnique(testStudents) << endl;

    set<Student> s2(testStudents.begin(), testStudents.end());
    cout << "2nd Count of Unique Students: " << s2.size() << endl;


    return 0; 

}