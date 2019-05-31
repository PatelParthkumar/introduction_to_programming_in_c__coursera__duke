#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double calcBalance(int start_age, double initial, retire_info retinf) {
  /*
  print and update the balance
  */
  double balance = initial;
  for (int mth = start_age; mth < start_age + retinf.months; mth++) {
    int years = mth/12;
    int imth = mth%years;
    printf("Age %3d month %2d you have $%.2f\n", years, imth, balance);

    balance = balance*(1.0 + retinf.rate_of_return) + retinf.contribution;
  }  // for: all working months

  return balance;
}  // fcn: balcBalance

void retirement(int startAge,  // in months
		double initial,  // initial savings in dollars
		retire_info working,  // info about working
		retire_info retired) {  // info about being retired

  // add stuff to the balance
  double balance = calcBalance(startAge, initial, working);
  balance = calcBalance(startAge + working.months, balance, retired);
}  // fcn: retirement

int main() {

  double initial = 21345.0;
  int start_age = 327;
  
  retire_info working = {
    .months = 489,
    .contribution = 1000.0,
    .rate_of_return = 0.045/12.0
  };
  retire_info retired = {
    .months = 384,
    .contribution = -4000.0,
    .rate_of_return = 0.01/12.0
  };

  retirement(start_age, initial, working, retired);

  return EXIT_SUCCESS;

}  // fcn: main
