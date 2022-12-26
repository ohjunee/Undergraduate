clc; clear;

point = 32;

M = 1:point;        % 32개의 인덱스를 나타냄
w = 2*pi/point;     % wk = w / N
h = [1/4,1/2,1/4, zeros(1,point-6), 1/4,1/2,1/4]; % orginal data
H = zeros(point);                    % dft 변환 값
h_r = zeros(point);                  % idft 변환 값

for k = M
    for row = M
        H(k) = H(k) + h(row)*exp(-1i*w*(k-1)*(row-1));
    end
end

for k = M
    for row = M
        h_r(k) = h_r(k) + H(row)*exp(1i*w*(k-1)*(row-1));
    end
    h_r(k) = h_r(k)/point;
end

subplot(3,1,1)
stem(M-1,h(M))
xlabel('n')
ylabel('h[n]')
axis([-1 point 0 1])
title('Original Data')

subplot(3,1,2)
stem(abs(H(M)))
xlabel('k')
ylabel('H[k]')
axis([0 32 0 2])
title([num2str(point), '-point DFT'])

subplot(3,1,3)
stem(M-1,h_r(M))
xlabel('n')
ylabel('h_r[n]')
axis([-1 point 0 1])
title('Reconstructed Data')


