// Project Euler: Largest Palindrome
//
// C++11
//
// A palindromic number reads the same both ways.
// The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int n)
{
  string number = to_string(n);
  // Use .rbegin()/.rend() to iterate from end of string to start
  string rev_number(number.rbegin(), number.rend());

  return number == rev_number;
}

// Get square root to get closest factors first
int approxRoot(int n)
{
  return sqrt(n);
}

// Get closets factors
// C++ doesn't allow returning array
// so create pointer instead and access with indeces
int * factors(int n)
{
  // *** Find out what static refers to?
  // *** Is array immutable once instantiated?
  static int r[2];

  for (int i = approxRoot(n); i > 1; i--)
  {
    if (n % i == 0)
    {
      r[0] = i;
      r[1] = n / i;

      // *** Necessary for soltion
      // *** Does this tie in to static type
      break;
    }
  }
  return r;
}

// Use to check if factors are both 3-digit numbers
bool factor_length(int x, int y)
{
  // *** Is this idiomatic C++?
  return to_string(x).length() == to_string(y).length();
}

int main()
{
  // Range is all possible multiples of two 3-digit numbers
  for (int i = 999 * 999; i > 100 * 100; i--)
  {
    // *** Is this idiomatic C++?
    if (isPalindrome(i) && factor_length(factors(i)[0], factors(i)[1]))
    {
      cout << "Solution: " << i << endl;
      cout << "Factors: " << factors(i)[0] << " " << factors(i)[1] << endl;
      return 0;
    }
  }
}
