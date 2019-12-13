class SubExpression: public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
    static Expression* parse(istringstream& myStringStream);
protected: 
    Expression* left;
    Expression* right;
};
