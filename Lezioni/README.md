# Appunti Laboratorio Algoritmi e Strutture Dati

## Informazioni generali

- **Anno Accademico**: 2023/2024
- **Docente**: Prof. Fabio Mogavero
- **Studente**: Riccardo Elena

## Struttura della repository

- `n`: cartella con i contenuti della lezione numero n
  - `*.cpp`: file sorgenti in C++ con il codice sorgente
  - `*.hpp`: file header in C++ con le dichiarazioni delle funzioni
- `build.sh`: script bash per compilazione e lancio dei sorgenti
- `compile.sh`: script bash per compilazione dei sorgenti
- `run.sh`: script bash per lancio degli eseguibili
- `README.md`: file contenente le informazioni generali sulla repository

## Utilizzo degli script

Sono forniti vati script bash per semplificare il processo di compilazione e lancio degli eseguibili. È fornita una spiegazione di tutti gli script con dei **MWE**.

Tutti i **MWE** sono scritti con passaggio di parametri esplicito, ma è possibile eseguire senza passaggio di parametri, in tal caso verrà chiesto d'inserire i parametri mancanti.

In tutti gli esempi si suppone che la cartella corrente sia la cartella principale della repository.

***Nota***: *Gli script bash sono stati scritti per essere eseguiti in ambiente Unix, quindi potrebbero non funzionare correttamente in ambiente Windows.*

### Compilazione dei sorgenti

Per compilare i sorgenti è sufficiente eseguire lo script `compile.sh` nella cartella di cui si vuole compilare il codice. Lo script si occuperà di compilare tutti i file sorgenti presenti nella cartella e di generare un eseguibile con lo stesso nome della cartella.

```bash
cd {{folder}}
../compile.sh {{compiler}} {{executable}}
```

### Esecuzione degli eseguibili

Per eseguire gli eseguibili è sufficiente eseguire lo script `run.sh` nella cartella di cui si vuole eseguire il codice. Lo script si occuperà di eseguire l'eseguibile generato dalla compilazione.

```bash
cd {{folder}}
../run.sh {{executable}}
```

### Compilazione e lancio degli eseguibili

Per semplificare il processo di compilazione e lancio degli eseguibili è possibile eseguire lo script `build.sh` nella cartella di cui si vuole eseguire il codice. Lo script si occuperà di eseguire la compilazione e l'esecuzione degli eseguibili.

```bash
cd {{folder}}
../build.sh {{compiler}} {{filename}}
```
