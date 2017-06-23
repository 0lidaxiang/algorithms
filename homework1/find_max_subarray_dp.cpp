#include <iostream>
using namespace std;
int start_index, end_index, sum;
void bottom_up_cut_rod(int Arr[], int n) {
  start_index = 0;
  end_index = 0;
  int dpArr[n];
  int temp = 0;

  sum = Arr[0];
  dpArr[0] = Arr[0];
  for (int i = 1; i < n; i++) {
    if (dpArr[i - 1] <= 0) {
      dpArr[i] = Arr[i];
      temp = i;
    } else {
      dpArr[i] = Arr[i] + dpArr[i - 1];
    }
    if (dpArr[i] > sum) {
      sum = dpArr[i];
      start_index = temp;
      end_index = i;
    }
  }
}
int main() {
  while (1) {
    int n;
    cin >> n;
    if (cin.fail()) {
      break;
    }
    int Arr[n];
    for (int i = 0; i < n; i++) {
      cin >> Arr[i];
    }
    bottom_up_cut_rod(Arr, n);
    cout << start_index << " " << end_index << " " << sum << endl;
  }
  return 0;
}
