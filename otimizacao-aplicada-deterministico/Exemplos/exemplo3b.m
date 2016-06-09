function xdot = exemplo3b(t,x)

xdot = zeros(size(x,1),1);
g = 9.8;
L = 0.5;

xdot(1) = x(2);
xdot(2) = -(g/L)*sin(x(1));





