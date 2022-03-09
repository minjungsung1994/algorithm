// Algorithm Analysis
// 이분 탐색 알고리즘 (Binary search)

#include <iostream>
#define MAX 10

using namespace std;

int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int d = 7;

int binarySearch(int start, int end, int data) {
  if (start > end) return -1;
  int mid = (start + end) / 2;
  if (arr[mid] == data) return mid;
  else if (arr[mid] > data) return binarySearch(start, mid - 1, data);
  else return binarySearch(mid + 1, end, data);
}

int main() {
  int idx = binarySearch(0, MAX - 1, d);
  if (idx != -1) {
    cout << idx + 1 << "번째 index에서 발견" << endl; // 7
  }
  return 0;
}