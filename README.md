# planista
Jednym z zadań systemu operacyjnego jest przydział czasu procesora poszczególnym procesom. Napisz program realizujący prostego planistę.

Czas procesora powinien być przydzielany według następujących zasad:

każdy proces może mieć wysoki, normalny lub niski priorytet,
procesy i niższym priorytecie nie będą otrzymywały procesora, jeżeli istnieją procesy o priorytecie wyższym,
procesy o takim samym priorytecie wykonywane są na przemian, w kolejności ich utworzenia,
procesy można tworzyć, usuwać i zmieniać im priorytet,
jeżeli w systemie nie ma żadnego procesu, wykonywany jest specjalny proces o nazwie idle.
Każdy proces jest jednoznacznie identyfikowany przez swój numer (dodatnia liczba całkowita, nie większa niż 231-1).

Jeżeli w systemie są 3 procesy (1, 2, 3) o normalnym priorytecie, to będą one wykonywane w kolejności 1, 2, 3, 1, 2, 3, ... . Jeżeli dodamy w tym momencie proces 4 o priorytecie wysokim, to kolejnymi wykonywanymi procesami będą: 4, 4, 4, ... .

Rozwiązanie wykorzystujące dynamiczne struktury danych (lista, lista cykliczna) będzie zdecydowanie wyżej punktowane (max. 100%) niż zadanie korzystające z tablic (max 30%).

Wejście i wyjście

Na wejściu pojawi się ciąg komend:

n - przydzielenie czasu procesora kolejnemu procesowi; na wyjście należy wypisać numer zadania, które ma otrzymać procesor lub idle jeżeli w systemie nie ma zadań,
c id p - utworzenie procesu o numerze id i priorytecie p, 1 oznacza priorytet wysoki, 0 to priorytet normalny, zaś -1 - priorytet niski; nowo utworzone zadanie powinno trafiać na koniec kolejki o danym priorytecie, jeżeli w sytuacji 0: 2 3 1 wykonamy c 4 0 wynikiem powinno być 0: 2 3 1 4,
t id - oznacza zakończenie zadania o numerze id,
p id p - zmiana priorytetu zadania o numerze id na p (rownoważne usunięciu zadania id i dodaniu go z nowym priorytetem),
l - (mała litera L) lista zadań; należy wypisać wszystkie zadania w formacie:
1: 
0: 
-1:
Np. jeżeli w systemie są zadania 1, 2, 3, 4, 5, przy czym 1, 2, 3 mają normalny priorytet a 4 i 5 wysoki, 4 będzie wykonane wcześniej niż 5, a zadania 1, 2, 3 byłyby wykonane w takiej kolejności (np. po usunięciu zadań 4 i 5) to na wyjściu powinno pojawić się:
1: 4 5
0: 1 2 3
-1:
