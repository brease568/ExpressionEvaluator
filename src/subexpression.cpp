#include <iostream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greater.h"
#include "less.h"
#include "equals.h"
#include "and.h"
#include "or.h"
#include "conditional.h"
#include "negation.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse()
{
    Expression* left;
    Expression* right;
    Expression* condition; //Added for conditional operator
    char operation, paren, question;
    
    left = Operand::parse();
    cin >> operation;

    //First 'if' evaluates if the expression is a conditional expression
    if(operation == ':')
    {
	//The third operand represents the condition in the grammar
	right = Operand::parse();
	cin >> question;
	condition = Operand::parse();
	cin >> paren;
	return new Conditional(left, right, condition);
    }
    //Second 'if' evaluates if the expression is a negation expression
    else if(operation == '!')
    {
	cin >> paren;
	return new Negation(left, NULL); //This expression should only contain one operand
    }
    //Else the expression is one of the following switch case expressions
    else
    {
    	right = Operand::parse();
    	cin >> paren;
    	switch (operation)
    	{
            case '+':
            	return new Plus(left, right);
            case '-':
            	return new Minus(left, right);
            case '*':
    	        return new Times(left, right);
            case '/':
            	return new Divide(left, right);
	    //Adding support for relational and logical operators:
	    case '>':
	    	return new Greater(left, right);
	    case '<':
	    	return new Less(left, right);
	    case '=':
	    	return new Equals(left, right);
	    case '&':
	    	return new And(left, right);
	    case '|':
	    	return new Or(left, right);
    	}
    }
    return 0;
}
