// Problem: Randomly distribute fixed number of objects into                                                                                                                                                  
//          fixed number of buckets. Each bucket should atleast                                                                                                                                               
//          have a object.                                                                                                                                                                                    
//                                                                                                                                                                                                            
// Solution Algorithm:                                                                                                                                                                                        
//          1) Put one object into each bucket.                                                                                                                                                               
//          2) For each remaining object put it                                                                                                                                                               
//             into randomly selected bucket.                                                                                                                                                                 
//                                                                                                                                                                                                            
// Copyright (c) 2014 Pranav Kulkarni
// Copyright (c) 2014 Nishant Singh
// Copyright (c) 2014 Rohan Sharma
//
// See the file license.txt for copying permission.
//                                                                                                                                                                                                            

#include <cmath>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Get a random number from the range (inclusive)                                                                                                                                                             
int get_rand_from_range(double min, double max) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(min, max+1);

  return dist(gen);
}

// Computes the object distribution                                                                                                                                                                           
vector<int> gen_object_distribution(int bucket_count, int object_count) {
  vector<int> r(bucket_count, 1);

  for(int iter = 0; iter < (object_count - bucket_count); ++iter) {
      r[get_rand_from_range(0, bucket_count-1)]++;
  }

  return r;
}

int main(int argc, char *argv[]) {
  int bucket_count = 10, object_count = 100;
  int test_sum = 0;
  vector<int> distribution;

  if(argc < 3) {
    cout << "Usage: " <<argv[0] << " <buckets> <objects>. Now using default values >"
         << " bucket_count : " << bucket_count << " object_count : " << object_count
         << "." << endl;
  }
  else {
    string::size_type sz;
    bucket_count = stoi(argv[1], &sz);
    object_count = stoi(argv[2], &sz);
  }
  distribution = gen_object_distribution(bucket_count, object_count);

  cout << "Distribution:" << endl;
  for(vector<int>::size_type bid = 0; bid < distribution.size(); ++bid) {
    cout <<"[Bucket " << (bid+1) << ":\t" << distribution[bid] << " objects]\n";
    test_sum += distribution[bid];
  }

  cout << endl
       << ((test_sum == object_count) ? "Done!" : "Sucked!")
       << endl;

  return 0;
}
