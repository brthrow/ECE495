%{
    Joshua Smith
    ECE 495 - Clemson University
    Testing Image Processing Functionality with Static Imaages
    3/8/2017
%}
 
clear
clc
close all;

% load images
background=imread('background.JPG');
newimg=imread('6balls.JPG');
table=newimg;

background=rgb2gray(background);
newimg=rgb2gray(newimg);

figure, imshow (table); hold on;

for i=1:1:10
    back=im2bw(background,i/10-0.1);
    new=im2bw(newimg,i/10);
    foreground=bitxor(new,back);
    binimg=im2bw(foreground,0.5);
    [centers, radii, metric]=imfindcircles(binimg,[20,32]);
    viscircles(centers, radii, 'EdgeColor','b');
    disp(radii);
    clear back; clear new; clear foregroun; clear binimg;
    clear centers; clear radii; clear metric;
end




