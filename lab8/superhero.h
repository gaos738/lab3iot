#ifndef SUPERHERO_H_INCLUDED
#define SUPERHERO_H_INCLUDED



#endif // SUPERHERO_H_INCLUDED
#include <string>
using namespace std;

class Superhero
{
private:
    string identity;
    string name;
    string power;
public:
    Superhero(string  identity_,string  name_,string  power_)
    {
        identity = identity_;
        name = name_;
        power = power_;
    }

    string getName() { return name; }
    string getPower() { return power; }
    string getIdentity()  { return identity; }
};
