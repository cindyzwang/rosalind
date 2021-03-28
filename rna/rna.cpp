// g++ --std=c++17 rosalind/rna/rna.cpp -o rna.out
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  string rna;
  ifstream dna_file("rosalind/rna/rosalind_rna.txt");
  if (dna_file.is_open()) {
    getline(dna_file, rna);

    for (char &c : rna) {
      if (c == 'T') {
        c = 'U';
      }
    }
  }
  cout << rna;
  return 0;
}