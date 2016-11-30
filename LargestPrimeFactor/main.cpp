// Project Euler: Largest Prime Factor #
// #####################################

// C++11

// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143?

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isFactor(long n, long i)
{
  return n % i == 0;
}

bool isEven(long n)
{
  return n % 2 == 0;
}

long halve(long n)
{
  if (isEven(n)) return n / 2;
  return n;
}

long findFactor(long n)
{
  for (long i = 3; i < n; i+=2)
  {
    if (isFactor(n, i)) return i;
  }
  return 1;
}

long solve(long n)
{
  // Halve to remove even numbers
  n = halve(n);

  // Find 1st odd factor
  long f = findFactor(n);
  long q = n / f;

  // Larget prime factor
  if (f == 1) return q;

  return solve(q);
}

int main()
{
  // Integer to verify
  // int n = 13195;
  
  // Long to solve
  long n = 600851475143;

  cout << "The largest prime factor of " << n << " is:" << endl;
  cout << solve(n) << endl;

  return 0;
}
