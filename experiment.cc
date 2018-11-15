///////////////////////////////////////////////////////////////////////////////////
////// experiment.cc
//////
////// Example code showing how to run an algorithm once and measure its elapsed
////// time precisely. You should modify this program to gather all of your
////// experimental data.
//////
///////////////////////////////////////////////////////////////////////////////////
////
#include <iostream>

#include "project2.hh"
#include "timer.hh"

using namespace std;

int main() {

  int n = 100000;

  string_vector all_words;
  if ( ! load_words(all_words, "words.txt") ) {
    cerr << "error: cannot open \"words.txt\"" << endl;
    return 1;
  }
  

  //test mergesort
  for (int i = 0; i < 20; i++) {
		  string_vector n_words(all_words.begin(), all_words.begin() + n);
		  randomize_list(n_words);

		  Timer timer;
		  mergesort(n_words);
		  double elapsed = timer.elapsed();

		  cout << elapsed << endl;
  }

  cout << endl;
  
  //test quicksort
  for (int i = 0; i < 20; i++)  {
		  string_vector n_words(all_words.begin(), all_words.begin() + n);
		  randomize_list(n_words);

		  Timer timer;
		  quicksort(n_words);
		  double elapsed = timer.elapsed();

		  cout << elapsed << endl;
  }

  return 0;
}
