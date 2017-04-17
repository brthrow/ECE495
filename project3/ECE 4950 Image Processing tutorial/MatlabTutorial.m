%A brief tutorial to using Image Processing Functions in MATLAB.
%This code loads an image of a gameboard, processes it using functions 
%for image processing applications such thresholding, background subtraction
%Many lines of code have been commented out, you can uncomment them to see
%the output. When in doubt, MATLAB Help files will come in handy. 
%Written for ECE 4950 Senior Design at Clemson University
%Author: Venkataraman Ganesh  
%10 October 2014

clc;
clear all;

%load and prepare the image: 
gameboard= imread('gameboard.jpg'); %Load your background image 
newimg= imread ('gameboardpin.jpg'); %Load your live image 

%if you ever have to rotate the image
%test = imrotate(gameboard, 90);

%convert to grayscale 
histimg= rgb2gray(gameboard); % converts rgb to gray, 
newimg2= rgb2gray(newimg);

%view histogram (useful when you want to estimate a threshold value for manual thresholding)
%figure, imhist(histimg,256); % 256 bins or pixel values


%Thresholding with graythresh
thresholdlevel= graythresh(histimg); % thresholds using inbuilt Otsu's thresholding method
%figure, imshow (histimg);

%manually thresholding with a cut-off value between 0 and 1, to get a binary image
thresh = im2bw(histimg,0.35);
thresh2 = im2bw(newimg2,0.45);% we can use a different threshold value to capture the foreground
%figure, imshow (thresh2);

%%% Image must be binary for background subtraction %%%

%dilate to fill in eroded foreground pixels
se = strel('square',10); % Structural element of 5x5 
dilate= imdilate(thresh, se);
dilate2= imdilate(dilate, se); %Dilate multiple times if needed
figure, imshow (dilate2);

%Background subtraction:
foreground= bitxor(thresh2, thresh); %there are multiple ways to do background subtraction, here we simply use bitwise XOR
%figure, imshow (foreground); %Foreground pixels separated 

%grayimg= rgb2gray(foreground);

%Convert to a binary image from the intensity image
binimg= im2bw(foreground,0.5);

%Use CC to identify connected components
CC = bwconncomp(binimg);

%Use regionprops to compute area/ find centroids
S = regionprops(CC,'Area');

g= S(1).Area; %Values stored in a struct

%Use regionprops to find centroid
cent = regionprops(binimg, 'centroid');
centroids = cat(1, cent.Centroid); %struct holds the centroids

%figure, imshow(foreground)
hold on
for x = 1: numel(S)
    if (S(x).Area>1000)
        plot(cent(x).Centroid(1),cent(x).Centroid(2),'rx');
    end
end
hold off


%label image regions
L = bwlabel(binimg);

%figure,imshow(binimg)
hold on
for i = 1:numel(cent)
    c = cent(i).Centroid;
    text(c(1), c(2), sprintf('%d', i), ...
        'HorizontalAlignment', 'center', ...
        'VerticalAlignment', 'middle');
end
hold off

[centers, radii, metric] = imfindcircles(binimg, [20,50]);
viscircles(centers, radii, 'EdgeColor', 'b');