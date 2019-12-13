#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(istringstream& myStringStream);

int main()
{
    //Declare variables for the expression and literal parenthesis and commas:
    Expression* expression;
    char paren, comma;

    //Read expressions in from a file:
    cout << "\nAttempting to read from file: 'expressions.txt'" << endl;

    ifstream inFile("expressions.txt");
    if(!inFile)
    {
	cout << "Could not find the file: 'expressions.txt'" << endl;
	return -1;
    }

    string fileLine;
    while(getline(inFile, fileLine))
    {
	if(fileLine.empty()) { continue; }
	//Clear the symbolTable to not interfere with multiple expressions in a file
	symbolTable.clear();
	istringstream myStringStream(fileLine);
	cout << fileLine << endl;
	myStringStream >> paren;
	expression = SubExpression::parse(myStringStream);
	myStringStream >> comma;
	parseAssignments(myStringStream);
	cout << "Value = " << expression->evaluate() << endl;
	cout << "" << endl;
    }
    cout << "Done reading file." << endl;
    inFile.close();
    return 0;
}

void parseAssignments(istringstream& myStringStream)
{
    char assignop, delimiter;
    string variable;
    int value;
    do
    {
        variable = parseName(myStringStream);
        myStringStream >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}
