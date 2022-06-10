#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#include "Cl_app.h"
int main()
{
    Cl_app obj;
    obj.build_tree_obj();
    obj.enterConnections();
    obj.execute();
}

