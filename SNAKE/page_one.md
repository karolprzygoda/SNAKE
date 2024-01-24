@mainpage Strona glowna dokumentacji

## Autorzy

- Karol Przygoda

- Bartosz Sułek

- Grupa: 3ID14A

- Przedmiot: Podstawy Grafiki Komputerowej

- Temat: Implementacja gry Snake

## Informacje wstepne

- Dokumentacja ta opisuje program Snake napisany w jezyku C++ z wykorzystaniem biblioteki graficznej Allegro.

- Snake to prosta gra polegajaca na poruszaniu sie weza po polu gry i
  zbieraniu jedzenia w tym przypadku czerwonych jablek.

- Celem gry jest uzyskanie jak najlepszego wyniku punktowego poprzez zbieranie jablek bez dotkniecia scian, trujacych
  grzbyow lub wlasnego ciala.

- Gra posiada 3 rozne poziomy trudnosci ktore odzwierciedla
  ilosc grzybow na planszy.

- Uzyskany wynik ma rowniez mozliwosc bycia wyswietlonym w
  tablicy wynikow jezeli jest wystarczajaco wysoki.

- Program zostal napisany z wykorzystaniem biblioteki Allegro, ktora umozliwia tworzenie
  grafiki i interfejsu uzytkownika w aplikacjach napisanych w jezyku C/C++. Dzieki temu
  mozliwe jest stworzenie atrakcyjnego wizualnie interfejsu gry oraz latwe obslugiwanie
  zdarzen za pomoca klawiatury.

- Dokumentacja ta zawiera opis funkcji i niektorych zmiennych uzytych w programie.
  Przewodnik ten jest przeznaczony dla osob znajacych podstawy jezyka C i chcacych dowiedziec sie wiecej o tym, jak zostal
  zaimplementowany Snake z wykorzystaniem biblioteki Allegro.

## Elementy biblioteki Allegro uzyte w projekcie

### Procedury inicializujace

- al_init() - procedura inicializacji biblioteki allegro

- al_install_keyboard() - procedura inicializujaca obsluge klawiatury w aplikacji

- al_install_audio() - procedura inicializujaca obsluge dziwkow w aplikacji

- al_init_acodec_addon() - procedura inicjalizacji dodatku ACodec (Audio Codec) ktory umozliwia obsluge plikow audio w roznych formatach

- al_init_image_addon() - procedura inicjalizacji dodatku do obslugi obrazow

### Funkcje tworzace niezbedne elementy

- al_create_timer("float" / "float") - funkcja ktora sluzy do tworzenia obiektu timera. Timer to narzedzie, ktore pozwala na wyzwalanie okreslonych zdarzen co jakis czas. Jako argumenty funkcji podajemy czestotliwosc z jaka chcemy aby nasza aplikacja sie odswiezala NP: (1.0/60) - Tworzenie timera z czestotliwoscia 60 klatek na sekunde (60 FPS). Zwraca ona wskaznik na stworzony timer.

- al_create_event_queue() - funkcja ktora sluzy do stworzenia kolejki zdarzen ktora jest narzedziem umozliwiajacym aplikacji rejestrowanie i odbieranie zdarzen jak klikniecia mysza, nacisniecia klawiszy. Funkcja zwaraca wskaznik na utworzona kolejke zdarzen.

- al_create_display(width, height) - funkcja ktora tworzy okno aplikacji. Pierwszym podanym elementem jest szerokosc okna a drugim jego wysokosc (podanych jako liczby calkowite dodatnie). Funkcja zwaraca wskaznik na utworzone okno.

- al_create_builtin_font() - funkcja ktora tworzy czcionke wbudowana czyli taka ktora jest bezposrednio dostepna w bibliotece Allegro. Funkcja zwarca wskaznik na utworzona czcionke.

- al_create_sample_instance(song) - funkjca sluzy do tworzenia instancji probki dzwiekowej. Instancja probki dzwiekowej to obiekt, ktory reprezentuje konkretne wystapienie dzwieku w aplikacji. Mozna utworzyc wiele instancji tego samego dzwieku i odtwarzac je w roznych miejscach lub z roznymi ustawieniami, takimi jak glosnosc, panowanie czy predkosc odtwarzania. Jako argument nalezy podac zmienna ktora posiada wskaznik na plik z dzwiekiem ktory chcemy zmodyfikowac. Funkcja zwraca wskaznik na utworzona instancje.

### Funckje wczytujace

- al_load_sample(nazwa.rozszerzenie) - funcja wczytujaca probke dzwieku podanej jako argument ktorym jest nazwa pliku dzwiekowego wraz z jego rozszerzeniem. Zwraca wsaznik na podany plik.

- al_load_bitmap("nazwa.rozszerzenie") - funkcja wczytujaca obraz podano jako argument ktorym jest nazwa pliku w ktorym znajduje sie pozadnay obraz wraz z jego rozszerzeniem.Zwraca wskaznik na podany plik.

### Dodatkowe funkcje

- al_set_window_position(disp,argument2,argument3) - funkcja ktora ustawia pozycje okna na ekranie jako argumenty nalezy podac 1.wskaznik na okno 2.wspolzedna w poziomie 3. wspolzedna w pionie (w pixelach)

