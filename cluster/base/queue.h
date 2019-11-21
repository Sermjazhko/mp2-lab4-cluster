#ifndef __QUEUE_H__
#define __QUEUE_H__

const int max_queue_size = 10000;

template <class T>
class T_queue
{
  T *pMem;
  int size;
  int top;
  int queue_size;
public:
  T_queue(int _size = 1)
  {
    queue_size = 0;
    size = _size;
    top = -1;
    if ((size < 1) || (size > max_queue_size))
      throw "size";
    pMem = new T[size];
  }
  ~T_queue()
  {
    delete[] pMem;
  }
  void push(T element)
  {
    if (full())
      throw "full";
    top = (top + 1) % size;
    pMem[top] = element;
    queue_size++;
  }
  T pop()
  {
    if (empty())
      throw "empty";
    queue_size--;
    return pMem[(size + top - queue_size) % size];
  }
  bool empty()
  {
    return queue_size == 0;
  }
  bool full()
  {
    return queue_size == size;
  }
  T get_size()
  {
    return queue_size;
  }
};

#endif