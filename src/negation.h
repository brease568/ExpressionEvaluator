class Negation: public SubExpression
{
public:
    Negation(Expression* left, Expression* right):
    SubExpression(left, right)
    {
    }
    double evaluate()
    {
        return !(left->evaluate());
    }
};
