# ITMO_programming_2semester


## 1. Кольцевой буффер
ТЗ:

Реализовать к​ольцевой буфер в виде stl-совместимого контейнера (например, может быть использован с стандартными алгоритмами), обеспеченного итератором произвольного доступа Реализация не должна использовать ни одни из контейнеров STL. Буфер должен обладать следующими возможностями:

- Вставка и удаление в конец
- Вставка и удаление в начало
- Вставка и удаление в произвольное место по итератору
- Доступ в конец, начало
- Доступ по индексу
- Изменение капасити





## 2. REST-запросы. Получние курса валют (приложен отчет по работе)
ТЗ: 

Написать программу, которая обеспечит следующий функции:
- получение курса валюты к российскому рублю на выбранную дату
- получение курса валюты к российскому рублю на выбранный период
- сохранение полученной информации в файл

Программа выполняется из командной строки с параметрами. Параметры разделены пробелами. Параметр состоит из ключа и значения.
Формат параметра: `--<key>=<value>`

Параметры и список возможных значение:
* **Vname** – название валюты, значение - буквенный код валюты, например `. Полный список кодов: https://www.iban.ru/currency-codes. Обязательный паромер.
* **Vnom** – наминал валюты, значение – целое положительное число, обычно 1, может быть 10, 100 и т.д. Не обязательный параметр, по умолчанию номинал считается равным номиналу определяемому ЦБ РФ.
* **Date** – дата, на которую получают курс, значение – дата, формат: `dddd.mmmm.yyyy`. Не обязательный параметр, по умолчанию текущая дата.
* **DateDate** – период на который получают курс. Значение – дата начала и дата окончания периода включительно, разделенная символом `-`. Формат: `dddd.mmmm.yyyyyyyy-dddd.mmmm.yyyy`. Не обязательный параметр. Нет значения по умолчанию. Не совместим с параметром DateDate.
* **FileName** – имя, или полный путь, файла куда будет записан результат запроса. Значение – имя или путь в формате используемой операционной системы. Не обязательный параметр. Значения по умолчанию нет. При отсутствии параметры выводить информацию на экран.

Вывод информации в формате: `<код валюты> <номинал> <дата> <курс>`

Если выводится информация на период, то каждая дата выводится отдельной строкой.

Курс валют определяет ЦБ РФ.

Пример командной строки:

`Lab9.exe Vname=USD Vnom=10 Date=01.01.2024`

Получение курса 10 долларов США на 1 января 2024 года

Вывод:

`USD 10 01.01.2024 896 883`



## 3. Кубик Рубика 2D + OpenGL (приложен отчет по работе)
ТЗ:

Спроектировать и реализовать программу, имитирующую сборку [Кубика Рубика](https://ru.wikipedia.org/wiki/Кубик_Рубика) 3x3.

К программе предъявляются следующие функциональные требования:

- Сохранение и чтение состояния кубика рубика из файла.
- Проверка корректности текущего состояния (инвариант состояний кубика).
- Вывод в консоль текущего состояния.
- Вращение граней кубика рубика с помощью вводимых команд.
- Генерация случайного состояния Кубика Рубика, корректного с точки зрения инварианта состояний.
- Нахождения "решения" для текущего состояния в виде последовательности поворотов граней.


Нефункциональные требования:
- Программа должны быть спроектирована, с использованием ОПП.
- Логические сущности должны быть выделены в отдельные классы (1 класс = 1h/hpp + 1 cpp).

Критерии оценки:

Дополнительно (за дополнительные баллы):
Реализовать графический интерфейс приложения, с использованием [OpenGL Utility Toolkit](https://en.wikipedia.org/wiki/OpenGL_Utility_Toolkit)


