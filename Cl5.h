//
// Created by inade on 28.05.2022.
//

#ifndef __CL5__
#define __CL5__
#include "Cl1.h"
class Cl5:public ClBase
{
public:
    Cl5(ClBase* parent, string name):ClBase(parent, name, 5){};
    void signal(string &str);
    void handler(string str);
};
#endif
