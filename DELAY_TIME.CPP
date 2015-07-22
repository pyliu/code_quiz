#include <time.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void delay(float secs)
{
  clock_t end;
  end = (int) (secs * CLOCKS_PER_SEC) + clock();
  while (clock() < end)
    ;
}
int main(int argc, char *argv[])
{
  cout << "Count down :" << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << 10 - i <<endl;
    delay(1.0);
  }
  cout << 0 << endl;
  cout << "Totaltime is " << clock() / CLOCKS_PER_SEC << " secs!" << endl;
  system("PAUSE");
  return 0;
}
