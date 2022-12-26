clc; clear;

fs = 8000;
cf_p = 1500;   % passband cutoff freq
cf_s = 2000;   % stopband cutoff freq

r_p = 1;    % passband에서의 최대오차
r_s = 60;   % stopband에서의 최소감쇠량

e_p = 10^(r_p/20)-1; % epsilon_p
e_s = 10^(-r_s/20);  % epsilon_s

% 최적 FIR 필터 차수 추정 %
[n, f0, a0, w] = firpmord([cf_p cf_s], [1 0], [e_p e_s], fs);

% 최적 FIR 필터 설계함수 %
b = firpm(n, f0, a0, w);
freqz(b);

