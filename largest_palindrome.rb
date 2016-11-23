# Project Euler: Largest Palindrome #
#######################################

# Ruby 2.3.1
#
# A palindromic number reads the same both ways.
# The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
# Find the largest palindrome made from the product of two 3-digit numbers.

def is_palindrome(n)
  n.to_s == n.to_s.reverse
end

def approx_root(n)
  (n ** 0.5).to_i
end

def factor(n)
  approx_root(n).downto(1) do |i|
    return [i, (n / i)] if n % i == 0
  end
end

def factor_length(arr, x)
  factors = arr.map { |n| n.to_s }
  return factors[0].length == x && factors[1].length == x
end

def solve
  (999 * 999).downto(100 * 100) do |i|
    if is_palindrome(i)
      return i if factor_length(factor(i), 3)
    end
  end
end

# Solve problem
p solve
