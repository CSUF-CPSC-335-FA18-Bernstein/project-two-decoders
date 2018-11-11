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
	
	std::srand(std::time(nullptr));		//use current time as seed for random generator
	
	for (size_t i = 0; i < strings.size() - 1; i++) {
		
    //limit our random number to be less than the size of the number of elements "words"
    size_t random_value = std::rand() % strings.size() - 1;
    
    //only swap when the random_value is not the same as the i index incrementor
    if ( random_value != i){
      
      std::swap(strings[i], strings[random_value]);

    }
	}
}

//-----------------------------------------------------------------------------
void merge(string_vector & strings, size_t start, size_t mid, size_t end) {
  
  //int i = start;
  //int j = mid + 1;
  //int k = 0;
  //int temporary[end - start + 1];

  ////merge the 2 parts and place in temporary
  //while ( i <= mid && j <= end ){

  //  if ( strings[i] < strings[j] ){

  //    //temporary[k] = strings[i];
  //    k++;
  //    i++;

  //  }
  //  else{

  //    //temporary[k] = strings[j];
  //    k++;
  //    j++;

  //  }

  //}

  



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

  //if (strings.size() == 1) {
  //  return;
  //}
  //else{

  //  //allocate memory for both parts, for each recursion call
  //  string_vector* b = new string_vector();
  //  string_vector* c = new string_vector();

  //  cout <<"first part from " << start << " to " <<  end / 2 << endl;
  //  cout <<"2nd part from " << end / 2 + 1 << " to " <<  end << endl;

  //  for ( int i = 0; i < end / 2 + 1; i++){

  //    //copy first part of words into b vector
  //    b->push_back(strings[i]);

  //  }

  //  for ( int i = end / 2 + 1; i < end + 1; i++){

  //    //copy 2nd part of the words into c vector
  //    c->push_back(strings[i]);
  // 
  //  }

  //  cout << b->at(0) << endl;
  //  cout << c->at(0) << endl;    

  //  mergesort(*b,0,b->size()-1);
  //  mergesort(*c,0,c->size()-1);

  //  cout <<"Begin the merge process from here on" << endl;
  //  //need to implement merge

  //  return;
  //  
  //}
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

	int l = start, r = end;
	std::string pivot = strings[start];

	while (l < r) {

		while (pivot < strings[r] && r > l) {
			r--;
		}
		swap(strings[l], strings[r]);

		while (pivot >= strings[l] && l < r) {
			l++;
		}
		swap(strings[r], strings[l]);
	}
	return l;
}

//-----------------------------------------------------------------------------
// Sort the given list using the quicksort algorithm.
// This is a recursive method which splits the list into two
// parts, recursively calls itself on the two parts and then merges 
// the two parts together using the merge() method.
//-----------------------------------------------------------------------------
void quicksort(string_vector & strings, int start, int end) {
	//needs hoare_partition in order to work
	//std::string pivot = strings[start];
	//if (start < end)
	//{
	//	int split_point = hoare_partition(strings, start, end);
	//	quicksort(strings, start, split_point - 1);
	//	quicksort(strings, split_point + 1, end);
	//}

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
  //std::cout << "Loading words from [" << path << "]" << std::endl;		//doesn't work w/o #include<iostream>
  words.clear();
  std::ifstream ifs(path.c_str());
  if (!ifs.is_open() || !ifs.good()) {
    //cout << "Failed to open [" << path << "]" << std::endl;
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
  std::cout << "Loaded " << countWordsLoaded << " words from [" << path << "]" << std::endl;

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

