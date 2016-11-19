# Project Euler: Largest Prime Factor #
#######################################

# Ruby 2.3.1
#
# The prime factors of 13195 are 5, 7, 13 and 29.
# What is the largest prime factor of the number 600851475143?


def is_factor(n, i)
  n % i == 0
end

def is_even(n)
  is_factor(n, 2)
end

def halve(n)
  return n / 2 if is_even(n)
  return n
end

def find_factor(n)
  (3..n).step(2) do |i|
    return i if is_factor(n, i)
  end
end

def solve(n)
  # Halve to remove even numbers
  n = halve(n)

  # Find first odd factor
  f = find_factor(n)
  q = n / f

  # Largest prime factor
  if q < f
    return f
  else
    solve(q)
  end
end

# Solve problem
p "Solution: #{solve(600851475143)}"
