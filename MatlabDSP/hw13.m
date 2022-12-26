clc; clear;

x = 0:6; % 정의역
fx = [0 0.8415 0.9093 0.1411 -0.7568 -0.9589 -0.2794]; % 샘플값
xd = 0:0.001:6;% 보간되는 샘플 값 위치(쿼리 값)

near = interp1(x, fx, xd, 'near');
linear = interp1(x, fx, xd, 'linear');
cubic = interp1(x, fx, xd, 'cubic');

subplot(221)
stem(x,fx)
title('Original Signal')

subplot(222)
plot(xd,near)
title('Nearest-Neighbor Interpolation')

subplot(223)
plot(xd,linear)
title('Linear Interpolation')

subplot(224)
plot(xd,cubic)
title('Cubic Interpolation')
