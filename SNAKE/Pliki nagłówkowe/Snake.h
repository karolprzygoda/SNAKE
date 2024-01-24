/**
 * @file Snake.h
 * @brief Deklaracja klasy Snake oraz jej sk³adowych.
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
  * @brief Struktura reprezentuj¹ca punkt w dwuwymiarowej przestrzeni.
  */
struct Point {
	/** Wspó³rzêdna X punktu.*/
	int x;
	/** Wspó³rzêdna Y punktu.*/
	int y;
};

/**
 * @class Snake
 * @brief Klasa reprezentuj¹ca obiekt wê¿a w grze.
 */
class Snake {
private:
	/**< Wektor przechowuj¹cy punkty reprezentuj¹ce cia³o wê¿a. */
	std::vector<Point>body;
	/**< Kierunek, w którym porusza siê w¹¿. */
	int dir;
	/**< K¹t obrotu g³owy wê¿a. */
	float angle;
	/**< WskaŸnik do obiektu bitmapy Allegro 5 reprezentuj¹cego cia³o wê¿a. */
	ALLEGRO_BITMAP* bodyBmp;
	/**< WskaŸnik do obiektu bitmapy Allegro 5 reprezentuj¹cego g³owê wê¿a. */
	ALLEGRO_BITMAP* headBmp; 
	/**< Stan klawiatury Allegro 5 do obs³ugi wejœcia. */
	ALLEGRO_KEYBOARD_STATE keyboard;
	/**< WskaŸnik do obiektu sampla Allegro 5 reprezentuj¹cego dŸwiêk jedzenia. */
	ALLEGRO_SAMPLE* eatingSound;
	/**< Wyliczenie reprezentuj¹ce kierunki poruszania siê wê¿a. */
	enum DIRECTION { UP, DOWN, LEFT, RIGHT };
public:
	/**< Nick gracza. */
	std::string nickName;
	/**
	* @brief Konstruktor klasy Snake.
	*        Inicjalizuje pocz¹tkowe ustawienia wê¿a.
	*/
	Snake();
	/**
	* @brief Wyœwietla wê¿a na ekranie.
	*/
	void displaySnake();
	/**
	* @brief Porusza wê¿em na planszy, uwzglêdniaj¹c kolizje.
	* @param apple WskaŸnik do obiektu klasy Apple reprezentuj¹cego jab³ko.
	* @param mushrooms Wektor wskaŸników do obiektów klasy Mushroom reprezentuj¹cych grzyby.
	*/
	void moveSnake(Apple* apple, std::vector<Mushroom*> mushrooms);
	/**
	* @brief Zwraca wspó³rzêdn¹ X g³owy wê¿a.
	* @return Wspó³rzêdna X g³owy wê¿a.
	*/
	int getX();
	/**
	* @brief Zwraca wspó³rzêdn¹ Y g³owy wê¿a.
	* @return Wspó³rzêdna Y g³owy wê¿a.
	*/
	int getY();
	/**
	 * @brief Losuje now¹ pozycjê wê¿a na planszy.
	 */
	void randomize();
	/**
	* @brief Przypisuje klawisze do sterowania wê¿em.
	*/
	void keyAssignment();
	/**
	 * @brief Inicjalizuje wê¿a na pocz¹tku gry.
	 */
	void initializeSnake();
	/**
	* @brief Sprawdza kolizjê z jab³kiem i aktualizuje wynik gry.
	* @param apple WskaŸnik do obiektu klasy Apple reprezentuj¹cego jab³ko.
	* @param newSegment Nowy segment dodawany do cia³a wê¿a.
	* @param newHead Nowa g³owa wê¿a.
	*/
	void checkCollisionWithApple(Apple* apple, Point newSegment, Point newHead);
	/**
	 * @brief Sprawdza kolizjê z œcian¹ planszy.
	 * @param newHead Nowa g³owa wê¿a.
	 */
	void chceckCollisionWithWall(Point newHead);
	 /**
     * @brief Sprawdza kolizjê z samym sob¹.
     * @param newHead Nowa g³owa wê¿a.
     */
	void chceckCollisionWithItself(Point newHead);
	/**
	* @brief Sprawdza kolizjê z grzybami.
	* @param mushrooms Wektor wskaŸników do obiektów klasy Mushroom reprezentuj¹cych grzyby.
	* @param newHead Nowa g³owa wê¿a.
	*/
	void checkCollisionWithMushroom(std::vector<Mushroom*> mushrooms, Point newHead);
	/**
	* @brief Porusza wê¿em z uwzglêdnieniem animacji (tweening).
	* @param apple WskaŸnik do obiektu klasy Apple reprezentuj¹cego jab³ko.
	* @param mushrooms Wektor wskaŸników do obiektów klasy Mushroom reprezentuj¹cych grzyby.
	* @param elapsedTime Czas, który up³yn¹³ od ostatniego kroku animacji.
	*/
	void moveSnakeWithTweening(Apple* apple, std::vector<Mushroom*> mushrooms, double elapsedTime);
	static int score;/**< Aktualny wynik gry. */
	/**
	* @brief Funkcja interpolacji liniowej.
	* @param a Pocz¹tkowa wartoœæ.
	* @param b Koñcowa wartoœæ.
	* @param t Wartoœæ od 0.0 do 1.0 okreœlaj¹ca stopieñ interpolacji.
	* @return Wynik interpolacji liniowej.
	*/
	float lerp(float a, float b, float t);
};

#endif  // SNAKE_H