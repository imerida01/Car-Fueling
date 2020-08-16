#include <iostream>
#include <cassert>
#include <sys/time.h>
#include <algorithm>
#include <vector>

using namespace std;
using std::vector;


int compute_min_refills(int d, int m, vector<int> & stops) {
    int numRefills = 0;
    int currentRefill = 0;

    stops.insert(stops.begin(), 0);
    stops.push_back(d);
    int n = (stops.size())-1;
    //std::cout<<"\n+++++++++++++++++++++++++++++++++++++++++n="<<n;

    while (currentRefill < n)
    {
    //std::cout<<"\n_______________________________________________________________";
      int lastRefill = currentRefill;
      while (currentRefill < n && ((stops[currentRefill+1] - stops[lastRefill]) <= m))
      {
        currentRefill += 1;
      }

      //std::cout<<"\n currentRefill = "<<currentRefill;

      //std::cout<<"\n lastRefill = "<<lastRefill;
      if (currentRefill == lastRefill)
      {
        //  std::cout<<"\nooooooooooooooooooooooooooooooooooooooooooooooooo\n";
        return -1;
      }
      if (currentRefill < n)
      {
        numRefills += 1;
      }
      //std::cout<<"\n no. of refills = "<<numRefills;
    }
    if (d - stops[currentRefill-1] <= m)
    {
        //std::cout<<"\nyassssssssssssssssssssss";
      return numRefills;
    }
    else
    {
      return -1;
    }
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops[i];

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
