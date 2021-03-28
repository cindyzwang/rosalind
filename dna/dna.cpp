#include <fstream>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// g++ --std=c++11 rosalind/dna/dna.cpp -o dna.out

int main() {
  string dna;

  unordered_map<char, int> counts = {
    {'A', 0},
    {'C', 0},
    {'G', 0},
    {'T', 0}
  };

  ifstream dna_file("rosalind/dna/rosalind_dna.txt");
  if (dna_file.is_open()) {
    getline(dna_file, dna);
    for (char& c: dna) {
        counts[c] += 1;
    }
  } else {
    cout << "Check file path";
  }

  dna_file.close();

  cout << counts['A'] << ' ' << counts['C'] << ' ' << counts['G'] << ' ' << counts['T'] << endl;
  return 0;
}