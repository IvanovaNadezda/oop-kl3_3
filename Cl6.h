//
// Created by inade on 28.05.2022.
//

#ifndef __CL6__
#define __CL6__
#include "Cl1.h"
class Cl6:public ClBase
{
public:
    Cl6(ClBase* parent, string name):ClBase(parent, name,6){};
    void signal(string &str);
    void handler(string str);
};
#endif