- al_set_window_title(disp,"tytul") - funkcja ktora ustawia tytul aplikacji na wprowadzony jako drugi argument funkcji, pierwszym argumentem funkcji jest wskaznik na okno w ktorym chcemy ustawic tytul

- al_reserve_samples("int") - funkcja, ktora sluzy do rezerwowania miejsca dla probek dzwieku. Probki dzwieku to nagrania dzwieku, ktore moga byc odtwarzane przez biblioteke Allegro. Jako argument nalezy podac ilosc probek (liczbe calkowita dodatnia) ktore maja zostac zarezerwowane.

- al_set_sample_instance_playmode(argument,2argument) - funkcja ktora sluzy do ustawienie trybu odtwarzania dla instacji probki dziwkowej. Jako pierwszy argument nalezy podac wskaznik na instacje probki a jako drugi argument tryb odtwarzania.

- al_attach_sample_instance_to_mixer(argument, 2argument) - funkcja ktora sluzy do przypisania instancji probki dzwiekowej do miksera. Mikser to obiekt, ktory pozwala na odtwarzanie wielu dzwiekow jednoczesnie i laczenie ich w jeden efekt dzwiekowy. Jako argumenty nalezy podac 1.wskaznik na instacje probki 2.mikser do ktorego chcemy przylaczyc instancje

- al_set_display_icon(disp,ikona) - funckja ktora sluzy do ustawienia ikony projektu. Jako pierwszy argument nalezy podac wskaznik na uzywane okno jako drugi argument nalezy podac wskaznik na plik w ktorym ikona sie znajduje

- al_register_event_source(argument,2argument) - funkcja , ktora sluzy do rejestrowania zrodla zdarzen w kolejce zdarzen. Pierwszym argumentem jest kolejka zdarzen drugim natomiast zdarzenie ktore ma byc obslugiwane np obsluga klawiatury

- al_rest(argument) - funkcja ktora zatrzymuje dzialanie aplikacji na czas podany w argumencie w sekundach jako liczba rzeczywista dodatnia.

- al_clear_to_color() - funkcja, ktora sluzy do wyczyszczenia ekranu do okreslonego koloru podanego w argumencie jako inna funcja al_map_rgb(0, 0, 0).

- al_map_rgb(0, 0, 0) - funckja ustawiajaca kolor podany w argumentach.

- al_draw_bitmap(wskaznik,0,0,0) - funkcja wyswietlajaca bitmape. Argumentami funkcji sa 1.wskaznik na pozadana bitmape 2. kolor kotry ma byc uzupelniem bitmapy 3. -||- 4. -||-.

- al_flip_display() - funkcja odswiezajaca ekran.

- al_get_keyboard_state(&KeyState) - funkcja ktora pobiera stan klawiatury. Jako argument nalezy podac wskaznik na stan klawiatury.

- al_key_down() - funkcja , ktora sluzy do sprawdzenia, czy dany klawisz jest wcisniety.

- al_play_sample_instance(SongInstance) - funkcja, ktora sluzy do odtwarzania dzwieku za pomoca instancji probki dzwiekowej. Jako argument nalezy podac wskaznik na instacje probki dzwiekowej.

- al_start_timer(timer) - funkcja, ktora sluzy do uruchomienia licznika czasu. Jako argument nalezy podac wskaznik na licznik czasu.

- al_draw_textf() - funckja ktora wypisuje tekst na ekranie. Jako argumenty nalezy podac wskaznik na czcionke, kolor czcionki, miejsce wyswietlenia oraz tekst jaki ma zostac wyswietlony.

### Funkcje usuwajace

- al_destroy_bitmap() - funkcja usuwa bitmape z pamieci. Jako argument nalezy podac wskaznik na plik zawierajacy bitmape.

- al_destroy_sample_instance() - funkcja usuwa instancje dzwieku z pamieci. Jako argument nalezy podac wskaznik na instacje dzwieku.

- al_destroy_display() - funkcja usuwajaca okno aplikacji z pamieci. Jako argument nalezy podac wskaznik na okno aplikacji.

- al_destroy_timer() - funkcja usuwajaca licznik czasu z pamieci. Jako argument nalezy podac wskaznik na licznik czasu.

- al_destroy_event_queue() - funkcja usuwajaca kolejke zdarzen z pamieci. Jako argument nalezy podac wskaznik na kolejke zdarzen.

@note

- Program posiada pliki z rozszerzeniem .cpp w kotrych zawarte sa wnetrza opisywnaych funkcji aplikacji. W dokumentacji wyswietlane beda tylko pliki naglowkowe oraz plik zawierajacy funkcje glowna main() w celu unikniecia redundancji informacji o projekcie.

- W programie uzyta jest biblioteka systemowa systemu Operacyjnego Windows ktora zostala uzyta w celu "schowania" okna konsoli programu. Jezeli uzytkownik korzysta z innego systemu operacyjnego konsola bedzie dalej widoczna natomiast nie jest konieczne usuwanie badz komentowanie linijek kodu odpowiedzialnych za te opreracje poniewaz w aplikacji zostal zaimplementowany mechaniznm wykrywania systemu operacyjnego windows.
