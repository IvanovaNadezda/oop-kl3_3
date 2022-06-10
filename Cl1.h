//
// Created by inade on 28.05.2022.
//

#ifndef __CLBSE1__
#define __CLBSE1__
#include "ClBase.h"
class Cl1:public ClBase
{
public:
    Cl1(ClBase* parent, string name, int number=1):ClBase(parent, name, number){};
    void signal(string &str);
    void handler(string str);
};
#endif
