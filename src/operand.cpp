#include <cctype>
#include <sstream>
#include <list>
#include <string>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse(istringstream& myStringStream)
{
    char paren;
    int value;

    myStringStream >> ws;
    if (isdigit(myStringStream.peek()))
    {
        myStringStream >> value;
        Expression* literal = new Literal(value);
        return literal;
    }
    if (myStringStream.peek() == '(')
    {
        myStringStream >> paren;
        return SubExpression::parse(myStringStream);
    }
    else
        return new Variable(parseName(myStringStream));
    return 0;
}
