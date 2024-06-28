namespace lasd {
#include <algorithm>
#include <string>

/* ************************************************************************** */

// Hashable Implementations

template <> class Hashable<int> {
public:
  unsigned long operator()(const int &d) const noexcept { return d * d; }
};

template <> class Hashable<double> {
public:
  unsigned long operator()(const double &d) const noexcept {
    long i{static_cast<long>(std::floor(d))};
    long f{static_cast<long>(pow(2, 24) * (d - i)) + 1};
    return i * f;
  }
};

template <> class Hashable<std::string> {
public:
  unsigned long operator()(const std::string &d) const noexcept {
    unsigned long res{5262};

    for (unsigned long i{0}; i < d.length(); ++i)
      res += ((res << 5) - res) + d[i];

    return res;
  }
};
// HashTable Methods

// Constructors

template <typename Data> inline HashTable<Data>::HashTable() {
  a = dista(gen);
  b = distb(gen);
}

// ! check for size syntax
template <typename Data>
HashTable<Data>::HashTable(const HashTable<Data> &other)
    : a(other.a), b(other.b), tsize(other.tsize) {
  size = other.size;
}

template <typename Data>
HashTable<Data>::HashTable(HashTable<Data> &&other) noexcept {
  std::swap(a, other.a);
  std::swap(b, other.b);
  std::swap(tsize, other.tsize);
  std::swap(size, other.size);
}

template <typename Data>
HashTable<Data> &HashTable<Data>::operator=(const HashTable<Data> &other) {
  a = other.a;
  b = other.b;
  tsize = other.tsize;
  size = other.size;
  return *this;
}

template <typename Data>
HashTable<Data> &HashTable<Data>::operator=(HashTable<Data> &&other) noexcept {
  std::swap(a, other.a);
  std::swap(b, other.b);
  std::swap(tsize, other.tsize);
  std::swap(size, other.size);
  return *this;
}

template <typename Data>
inline unsigned long HashTable<Data>::HashKey(const Data &d) const noexcept {
  return HashKey(hash(d));
}

template <typename Data>
inline unsigned long HashTable<Data>::HashKey(unsigned long k) const noexcept {
  return ((a * k + b) % MAX_PRIME) % tsize;
}

template <typename Data>
unsigned long HashTable<Data>::PrimeSucc(unsigned long d) const noexcept {
  unsigned long best{25}, i{0}, j{25}, m;

  while (i < j)
    primes[m = (i + j) >> 1] < d ? i = m + 1 : best = j = m;

  return primes[best];
}

template <typename Data>
unsigned long HashTable<Data>::PrimePred(unsigned long d) const noexcept {
  unsigned long best{0}, i{0}, j{25}, m;

  while (i < j)
    primes[m = (i + j) >> 1] >= d ? j = m : i = (best = m) + 1;

  return primes[best];
}

/* ************************************************************************** */

} // namespace lasd
