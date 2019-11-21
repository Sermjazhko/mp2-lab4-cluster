#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cluster.h"
#include "actual_tasks.h"
using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian");
  srand(time(NULL));

  int size;
  int time;
  cout << "Количество процессоров: " << endl;
  cin >> size;
  T_cluster check(size);
  cout << "Количество тактов: " << endl;
  cin >> time;
  check.cluster(time);
  return 0;
}
