#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Locates
{
  int street;
  int avenue;
};

void encontrarPuntoOptimo(vector<Locates>& locaciones, int friends)
{
  vector<int> street, avenue;

  for (Locates loc : locaciones)
    {
      street.push_back(loc.street);
      avenue.push_back(loc.avenue);
    }
  sort(street.begin(), street.end());
  sort(avenue.begin(), avenue.end());
  int mejorCalle = street[(friends - 1) / 2];
  int mejorAvenida = avenue[(friends - 1) / 2];
  printf("(Street: %d, Avenue: %d)\n", mejorCalle, mejorAvenida);
}

int main()
{
  int cases;
  cin >> cases;
  while (cases--)
    {
      int streets, avenues, friends;
      cin >> streets >> avenues >> friends;

      vector<Locates> locaciones(friends);
      for (int i = 0; i < friends; i++)
        {
          cin >> locaciones[i].street >> locaciones[i].avenue;
        }
      encontrarPuntoOptimo(locaciones, friends);
    }
  return 0;
}

