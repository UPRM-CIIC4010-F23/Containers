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

    void setGpa(float v){gpa = v;}


    // operator< required by sort without parameters
    bool operator< (const Student &s) const {
        return this->getId() < s.getId() ;
    }
    //  s1 < s2
};

bool compByGPAIncreasing(const Student &s1, const Student &s2){
    return s1.getGpa() < s2.getGpa() ; 
}

bool compByGPADecreasing(const Student &s1, const Student &s2){
    return s1.getGpa() > s2.getGpa() ; 
}


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

    // // Sort students by id using operator<
    // sort(testStudents.begin(),testStudents.end()); 
   
    // // Sort increasingly by GPA using standalone comparator function
    // sort(testStudents.begin(),testStudents.end(), compByGPAIncreasing); 
    
    // // Sort decreasingly by GPA using standalone comparator function
    // sort(testStudents.begin(),testStudents.end(), compByGPADecreasing); 
    
    // Sort increasingly by GPA using lambda expression
    // sort(testStudents.begin(),testStudents.end(), 
    // [](const Student &s1, const Student &s2) {return s1.getGpa() < s2.getGpa() ; }); 

    // Sort increasingly by lastname using lambda expression
    // sort(testStudents.begin(),testStudents.end(), 
    // [](const Student &s1, const Student &s2) {return s1.getLastName() < s2.getLastName() ; }); 

    // Find Student with last name "García"
    auto it = find_if(testStudents.begin(),testStudents.end(), 
    [](const Student &s){return s.getLastName() == "García"; }) ; 

    cout << "First ID: " << it ->getId() <<endl; 

    // Find second Student with last name "García"
    auto it2 = find_if(it+1,testStudents.end(), 
    [](const Student &s){return s.getLastName() == "García"; }) ; 

    cout << "Second ID: " << it2 ->getId() <<endl; 
    
    // Find third Student with last name "García"
    auto it3 = find_if(it2+1,testStudents.end(), 
    [](const Student &s){return s.getLastName() == "García"; }) ; 

    cout << "Third ID: " << it3 ->getId() <<endl; 

    cout << boolalpha << (it3 == testStudents.end()) <<endl ;

    // Count how many students have GPA >= 3.5
    int total = count_if(testStudents.begin(),testStudents.end(), 
    [](const Student &s) {return s.getGpa() >= 3.5 ; });

    cout << total << " students with 3.5 GPA or higher." << endl ; 


    // Round every GPA using for_each
    for_each(testStudents.begin(),testStudents.end(), 
    [](Student &s) {  s.setGpa( round(s.getGpa()) ); });
    
    cout << "The End" << endl;
}
