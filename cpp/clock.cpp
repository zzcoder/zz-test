#include <iostream>
#include <string>
#include <stdio.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

  int hour, min, hour_delta, min_delta;
  string ap, fb;
  
  cout << "Enter current time (A for AM, P for PM), e.g. 7 30 P: ";

  cin >> hour >> min >> ap;

  cout << "How many hours forwards or backwards do you want to move the clock " 
       << "(F for forwards, B for backwards) e.g. F 7 45: ";

  cin >> fb >> hour_delta >> min_delta;

  // TODO: Should do some validation here

  // Convert to minutes
  int minutes = hour*60 + min;

  if (ap == "p" || ap == "P") {
    // Add 12 hours
    minutes += 12*60;
  }

  int delta = hour_delta*60 + min_delta;

  if (fb == "b" || fb == "B") {
    delta = -delta;
  }

  minutes += delta;

  int hour_new = (minutes/60)%24;
  int min_new = minutes%60;
  ap = "A";
  if (hour_new >= 12) {
    ap = "P";
    if (hour_new > 12) {
      hour_new -= 12;
    }
  } 

  printf("The new time is: %d:%02d%s\n", hour_new, min_new, ap.c_str());
}
