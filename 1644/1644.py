def prime_list(n):
    sieve = [True] * n

    m = int(n ** 0.5)
    for i in range(2, m + 1):
        if sieve[i] == True:
            for j in range(i+i, n, i):
                sieve[j] = False

    return [i for i in range(2, n) if sieve[i] == True]


if __name__ == "__main__":
  n =  int(input())
  primes =  prime_list(n + 1)
  count = 0
  len_cumulative_primes = 0

  cumulative_primes = [0]

  for prime in primes:
    cumulative_primes.append(cumulative_primes[-1] + prime)

  len_cumulative_primes = len(cumulative_primes)
  i = 0; j = 0

  while i <= j and j < len_cumulative_primes:
    if cumulative_primes[j] - cumulative_primes[i] < n:
      j += 1
    elif cumulative_primes[j] - cumulative_primes[i] == n:
      count += 1
      j += 1
    else:
      i += 1

  print(count)