#include <iostream>
#include <vector>
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
  vector<float> percentage = {0.2, 0.20, 0.3, 0.1, 0.2};
  for (int i = 0; i < cases; i++)
  {
    vector <int> grades;
    int number;
    for (int k = 0; k < 7; k++)
    {
      cin >> number;
      grades.push_back(number);
    }
    //test
    float media_test = 0;
    for(int j = 0; j < 3; j++)
    {
      media_test += grades[4 + j];
    }
    media_test += media_test / 3;
    vector<float> final_grades(5);

    final_grades[0] = (grades[0]/20 * 100) * percentage[0];
    final_grades[1] = grades[1]/20 * 100 * percentage[1];
    final_grades[2] = grades[2]/30 * 100 * percentage[2];
    final_grades[3] = grades[3]/10 * 100 * percentage[3];
    final_grades[4] = media_test / 20 * 100 * percentage[4];
    float sum = 0;
    for (float num: final_grades)
    {
      sum += num;
    }
    cout << sum;
  }
  return 0;
}
