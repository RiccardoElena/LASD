# Domande da sottoporre al docente riguardo la Lezione 4

## 1

### Dove definire i tipi definiti dall'utente (struct, enum, etc.)?

Nel caso in cui si abbia un tipo definito dall'utente, come `struct` o `enum`, dove è meglio definirlo? Nell'header file o nel file sorgente?

La logica direbbe nell'header, ma non so se può causare problemi di multipla definizione.

In ogni caso, se fosse l'header il punto designato, ci sono delle best practices da seguire? Ad esempio l'inizializzazione dei campi a valori di default crea problemi?

### Risposta 1

In generale la parte di definizioni come struct, template di funzioni etc. va messa nell'header file, mentre la parte di implementazione va messa nel file sorgente. Questo perché il file sorgente è quello che viene compilato, e quindi è lì che vanno le implementazioni. L'header file è incluso nel file sorgente, quindi è lì che vanno le definizioni.

Non è sempre questo il caso poi lo vedremo, ma in generale è così.

## 2

### Per quanto riguarda la definizione di operatori?

Per gli operatori custom andrebbero trattati come funzioni, quindi definiti nell'header file e implementati nel file sorgente, o lasciati direttamente al sorgente?

### Risposta 2

Tale e quale alla domanda 1, gli operatori custom vanno definiti nell'header file e implementati nel file sorgente.
