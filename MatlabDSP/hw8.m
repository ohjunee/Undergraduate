clc; clear all;

M = 100;                     % 필터의 차수
fc = 0.68;                  % cut off freq
wh = hamming(M+1);           % 해밍 윈도우 함수
hd1 = fir1(M, fc, wh);       % 인자로 주어지는 창 함수 기반의 FIR 설계 (필터의 차수, 차단주파수, 윈도우 함수)

beta = 10;
wk = kaiser(M+1, beta);      % Kaiser 윈도우 함수
hd2 = fir1(M, fc, wk);       % 인자로 주어지는 창 함수 기반의 FIR 설계 (필터의 차수, 차단주파수, 윈도우 함수)

subplot(221)
stem(wh)
title('Hamming window function')

subplot(222)
stem(hd1)
title('Impulse Response of LPF using Hamming window')

subplot(223)
stem(wk)
title('Kaiser window function')

subplot(224)
stem(hd2)
title('Impulse Response of LPF using Kaiser window')

% 주파수 대역에서의 저역통과 필터의 시각화 
figure;grid
freqz(hd1)
title('Frequency Response of LPF using Hamming window')

figure;grid
subplot(212)
freqz(hd2)
title('Frequency Response of LPF using Kaiser window')

