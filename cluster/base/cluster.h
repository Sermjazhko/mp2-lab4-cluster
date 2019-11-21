#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "actual_tasks.h"
#include "queue.h"

using namespace std;
const int max_size = 10000;

class T_cluster
{
  int number_pr;
  int free_pr;
  int time;
  int number_ts;
public:
  T_cluster(int number = 1)
  {
    if ((number < 1) || (number > max_size))
      throw "size";
    number_pr = number;
    free_pr = number;
    time = 0;
    number_ts = 0;
  }
  void take_pr(int number);//использовать несколько процессоров
  int get_free_pr();
  void cluster(int _time);//выполнение задач на кластере
  void statistics(int _number, int _size); //статистика
};

#endif
