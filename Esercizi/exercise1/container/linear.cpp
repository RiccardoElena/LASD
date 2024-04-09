
namespace lasd {

// Linear Container
/* ************************************************************************** */

// Operators

template <typename Data>
bool LinearContainer<Data>::operator==(
    const LinearContainer<Data> &con) const noexcept {
  if (size != con.size) {
    return false;
  }

  for (unsigned long i = 0; i < size; ++i) {
    if ((*this)[i] != con[i]) {
      return false;
    }
  }
  return true;
}

// Specific Methods

template <typename Data>
inline const Data &LinearContainer<Data>::Front() const {
  if (size == 0) {
    throw std::length_error("Empty structure.");
  }
  return (*this)[0];
}

template <typename Data> inline Data &LinearContainer<Data>::Front() {
  if (size != 0) {
    throw std::length_error("Empty structure.");
  }
  return (*this)[0];
}

template <typename Data>
inline const Data &LinearContainer<Data>::Back() const {
  if (size == 0) {
    throw std::length_error("Empty structure.");
  }
  return (*this)[size - 1];
}

template <typename Data> inline Data &LinearContainer<Data>::Back() {
  if (size == 0) {
    throw std::length_error("Empty structure.");
  }
  return (*this)[size - 1];
}
// Overrided Methods

template <typename Data>
void LinearContainer<Data>::PreOrderTraverse(const TraverseFun func) const {
  for (unsigned long i = 0; i < size; ++i) {
    func((*this)[i]);
  }
}

template <typename Data>
void LinearContainer<Data>::PostOrderTraverse(const TraverseFun func) const {

  for (unsigned long i = size; i > 0;) {
    func((*this)[--i]);
  }
}

template <typename Data> void LinearContainer<Data>::PreOrderMap(MapFun func) {
  for (unsigned long i = 0; i < size; ++i) {
    func((*this)[i]);
  }
}

template <typename Data> void LinearContainer<Data>::PostOrderMap(MapFun func) {
  for (unsigned long i = size; i > 0;) {
    func((*this)[--i]);
  }
}

/* ************************************************************************** */

// Sortable Linear Container
/* ************************************************************************** */

// Specific Methods

template <typename Data>
void SortableLinearContainer<Data>::quickSort(unsigned long p,
                                              unsigned long r) noexcept {
  if (p >= r) {
    return;
  }

  if (r - p < 12) {
    insertionSort(p, r);
    return;
  }

  unsigned long h = partition(p, r);
  quickSort(p, h);
  quickSort(h + 1, r);
}

template <typename Data>
void SortableLinearContainer<Data>::insertionSort(unsigned long p,
                                                  unsigned long r) noexcept {
  Data currVal;
  unsigned long t;

  for (unsigned long i = p + 1; i <= r; i++) {

    currVal = (*this)[i];
    t = i;
    while (t > p && (*this)[t - 1] > currVal) {
      (*this)[t] = (*this)[t - 1];
      if (t > 0)
        --t;
      else
        break;
    }
    (*this)[t] = currVal;
  }
}

template <typename Data>
unsigned long
SortableLinearContainer<Data>::partition(unsigned long p,
                                         unsigned long r) noexcept {
  unsigned long i = p - 1;
  unsigned long j = r + 1;

  std::swap((*this)[p], (*this)[randomMedian(p, r)]);
  Data pivot = (*this)[p];

  do {
    do {
      --j;
    } while (pivot < (*this)[j]);

    do {
      ++i;
    } while (pivot > (*this)[i]);

    if (i < j) {
      std::swap((*this)[i], (*this)[j]);
    }
  } while (i < j);

  return j;
}

template <typename Data>
unsigned long
SortableLinearContainer<Data>::randomMedian(unsigned long p,
                                            unsigned long r) const noexcept {
  std::default_random_engine genx(std::random_device{}());
  std::uniform_int_distribution<unsigned long> dist(p, r);

  unsigned long ind1 = dist(genx);
  unsigned long ind2 = dist(genx);
  unsigned long ind3 = dist(genx);
  Data a = (*this)[ind1];
  Data b = (*this)[ind2];
  Data c = (*this)[ind3];

  if ((a < b && b < c) || (c < b && b < a))
    return ind2;
  else if ((b < a && a < c) || (c < a && a < b))
    return ind1;
  else
    return ind3;
}

/* ************************************************************************** */
} // namespace lasd
