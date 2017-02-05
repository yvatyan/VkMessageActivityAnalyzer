#ifndef THREADTASKS_H
#define THREADTASKS_H

#include <QRunnable>

namespace ThreadTasks {
    template <class objType, typename retType>
    class NoArgsObjMethod : public QRunnable {
        private:
            objType* object;
            retType (objType::*method)();
        public:
            NoArgsObjMethod(objType* obj, retType (objType::*proc)())
                : object(obj)
                , method(proc) {}
            void run() {
                (object->*method) ();
            }
    };
    template <class objType, typename retType, typename arg1Type>
    class OneArgObjMethod : public QRunnable {
        private:
            objType* object;
            retType (objType::*method)();
            arg1Type argument1;
        public:
            OneArgObjMethod(objType* obj, retType (objType::*proc)(), arg1Type arg1)
                : object(obj)
                , method(proc)
                , argument1(arg1) {}
            void run() {
                (object->*method) (argument1);
            }
    };
    template <class objType, typename retType, typename arg1Type, typename arg2Type>
    class TwoArgsObjMethod : public QRunnable {
        private:
            objType* object;
            retType (objType::*method)();
            arg1Type argument1;
            arg2Type argument2;
        public:
            TwoArgsObjMethod(objType* obj, retType (objType::*proc)(), arg1Type arg1, arg2Type arg2)
                : object(obj)
                , method(proc)
                , argument1(arg1)
                , argument2(arg2) {}
            void run() {
                (object->*method) (argument1, argument2);
            }
    };
}

#endif // THREADTASKS_H
