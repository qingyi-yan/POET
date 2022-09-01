#ifndef TATAS_H
#define TATAS_H
#include <atomic>
#include <iostream>


class TATAS {
    std::atomic<bool> state;

    public:
        TATAS();
        void lock();
        void unlock();
    protected:
    private:
};

class AcquireLock
{
  TATAS *obj;
 public:
  AcquireLock(TATAS& _obj) : obj(&_obj) { obj->lock(); /*std::cerr << "lock\n";*/ }
  AcquireLock(TATAS* _obj) : obj(_obj) { if (obj != 0) obj->lock(); /*std::cerr << "lock\n";*/ }
  AcquireLock() : obj(0) {}
  ~AcquireLock() { /*std::cerr << "unlock\n";*/ if (obj != 0) { obj->unlock(); obj = 0; } } 
  void unlock() { if (obj != 0) { obj->unlock(); obj = 0; } }
  void lock(TATAS* _obj) { if (obj != 0) { obj->unlock(); obj=0; } obj = _obj; }
  void lock(TATAS& _obj) { if (obj != 0) { obj->unlock(); obj=0; } obj = &_obj; }
};

#endif // TATAS_H
