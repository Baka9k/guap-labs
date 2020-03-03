% плоскость 1
subplot(2,1,1)

% график 1
f1 = @(x)3*x.^4+4*x.^3-12*x.^2-7;
fplot(f1, [-10 10], 'b');

hold on;
ylim([-50 50])
xlabel('x');
ylabel('y');
title('$3x^{4}+4x^{3}-12x^{2}-7=0$','Interpreter','latex')
grid on;



% плоскость 2
subplot(2,1,2)

% график 2
f2 = @(x,y)x.^3+y.^3-6;
fcontour(f2, [-10 10], 'b');
hold on;

% график 3
f3 = @(x)exp(-x);
fplot(f3, [-10 10], 'r');
hold on;

% корни
plot(-2.082, 8.016, 'ko', -0.604, 1.830, 'ko');
plot(1.807, 0.064, 'ko', 7.968, 0, 'ko');

text(-2.082, 9, 'Корень 1');
text(-0.604, 2.830, 'Корень 2');
text(1.807, 1.064, 'Корень 3');
text(7.968, 1, 'Корень 4');

xlabel('x');
ylabel('y');
ylim([-10 10])
title('$x^{3}+y^{3}=6, y=\exp^{-x}$','Interpreter','latex')
grid on;

