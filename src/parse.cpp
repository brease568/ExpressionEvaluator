#include <cctype> 
#include <sstream> 
#include <string> 
using namespace std;

#include "parse.h"

string parseName(istringstream& myStringStream)
{
    char alnum;
    string name = "";

    myStringStream >> ws;
    while (isalnum(myStringStream.peek()))
    {
        myStringStream >> alnum;
        name += alnum;
    }
    return name;
}
