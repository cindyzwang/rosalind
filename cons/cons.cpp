#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// g++ --std=c++2a cons/cons.cpp -o cons.out

char get_consensus_char(unordered_map<char, int> char_counts);

int main() {
  // Sample data implies that each dna string is one line
  // real data has multiline DNA
  ifstream fasta_file("cons/rosalind_cons.txt");
  string line;
  string consensus_dna;

  vector<string> dnas;
  dnas.reserve(10);

  if (fasta_file.is_open()) {
    while(getline(fasta_file, line, '>')) {
      // remove label (first line)
      line.erase(
        find(line.begin(), line.end(), 'R'),
        find(line.begin(), line.end(), '\n')
      );
      // remove every newline in the dna string
      line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());

      if (line.length()) {
        dnas.push_back(line);
      }
    }
  }

  int n_dnas = dnas.size();

  vector<short unsigned int> a_counts;
  vector<short unsigned int> c_counts;
  vector<short unsigned int> t_counts;
  vector<short unsigned int> g_counts;  
  a_counts.reserve(line.length());
  c_counts.reserve(line.length());
  t_counts.reserve(line.length());
  g_counts.reserve(line.length());

  for (int i_char = 0; i_char < line.length(); i_char++) {
    unordered_map<char, int> nucleotide_count = {
      {'A', 0},
      {'C', 0},
      {'T', 0},
      {'G', 0},
    };

    for (int i_dna = 0; i_dna < n_dnas; i_dna++) {
      char nucleotide = dnas.at(i_dna)[i_char];
      nucleotide_count[nucleotide] += 1;
    }

    a_counts.push_back(nucleotide_count['A']);
    c_counts.push_back(nucleotide_count['C']);
    t_counts.push_back(nucleotide_count['T']);
    g_counts.push_back(nucleotide_count['G']);

    char consensus_char = get_consensus_char(nucleotide_count);
    consensus_dna += consensus_char;
  }

  cout << consensus_dna << endl;

  cout << "A:";
  for (int count : a_counts) {
    cout << ' ' << count;
  }
  cout << endl;

  cout << "C:";
  for (int count : c_counts) {
    cout << ' ' << count;
  }
  cout << endl;

  cout << "G:";
  for (int count : g_counts) {
    cout << ' ' << count;
  }
  cout << endl;

  cout << "T:";
  for (int count : t_counts) {
    cout << ' ' << count;
  }
  cout << endl;

  return 0;
}

char get_consensus_char(unordered_map<char, int> char_count) {
  char consensus_char;
  for (auto i : char_count) {
    if (i.second > char_count[consensus_char]) {
      consensus_char = i.first;
    }
  }
  return consensus_char;
}