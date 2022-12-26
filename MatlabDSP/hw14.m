clc; clear;

img = imread('LENNA.bmp');

nearest = imresize(img, 3, 'nearest');
bilinear = imresize(img, 3, 'bilinear');
bicubic = imresize(img, 3, 'bicubic');

subplot(221)
imshow(img) % 원본이미지 출력, 이미지 출력함수 imshow
title('Original signal')
axis([100 150 100 150])

subplot(222)
imshow(nearest)
title('2D nearest neighbor interpolation')
axis([300 450 300 450])

subplot(223)
imshow(bilinear)
title('bilinear interpolation')
axis([300 450 300 450])

subplot(224)
imshow(bicubic)
title('bicubic interpolation')
axis([300 450 300 450])
