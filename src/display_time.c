#include <time.h>
#include "my_ls.h"

#define HOURSMINUTES_OFFSET 11
#define HOURSMINUTES_LENGTH 5
#define DAY_OFFSET 8
#define DAY_LENGTH 3
#define MONTH_OFFSET 4
#define MONTH_LENGTH 4
#define YEAR_OFFSET 20
#define YEAR_LENGTH 4

void printt_month(char *f)
{
  my_putstrn(f + MONTH_OFFSET, MONTH_LENGTH);
}

void printt_day(char *f)
{
  my_putstrn(f + DAY_OFFSET, DAY_LENGTH);
}

void printt_hoursminutes(char *f)
{
  my_putstrn(f + HOURSMINUTES_OFFSET, HOURSMINUTES_LENGTH);
}

void printt_year(char *f)
{
  my_putchar(' ');
  my_putstrn(f + YEAR_OFFSET, YEAR_LENGTH);
}

#define SAME_YEAR(c1, c2) \
  ((!my_strncmp((c1) + YEAR_OFFSET, (c2) + YEAR_OFFSET, YEAR_LENGTH)))

void printt_last_segment(char *f)
{
  time_t now;
  char   *fnow;

  now = time(NULL);
  fnow = ctime(&now);
  if (SAME_YEAR(f, fnow))
    printt_hoursminutes(f);
  else
    printt_year(f);
}

void print_time(time_t t)
{
  char *f;

  f = my_strnew(ctime(&t));
  printt_month(f);
  printt_day(f);
  printt_last_segment(f);
  free(f);
}
