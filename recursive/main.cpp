#include <iostream>
using namespace std;

void insert_arr(int arr[], int size, int index) {
  int x;
  if (index == size) {
    return;
  } else {
    cout << "please enter the value of index" << ":" << index << "    ";
    cin >> x;
    arr[index] = x;
    insert_arr(arr, size, index + 1);
  }
}

bool exists(int arr[], int index, int search) {
  if (search < 0) return false;
  if (arr[index] == arr[search]) return true;
  return exists(arr, index, search - 1);
}

int count_distinct(int arr[], int size, int index) {
  if (index == size) return 0;
  if (exists(arr, index, index - 1))
    return count_distinct(arr, size, index + 1);
  return 1 + count_distinct(arr, size, index + 1);
}

int main() {
  int size;
  cout << "write the size of the array: ";
  cin >> size;
  int *arr = new int[size];
  insert_arr(arr, size, 0);
  cout << "the distinct numbers: " << count_distinct(arr, size, 0) << endl;
  return 0;
}
