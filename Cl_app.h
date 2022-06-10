//
// Created by inade on 28.05.2022.
//

#ifndef __CLAPP__
#define __CLAPP__
#include "ClBase.h"
#include "Cl1.h"
#include "Cl2.h"
#include "Cl3.h"
#include "Cl4.h"
#include "Cl5.h"
#include "Cl6.h"
class Cl_app:public ClBase
{
public:
    int execute();
    void signal(string &str);
    void handler(string str);
    void enterConnections();
    Cl_app():ClBase(nullptr, ""){};
    bool build_tree_obj();
    void build_ready_tree();
    int exec_app();
};
#endif
