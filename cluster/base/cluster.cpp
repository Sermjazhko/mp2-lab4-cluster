#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cluster.h"
#include "actual_tasks.h"
#include "queue.h"
using namespace std;

void T_cluster::take_pr(int number)
{
  free_pr = free_pr - number;
}
int T_cluster::get_free_pr()
{
  return free_pr;
}
void T_cluster::cluster(int _time)
{
  T_queue<int> task(2000); //очередь процессоров
  T_queue<int> tact(2000);//очередь тактов (взаимно однозначно с очередью процессоров)
  T_actual_tasks cluster_tasks; //список выполняемых задач
  int probability = 0; // вероятность появления задачи
  int numb_proc_ts = 0;//количество проц. для задачи
  int time_ts = 0; //такты отдельной задачи
  int element, time_element; // вспомогательные переменные для количества процессоров и тактов
  int completed_tasks;// освободившиеся процессоры после выполнения задач на кластере

  while (time < _time) // цикл тактов
  {
    probability = rand() % 5; //добавление задачи (?) МОЖНО ДАВАТЬ ПОЛЬЗОВАТЕЛЮ ВОЗМОЖНОСТЬ МЕНЯТЬ КОЛИЧЕСТВО ЗАДАЧ И ВЕРОЯТНОСТЬ, но мне лень))
    if (probability > 0)
    {
      for (int k = 0; k < probability; k++) // создается столько задач за 1 такт ЗДЕСЬ МОЖНО УКАЗАТЬ, СКОЛЬКО ЗАДАЧ СОЗДАЕТСЯ ЗА ТАКТ
      {       
        numb_proc_ts = 1 + rand() % (number_pr);
        time_ts = 1 + rand() % (_time);
        if (task.empty() && numb_proc_ts <= free_pr)
        {
          take_pr(numb_proc_ts); //занять процессоры
          cluster_tasks.add_elem(time_ts, numb_proc_ts);//добавить в список
          number_ts++;//выполняющиеся задачи
        }
        else
        {
          task.push(numb_proc_ts); //в очередь
          tact.push(time_ts);
          for (int i = 0; i < task.get_size(); i++) //пробег по очереди
          {
            if (free_pr == 0) //если свободных процессоров  нет, выход
              break;
            element = task.pop();// забираем последний элемент очереди
            time_element = tact.pop();
            if (element <= free_pr) //если хватает процессоров, то на кластер
            {
              take_pr(element);
              cluster_tasks.add_elem(time_element, element);
              number_ts++;
            }
            else
            {
              task.push(element); //убираем в конец очереди
              tact.push(time_element);
            }
          }
        }
      }
    }
    // либо задача появилась, либо нет
    completed_tasks = cluster_tasks.check_and_delete(); //количество освободившихся процессоров, если не были заняты или всё ещё выполняются задачи, то вернет 0
    take_pr(-completed_tasks); // прибавляем освободившиеся процессоры
    time++;
  }
  //работа кластера закончилась
  statistics(cluster_tasks.get_size(), task.get_size()); //вызываем статистику, передаем, сколько задач осталось на кластере и в очереди
}
void T_cluster::statistics(int _number, int _size)
{
  double work = 0;
  work = number_ts;
  cout << "Общее время работы: " << time << endl;
  cout << "Всего создано задач: " << (number_ts + _size) << endl;
  cout << "В очереди: " << _size << endl;
  cout << "Осталось на кластере: " << _number << endl;
  cout << "Средняя загруженность кластера: " << work / time << endl;
}
