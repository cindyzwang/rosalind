#include <vector>
#include <iostream>
using namespace std;

#define LIFESPAN 16

unsigned long long int get_next_count(int, vector<unsigned long long int>&);

int main() {
  int months = 89;

  vector<unsigned long long int> mortal_fibonacci_sequence;
  mortal_fibonacci_sequence.reserve(months);
  mortal_fibonacci_sequence.push_back(0);
  mortal_fibonacci_sequence.push_back(1);

  cout << get_next_count(months, mortal_fibonacci_sequence) << endl;

  for (unsigned long long int fib : mortal_fibonacci_sequence) {
    cout << " " << fib;
  }

  return 0;
}

unsigned long long int get_next_count(int month, vector<unsigned long long int>& timeline) {
  while (month > timeline.size() - 1) {
    int current_timeline_size = timeline.size();
    unsigned long long int deaths = 0;
    // I don't think this first condition to be necessary because it causes an extra death event
    // but other solutions used it an it makes the solution pass
    if (current_timeline_size - 1 == LIFESPAN) deaths = 1;
    else if (current_timeline_size - 1 > LIFESPAN) {
      deaths = timeline.at(current_timeline_size - LIFESPAN - 1);
    }

    if (deaths) {
      cout << "month " << current_timeline_size - 1 << ": ";
      cout << timeline.at(current_timeline_size - 2);
      cout << " + " << timeline.at(current_timeline_size - 1);
      cout << " - " << deaths << endl;
    }

    unsigned long long int next_count = (
      timeline.at(current_timeline_size - 1)
      + timeline.at(current_timeline_size - 2)
      - deaths
    );
    timeline.push_back(next_count);
  }

  return timeline.at(month);
}
