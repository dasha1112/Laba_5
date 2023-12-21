#include "JobStream.h"
#include "Proc.h"
#include "gtests.h"
TEST(TJobStreamTest, NewJobGeneration) 
{
  TJobStream jobStream(0.3); // Инициализация объекта TJobStream с интенсивностью потока 0.3
  int previousJobId = 0;
  for (int i = 0; i < 100; ++i) 
  { 
    int newJobId = jobStream.GetNewJob();
    if (newJobId != 0) {
      ASSERT_EQ(newJobId, previousJobId + 1); 
      previousJobId = newJobId; 
    }
  }
}
TEST(TJobStreamTest, NewJobGeneratedWhenThresholdMet) {
  TJobStream jobStream(0.5);
  bool jobGenerated = false;
  for (int i = 0; i < 100; ++i) {
    int newJobId = jobStream.GetNewJob();
    if (newJobId != 0) {
      jobGenerated = true;
      break;
    }
  }
  ASSERT_TRUE(jobGenerated);
}

TEST(TProcTest, ProcessorNotBusyInitially) 
{
  TProc processor(2.0);
  ASSERT_FALSE(processor.IsProcBusy());
}

TEST(TProcTest, NewJobRunWhenProcessorFree) //для проверки успешного выполнения нового задания, когда процессор свободен
{
  TProc processor(2.0);
  ASSERT_EQ(processor.RunNewJob(1), 1);
  ASSERT_TRUE(processor.IsProcBusy());
}

