//
// Created by inade on 28.05.2022.
//
#include "Cl_app.h"
#include <iostream>
using namespace std;

void Cl_app::enterConnections(){ // ввод сигналов // добавление свзяей между сигналами (структуру)
    string from, to; // пути от кого и куда
    while(true){
        cin >> from; // вводим от кого идёт
        if(from=="end_of_connections")
            return;
        cin >> to; // вводим куда идём
        // берём указатель на объект от которого исходит сигнал
        // вызываем set..
        // указатель на поле структуры Connection - connected, явлю указателем на объект которому будет послан сигнал
        // указатель на сигнал объекта от которого уходит сигнал
        // handler объекта к которому будет передан сигнал
        // добавили в вектор новую структуру
        findPath(from)->setConnection(findPath(to), findPath(from)->getSignalPtr(), findPath(from)->getHandlerPtr());
    }
}



bool Cl_app::build_tree_obj(){
    string parent_path, child_name;
    ClBase* parent_ptr;
    int x;
    cin >> parent_path;
    setName(parent_path);

    while(true){
        cin >> parent_path; // путь родителя // имя родителя
        if(parent_path=="endtree"){
            cout << "Object tree" << endl;
            showTree("");
            return true;
        }
        cin >> child_name >> x; // имя ребёнка и состояние ребёнка(то есть номер которого потом создадим)
        parent_ptr=findPath(parent_path); // находим указатель на родителя // путь на родителя
        if(!parent_ptr){
            cout << "Object tree" << endl;
            showTree("");
            cout << "\nThe head object " << parent_path << " is not found";
            return false;
        }
        switch(x){
            case 2:
                new Cl2(parent_ptr, child_name); // кладёт ребенка в родителя(вектор)
                break;
            case 3:
                new Cl3(parent_ptr, child_name);
                break;
            case 4:
                new Cl4(parent_ptr, child_name);
                break;
            case 5:
                new Cl5(parent_ptr, child_name);
                break;
            case 6:
                new Cl6(parent_ptr, child_name);
                break;
            default:
                new Cl1(parent_ptr, child_name);
        }
    }
};

int Cl_app::execute(){
    string command;
    while(true){
        cin >> command;
        if(command == "END") // закончить работу
            return 0;
        if(command == "EMIT"){ // для срабатывания связи // сигнал от объекта к объекту
            string path, text; // от кого и какое сообщение
            cin >> path; // вводим от кого
            getline(cin, text); // учитывает пробелы
            if(findPath(path)){
                ClBase* obj = findPath(path); // сохраняет указатель на объект который нашелся
                obj->emitSignal(obj->getSignalPtr(),text); // передаем и текст и указатель на сигнал объекта по этому пути
            }
            else
                cout << endl << "Object " << path << " not found";
            continue;
        }
        if(command == "SET_CONNECT"){ // добавление новой связи
            string pathFrom, pathTo;
            cin >> pathFrom >> pathTo;
            if(findPath(pathFrom)){
                if(findPath(pathTo)){
                    findPath(pathFrom)->setConnection(findPath(pathTo), findPath(pathFrom)->getSignalPtr(), findPath(pathFrom)->getHandlerPtr());
                }
                else
                    cout << endl << "Handler object " << pathTo << " not found";
            }
            else
                cout << endl << "Handler object " << pathFrom << " not found";
        }
        if(command == "DELETE_CONNECT"){ // удаляет связь
            string pathFrom, pathTo;
            cin >> pathFrom >> pathTo;
            if(findPath(pathFrom)){ // если есть от кого
                if(findPath(pathTo)){ // если есть к кому
                    // то удаляем
                    findPath(pathFrom)->deleteConnection(findPath(pathTo), findPath(pathFrom)->getSignalPtr(), findPath(pathFrom)->getHandlerPtr());
                }
                else
                    cout << endl << "Handler object " << pathTo << " not found"; // объект обработчика не найден
            }
            else
                cout << endl << "Handler object " << pathFrom << " not found";
        }
        if(command == "SET_CONDITION"){ // установить состоние объекту
            string path; // путь объкета
            cin >> path;
            int ready; // готовность
            cin >> ready;
            if(findPath(path))
                findPath(path)->setReady(ready);
            else
                cout << endl << "Object " << path << " not found";
        }
    }
    return 0;
}



/*
appls_root
/ object_s1 3
/ object_s2 2
/object_s2 object_s4 4
/ object_s13 5
/object_s2 object_s6 6
/object_s1 object_s7 2
endtree
/object_s2/object_s4 /object_s2/object_s6
/object_s2 /object_s1/object_s7
/ /object_s2/object_s4
/object_s2/object_s4 /
end_of_connections
EMIT /object_s2/object_s4 Send message 1
DELETE_CONNECT /object_s2/object_s4 /
EMIT /object_s2/object_s4 Send message 2
SET_CONDITION /object_s2/object_s4 0
EMIT /object_s2/object_s4 Send message 3
SET_CONNECT /object_s1 /object_s2/object_s6
EMIT /object_s1 Send message 4
END
 */