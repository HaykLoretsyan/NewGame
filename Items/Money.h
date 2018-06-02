#ifndef MONEY_H
#define MONEY_H

struct Money
{
    unsigned gold;
    unsigned token;

    unsigned redGem;
    unsigned blueGem;
    unsigned greenGem;

    bool operator > (const Money& cost) {
        return (gold >= cost.gold &&
               token >= cost.token &&
               redGem >= cost.redGem &&
               blueGem >= cost.blueGem &&
               greenGem >= cost.greenGem);
    }

    bool operator < (const Money& cost) {
        return !(*this > cost);
    }

    Money& operator -= (const Money& cost) {

        if(*this < cost) return *this;

        gold -= cost.gold;
        token -= cost.token;
        redGem -= cost.redGem;
        blueGem -= cost.blueGem;
        greenGem -= cost.greenGem;

        return *this;
    }

    Money operator - (const Money& cost) {

        if(*this < cost) return *this;

        Money result(*this);

        return (result -= cost);
    }

    Money& operator += (const Money& addition) {

        gold += addition.gold;
        token += addition.token;
        redGem += addition.redGem;
        blueGem += addition.blueGem;
        greenGem += addition.greenGem;

        return *this;
    }

    Money operator + (const Money& addition) {

        Money result(*this);

        return (result += addition);
    }
};

#endif // MONEY_H
