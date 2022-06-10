//
// Created by inade on 28.05.2022.
//

#ifndef __CL2__
#define __CL2__
#include "Cl1.h"
class Cl2:public ClBase
{
public:
    Cl2(ClBase* parent, string name):ClBase(parent, name, 2){};
    void signal(string &str);
    void handler(string str);
};
#endif
