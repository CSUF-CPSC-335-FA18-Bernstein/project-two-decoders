///////////////////////////////////////////////////////////////////////////////
// project2.hh
//
// The three algorithms specified in the project 1 requirements
// document, plus helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#include "project2.hh"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


//-----------------------------------------------------------------------------
// Randomize the order of all items in the list
//-----------------------------------------------------------------------------
void randomize_list(string_vector & strings) {
	//Don't know if size_t random value goes inside or outside the for-loop
	//In Berstein's powerpoint slide, it shows it inside, but wouldn't that
	//loop forever?

	std::srand(std::time(nullptr));		//use current time as seed for random generator
	//size_t random_value = std::rand();
	//std::cout << "Random value on [0 " << RAND_MAX << "]: " << random_value << '\n';

	for (size_t i = 0; i < strings.size(); i++) {
		size_t random_value = std::rand();
		std::cout << "Random value on [0 " << RAND_MAX << "]: " << random_value << '\n';
		std::swap(strings[i], strings[random_value]);
	}
  return;
}

//-----------------------------------------------------------------------------
void merge(string_vector & strings, size_t start, size_t mid, size_t end) {
  // TODO: implement this function, then delete this comment

  return;
}

//-----------------------------------------------------------------------------
// Sort the given list using the merge sort algorithm.
// This is a recursive method which splits the list into two
// parts, recursively calls itself on the two parts and then merges 
// the two parts together using the merge() method.
//-----------------------------------------------------------------------------
void mergesort(string_vector & strings, size_t start, size_t end) {
  // TODO: implement this function, then delete this comment
  return;
}

//-----------------------------------------------------------------------------
// Implementation of the Hoare Partition.
// This partition uses the first element of the list as a partition
// and divides the list into less than and greater than the pivot value
// It returns the index of the final position of the pivot value.
//-----------------------------------------------------------------------------
int hoare_partition(string_vector & strings, int start, int end) {
  // TODO: implement this function, then delete this comment
  return 0;
}

//-----------------------------------------------------------------------------
// Sort the given list using the quicksort algorithm.
// This is a recursive method which splits the list into two
// parts, recursively calls itself on the two parts and then merges 
// the two parts together using the merge() method.
//-----------------------------------------------------------------------------
void quicksort(string_vector & strings, int start, int end) {
	//needs hoare_partition in order to work

	/*if (start < end)
	{
		int split_point = hoare_partition(strings, start, end);
		quicksort(strings, start, split_point - 1);
		quicksort(strings, split_point + 1, end);
	}*/

  return;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// ALREADY IMPLEMENTED 
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Load words from the file at the given path. The words vector is
// cleared, and then each word from the file is added to the
// vector. Returns true on success or fale on I/O error.
//-----------------------------------------------------------------------------
bool load_words(string_vector& words, const std::string& path) 
{
  std::cout << "Loading words from [" << path << "]" << std::endl;		//doesn't work w/o #include<iostream>
  words.clear();
  std::ifstream ifs(path.c_str());
  if (!ifs.is_open() || !ifs.good()) {
    cout << "Failed to open [" << path << "]" << std::endl;
    return false;
  }
  int countWordsLoaded = 0;
  while (!ifs.eof()) {
    std::string lineBuffer;
    std::getline(ifs, lineBuffer);
    if (ifs.eof()) {
      break;
    }
    words.push_back(lineBuffer);
    countWordsLoaded++;
  }
  std::cout << "Loaded " << countWordsLoaded << " words from [" << path << "]" << std::endl;;
  
  //randomize_list(words);				//output check to see if function works
  return true;
}

//-----------------------------------------------------------------------------
// Sort the given list using the merge sort algorithm.
// This method is simply a helper to make the initial 
// call the recursive mergesort() method below that requires
// first and last indexes for sorting range
//-----------------------------------------------------------------------------
void mergesort(string_vector & strings) {
  if (strings.size() == 0) {
    return;
  }
  mergesort(strings, 0, strings.size() - 1);
  return;
}

//-----------------------------------------------------------------------------
// Sort the given list using the quicksort algorithm.
// This method is simply a helper to make the initial 
// call the recursive mergesort() method below that requires
// first and last indexes for sorting range
//-----------------------------------------------------------------------------
void quicksort(string_vector & strings) {
  if (strings.size() == 0) {
    return;
  }
  quicksort(strings, 0, strings.size() - 1);
  return;
}

