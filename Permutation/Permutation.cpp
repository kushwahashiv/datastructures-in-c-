#include <iostream>

void print(const int *v, const int size)
{
  if (v != 0) {
    for (int i = 0; i < size; i++) {
      printf("%4d", v[i]);
    }
    printf("\n");
  }
} // print


void permute(int *v, const int start, const int n)
{
  if (start == n - 1) 
  {
    print(v, n);
  }
  else 
  {
    for (int i = start; i < n; i++) 
    {
      int tmp = v[i];

      v[i] = v[start];
      v[start] = tmp;
      permute(v, start + 1, n);
      v[start] = v[i];
      v[i] = tmp;
    }
  }
}


int main()
{
  int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  permute(v, 0, sizeof(v) / sizeof(int));

  system("pause");
  return 0;
}