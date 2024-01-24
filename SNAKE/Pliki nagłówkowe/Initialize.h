
/**
 * @file Initialize.h
 * @brief Deklaracja klasy Initialize oraz jej funkcji sk�adowych.
 */

#ifndef INITIALIZE_H
#define INITIALIZE_H


#include "dependencies.h"

 /**
  * @class Initialize
  * @brief Klasa zawieraj�ca funkcje inicjalizacyjne dla programu.
  */
class Initialize {
public:
	/**
	 * @brief Inicjalizuje r�ne modu�y i zasoby potrzebne do poprawnego dzia�ania programu.
	 */
	static void initialize();
};

#endif  // INITIALIZE_H