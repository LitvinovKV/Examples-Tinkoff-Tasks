#Задание
В прямоугольной комнате представителей Tinkoff.ru пол это рисунок карты некоторой части Москвы. У Арсения в кармане лежит календарик, где изображена ровно та же часть Москвы, но в мнеьшем масштабе (по сути уменьшенная копия пола с сохранением отношения сторон). Сеня выронил календарь рисунком вверх, так, что календарь находится строго внутри комнаты.
При таком положении должна существовать "неподвижная точка": если проткнуть иголкой и календарь и пол насквозь в этой точке, прокол будет соответсвовать одной и той же точке на местности.

#Входные данные
Первая строка содержит два вещественных числа: ширину X и длину Y комнаты (1 <= X, Y <= 1000). Углы комнаты расположены в декартовой прямоугольной системе координат в точках (0,0), (X,0), (X,Y), (0,Y).
Вторая строка содержит восемь вещественных чисел - углы календаря в той же системе координат. Сначала идет угол календаря, соответсвующий точке (0,0), затем (X,0), (X,Y) и (0, Y).
Входные данные корректны: календарь имеет те же пропорции, что и пол комнаты, календарь не выходит за пределы комнаты.
Все вещественные числа заданы с точностью до 5 знаков после запятой. Масштаб календарика по отношению к полу не менее 0.0001 и не более 1.

#Результат работы
2 вещественных числа, координаты неподвижной точки с точностью 3 знака после запятой.

#Пример
10 5
1 1.5 3 1.5 3 2.5 1 2.5
1.250 1.875