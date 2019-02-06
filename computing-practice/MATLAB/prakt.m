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
% epsilon - погрешность
epsilon = input('Введите epsilon: ');

% проверить, что функция меняет знак на введенном интервале
fValMin = fun(tMin);
fValMax = fun(tMax);
if (fValMin >= 0 && fValMax >= 0 || fValMin < 0 && fValMax < 0)
    disp('Значение функции должно менять знак на заданном интервале');
    disp('Нахождение корня методом хорд невозможно');
    return;
end

% вычислять методом хорд, пока погрешность больше требуемой
min = tMax;
max = tMax;
while(abs(tMax - tMin) > epsilon)
    tMin = tMax - (tMax - tMin) * fun(tMax) / (fun(tMax) - fun(tMin));
    tMax = tMin + (tMin - tMax) * fun(tMin) / (fun(tMin) - fun(tMax));
end
fVal = fun(tMax);

% вывод результата
fprintf('\nКорнем уравнения является число %5.7f\n', tMax);
fprintf('Функция при таком значении t равна %5.7f\n\n', fVal);
