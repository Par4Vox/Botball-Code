#include <stdio.h>
#include <kipr/wombat.h> // Simulation
#include <unistd.h> // Adds a sleep function
#include <time.h> // Adds Timer functions

// Variables

// Struct
struct Settings
{
  // Motors
  int M1;
  int M2;
  // Servos
};

struct Settings Settings1;

// Functions

void motors(int A, int B)
{
  motor(Settings1.M1, A);
  motor(Settings1.M2, B);
}

void assignStruct()
{
  Settings1.M1 = 0;
  Settings1.M2 = 3;
  
  printf("%d\n", Settings1.M1);
  printf("%d\n", Settings1.M2);
}


void LineFollow(int timeinput)
{
  time_t endwait;
  time_t start = time(NULL);
  time_t seconds = timeinput; // end loop after this time has elapsed
  endwait = start + seconds;
  while (start < endwait)
  {
    start = time(NULL);
    if (analog(1) > 1000)
    {
      motors(0, 100);
    }
    else
    {
      motors(100, 0);
    }
  }
  printf("Ended loop\n");
}

// Execute Code
int main(void)
{
  assignStruct();
  LineFollow(10);
  return 0;
}




