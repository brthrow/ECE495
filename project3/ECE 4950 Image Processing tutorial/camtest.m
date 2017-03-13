%A brief tutorial to using Image Processing Functions in MATLAB.
%This code loads an image of a gameboard, processes it using functions 
%for image processing applications such thresholding, background subtraction
%Many lines of code have been commented out, you can uncomment them to see
%the output. When in doubt, MATLAB Help files will come in handy. 
%Written for ECE 4950 Senior Design at Clemson University
%Author: Venkataraman Ganesh  
%10 October 2014

%Get to know your camera:

info= imaqhwinfo('winvideo');
info.DeviceInfo.SupportedFormats; %we get to see the supported formats

%create a video object
vid = videoinput('winvideo', 1,'MJPG_640x480'); %1 is the built-in camera, the external camera will be 2
set(vid, 'ReturnedColorSpace', 'RGB');

%grab a frame from the video object
img = getsnapshot(vid);
figure, imshow(img)

%image processing : find contour of the object in the image
cont=imcontour(rgb2gray(img));
figure, imshow(cont);

