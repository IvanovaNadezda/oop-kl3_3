#include "ClBase.h"
#include "Cl_app.h"
#include "Cl2.h"
#include "Cl3.h"
#include "Cl4.h"
#include "Cl5.h"
#include "Cl6.h"

void ClBase::setConnection(ClBase* c, TYPE_SIGNAL s, TYPE_HANDLER h) // с - указатель на объект которому приходит сигнал
{
    // Добавляет в вектор связей новую
    connections.push_back(new Connection(c,s,h));
}

void ClBase::deleteConnection(ClBase* c, TYPE_SIGNAL s, TYPE_HANDLER h) // Удаление связей объекта
{
    for(int i=0; i<connections.size(); i++)
    {
        // Смотрим каждую свзяь в векторе, если совпадает всё полностью [i] структура в вектор мы удаляем ту которую нашли
        if(connections[i]->connected == c && connections[i]->signal == s && connections[i]->handler==h)
            connections.erase(connections.begin()+i);
    }
}

int ClBase::getNumber()
{
    return number;
}

void ClBase::emitSignal(TYPE_SIGNAL s, string str) // Отправка сигнала // Работа связи
{
    if(ready==0) // ready у текущего объекта
        return;
    // *s указатель на метод
    // сразу отрабатывает
    (this->*s)(str); // Передаем в метод сигнал для объекта данного класса, передаём сообщение
    for(int i=0; i<connections.size(); i++) // проходимся по связям
    {
        if(connections[i]->signal==s) //если сигнал равен этому сигналу который пришел в emit
        {
            if(connections[i]->connected->ready!=0) // если объект готов // у которого найден сигнал
                (connections[i]->connected->*connections[i]->handler)(str); // вызывает метод handler для объекта в который направлен сигнал
        }
    }
    // Сначала срабатывает сигнал текущего объекта
    // и если все нормально, то мы направляем
}


TYPE_HANDLER ClBase::getHandlerPtr()
{
    TYPE_HANDLER h;
    switch(getNumber())
    {
        case 1:
            h=HANDLER_D(Cl_app::handler);
            break;
        case 2:
            h=HANDLER_D(Cl2::handler);
            break;
        case 3:
            h=HANDLER_D(Cl3::handler);
            break;
        case 4:
            h=HANDLER_D(Cl4::handler);
            break;
        case 5:
            h=HANDLER_D(Cl5::handler);
            break;
        case 6:
            h=HANDLER_D(Cl6::handler);
            break;
    }
    return h;
}

TYPE_SIGNAL ClBase::getSignalPtr()
{
    TYPE_SIGNAL h;
    switch(getNumber())
    {
        case 1:
            h=SIGNAL_D(Cl_app::signal);
            break;
        case 2:
            h=SIGNAL_D(Cl2::signal);
            break;
        case 3:
            h=SIGNAL_D(Cl3::signal);
            break;
        case 4:
            h=SIGNAL_D(Cl4::signal);
            break;
        case 5:
            h=SIGNAL_D(Cl5::signal);
            break;
        case 6:
            h=SIGNAL_D(Cl6::signal);
            break;
    }
    return h;
}

string ClBase::getPath()
{
    if(!parent)
        return("/");
    string path = getName();
    ClBase* ptr = parent;
    while(ptr->getParent())
    {
        path = ptr->getName() + "/" + path;
        ptr=ptr->getParent();
    }
    return "/" + path;
}

ClBase* ClBase::findPath(string path){
    /*
    if(path.substr(0,2)=="//") // найти объект относительно текущего (найти ребёнка) 3_2
        return search(path.substr(2));
    if(path==".") // вернуть текущий 3_2
        return current; // current - поле у объекта туда записывался текущий // current - указатель на собственный объект
    */
    if(path == "/") // вернуть
        return this; // просто текущий?
    // отсюда нанает работать 3_3
    int posSlash = path.find('/', 1); //  /root/ob1/ob4
    if(path[0]=='/'){
        string nextName;
        if(posSlash==-1){
            nextName=path.substr(1);
            for(int i=0; i<children.size(); i++){
                if(nextName==children[i]->getName())
                    return children[i];
            }
            return(nullptr);
        }
        nextName=path.substr(1,posSlash-1);
        for(int i=0; i<children.size(); i++){
            if(nextName==children[i]->getName())
                return children[i]->findPath(path.substr(posSlash)); // posSlash от ob1 // идет отсечение
        }
        return(nullptr);
    }
    return nullptr; // !!!!!!!!!!!
    //return current->findPath("/"+path);
}

ClBase::ClBase(ClBase* parent, string name, int number)
{
    this->number=number;
    current=this;
    this->name = name;
    this->parent = parent;
    ready=true;
    if(parent!=nullptr)
    {
        parent->children.push_back(this);
    }

}

ClBase::~ClBase()
{
    for(int i=0; i<children.size(); i++)
    {
        delete children[i];
    }
}

ClBase* ClBase::getParent()
{
    return this->parent;
    /*
    root
     ob1
      ob2 ob3 (вернет ob1)
    */
}

/*void ClBase::print()
{
    if(children.size()!=0)
    {
        cout << getName();
        for(int i=0; i<children.size(); i++)
        {
            cout << " " << children[i]->getName();
        }
        bool first = true;
        for(int i=0; i<children.size(); i++)
        {
            if(children[i]->children.size()!=0 && first == true)
            {
                cout << endl;
                first=false;
            }
            children[i]->print();
        }
    }
}*/

void ClBase::showTree(string depth)
{
    cout << this->name;
    if(children.size()!=0)
    {
        depth+="    ";
        for(int i=0; i<children.size(); i++)
        {
            cout << endl << depth;
            children[i]->showTree(depth);
        }
    }
    /*
    root
        ob1
            ob4
        ob2
            ob7
    */
}

/*void ClBase::printReady(string depth)
{
    cout << name;
    if(this->ready==true)
        cout << " is ready";
    else
        cout << " is not ready";
    if(children.size()!=0)
    {
        depth+="    ";
        for(int i=0; i<children.size(); i++)
        {
            cout << endl << depth;
            children[i]->printReady(depth);
        }
    }
}*/

string ClBase::getName()
{
    return name;
}

void ClBase::setName(string name)
{
    this->name=name;
}

void ClBase::setReady(int x)
{
    if(x==0)
    {
        this->ready=false;
        for(int i=0; i<children.size(); i++)
            (this->children[i])->setReady(0);
    }
    else
    {
        /*
        root(может 0, а может нет)
            ob1(0)
                ob2 тоже 0
            ob3(не 0)
                ob6(может 0, а может и не 0)
        */
        ClBase* temp = this->parent;
        while(temp!=nullptr)
        {
            if(temp->ready==0)
            {
                this->ready=false;
                return;
            }
            temp=temp->parent;
        }
        this->ready=true;
    }
}

ClBase* ClBase::search (string name)
{
    if(this->name==name)
        return this;
    for(int i=0; i<children.size(); i++)
    {
        ClBase* obj = children[i]->search(name); //
        if(obj)
            return obj;
    }
    /*
     * пришло ob3
    root
        ob1
            ob3
                ob4
            ob5
        ob2
    */
    return nullptr;
}