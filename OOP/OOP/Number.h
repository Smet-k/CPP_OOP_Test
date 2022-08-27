/*
// PROPERTY
int pValue;

int getValue()
{
    return pValue;
}

void setValue(int value)
{
    pValue = value;
}
*/


class Number
{
public: 
    // FIELD
    

    //METHOD

    void setValue(int number)
    {
        value = number;
    }

    int getValue()
    {
        return value;
    }

    Number sum(Number number)
    {
        return proccess(value + number.value);
    }

    Number substract(Number number)
    {
        return proccess(value - number.value);
    }

    Number multiply(Number number)
    {
        return proccess(value * number.value);
    }

    Number divide(Number number)
    {
        return proccess(value / number.value);
    }

    Number avg(Number number)
    {
        return proccess(sum(number).value / 2);
    }

private:
    int value;

    Number proccess(int value)
    {
        Number result;
        result.value = value;
        return result;
    }

};