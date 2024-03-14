# Domande da sottoporre al docente riguardo la Lezione 2

## 1. Tesing Librerie

Per lo svolgimento degli esercizi immagino sarà fondamentale criterio l'efficienza e la correttezza del codice. Per questo motivo mi chiedevo se fornirà dei metodi, dei dummy data, dei programmi o delle librerie di testing per verificare la correttezza e l'efficienza del codice.

### Risposta

Si.

## 2. Valore di ritorno di una funzione assegnato a un tipo referenziato

Nell'esempio fatto (slide3.cpp 21:22) è stato eseguito un codice simile a questo che non ha portato a errori di compilazione:

```cpp
int f()
{
  return 0;
}

int main()
{

  // int &var = 0;  COMP_ERR: il valore iniziale del riferimento a non const deve essere un lvalue
  20 | const int &var = 0;

  21 | int result = f();   // Copia il valore di ritorno

  22 | int &results = f(); // COMP_ERR: l'indirizzo di ritorno di f() non è un lvalue

  return 0;
}
```

Testandolo però come denotato nei commenti mi sono accorto che la riga `int &results = f();` non ha portato a errori di compilazione.

Il valore di ritorno di `f()` è un rvalue, quindi non è un lvalue, quindi non può essere assegnato a un tipo referenziato.

Perché non è stato segnalato un errore di compilazione? E in ogni caso, perché con una `string` invece si?

Due possibili fix che ho trovato sono:

- Analogo alle `string`:

  ```cpp
  int &&results = f();
  ```

- Dichiarare il riferimento come `const`:

  ```cpp
  const int &results = f();
  ```

Queste due soluzioni non danno errore di compilazione, come mai? Perché sono necessarie?

### Risposta 2

In realtà è corretto che non funzioni ma per tipi primimitivi vecchi compilatori fanno la copia in maniera nascosta. Non andrebbe fatto è corretto avere l'errore lì.

## 3. Riferimenti a riferimenti

Come funziona un riferimento a riferimento? È possibile dichiarare un riferimento a riferimento? Se sì, come? Ad esempio questo codice è corretto?

```cpp
int main()
{
  int a = 0;
  int &b = a;
  int &c = b;

  return 0;
}
```

### Risposta 3

Funziona ma è inutile poichè avranno tutti la stessa locazione.

## 4. Casting C-style e static_cast

Negli esempi da lei forniti (slide2.cpp\[23:77\]) sono presentati due casting diversi uno
vicino all'altro come analoghi, ma il secondo porta un errore di compilazione.

```cpp
  23 | const char * cpcon;
  24 |
  // Irrelevant code...
  70 | uint uivar = 25;
  // Irrelevant code...
  74 | // C-like cast
  75 | uivar = *((uint *)cpcon); 
  76 | // C++ static cast
  77 | uivar = *(static_cast<uint *>(cpcon));  //COMP_ERR: static_cast da 'const char *' a 'uint *' (aka 'unsigned int *') non è ammesso
```

Come mai il secondo porta a un errore di compilazione? Come mai il primo no?

### Risposta 4

In realtà è corretto che non funzioni, il casting C è più permissivo e ti fa fare cose scomode e lascia a te la palla. Anche per questo andrebbe usato quello di C++.

## 5. Move a tempo costante

Come avviene nel dettaglio move a tempo costane? Quando vado a spostare il puntatore del valore di ritorno di una funzione su null come fa la prossima funzione a sapere qual è la cella di memoria su cui può scrivere il valore di ritorno?

### Risposta 5

Quello che viene cancellato al pop è la variabile interna, che nel caso di dati complessi è solo un riferimento al dato.

## 6. Move implicita

Quando avviene la move implicita? È possibile forzare la move implicita? Se sì, come?

### Risposta 6

Andrebbe evitato, ma se il valore a destra è già un rvalue reference e a sinistra un lvalue reference fa in automatico la move, altrimenti fa una copia
