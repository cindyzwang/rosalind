#include <fstream>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

float get_gc_content(const string&);

int main() {
  ifstream fasta_file("rosalind/gc/rosalind_gc.txt");
  unordered_map<string, float> gc_contents;

  if (fasta_file.is_open()) {
    string label;
    string dna;
    while (getline(fasta_file, label) && getline(fasta_file, dna, '>')) {
      float gc_content = get_gc_content(dna);
      gc_contents.insert({label, gc_content});
    }
  }

  // // Another way to iterate
  // for (pair<string, float> element : gc_contents) {
  //   cout << element.first << ": " << element.second << endl;
  // }

  string max_label;
  float max_gc_content = 0;
  for (unordered_map<string, float>::iterator it = gc_contents.begin(); it != gc_contents.end(); it++) {
    if (it->second > max_gc_content) {
      max_label = it->first;
      max_gc_content = it->second;
    }
  }

  cout << max_label << endl;
  cout << max_gc_content;

  return 0;
}

float get_gc_content(const string& dna) {
  int gc = 0;
  int total = 0;

  for (const char nucleotide : dna) {
    if (nucleotide == 'G' || nucleotide == 'C') {
      gc += 1;
    }

    if (nucleotide != '\n') {
      total += 1;
    }
  }

  return float(gc) / total * 100;
}