class Operand: public Expression
{
public:
    static Expression* parse(istringstream& myStringStream);
};
