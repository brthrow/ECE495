%A brief tutorial to using Image Processing Functions in MATLAB.
%This code loads an image and processes it using regionprops and connected
%components.
%Many lines of code have been commented out, you can uncomment them to see
%the output. 
%When in doubt, MATLAB Help files will come in handy. 
%Written for ECE 4950 Senior Design at Clemson University
%Author: Venkataraman Ganesh  
%10 October 2014

clc;

%load the image: 
img= imread('regionprops.jpg');
grayimg= rgb2gray(img);

%Convert to a binary image from the intensity image
binimg= im2bw(grayimg,0.5);

%Use CC to identify connected components
CC = bwconncomp(binimg);

%Use regionprops to compute area/ find centroids
S = regionprops(CC,'Area');

%g= S(1).Area; %Values stored in a struct

%Use regionprops to find centroid
cent = regionprops(binimg, 'centroid');
centroids = cat(1, cent.Centroid); %struct holds the centroids

figure, imshow(grayimg)
hold on
for x = 1: numel(S)
    plot(cent(x).Centroid(1),cent(x).Centroid(2),'rx');
end
hold off


%label image regions
L = bwlabel(binimg);

figure,imshow(binimg)
hold on
for i = 1:numel(cent)
    c = cent(i).Centroid;
    text(c(1), c(2), sprintf('%d', i), ...
        'HorizontalAlignment', 'center', ...
        'VerticalAlignment', 'middle');
end
hold off



