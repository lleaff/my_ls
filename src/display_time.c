#include <time.h>
#include "my_ls.h"

void printt_month(char *f)
{
  my_putstrn(f + 4, 4);
}

void printt_day(char *f)
{
  my_putstrn(f + 8, 3);
}

void printt_hoursminutes(char *f)
{
  my_putstrn(f + 11, 5);
}

void print_time(time_t t)
{
  char *f;

  f = ctime(&t);
  printt_month(f);
  printt_day(f);
  printt_hoursminutes(f);
}
