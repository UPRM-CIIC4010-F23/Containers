#include <iostream>
#include <map>
#include <string>

using namespace std;

// https://www.hackerrank.com/challenges/linkedin-practice-dictionaries-and-maps/problem

int main() {

    string sentence = "the quick brown fox jumps over the lazy dog"; 

    string paragraph = "A planet is an astronomical body orbiting a star or stellar remnant that is massive enough to be rounded by its own gravity";

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

    // CODE HERE

    map<char, int> alphabetHistogram ; 

    for (char l : alphabet){
        alphabetHistogram [l] = 0 ;
    }

    for (char l : paragraph){
        alphabetHistogram [toupper(l)]++ ;
    }

    for (char l : alphabet){
        cout << "Letter " << l << " appears: " << alphabetHistogram [l]  << endl;
    }

    return 0;
    
}