#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "date.h"
#include "common.h"

struct date {
  int day;
  int month;
  int year;
};

Date createDate(int day, int month, int year) {
    Date d = malloc(sizeof(struct date));
    d->day = day;
    d->month = month;
    d->year = year;
    return d;
}

int get_day(Date d) {
    return d->day; 
}

int get_month(Date d) {
    return d->month; //change to enum? (Acho que sim. Desta forma já garantimos a limitação necessária)
}

int get_year(Date d) {
    return d->year;
}

char* dateConvert(Date d){
  char strAno[10];
  char strMes[10];
  char strDia[10];

  sprintf(strAno, "%d-", d->year);

  if (d->month <= 9) sprintf(strMes, "0%d-", d->month);
  else sprintf(strMes, "%d-", d->month);

  if(d->day > 9) sprintf(strDia, "%d", d->day);
  else sprintf(strDia, "0%d", d->day);

  strcat(strMes, strDia);

  return (mystrdup(strcat(strAno, strMes)));
}


void free_date(Date d) {
    free(d);
}

