#include<iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct Locates
{
  int avenue;
  int street;
};
struct Optimos
{
  Locates local;
  int total;
};
void print(vector<Optimos> a)
{
  for (Optimos opti: a)
  {
    cout << opti.local.street << " " << opti.local.avenue << endl; 
  }
}
bool compararPorTotal(const Optimos &a, const Optimos &b)
{
  return a.total < b.total;
}
void iguales(Locates a, Locates b)
{
  if (a.street + a.avenue < b.street + b.avenue)
  {
    printf("(Street: %d, Avenue: %d)\n", a.street, a.avenue);
    return;
  }
  printf("(Street: %d, Avenue: %d)\n", b.street, b.avenue);
}
int main()
{
  int cases; cin >> cases;
  while(cases--)
  {
    int streets;  cin >> streets;
    int avenues; cin >> avenues;
    int friends; cin >> friends;
    vector<Locates> locaciones;
    for (int i = 0; i < friends; i++)
    {
      int s; cin >> s;
      int a; cin >> a;
      locaciones.push_back({a, s});
    }
    vector<Optimos> caminata_total(locaciones.size());
    for (int j = 0; j < locaciones.size(); j++)
    {
      int distancia_total = 0;
      for (Locates dir: locaciones)
      {
        distancia_total += abs(locaciones[j].avenue - dir.avenue) + abs(locaciones[j].street - dir.street);
      }
      caminata_total[j] = {locaciones[j], distancia_total};
    }
    sort(caminata_total.begin(), caminata_total.end(), compararPorTotal);
    if (caminata_total[0].total == caminata_total[1].total)
      iguales(caminata_total[0].local, caminata_total[1].local);
    else
      printf("(Street: %d, Avenue: %d)\n", caminata_total[0].local.street, caminata_total[0].local.avenue);
  }
  return 0;
}
