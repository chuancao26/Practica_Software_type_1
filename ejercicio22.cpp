#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char getGrade(float sum) 
{
  if (sum >= 90) return 'A';
  else if (sum >= 80) return 'B';
  else if (sum >= 70) return 'C';
  else if (sum >= 60) return 'D';
  else return 'F';
}

int main()
{
  int cases;
  cin >> cases;

  for (int i = 1; i <= cases; i++)
  {
    int term1, term2, finalExam, attendance, test1, test2, test3;
    cin >> term1 ; 
    cin >> term2; 
    cin >> finalExam; 
    cin >> attendance; 
    cin >> test1;
    cin >> test2;
    cin >> test3;
    vector<int> tests = {test1, test2, test3};
    sort(tests.begin(), tests.end());
    float best = (tests[1] + tests[2]) / 2.0;
    float final_grade= (term1 / 20.0) * 20 
      + (term2 / 20.0) * 20 
      + (finalExam / 30.0) * 30 
      + (attendance / 10.0) * 10 
      + (best / 20.0) * 20;
    char grade = getGrade(final_grade);
    cout << "Case " << i << ": " << grade << endl;
  }
  return 0;
}

