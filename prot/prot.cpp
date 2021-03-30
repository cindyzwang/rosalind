#include <string>
#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

char get_amino_acid(string codon);

static const unordered_map<string, char> codon_table = {
  {"UUU", 'F'},
  {"CUU", 'L'},
  {"AUU", 'I'},
  {"GUU", 'V'},
  {"UUC", 'F'},
  {"CUC", 'L'},
  {"AUC", 'I'},
  {"GUC", 'V'},
  {"UUA", 'L'},
  {"CUA", 'L'},
  {"AUA", 'I'},
  {"GUA", 'V'},
  {"UUG", 'L'},
  {"CUG", 'L'},
  {"AUG", 'M'},
  {"GUG", 'V'},
  {"UCU", 'S'},
  {"CCU", 'P'},
  {"ACU", 'T'},
  {"GCU", 'A'},
  {"UCC", 'S'},
  {"CCC", 'P'},
  {"ACC", 'T'},
  {"GCC", 'A'},
  {"UCA", 'S'},
  {"CCA", 'P'},
  {"ACA", 'T'},
  {"GCA", 'A'},
  {"UCG", 'S'},
  {"CCG", 'P'},
  {"ACG", 'T'},
  {"GCG", 'A'},
  {"UAU", 'Y'},
  {"CAU", 'H'},
  {"AAU", 'N'},
  {"GAU", 'D'},
  {"UAC", 'Y'},
  {"CAC", 'H'},
  {"AAC", 'N'},
  {"GAC", 'D'},
  {"UAA", '\n'},
  {"CAA", 'Q'},
  {"AAA", 'K'},
  {"GAA", 'E'},
  {"UAG", '\n'},
  {"CAG", 'Q'},
  {"AAG", 'K'},
  {"GAG", 'E'},
  {"UGU", 'C'},
  {"CGU", 'R'},
  {"AGU", 'S'},
  {"GGU", 'G'},
  {"UGC", 'C'},
  {"CGC", 'R'},
  {"AGC", 'S'},
  {"GGC", 'G'},
  {"UGA", '\n'},
  {"CGA", 'R'},
  {"AGA", 'R'},
  {"GGA", 'G'},
  {"UGG", 'W'},
  {"CGG", 'R'},
  {"AGG", 'R'},
  {"GGG", 'G'}, 
};

int main() {
  string dna;
  string protein;

  ifstream dna_file("prot/rosalind_prot.txt");
  if (dna_file.is_open()) {
    getline(dna_file, dna);
    for (int i = 0; i < dna.length(); i += 3) {
      protein += get_amino_acid(dna.substr(i, 3));
    }

    cout << protein;
  }
  return 0;
}

char get_amino_acid(const string codon) {
  return codon_table.at(codon);
}