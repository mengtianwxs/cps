#ifndef MAN_H
#define MAN_H

#include <QObject>

class man
{

public:
    man();
    virtual QString readMan();

public:
    QString data="";
};

#endif // MAN_H
