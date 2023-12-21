#ifndef _PROC_
#define _PROC_

#include <iostream>
#include "Queue.h"
class TProc {
private:
  double ProcRate; // ������������������ ����������
  int JobId; // Id ������������ �������
public:
  TProc(int Rate) : ProcRate(Rate), JobId(-1) {}
  int IsProcBusy(void) {
    return (JobId != -1); // �������� ��������� ����������
  }
  int RunNewJob(int newJobId) {
    if (!IsProcBusy()) {
      JobId = newJobId; // ���������� ������ ������� ��� ����������
      return 1; // �������� ���������� ������ �������
    }
    else {
      return 0; // ��������� �����, ����� ������� �� ���������
    }
  }
  void ProcessNextJob(void) {
    // ������ ��������� ���������� �������, ������� �������� ���������� �������� q2 ��� ���������� ��������� �������
    double threshold = 0.5; // ������ ���������� �������� q2 (����� ���� ������ ��� ��������� ��� ������������� ��������)
    if (rand() / static_cast<double>(RAND_MAX) < threshold) {
      // ��������� ���������� ������� ���������
      JobId = -1; // ������������ ���������� �� �������� �������
      // ����������� ������������ ���������� ������� �� ������� ��������
    }
  }
};
#endif