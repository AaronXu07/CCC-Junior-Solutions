#include <bits/stdc++.h>

using namespace std;

int main() {

  int N;
  cin >> N;

  int network[6] = {1, 1, 1, 1, 1, 1};

  for (int i = 0; i < N - 1; i++) {

    int inviter;

    cin >> inviter;

    network[i] += 1;

    network[inviter - 1] *= network[i];
  }

  cout << network[N - 1];
}
