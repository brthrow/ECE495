%{
    Joshua Smith
    ECE 495 - Clemson University
    Testing Image Processing Functionality with Static Imaages
    3/8/2017
%}
 
clear
clc
close all;
tic
% load images
background=imread('background.JPG');
newimg=imread('6balls.JPG');
table=newimg;

background=rgb2gray(background);
newimg=rgb2gray(newimg);

figure, imshow (table); hold on;

v={};
for i=3:1:9
    back=im2bw(background,i/10-0.1);
    new=im2bw(newimg,i/10);
    foreground=bitxor(new,back);
    binimg=im2bw(foreground,0.5);
    [centers, radii, metric]=imfindcircles(binimg,[22,35]);
    if size(centers) > 0 
        if exist('v_centers')
            v_centers=[v_centers; centers];
            v_radii=[v_radii; radii];
            v_metric=[v_metric; metric];
        else
            v_centers=centers;
            v_radii=radii;
            v_metric=metric;
        end
    end
    clear back; clear new; clear foregroun; clear binimg;
    clear centers; clear radii; clear metric;
end

num=length(v_radii);
rad=mean(v_radii);
bin=ones(num,1);

idx = rangesearch(v_centers, v_centers, rad);

center=[];
radii=[];
metric=[];

k=1;
for i=1:1:num
    if bin(i)
        for j=1:1:(length(idx{i})-1)
            bin(idx{i}(1+j),1)=0;
        end
        center(k,:)=v_centers(i,:);
        radii(k,:)=v_radii(i,:);
        metric(k,:)=v_metric(i,:);
        k=k+1;
    end
end

viscircles(center, radii, 'EdgeColor','b');
toc