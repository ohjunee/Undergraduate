clc; clear;

x = 0:0.001:1;
freq = 5;

original = cos(2*pi*freq*x);                    % 원 신호

subplot(3,1,1)
plot(x,original);
title('original signal')

sampling_freq = 11;                             % 샘플링 주파수

sampled = zeros(0, sampling_freq);
reconstructed = 0;                              % 복원된 신호

for i = 0:sampling_freq
    sampled(i+1) = cos(2*pi*freq*i/sampling_freq);
    reconstructed = reconstructed + sampled(i+1)*sinc((x-i/sampling_freq)*sampling_freq);
end

subplot(3,1,2)
stem(0:1/sampling_freq:1, sampled)
title([num2str(sampling_freq), 'Hz sampling'])

subplot(3,1,3)
plot(x, reconstructed(1:length(x)))
title([num2str(sampling_freq), 'Hz sampling reconstruction'])