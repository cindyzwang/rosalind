#include <fstream>
#include <string>
#include <iostream>

using namespace std;

char get_complement(char c);

int main() {
  string dna;
  ifstream dna_file("rosalind/revc/rosalind_revc.txt");

  if (dna_file.is_open()) {
    getline(dna_file, dna);
    for (string::reverse_iterator rit = dna.rbegin(); rit != dna.rend(); ++rit) {
      cout << get_complement(*rit);
    }
  }

  return 0;
}

char get_complement(char c) {
  switch(c) {
    case 'A': return 'T';
    case 'T': return 'A';
    case 'C': return 'G';
    case 'G': return 'C';
    default: return ' ';
  }
}