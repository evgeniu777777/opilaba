# Задание 2. Разработка программного продукта 

Вариант 20

## Условие

На хоккейном стадионе в одном большом городе расположено большое прямоугольное табло размером `n` строк на `m` столбцов (то есть состоит из `n x m` ячеек). Во время хоккейного матча табло служит для отображения счета и времени, прошедшего с начала тайма, а в перерывах на нем показывают различную рекламу.

Задача заключается в проверке возможности показа на табло определенной рекламной заставки. Заставка также имеет размер `n` строк на `m` столбцов. Каждая из ячеек заставки окрашена в один из четырех цветов - трех основных: красный (R), зеленый (G), синий (B) и черный (точка '.'). 

Каждая из ячеек табло характеризуется своими цветопередаточными возможностями. Любая из ячеек табло может отображать черный цвет, что соответствует тому, что на нее вообще не подается напряжение. Также каждая из ячеек может отображать некоторое подмножество множества основных цветов. В этой задаче эти подмножества кодируются следующим образом:

- `0` - ячейка может отображать только черный цвет;
- `1` - ячейка может отображать только черный и синий цвета;
- `2` - ячейка может отображать только черный и зеленый цвета;
- `3` - ячейка может отображать только черный, зеленый и синий цвета;
- `4` - ячейка может отображать только черный и красный цвета;
- `5` - ячейка может отображать только черный, красный и синий цвета;
- `6` - ячейка может отображать только черный, красный и зеленый цвета;
- `7` - ячейка может отображать черный, красный, зеленый и синий цвета.

Напишите программу, которая по описанию табло и заставки определяет: возможно ли на табло отобразить эту заставку.

## Входные данные

- Целые числа `n` и `m` (1 ≤ n, m ≤ 100).
- `n` строк по `m` символов каждая - описание заставки (каждый из символов описания заставки принадлежит множеству {R, G, B, .}).
- `n` строк по `m` чисел, соответствующие возможностям ячейки табло.

## Выходные данные

- `YES`, если на табло возможно отобразить заставку, и `NO` - в противном случае.


## Примеры

### Ввод

```
3 3

.GB
R.B
RG.

0 1 2 
3 4 5
6 7 0
```

### Вывод

```
No
```

### Ввод

```
2 3

RGB
.G.

7 7 7 
7 7 7
```
### Вывод

```
Yes
```
