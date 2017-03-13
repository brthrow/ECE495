% Test the image acquisition toolbox
% ECE 495 Fall 2012
%   ninad & matt, october 14 2012

% Notes
% 	- Source code modified from its original form ('Getting Started', pg 20) 
%   in Image Acquisition Toolbox User Guide for R2012a.
function imaqtest

%
clc; close all; clear all;
imaqreset; % reset device configuration. helps release open device handles.

% user inputs 
nmaxframes = 200; % how many frames should be displayed during trial?
nframegrab = 1; % get every nth frame from the camera

% create the video input object. specify the image format and size
%vid = videoinput('winvideo', 1, 'MJPG_160x120');
vid = videoinput('winvideo', 1, 'MJPG_640x480'); % capture a RGB image of size 640x480 pixels

% Set video input object properties for this application.
set(vid,'TriggerRepeat',Inf);
vid.FrameGrabInterval = nframegrab; % grab every nth frame from the device

% Create a figure window.
fig_image = figure;

% Start acquiring frames.
start(vid);

% Calculate difference image and display it.
while(vid.FramesAcquired <= nmaxframes) % stop after a user-specified number of frames
    
    data = getdata(vid,1); % get 1 frame from the video stream > defined using the second parameter
    im = data(:,:,:,1);
    
    figure(fig_image);
    imshow(im);
    title_txt = sprintf('Image %d',vid.FramesAcquired);
    title(title_txt);
    
end

stop(vid);
delete(vid);
clear;