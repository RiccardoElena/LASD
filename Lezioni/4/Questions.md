# Domande da sottoporre al docente riguardo la Lezione 4

## 1

### Dove definire i tipi definiti dall'utente (struct, enum, etc.)?

Nel caso in cui si abbia un tipo definito dall'utente, come `struct` o `enum`, dove è meglio definirlo? Nell'header file o nel file sorgente?

La logica direbbe nell'header, ma non so se può causare problemi di multipla definizione.

In ogni caso, se fosse l'header il punto designato, ci sono delle best practices da seguire? Ad esempio l'inizializzazione dei campi a valori di default crea problemi?

### Risposta 1

## 2

### Per quanto riguarda la definizione di operatori?

Per gli operatori custom andrebbero trattati come funzioni, quindi definiti nell'header file e implementati nel file sorgente, o lasciati direttamente al sorgente?

### Risposta 2

## 3

### Strutturazione modulare ottimale?

Per quanto riguarda la strutturazione modulare del codice in ottica di user defined types, quali sono le best practices? Ad esempio, è meglio definire una struct in un file sorgente e le funzioni che la manipolano in un altro, o tutto insieme?

### Risposta 3

## 4

### Come funziona per operatori non incapsulati che lavorano con campi privati?

Ci ha detto che gli operatori user defined se lavorano con tipi diversi e non sono
semanticamente asimmetrici verso uno dei due tipi, andrebbero dichiarati come funzioni globali.

Ma nel caso tali operatori debbano lavorare con campi privati di una struct, come si fa?

Si può accedere ai campi privati di una struct da una funzione globale?

È possibile definire una sorta di alias dell'operatore interno alla struct che richiami l'operatore globale o viceversa?

Semplicemente in tali casi si procede all'incapsulamento dell'operatore in una funzione membro?

### Risposta 4
