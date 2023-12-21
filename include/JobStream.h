#ifndef _JOB_
#define _JOB_

#include <iostream>
#include "Queue.h"
using namespace std;
class TJobStream
{
private:
  double JobIntеns; // интенсивность потока задач
public:
  TJobStream(int Intеns) : JobIntеns(Intеns)
  {
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел
  }
  int GetNewJob(void)
  {
    // Логика генерации нового задания в соответствии с пороговым значением q1
    double threshold = 0.3; // Пример порогового значения q1 (может быть задано как константа или настраиваемый параметр)
    if (rand() / static_cast<double>(RAND_MAX) < threshold)
    {
      static int currentJobId = 0; // Статическая переменная для хранения текущего идентификатора задания
      currentJobId++; // Увеличиваем идентификатор задания на 1
      return currentJobId; // Возвращаем новый идентификатор для задания
    }
    else
    {
      return 0; // Новое задание не поступ 
    }
  }
};
#endif