#ifndef _PROC_
#define _PROC_

#include <iostream>
#include "Queue.h"
class TProc {
private:
  double ProcRate; // производительность процессора
  int JobId; // Id выполн€емого задани€
public:
  TProc(int Rate) : ProcRate(Rate), JobId(-1) {}
  int IsProcBusy(void) {
    return (JobId != -1); // ѕроверка зан€тости процессора
  }
  int RunNewJob(int newJobId) {
    if (!IsProcBusy()) {
      JobId = newJobId; // ѕрисвоение нового задани€ дл€ выполнени€
      return 1; // ”спешное выполнение нового задани€
    }
    else {
      return 0; // ѕроцессор зан€т, новое задание не выполнено
    }
  }
  void ProcessNextJob(void) {
    // Ћогика обработки следующего задани€, включа€ проверку порогового значени€ q2 дл€ завершени€ обработки задани€
    double threshold = 0.5; // ѕример порогового значени€ q2 (может быть задано как константа или настраиваемый параметр)
    if (rand() / static_cast<double>(RAND_MAX) < threshold) {
      // ќбработка очередного задани€ завершена
      JobId = -1; // ќсвобождение процессора от текущего задани€
      // ѕродолжение обслуживани€ следующего задани€ из очереди ожидани€
    }
  }
};
#endif