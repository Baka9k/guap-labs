a = 1.5;
b = 2.5;
c = 1;

t = (0:0.05:2)';
v = [0:0.05*pi:2*pi];

X = a * cosh(t) * ones(size(v));
Y = b * sinh(t) * sin(v);
Z = c * sinh(t) * cos(v);

figure('Color','w')
hS1=mesh(X,Y,Z);

hold on

X=-X;

hS2=mesh(X,Y,Z);
colormap(flag);

xlabel('x'); ylabel('y'); zlabel('z')