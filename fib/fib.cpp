#include <iostream>
#include <math.h>
using namespace std;

long int procreate(int, int);

int main() {
  int months = 28;
  int pairs_per_litter = 5;

  cout << procreate(months, pairs_per_litter);

  return 0;
}

long int procreate(int month, int pairs_per_litter) {
  if (month == 0) return 0;
  if (month == 1) return 1;
  return (
    procreate(month - 1, pairs_per_litter) + (procreate(month - 2, pairs_per_litter) * pairs_per_litter)
  );
}
