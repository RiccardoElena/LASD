# Domande da sottoporre al docente riguardo la Lezione 4

## 1

### Errore di compilazione nella generazione random

Il codice da lei fornito crea un errore di compilazione. In particolare istanziando un oggetto di tipo `random_device` e immediatamente chiamando il metodo `operator()` si ottiene un errore di compilazione. Perché?

```cpp

#include <random>

using namespace std;

// ...

61 | default_random_engine genx(random_device{}());

// ...

```

Questo codice genera l'errore:

```plaintext
Error occurred:
main.cpp:61:43: error: expected ')'
  default_random_engine genx(random_device{}());
                                          ^
main.cpp:61:29: note: to match this '('
  default_random_engine genx(random_device{}());

```

Un possibile fix è istanziare l'oggetto `random device` separatamente:

```cpp

#include <random>

using namespace std;

// ...
60 | random_device rd;
61 | default_random_engine genx(rd());

// ...

```

Come mai si ha questo comportamento?

### Risposta 1

## 2

### Quantità enorme di errori random

Utilizzando il compilatore `clang` invece che `g++` la generazione di numeri casuali crea un numero enorme di errori di compilazione. Perché?

```bash
Error occurred:
ld: Undefined symbols:
  std::__1::locale::use_facet(std::__1::locale::id&) const, referenced from:
      std::__1::ctype<char> const& std::__1::use_facet[abi:v160006]<std::__1::ctype<char>>(std::__1::locale const&) in main-63ef54.o
  std::__1::ios_base::getloc() const, referenced from:
      std::__1::basic_ios<char, std::__1::char_traits<char>>::widen[abi:v160006](char) const in main-63ef54.o
  std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__init(char const*, unsigned long), referenced from:
      std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::basic_string[abi:v160006]<std::nullptr_t>(char const*) in main-63ef54.o
  std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__init(unsigned long, char), referenced from:
      std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::basic_string[abi:v160006](unsigned long, char) in main-63ef54.o
  std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::~basic_string(), referenced from:
      cppLikeRandom() in main-63ef54.o
      cppLikeRandom() in main-63ef54.o
      std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:v160006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char) in main-63ef54.o
      std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>> std::__1::__pad_and_output[abi:v160006]<char, std::__1::char_traits<char>>(std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>, char const*, char const*, char const*, std::__1::ios_base&, char) in main-63ef54.o
  std::__1::basic_ostream<char, std::__1::char_traits<char>>::put(char), referenced from:
      std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::endl[abi:v160006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&) in main-63ef54.o
  std::__1::basic_ostream<char, std::__1::char_traits<char>>::flush(), referenced from:
      std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::endl[abi:v160006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&) in main-63ef54.o
  std::__1::basic_ostream<char, std::__1::char_traits<char>>::sentry::sentry(std::__1::basic_ostream<char, std::__1::char_traits<char>>&), referenced from:
      std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:v160006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long) in main-63ef54.o
  std::__1::basic_ostream<char, std::__1::char_traits<char>>::sentry::~sentry(), referenced from:
      std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:v160006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long) in main-63ef54.o
      std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:v160006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long) in main-63ef54.o
  std::__1::basic_ostream<char, std::__1::char_traits<char>>::operator<<(int), referenced from:
      cLikeRandom() in main-63ef54.o
      cLikeRandom() in main-63ef54.o
      cLikeRandom() in main-63ef54.o
  std::__1::basic_ostream<char, std::__1::char_traits<char>>::operator<<(unsigned int), referenced from:
      cppLikeRandom() in main-63ef54.o
  std::__1::random_device::random_device(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&), referenced from:
      cppLikeRandom() in main-63ef54.o
  std::__1::random_device::~random_device(), referenced from:
      cppLikeRandom() in main-63ef54.o
      cppLikeRandom() in main-63ef54.o
  std::__1::random_device::operator()(), referenced from:
      cppLikeRandom() in main-63ef54.o
  std::__1::cout, referenced from:
      cLikeRandom() in main-63ef54.o
      cppLikeRandom() in main-63ef54.o
  std::__1::ctype<char>::id, referenced from:
      std::__1::ctype<char> const& std::__1::use_facet[abi:v160006]<std::__1::ctype<char>>(std::__1::locale const&) in main-63ef54.o
  std::__1::locale::~locale(), referenced from:
      std::__1::basic_ios<char, std::__1::char_traits<char>>::widen[abi:v160006](char) const in main-63ef54.o
      std::__1::basic_ios<char, std::__1::char_traits<char>>::widen[abi:v160006](char) const in main-63ef54.o
  std::__1::ios_base::__set_badbit_and_consider_rethrow(), referenced from:
      std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:v160006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long) in main-63ef54.o
  std::__1::ios_base::clear(unsigned int), referenced from:
      std::__1::ios_base::setstate[abi:v160006](unsigned int) in main-63ef54.o
  std::terminate(), referenced from:
      ___clang_call_terminate in main-63ef54.o
  ___cxa_begin_catch, referenced from:
      ___clang_call_terminate in main-63ef54.o
      std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:v160006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long) in main-63ef54.o
  ___cxa_call_unexpected, referenced from:
      std::__1::char_traits<char>::length(char const*) in main-63ef54.o
      std::__1::ostreambuf_iterator<char, std::__1::char_traits<char>>::ostreambuf_iterator[abi:v160006](std::__1::basic_ostream<char, std::__1::char_traits<char>>&) in main-63ef54.o
  ___cxa_end_catch, referenced from:
      std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:v160006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long) in main-63ef54.o
      std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::__put_character_sequence[abi:v160006]<char, std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*, unsigned long) in main-63ef54.o
  ___gxx_personality_v0, referenced from:
      /private/var/folders/xx/r66n1x_n6wg1m2b88t8x5kpm0000gn/T/main-63ef54.o
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```
