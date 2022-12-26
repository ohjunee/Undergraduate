clc; clear;

point = 32;

M = 1:point;
w = 2*pi/point;
h = [1/4, 1/2, 1/4, zeros(1, point-3)];
H = zeros(1, point);

for k = M
    for row = M
        H(k) = H(k) + h(row)*exp(-1i*w*(k-1)*(row-1));
    end
end

subplot(211)
stem(M-1, h(M))
xlabel('n')
ylabel('h[n]')
axis([-1 point 0 1])
title('Original data')

subplot(212)
stem(M-1, abs(H(M)))
xlabel('k')
ylabel('H[k]')
axis([-1 point 0 1])
title([num2str(point), '-point DFT'])


