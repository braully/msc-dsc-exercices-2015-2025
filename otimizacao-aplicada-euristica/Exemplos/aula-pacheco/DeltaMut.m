clc; warning off; clear all; close all;

gmax = 100;
g = 1:gmax;

for ia = 1:length(g)
    D1(ia) = 1/g(ia);
    D2(ia) = 1/g(ia) * rand(1);
end


plot(g,D1,'r');
hold on;
plot(g,D2,'b');
hold off;