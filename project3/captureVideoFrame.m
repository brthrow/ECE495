% Test the image acquisition toolbox
% ECE 495 Fall 2012
%   ninad & matt, nov 9 2012

% Notes
% 	- Source code modified from its original form ('Getting Started', pg 20) 
%   in Image Acquisition Toolbox User Guide for R2012a.

function im = captureVideoFrame(vidLength,nframegrab,figureHandle)
% 'vidLength' - length in seconds of video to capture a frame
% 'nframegrab' - get every nth frame from the camera
% 'figureHandle' - optional passing of figure handle for displaying video
%                  in a figure selected by the user
% 'im' - written for use with HP webcam vid properties, returns a jpg

%Example: im = captureVideoFrame(10,2,figHandle)
%**************************************************************************
imaqreset; % reset device configuration. helps release open device handles.

% user inputs 
fps = 30; % frames per second retrieval rate
nmaxframes = vidLength/nframegrab*fps; % how many frames should be displayed


% create the video input object. specify the image format and size
vid = videoinput('winvideo', 1, 'MJPG_640x480'); % capture a RGB image of size 640x480 pixels

% Set video input object properties for this application.
set(vid,'TriggerRepeat',Inf);
vid.FrameGrabInterval = nframegrab; % grab every nth frame from the device

if ~exist('figureHandle','var')
    % Create a figure window.
    close(findobj('type','figure','name','Video')); % house-cleaning if the window is previously open
    figureHandle = figure('name','Video','numbertitle','off');
end

figure(figureHandle);
% Start acquiring frames.
start(vid);

% Calculate difference image and display it.
while(vid.FramesAcquired <= nmaxframes) % stop after a user-specified number of frames
    
    data = getdata(vid,1); % get 1 frame from the video stream > defined using the second parameter
    im = data(:,:,:,1);
    imshow(im);
    title_txt = sprintf('Image %d',vid.FramesAcquired);
    title(title_txt);
    
end

stop(vid);
delete(vid);
end