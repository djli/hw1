/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr test;
  test.push_front("index location 1");
  test.push_front("index location 0");
  test.push_back("index location 2");
  test.push_back("index location 3");
  test.push_back("index location 4");
  test.push_back("index location 5");
  test.push_back("index location 6");
  test.push_back("index location 7");
  test.push_back("index location 8");
  test.push_back("index location 9");
  test.push_back("index location 10");
  test.push_back("index location 11");
  cout << "CURRENT SIZE: " << test.size() << endl; //should output 3
  cout << "STRING AT INDEX 0: " << test.get(0) << endl; //should ouput index location 0
  cout << "STRING AT INDEX 3: " << test.get(3) << endl; //should output index location 3
  cout << "STRING AT INDEX 20: " << test.get(20) << endl; //should output nothing
  cout << "STRING AT FRONT: " << test.front() << endl; //should ouput index location 0
  cout << "STRING AT BACK: " << test.back() << endl; //should output index location 11
  test.pop_front(); //1
  cout << "CURRENT SIZE: " << test.size() << endl; //should output 2
  test.pop_front(); //2
  test.pop_back(); //1
  cout << "CURRENT SIZE: " << test.size() << endl; //should output 1
  test.pop_back(); //2
  test.pop_back(); //3
  test.pop_back(); //4
  test.pop_back(); //5
  test.pop_back(); //6
  test.pop_back(); //7
  test.pop_back(); //8
  test.pop_back(); //9
  test.pop_back(); //10
  cout << "CURRENT SIZE: " << test.size() << endl; //should output 0
  cout << "IS IT EMPTY? " << test.empty() << endl; //should output 1 (true)
  return 0;
}
