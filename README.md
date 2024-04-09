# Corso di Laboratorio Algoritmi e Strutture Dati - AA 2023/2024

## Indice

1. [Informazioni generali](#informazioni-generali)
2. [Riassunto informazioni preliminari sul corso](#riassunto-informazioni-preliminari-sul-corso)
3. [Appunti Lezioni](#appunti-lezioni)
    1. [Struttura della cartella Lezioni](#struttura-della-cartella-lezioni)
    2. [Utilizzo appunti lezioni](#utilizzo-appunti-lezioni)
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

## Esercizi

Nella cartella esercizi sono presenti gli esercizi assegnati dal docente, con relativi file sorgenti e file di test.

Gli esercizi sono già stati risolti, per cui è possibile consultare le soluzioni. Inoltre, sono presenti i file di test per verificare la correttezza delle soluzioni.

Per reperire gli esercizi assegnati dal docente, si rimanda al [sito web del corso](https://www.docenti.unina.it/#!/professor/464142494f4d4f47415645524f4d475646424138334533314837303341/materiale_didattico), (è necessario essere autenticati e iscritti al corso per accedere ai materiali didattici).
