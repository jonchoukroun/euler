# Project Euler: Largest Palindrome #
#######################################

# Ruby 2.3.1
#
# A palindromic number reads the same both ways.
# The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
# Find the largest palindrome made from the product of two 3-digit numbers.

def is_palindrome?(n)
  n = n.to_s
  mid = n.length / 2

  if n.length % 2 == 0
    n.slice(0...mid) == n.slice(mid..n.length).reverse!
  else
    n.slice(0...mid) == n.slice((mid + 1)..n.length).reverse!
  end
end

def solve
  (999 * 999).downto(100 * 100) do |i|
    return i if is_palindrome?(i)
  end
end

# Test cases
# p is_palindrome?(9009)    # true (even length)
# p is_palindrome?(90509)   # true (odd length)
# p is_palindrome?(9509)    # false (even length)
# p is_palindrome?(95039)   # false (odd length)

# Solve problem
p solve
