/**
 * @file Snake.h
 * @brief Deklaracja klasy Snake oraz jej sk�adowych.
 */

#ifndef SNAKE_H
#define SNAKE_H

#include "dependencies.h"
#include <vector>
#include "Apple.h"
#include "Mushroom.h"
#include "GameOver.h"

 /**
  * @struct Point
  * @brief Struktura reprezentuj�ca punkt w dwuwymiarowej przestrzeni.
  */
struct Point {
	/** Wsp�rz�dna X punktu.*/
	int x;
	/** Wsp�rz�dna Y punktu.*/
	int y;
};

/**
 * @class Snake
 * @brief Klasa reprezentuj�ca obiekt w�a w grze.
 */
class Snake {
private:
	/**< Wektor przechowuj�cy punkty reprezentuj�ce cia�o w�a. */
	std::vector<Point>body;
	/**< Kierunek, w kt�rym porusza si� w��. */
	int dir;
	/**< K�t obrotu g�owy w�a. */
	float angle;
	/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego cia�o w�a. */
	ALLEGRO_BITMAP* bodyBmp;
	/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego g�ow� w�a. */
	ALLEGRO_BITMAP* headBmp; 
	/**< Stan klawiatury Allegro 5 do obs�ugi wej�cia. */
	ALLEGRO_KEYBOARD_STATE keyboard;
	/**< Wska�nik do obiektu sampla Allegro 5 reprezentuj�cego d�wi�k jedzenia. */
	ALLEGRO_SAMPLE* eatingSound;
	/**< Wyliczenie reprezentuj�ce kierunki poruszania si� w�a. */
	enum DIRECTION { UP, DOWN, LEFT, RIGHT };
public:
	/**< Nick gracza. */
	std::string nickName;
	/**
	* @brief Konstruktor klasy Snake.
	*        Inicjalizuje pocz�tkowe ustawienia w�a.
	*/
	Snake();
	/**
	* @brief Wy�wietla w�a na ekranie.
	*/
	void displaySnake();
	/**
	* @brief Porusza w�em na planszy, uwzgl�dniaj�c kolizje.
	* @param apple Wska�nik do obiektu klasy Apple reprezentuj�cego jab�ko.
	* @param mushrooms Wektor wska�nik�w do obiekt�w klasy Mushroom reprezentuj�cych grzyby.
	*/
	void moveSnake(Apple* apple, std::vector<Mushroom*> mushrooms);
	/**
	* @brief Zwraca wsp�rz�dn� X g�owy w�a.
	* @return Wsp�rz�dna X g�owy w�a.
	*/
	int getX();
	/**
	* @brief Zwraca wsp�rz�dn� Y g�owy w�a.
	* @return Wsp�rz�dna Y g�owy w�a.
	*/
	int getY();
	/**
	 * @brief Losuje now� pozycj� w�a na planszy.
	 */
	void randomize();
	/**
	* @brief Przypisuje klawisze do sterowania w�em.
	*/
	void keyAssignment();
	/**
	 * @brief Inicjalizuje w�a na pocz�tku gry.
	 */
	void initializeSnake();
	/**
	* @brief Sprawdza kolizj� z jab�kiem i aktualizuje wynik gry.
	* @param apple Wska�nik do obiektu klasy Apple reprezentuj�cego jab�ko.
	* @param newSegment Nowy segment dodawany do cia�a w�a.
	* @param newHead Nowa g�owa w�a.
	*/
	void checkCollisionWithApple(Apple* apple, Point newSegment, Point newHead);
	/**
	 * @brief Sprawdza kolizj� z �cian� planszy.
	 * @param newHead Nowa g�owa w�a.
	 */
	void chceckCollisionWithWall(Point newHead);
	 /**
     * @brief Sprawdza kolizj� z samym sob�.
     * @param newHead Nowa g�owa w�a.
     */
	void chceckCollisionWithItself(Point newHead);
	/**
	* @brief Sprawdza kolizj� z grzybami.
	* @param mushrooms Wektor wska�nik�w do obiekt�w klasy Mushroom reprezentuj�cych grzyby.
	* @param newHead Nowa g�owa w�a.
	*/
	void checkCollisionWithMushroom(std::vector<Mushroom*> mushrooms, Point newHead);
	/**
	* @brief Porusza w�em z uwzgl�dnieniem animacji (tweening).
	* @param apple Wska�nik do obiektu klasy Apple reprezentuj�cego jab�ko.
	* @param mushrooms Wektor wska�nik�w do obiekt�w klasy Mushroom reprezentuj�cych grzyby.
	* @param elapsedTime Czas, kt�ry up�yn�� od ostatniego kroku animacji.
	*/
	void moveSnakeWithTweening(Apple* apple, std::vector<Mushroom*> mushrooms, double elapsedTime);
	static int score;/**< Aktualny wynik gry. */
	/**
	* @brief Funkcja interpolacji liniowej.
	* @param a Pocz�tkowa warto��.
	* @param b Ko�cowa warto��.
	* @param t Warto�� od 0.0 do 1.0 okre�laj�ca stopie� interpolacji.
	* @return Wynik interpolacji liniowej.
	*/
	float lerp(float a, float b, float t);
};

#endif  // SNAKE_H