#Задание
Представитель Tinkoff.ru создал телепорт между пунктами 1,2....N. Телепорт в стадии тестирования и список поддерживаемых перемещений пока ограничен. Представитель хочет попасить из пункта 1 в пункт N. При этом, если он находится в пункте K (1 <= K <= N), то производит обслуживание клиента в этом пункте, которое занимает фиксированное индивидуальное время. Через какое минимальное время он сможет оказаться в пункте N?

#Входные данные
Первая строка содержит число N (1 <= N <= 100). Следующая строка содержит N чисел - время обслуживания клиента в пунктах 1,2...N соответственно. Время обслуживания занимает от 0 до 100 минут. Следующая строка содержит кол-во поддерживаемых телепортом путей M. Далее идет M строк, каждая из которых содержит номера пары пунктов, которые соединяет телепорт. Все перемещения поддерживаются в обе стороны, телепорт перемещает между двумя пунктами единственным образом и не перемещает на то же самое место, где сейчас находится представитель.

#Результат работы
Одно число - минимальное время, через которое представитель сможет оказаться в пункте N и -1, если добраться до него невозможно.

#Примеры
9
5 3 4 5 7 9 1 2 5
12
1 3
1 2
2 4
3 4
2 5
4 5
4 6
6 9
4 7
7 8
5 8
8 9