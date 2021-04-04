#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string dna;
  string substring;
  fstream input_file("subs/rosalind_subs.txt");
  if (input_file.is_open()) {
    getline(input_file, dna);
    getline(input_file, substring);
  }

  int substring_length = substring.length();
  for (int i = 0; i < dna.length(); i++) {
    if (dna.substr(i, substring_length) == substring) {
      cout << i + 1 << ' ';
    }
  }

  return 0;
}