# Domande da sottoporre al docente riguardo la Lezione 10

## 1

### Dubbi riguardo l'utilità di friend functions

Essendo possibile definire il corpo di una funzione fuori dalla classe, qual è l'utilità di dichiararla come `friend`?

Ad esempio nel codice:

```cpp

class A
{
  int x;
public:
  A(int x) : x(x) {}
  void f(A a)`
  friend void g(A a);
};

void A::f(A a)
{
  cout << a.x << endl;
}

void g(A a)
{
  cout << a.x << endl;
}
```

`g` è una `friend function` di `A`, ma potrebbe essere definita fuori dalla classe senza problemi come con `f`. Qual è la differenza? E se non c'è differenza, qual è l'utilità di `friend`?

### Risposta 1

## 2

### explicit constructor

Leggendo le fonti bibliografiche che ci ha dato ([Str'13](../../Books/[Str'13]%20The%20C++%20Programming%20Language-4rh%20Ed-Stroustrup.pdf)) ho trovato che è
fortemente consigliato dichiarare i costruttori come `explicit` se possibile, per evitare conversioni implicite. Tuttavia, non abbiamo visto a lezione questa possibilità. Nel nostro usecase non è necessario o addirittura sconsigliato?

### Risposta 2

## 3

### inline functions

Sempre leggendo la documentazione ho notato che è possibile dichiarare una funzione come `inline` per ottimizzare il codice. Tuttavia, non abbiamo mai visto questa possibilità a lezione. È possibile utilizzarla nel nostro usecase? Se sì, come?

Inoltre leggevo che tutti i metodi definiti all'intterno della classe sono considerati `ìnline`. A tal proposito non sarebbe meglio, per evitare di appesantire inutilmente la fase di compilazione, definire all'interno della classe solo i metodi che hanno chance di essere trattati come `inline`?

### Risposta 3
