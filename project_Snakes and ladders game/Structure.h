#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <string>
using namespace std;

struct Data{
    string Day;
    string Mount;
    string Year;
};

struct Person{
    string Name;
    string Lastname;
    string Phonenumber;
    Data Birthday;
};

struct Player{
    string Username;
    string Password;
    int Score = 0;
    Person Info;
};

#endif // STRUCTURE_H
