class Greater: public SubExpression
{
public:
    Greater(Expression* left, Expression* right):
    SubExpression(left, right)
    {
    }
    double evaluate()
    {
        return left->evaluate() > right->evaluate();
    }
};
