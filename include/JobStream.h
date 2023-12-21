#ifndef _JOB_
#define _JOB_

#include <iostream>
#include "Queue.h"
using namespace std;
class TJobStream
{
private:
  double JobInt�ns; // ������������� ������ �����
public:
  TJobStream(int Int�ns) : JobInt�ns(Int�ns)
  {
    srand(static_cast<unsigned>(time(0))); // ������������� ���������� ��������� �����
  }
  int GetNewJob(void)
  {
    // ������ ��������� ������ ������� � ������������ � ��������� ��������� q1
    double threshold = 0.3; // ������ ���������� �������� q1 (����� ���� ������ ��� ��������� ��� ������������� ��������)
    if (rand() / static_cast<double>(RAND_MAX) < threshold)
    {
      static int currentJobId = 0; // ����������� ���������� ��� �������� �������� �������������� �������
      currentJobId++; // ����������� ������������� ������� �� 1
      return currentJobId; // ���������� ����� ������������� ��� �������
    }
    else
    {
      return 0; // ����� ������� �� ������ 
    }
  }
};
#endif