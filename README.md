# Corso di Laboratorio Algoritmi e Strutture Dati - AA 2023/2024

## Indice

1. [Informazioni generali](#informazioni-generali)
2. [Riassunto informazioni preliminari sul corso](#riassunto-informazioni-preliminari-sul-corso)
3. [Appunti Lezioni](#appunti-lezioni)
    1. [Struttura della cartella Lezioni](#struttura-della-cartella-lezioni)
    2. [Utilizzo appunti lezioni](#utilizzo-appunti-lezioni)
    3. [Utilizzo degli script](#utilizzo-degli-script)
        1. [Compilazione dei sorgenti](#compilazione-dei-sorgenti)
        2. [Esecuzione degli eseguibili](#esecuzione-degli-eseguibili)
        3. [Compilazione e lancio degli eseguibili](#compilazione-e-lancio-degli-eseguibili)
4. [Esercizi](#esercizi)

## Informazioni generali

- **Anno Accademico**: 2023/2024
- **Docente**: Prof. Fabio Mogavero
- **Studente**: Riccardo Elena
- **Corso**: Laboratorio Algoritmi e Strutture Dati
- **Corso di Laurea**: Informatica
- **Università**: Università degli Studi di Napoli Federico II

## Riassunto informazioni preliminari sul corso

Il corso sarà incentrato sullo studio e l'implementazione di algoritmi e strutture dati in C++.

L'esame è composto da una parte teorica e da una parte pratica.

La parte pratica può essere svolta in due modi:

- Svolgimento di **esercizi assegnati dal docente**, valutati di volta in volta, validi
  ai fini della valutazione **solo se superati** e **consegnati entro le deadline indicate**.
- Svolgimento di una **prova scritta vera e propria**, con esercizi simili a quelli
  assegnati durante il corso. Anche per sostenere l'esame in questa modalità **è
  necessario consegnare gli esercizi assegnati**, la cui *deadline sarà 10 giorni*
  *prima della data dell'esame scritto*.

La parte teorica, obbligatoria per entrambe le modalità di svolgimento dell'esame,
consiste in un colloquio orale su **argomenti trattati durante il corso e discussione**
**del codice consegnato con gli esercizi**.

Per le dettagli ulteriori, come **testi consigliati**, **orari di ricevimento** e **deadline precise**, si rimanda al [sito web del corso](https://www.docenti.unina.it/webdocenti-be/allegati/materiale-didattico/34825497).

## Appunti Lezioni

### Struttura della cartella Lezioni

- `{topic}`: cartella con i contenuti relativi a un argomento specifico
  - `*.cpp`: file sorgenti in C++ con il codice sorgente, opportunamente commentato con le spiegazioni
  - `*.hpp`: file header in C++ con le dichiarazioni delle funzioni, opportunamente commentato con le spiegazioni
  - `[Questions.md]`: file Markdown con eventuali domande da sottoporre al docente riguardo l'argomento trattato
- `build.sh`: script bash per compilazione e lancio dei sorgenti
- `compile.sh`: script bash per compilazione dei sorgenti
- `run.sh`: script bash per lancio degli eseguibili

### Utilizzo appunti lezioni

Gli appunti delle lezioni consisteranno essenzialmente nel codice sorgente commentato
nei punti salienti, come possibili istruzioni che portano a errori o sottigliezze d'implementazione non immediate, e nelle **domande da sottoporre al docente**.

Tali eventuali domande saranno presenti in un file `Questions.md` all'interno della cartella dell'argomento. In caso di domande specifiche su un particolare punto del codice, sarà presente un commento del tipo
  
  ```cpp
  // ? file://./Questions.md##[n]
  ```

Dove `n` è il numero della domanda da sottoporre al docente. Tale commento sarà
un riferimento cliccabile alla domanda corrispondente nel file `Questions.md`.

> ***Nota***: *I codici sorgenti sono stati scritti con l'IDE VSCode con installata l'estensione di miglioramento dei commenti presente in `.vscode/extensions.json`, che aiuta nella formattazione e nella visualizzazione di tali commenti. Sebbene sia possibile utilizzare questi appunti con qualsiasi IDE è consigliato, per un'esperienza completa, di utilizzare VSCode e di scaricare le estensioni raccomandate.*

### Utilizzo degli script

Sono forniti vati script bash per semplificare il processo di compilazione e lancio degli eseguibili. È fornita una spiegazione di tutti gli script con dei **MWE**.

Tutti i **MWE** sono scritti con passaggio di parametri esplicito, ma è possibile eseguire senza passaggio di parametri, in tal caso verrà chiesto d'inserire i parametri mancanti.

In tutti gli esempi si suppone che la cartella corrente sia la cartella **Lezioni** presente in questa repository.

> ***Nota***: *Gli script bash sono stati scritti per essere eseguiti in ambiente Unix, quindi potrebbero non funzionare correttamente in ambiente Windows.*

#### Compilazione dei sorgenti

Per compilare i sorgenti è sufficiente eseguire lo script `compile.sh`.

Lo script si occuperà di compilare **tutti i file sorgenti** presenti nella cartella e di generare un eseguibile con **il nome fornito** e l'estensione `.out`.

##### MWE

```bash
./compile.sh
```

##### Flag opzionali compile

| Flag |        Descrizione        | Valore di default |   Opzioni disponibili   |
|:----:|:-------------------------:|:-----------------:|:-----------------------:|
| `-c` | Compilatore da utilizzare |       `g++`       |          ____           |
| `-o` | Grado di ottimizzazione   |        `0`        | `0`, `1`, `2`, `3`, `s` |
| `-p` | Path alla cartella        |     `./`          |          ____           |
| `-f` | Nome dell'eseguibile      |       `a`     |          ____           |

###### Full Flag MWE compile

```bash
./compile.sh -c {{compiler}} -o {{opt}} -p {{path/to/folder}} -f {{executableName}}
```

#### Esecuzione degli eseguibili

Per eseguire gli eseguibili è sufficiente eseguire lo script `run.sh` specificando il path relativo al file eseguibile in questione (**senza alcuna estensione**). Lo script si occuperà di eseguire l'eseguibile generato dalla compilazione.

##### MWE

```bash
./run.sh
```

##### Flag opzionali run

| Flag |        Descrizione        | Valore di default |   Opzioni disponibili   |
|:----:|:-------------------------:|:-----------------:|:-----------------------:|
| `-f` | Nome dell'eseguibile      |       `program`     |          ____         |

###### Full Flag MWE run

```bash
./run.sh -f {{executableName}}
```

#### Compilazione e lancio degli eseguibili

Per semplificare il processo di compilazione e lancio degli eseguibili è possibile eseguire lo script `build.sh` nella cartella di cui si vuole eseguire il codice. Lo script si occuperà di eseguire la compilazione e l'esecuzione degli eseguibili.

```bash
./build.sh
```

##### Flag opzionali build

Le flag opzionali, come l'MWE, sono le stesse di [`compile.sh`](#flag-opzionali-compile).

## Esercizi
