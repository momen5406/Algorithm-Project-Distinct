#include <iostream>
using namespace std;

int count_distinct(int array[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int temp = 0;
      if (array[j] < array[i]) {
        temp = array[j];
        array[j] = array[i];
        array[i] = temp;
      }
    }
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0 || array[i] != array[i - 1]) {
      count++;
    }
  }

  return count;
}

int main() {
  int n;
  cout << "the size of the array: ";
  cin >> n;

  int *array = new int[n];

  for (int i = 0; i < n; i++) {
    cout << "the number of index " << i << " is: ";
    cin >> array[i];
  }
  cout << "\n";

  int count = count_distinct(array, n);

  cout << "the distinct numbers: " << count << endl;

  delete[] array;

  return 0;
}