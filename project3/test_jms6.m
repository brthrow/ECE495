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
background=imread('testBG.JPG');
newimg=imread('test6B.JPG');
table=newimg;

background=rgb2gray(background);
newimg=rgb2gray(newimg);

figure, imshow (table); hold on;

v={};
for i=1:1:10
    back=im2bw(background,i/10-0.1);
    new=im2bw(newimg,i/10);
    foreground=bitxor(new,back);
    binimg=im2bw(foreground,0.5);
    [centers, radii, metric]=imfindcircles(binimg,[10,25]);
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
    clear back; clear new; clear foreground; clear binimg;
    clear centers; clear radii; clear metric;
end

num=length(v_centers);
rad=mean(v_radii);
bin=zeros(num,1);

for i=1:1:num
   if (v_centers(i,1)>145 && v_centers(i,1)<590)
       if (v_centers(i,2)>130 && v_centers(i,2)<395)
           bin(i)=1;
       end
   end
end

idx = rangesearch(v_centers, v_centers, rad*1.5);

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

viscircles(center, radii, 'EdgeColor','b','LineStyle','--');

num=length(metric);
color = {};
for b=1:1:num
    ballNum = sprintf('%1.0f', b);
    text(center(b,1),center(b,2),ballNum,'HorizontalAlignment','center',...
        'VerticalAlignment','middle','color','g',...
        'FontWeight','bold','FontSize',14);
    x = round(center(b,2));
    y = round(center(b,1));
    rA=table(x-5:x+5,y-5:y+5,1);
    gA=table(x-5:x+5,y-5:y+5,2);
    bA=table(x-5:x+5,y-5:y+5,3);
    %{
    for i=-5:1:5
        for j=-5:1:5
            r8 = table(x+i, y+j, 1);
            g8 = table(x+i, y+j, 2)
            b8 = table(x+i, y+j, 3)
            r = r + typecast(r8,'double');
            g = g + typecast(g8,'double');
            b = b + typecast(b8,'double');
            count = count + 1;
        end
    end
    %}
    red = mean(mean(rA));
    green = mean(mean(gA));
    blue = mean(mean(bA));
    color{b} = getColor(red, green, blue);
    theta(b) = atand((365-center(b,1))/((445+55)-center(b,2)));
    fprintf('The color of the ball %s is %s, and it''s center is at (%d, %d)\n', ballNum, color{b}, round(center(b,1)), round(center(b,2)));
end
fprintf('The number of pool balls in this picture is %d\n\n',length(center));

flag = 0;
while 1 %~flag
    flag = menu('Please choose a color from the ones listed','red','black','blue','yellow','white','orange','all');
    switch flag
        case 1
            select = 'red';
        case 2
            select = 'black';
        case 3
            select = 'blue';
        case 4
            select = 'yellow';
        case 5
            select = 'white';
        case 6
            select = 'orange';
        case 7
            select = 'all';
    end
    bNum = strmatch(select,color);
    if flag ~= 0 && flag ~= 7
        set_param('Project3/Constant','Value',num2str(theta(bNum)));
            pause(2);
    elseif flag == 7
        for i=1:1:num
           set_param('Project3/Constant','Value',num2str(round(theta(i))));
           pause(2);
        end 
    end
end

toc