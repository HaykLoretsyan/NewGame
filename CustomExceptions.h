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
    void raise() const { throw *this; }
    IncompatibleWithServerException *clone() const { return new IncompatibleWithServerException(*this); }

    QString message() const {
        return QString("Data incompatible with server");
    }
};


class NetworkingNotAvailableException : public QException
{
public:
    NetworkingNotAvailableException() {}

public:
    void raise() const { throw *this; }
    NetworkingNotAvailableException *clone() const { return new NetworkingNotAvailableException(*this); }

    QString message() const {
        return QString("Networking is disabled");
    }
};


class IllegalFightCreation : public QException
{
public:
    IllegalFightCreation() {}

public:
    void raise() const { throw *this; }
    IllegalFightCreation *clone() const { return new IllegalFightCreation(*this); }

    QString message() const {
        return QString("Can't create fight");
    }
};

#endif // CUSTOMEXCEPTIONS_H
