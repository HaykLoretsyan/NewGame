#ifndef CUSTOMEXCEPTIONS_H
#define CUSTOMEXCEPTIONS_H

#include <QException>


class ReourceInitException : public QException
{
public:
    ReourceInitException(bool isNetwork = false) : m_isNetwork(isNetwork) {}

public:
    void raise() const { throw *this; }
    ReourceInitException *clone() const { return new ReourceInitException(*this); }

    QString message() const {
        if(m_isNetwork) {
            return QString("Failed to initialize resources from network");
        }
        else {
            return QString("Failed to initialize resources from database");
        }
    }

private:
    bool m_isNetwork;
};


class IncompatibleWithServerException : public QException
{
public:
    IncompatibleWithServerException() {}

public:
public:
    void raise() const { throw *this; }
    IncompatibleWithServerException *clone() const { return new IncompatibleWithServerException(*this); }

    QString message() const {
        return QString("Data incompatible with server");
    }
};

#endif // CUSTOMEXCEPTIONS_H
