//
// Created by inade on 28.05.2022.
//

#ifndef __CLBASE__
#define __CLBASE__
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class ClBase;
typedef void (ClBase::*TYPE_SIGNAL)(string&); // Зарезервированное под функцию слово //*указатель на метод
typedef void (ClBase::*TYPE_HANDLER)(string); // Используется для создания новых имён для типов данных
#define SIGNAL_D(signal) (TYPE_SIGNAL)(&signal)
#define HANDLER_D(handler) (TYPE_HANDLER)(&handler)
class ClBase{
    struct Connection{
        ClBase* connected; // Указатель на объект, к которому приходит сигнал
        TYPE_SIGNAL signal; // Указатель на сигнал текущего объекта
        TYPE_HANDLER handler; // Указатель на обработчик объекта, к которому приходит сигнал
        Connection(ClBase* c, TYPE_SIGNAL s, TYPE_HANDLER h):connected(c), signal(s), handler(h){}; // Конструктор, который присваивает значение параметров полям
    };
    int number;
    vector<Connection*> connections;
    bool ready;
    string name;
    ClBase* parent;
    vector<ClBase*> children;
public:
    ClBase(ClBase* parent, string name="", int number=1);
    ~ClBase();
    /*void setCurrent(ClBase* current);
    ClBase* getCurrent();*/
    string getName();
    ClBase* current;
    void signal(string &str);
    void handler(string str);

    void setConnection(ClBase* c, TYPE_SIGNAL s, TYPE_HANDLER h);
    void deleteConnection(ClBase* c, TYPE_SIGNAL s, TYPE_HANDLER h);
    void setConnection();
    void emitSignal(TYPE_SIGNAL s, string str);
    TYPE_SIGNAL getSignalPtr();
    TYPE_HANDLER getHandlerPtr();
    void deleteConnection();

    string getPath();
    int getNumber();

    ClBase* findPath(string path);
    void setName(string name);
    void print();
    void setReady(int num);
    ClBase* getParent();
    /*void setParent(ClBase* new_parent);*/
    ClBase* search(string name);
    void showTree(string depth);
    void printReady(string depth);
};
#endif
