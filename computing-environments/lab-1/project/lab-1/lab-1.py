# Необходимо разработать программу на языке Python для отображения графика функции или системы функций.
# Для построения графика необходимо использовать модуль matplotlib, математические функции и константы
#   доступны в модулях math, numpy.
# Значения коэффициентов a, b, c и d заданной по варианту математической функции должны считываться из внешнего файла,
#   представленного в формате TSV (Tab Separated Values).
# Для обозначения координатных осей и заголовка координатного пространства использовать команды системы верстки LaTeX.
#
#
# Вариант 16
#
# Символами a, b, c и d обозначены параметры;
#  y – зависимая переменная (значение функции);
#  x – независимая переменная (аргумент функции).
#
# y = a * (sin(b * x) + tg(c * x))
#


import matplotlib.pyplot
import numpy
import csv


# Считать a, b и c из файла
with open("values.tsv") as fd:
    rd = csv.reader(fd, delimiter="\t")
    for row in rd:
        a = float(row[0])
        b = float(row[1])
        c = float(row[2])

x = numpy.arange(-10.0, 10.0, 0.01)
y = a * (numpy.sin(b * x) + numpy.tan(c * x))

matplotlib.pyplot.xlabel(r'x', color='b')
matplotlib.pyplot.ylabel(r'y', color='b')
matplotlib.pyplot.title(r'$a(\sin (bx) + \tan (cx))$', color='g')

matplotlib.pyplot.plot(x, y, 'r')
matplotlib.pyplot.show()
