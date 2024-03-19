
#include <iostream>

// #include <stdexcept> // Optional when iostream is included!

using namespace std;

int main()
{

  cout << "Hello everyone... I am rising some exception!" << endl;

  concatenatedCatch();

  nestedCatch();

  return 0;
}

void concatenatedCatch()
{
  /*
    ! L'ordine dei catch dev'essere dal meno generale al più
    ! generale perché altrimenti la più generale catcherà le
    ! qualsiasi eccezione sua specializzazione ("consumando" l'eccezione)
    ! non facendo eseguiew i catch più specifici
  */
  try
  {

    // * scommentare la throw dell'exception da testare

    // throw logic_error("Some logic error.");
    // throw length_error("A lenght error occurred!");
    // throw out_of_range("An out-of-range access to some structure occurred!");

    // throw runtime_error("Some runtime error.");
    // throw overflow_error("An overflow occurred!");
    // throw underflow_error("An underflow occurred!");

    // throw bad_alloc(); // Just an example, do not throw thsi exception.

    // Note: In C++ qualsiasi tipo è lanciabile!
    // throw 25;
  }
  catch (length_error &exc)
  {

    cout << "Length error: " << exc.what() << endl;

    // // * La keyword throe isolata lancia l'eccezione attualmente catchata
    // throw;
  }
  catch (logic_error &exc)
  {

    cout << "Logic error: " << exc.what() << endl;
  }
  catch (overflow_error &exc)
  {

    cout << "Overflow error: " << exc.what() << endl;
  }
  catch (runtime_error &exc)
  {

    cout << "Runtime error: " << exc.what() << endl;
  }
  catch (bad_alloc &exc)
  {

    cout << "Bad allocation: " << exc.what() << endl;
  }
  // * Tra le eccezioni è sempre l'ultima poichè la più generale
  catch (exception &exc)
  {

    cout << "All unmanaged standard exceptions reach this point!" << exc.what() << endl;
  }
  // * L'operatore "..." si riferisce a "Tutto il resto".
  // * Qualsiasi throw sia stato fatto, se riesce a raggiungere un catch con ...
  // * Verrà intercettato
  catch (...)
  {

    cout << "All unmanaged non-standard exceptions reach this point!" << endl;
  }
}

void nestedCatch()
{

  // ! Seguire la numerazione dei commenti per comprendere il flusso
  // ! dell'informazione

  try
  {

    try
    {

      // * 1) Eccezione lanciata
      throw logic_error("some logic error.");
    }
    catch (logic_error &exc)
    { // * 2) Eccezione catturata

      cout << "i am unable to manage this exception: " << exc.what() << endl;

      throw; // * 3) Eccezione rilanciata

    } // * 3.5) Il try esterno propaga l'eccezione interna
  }
  catch (...)
  { // * 4) Eccezione catturata

    cout << "all unmanaged exceptions reach this point!" << endl;

  } // * 5) Catch innestati finiti, se l'eccezione non è stata gestita sarà ribalzata

  try
  {

    throw 5;
  }
  catch (int num)
  {

    cout << "Exception number: " << num << endl;
  }
}