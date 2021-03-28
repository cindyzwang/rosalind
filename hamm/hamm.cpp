#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
  string dna1, dna2;
  ifstream dnas_file("rosalind/hamm/rosalind_hamm.txt");
  getline(dnas_file, dna1);
  getline(dnas_file, dna2);

  int diffs = 0;
  for (int i = 0; i < dna1.length(); i++) {
    if (dna1[i] != dna2[i]) {
      diffs += 1;
    }
  }

  cout << diffs << endl;
  return 0;
}