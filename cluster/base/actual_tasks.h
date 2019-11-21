#ifndef __TASK_H__
#define __TASK_H__
#include <iostream>
using namespace std;

struct link
{
  int processors;
  int data;
  link *pNext;
};
class T_actual_tasks
{
  link *pFirst;
  int size;
public:
  T_actual_tasks()
  {
    pFirst = nullptr;
    size = 0;
  }
  bool empty()
  {
    return pFirst == nullptr;
  }
  void add_elem(int val, int num) // такты, количество процессоров
  {
    if (val != 0 && num!=0)
    {
      link *p = new link;
      p->pNext = nullptr;
      p->data = val;
      p->processors = num;
      if (empty())
        pFirst = p;
      else
      {
        link *pp = pFirst;
        while (pp->pNext != nullptr)
        {
          pp = pp->pNext;
        }
        pp->pNext = p;
      }
      size++;
    }
  }
  
  int check_and_delete() //удалять элемент с 0 значением (0 тактов)
  {
    int point = 0;
    link *p = pFirst;
    link *pp = pFirst;
    if (!empty())
    {
      while (p->pNext != nullptr)
      {
        pp = p; 
        p->data = p->data - 1;
        p = p->pNext;
      }
      p->data = p->data - 1;      
      p = pFirst;
      while (p->pNext != nullptr) // удаление из списка
      {
        if (p->data == 0)
        {
          if (p == pFirst) // первый элемент
          {
            pFirst = p->pNext;
            point = point + p->processors;
            delete p;
            p = pFirst;
            size--;
          }
          else
          {
            point = point + p->processors;
            link *help = pFirst;
            while (help->pNext != p)
              help = help->pNext;
            help->pNext = p->pNext;
            delete p;
            p = help;
            size--;
          }
        }
        if(p->pNext!= nullptr) // если последний остался
          p = p->pNext;
      }
      if (p->data == 0)
      {
        if (size == 1) //единственный элемент
        {
          point = point + p->processors;
          delete p;
          pFirst = nullptr;
          size--;
        }
        else //конец
        {
          point = point + p->processors;
          link *help = pFirst;
          while (help->pNext != p)
            help = help->pNext;
          delete p;
          size--;
          help->pNext = nullptr;
          p = help;
        }
      }
    }
    cout <<"Point " <<  point  << endl;
    return point;
  }
  void enter()
  {
    link *p = pFirst;
    cout << "Список: " << endl;
    while (p != nullptr)
    {
      cout << p->data << " ";
      p = p->pNext;
    }
  }
  int get_size()
  {
    return size;
  }
  ~T_actual_tasks()
  {
    while (pFirst != nullptr)
    {
      link *p = pFirst;
      pFirst = p->pNext;
      delete p;
    }
  }

};
#endif