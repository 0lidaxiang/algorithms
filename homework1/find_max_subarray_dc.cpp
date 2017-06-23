#include <iostream>
using namespace std;
struct Result {
  int low;
  int high;
  int sum;
};
Result find_max_crossing_subarray(int Arr[], int mid, int low, int high) {
  Result Result1;
  int left_sum = -1000;
  int right_sum = -1000;
  int sum = 0;
  int i = mid;
  int j = mid + 1;
  for (; i >= low; i--) {
    sum = sum + Arr[i];
    if (sum > left_sum) {
      left_sum = sum;
      Result1.low = i;
    }
  }
  sum = 0;

  for (; j <= high; j++) {
    sum = sum + Arr[j];
    if (sum > right_sum) {
      right_sum = sum;
      Result1.high = j;
    }
  }
  Result1.sum = left_sum + right_sum;
  return Result1;
}
Result find_maxmum_subarray(int Arr[], int low, int high) {
  Result LResult;
  Result RResult;
  Result CResult;
  Result Result1;
  if (high == low) {
    Result1.sum = Arr[low];
    Result1.low = low;
    Result1.high = high;
    return Result1;
  } else {
    int mid = (low + high) / 2;
    LResult = find_maxmum_subarray(Arr, low, mid);
    RResult = find_maxmum_subarray(Arr, (mid + 1), high);
    CResult = find_max_crossing_subarray(Arr, mid, low, high);
    if ((LResult.sum >= RResult.sum) && (LResult.sum >= CResult.sum)) {
      return LResult;
    } else if ((RResult.sum >= LResult.sum) && (RResult.sum >= CResult.sum)) {
      return RResult;
    } else {
      return CResult;
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
    Result Result0;
    Result0 = find_maxmum_subarray(Arr, 0, (n - 1));
    cout << Result0.low << " " << Result0.high << " " << Result0.sum << endl;
  }
  return 0;
}
