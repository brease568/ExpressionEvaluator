class Less: public SubExpression
{
public:
    Less(Expression* left, Expression* right):
    SubExpression(left, right)
    {
    }
    double evaluate()
    {
        return left->evaluate() < right->evaluate();
    }
};
