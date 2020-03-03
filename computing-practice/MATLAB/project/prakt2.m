clc; clear all; close all;

% объявление функции
% fun = inline('3*exp(1)^(-5*t) * sin(7*t + 0.1) - 1');
% disp('f(t) = 3*exp(1)^(-5*t) * sin(7*t + 0.1) - 1');
userInput = input('Введите функцию: ', 's');
fun = inline(userInput);

% ввод переменных:
% tMin, tMax - пределы хорды
tMin = input('Введите tMin: ');
tMax = input('Введите tMax: ');

% найти корень на данном интервале с помощью 
% встроенной функции fzero()
interval = [tMin tMax]; % интервал
fZeroResult = fzero(fun, interval);

% вывод результата
fprintf('Корень, найденный функцией fzero: %5.7f\n', fZeroResult);
