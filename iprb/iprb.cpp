#include <time.h>
#include <utility>
#include <iostream>
#include <cstdlib>
using namespace std;

// these names are horrible
bool offspring_will_have_dominant_phenotype(int, int, int);
bool will_get_dominant_allele(int, int, int);

int main() {
  int k = 24;  // homozygous dominant
  int m = 29;  // heterozygous
  int n = 18;  // homozygous recessive

  srand(time(0));

  int trials = 10000;
  int dominant_phenotype_counts = 0;
  for (int i = 0; i < trials; i++) {
    int j = offspring_will_have_dominant_phenotype(k, m, n);
    dominant_phenotype_counts += j;
  }

  cout << float(dominant_phenotype_counts) / trials << endl;
  return 0;
}

bool offspring_will_have_dominant_phenotype(int n_homozygous_dominant, int n_heterozygous, int n_homozygous_recessive) {
  int total = n_homozygous_dominant + n_heterozygous + n_homozygous_recessive;
  int person1 = rand() % total;
  int person2 = rand() % (total - 1);
  if (person2 >= person1) person2++;

  bool allele1 = will_get_dominant_allele(person1, n_homozygous_dominant, n_heterozygous);
  bool allele2 = will_get_dominant_allele(person2, n_homozygous_dominant, n_heterozygous);

  // cout << "person1 " << person1 << ", allele " << allele1;
  // cout << "\tperson2 " << person2 << ", allele " << allele2 << endl;

  return allele1 || allele2;
}

bool will_get_dominant_allele(int person, int n_homozygous_dominant, int n_heterozygous) {
  // dominant is 1, recessive is 0
  if (person < n_homozygous_dominant) return 1;
  if (person < n_homozygous_dominant + n_heterozygous) {
    return rand() % 2;
  }
  return 0;
}
