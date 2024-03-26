
#include <iostream>
// Function pointer a la C++
#include <functional>
#include <random>

using namespace std;

// * Primi quicksort con criterio di confronto hard-coded
void quicksort(int *, uint);
void quicksort(int *, uint, uint);
uint partition(int *, uint, uint);

// Note: può essere utile creare una enum di risultati dei confronti
// Note: per partizionare risultati di confronti più complessi di <,> e =
// Note: andremo così a indicare a prescindere dal criterio di confronto se
// Note: un dato 'a' deve stare prima, dopo o uguale a un dato 'b'
enum class ComparisonType
{
  BeforeThan,
  Equal,
  AfterThen
};

// Function pointer a la C
// typedef ComparisonType (*CompareFunction)(int, int);

// Note: Sintassi in BNF (https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form#Overview)
// * "typedef function <" <returnType> "(" [<paramsList>] ")>" <newTypeName>";"
// * <returnType> ::= <type>
// * <paramsList> ::= <paramsList>, <type> | <type> | ""
// * <newTypeName> ::= <typeName>
typedef std::function<ComparisonType(int, int)> CompareFunction;

// * I nostri algoritmi di ordinamento parametrizzano il criterio di ordinamento
// * sfruttando una funzione di tipo CompareFunction
void quicksort(int *, uint, CompareFunction);
void quicksort(int *, uint, uint, CompareFunction);
uint partition(int *, uint, uint, CompareFunction);

// Ordinamento Crescente
ComparisonType OrdA(int a, int b)
{
  if (a < b)
  {
    return ComparisonType::BeforeThan;
  }
  else if (a > b)
  {
    return ComparisonType::AfterThen;
  }
  return ComparisonType::Equal;
}

// Ordinamento Decrescente
ComparisonType OrdB(int a, int b)
{
  if (a < b)
  {
    return ComparisonType::AfterThen;
  }
  else if (a > b)
  {
    return ComparisonType::BeforeThan;
  }
  return ComparisonType::Equal;
}

// Ordinamento complesso (prima i pari crescenti, poi i dispari crescenti)
ComparisonType OrdC(int a, int b)
{
  if (a % 2 != b % 2)
  {
    return ((a % 2 == 0) ? ComparisonType::BeforeThan : ComparisonType::AfterThen);
  }
  else if (a < b)
  {
    return ComparisonType::BeforeThan;
  }
  else if (a > b)
  {
    return ComparisonType::AfterThen;
  }
  return ComparisonType::Equal;
}

int main()
{

  int A[11] = {5, 7, 6, 8, 4, 9, 3, 10, 2, 0, 1};

  cout << "Ordina la sequenza con ordinamento hard-coded" << endl;
  quicksort(A, 11);

  for (uint i = 0; i < 11; i++)
  {
    cout << A[i] << ' ';
  };
  cout << endl;

  cout << "Ordina la sequenza con ordinamenti decisi dal chiamante" << endl;

  quicksort(A, 11, OrdA);

  for (uint i = 0; i < 11; i++)
  {
    cout << A[i] << ' ';
  };
  cout << endl;

  quicksort(A, 11, OrdB);

  for (uint i = 0; i < 11; i++)
  {
    cout << A[i] << ' ';
  };
  cout << endl;

  quicksort(A, 11, OrdC);

  for (uint i = 0; i < 11; i++)
  {
    cout << A[i] << ' ';
  };
  cout << endl;

  return 0;
}

void quicksort(int *A, uint size)
{
  quicksort(A, 0, size - 1);
}

void quicksort(int *A, uint p, uint r)
{
  if (p < r)
  {
    uint q = partition(A, p, r);
    quicksort(A, p, q);
    quicksort(A, q + 1, r);
  }
}

uint partition(int *A, uint p, uint r)
{

  int x = A[p];
  int i = p - 1;
  int j = r + 1;

  do
  {

    do
    {
      j--;
    } while (x < A[j]);

    do
    {
      i++;
    } while (A[i] < x);

    if (i < j)
    {
      swap(A[i], A[j]);
    } // "swap" is standard-library function

  } while (i < j);

  return j;
}

void quicksort(int *A, uint size, CompareFunction cmp)
{
  quicksort(A, 0, size - 1, cmp);
}

void quicksort(int *A, uint p, uint r, CompareFunction cmp)
{
  if (p < r)
  {
    uint q = partition(A, p, r, cmp);
    quicksort(A, p, q, cmp);
    quicksort(A, q + 1, r, cmp);
  }
}

uint partition(int *A, uint p, uint r, CompareFunction cmp)
{

  default_random_engine genx(random_device{}());
  uniform_int_distribution<uint> dist(p, r);
  swap(A[p], A[dist(genx)]);
  int x = A[p];
  int i = p - 1;
  int j = r + 1;

  do
  {

    do
    {
      j--;
    } while (cmp(x, A[j]) == ComparisonType::BeforeThan);

    do
    {
      i++;
    } while (cmp(x, A[i]) == ComparisonType::AfterThen);

    if (i < j)
    {
      swap(A[i], A[j]);
    } // "swap" is standard-library function

  } while (i < j);

  return j;
}
