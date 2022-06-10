//
// Created by inade on 28.05.2022.
//

#ifndef __CL4__
#define __CL4__
#include "Cl1.h"
class Cl4:public ClBase
{
public:
    Cl4(ClBase* parent, string name):ClBase(parent, name, 4){};
    void signal(string &str);
    void handler(string str);
};
#endif
