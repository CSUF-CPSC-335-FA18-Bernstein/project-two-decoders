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

  string_vector all_words;
  if ( ! load_words(all_words, "words.txt") ) {
    cerr << "error: cannot open \"words.txt\"" << endl;
    return 1;
  }

  int n = 1000;
  string_vector n_words(all_words.begin(), all_words.begin() + n);

  randomize_list(n_words);

  Timer timer;

  //create another unsorted list to be used with quicksort
  string_vector n_words2 = n_words;

  
  //test mergesort
  mergesort(n_words);
  
  double elapsed = timer.elapsed();
  cout << "mergesort, "
       << "n=" << n << ", "
       << "elapsed time = " << elapsed << " seconds" << endl;
  
  //test quicksort
  quicksort(n_words2);

  double elapsed2 = timer.elapsed();
  cout << "quicksort, "
       << "n=" << n << ", "
       << "elapsed time = " << elapsed2 << " seconds" << endl << endl;
         
  return 0;
}