//
// Created by inade on 28.05.2022.
//

#ifndef __CL3__
#define __CL3__
#include "Cl1.h"
class Cl3:public ClBase
{
public:
    Cl3(ClBase* parent, string name):ClBase(parent, name, 3){};
    void signal(string &str);
    void handler(string str);
};
#endif
