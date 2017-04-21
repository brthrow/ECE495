function varargout = p3GUI(varargin)
% P3GUI MATLAB code for p3GUI.fig
%      P3GUI, by itself, creates a new P3GUI or raises the existing
%      singleton*.
%
%      H = P3GUI returns the handle to a new P3GUI or the handle to
%      the existing singleton*.
%
%      P3GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in P3GUI.M with the given input arguments.
%
%      P3GUI('Property','Value',...) creates a new P3GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before p3GUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to p3GUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help p3GUI

% Last Modified by GUIDE v2.5 19-Apr-2017 14:32:22

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @p3GUI_OpeningFcn, ...
                   'gui_OutputFcn',  @p3GUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT

% --- Executes just before p3GUI is made visible.
function p3GUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to p3GUI (see VARARGIN)
clc

background = imread('back.jpg');
setappdata(0, 'bg', background);

handles.vid = videoinput('winvideo', 1, 'MJPG_640x480');


set(handles.vid,'TriggerRepeat',Inf); 
handles.vid.FrameGrabInterval = 1;


% Choose default command line output for p3GUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% This sets up the initial plot - only do when we are invisible
% so window can get raised using p3GUI.
if strcmp(get(hObject,'Visible'),'off')
    plot(rand(5));
end

% UIWAIT makes p3GUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = p3GUI_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;

% --- Executes on button press in calculate.
function calculate_Callback(hObject, eventdata, handles)
% hObject    handle to calculate (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%axes(handles.axes1);
cla;

handles.vid = videoinput('winvideo', 1, 'MJPG_640x480');


set(handles.vid,'TriggerRepeat',Inf); 
handles.vid.FrameGrabInterval = 1;

start(handles.vid);
pause(3);
data = getdata(handles.vid,1); 
handles.newimg = data(:,:,:,1);

stop(handles.vid);

%{ 
hsvfore = rgb2hsv(handles.newimg);
hchannel2 = hsvfore(:,:,1);
schannel2 = 1.5 * hsvfore(:,:,2);
vchannel2 = hsvfore(:,:,3);
hsv2 = cat(3, hchannel2, schannel2, vchannel2);
handles.newimg = im2uint8(hsv2rgb(hsv2));

clear hsvfore; clear hchannel2; clear schannel2; clear vchannel2;

handles.table=handles.newimg;

background = getappdata(0, 'bg');

background=rgb2gray(background);
handles.newimg=rgb2gray(handles.newimg);

imshow (handles.table, 'Parent', handles.axes1); hold on;

v={};
se=strel('disk',8);
for i=3:1:9
    back=im2bw(background,i/10-0.1);
    new=im2bw(handles.newimg,i/10);
    new=imdilate(new,se);
    foreground=bitxor(new,back);
    binimg=im2bw(foreground,0.5);
    [centers, radii, metric]=imfindcircles(binimg,[10,23]);
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
handles.rad=mean(v_radii);
bin=zeros(num,1);

for i=1:1:num
   if (v_centers(i,1)>145 && v_centers(i,1)<590)
       if (v_centers(i,2)>130 && v_centers(i,2)<395)
           bin(i)=1;
       end
   end
end

idx = rangesearch(v_centers, v_centers, handles.rad*1.5);

handles.center=[];
handles.radii=[];
handles.metric=[];

k=1;
for i=1:1:num
    if bin(i)
        for j=1:1:(length(idx{i})-1)
            bin(idx{i}(1+j),1)=0;
        end
        handles.center(k,:)=v_centers(i,:);
        handles.radii(k,:)=v_radii(i,:);
        handles.metric(k,:)=v_metric(i,:);
        k=k+1;
    end
end

viscircles(handles.center, handles.radii, 'EdgeColor','b','LineStyle','--');

handles.num=length(handles.metric);
handles.color = {};
for b=1:1:handles.num
    ballNum = sprintf('%1.0f', b);
    text(handles.center(b,1),handles.center(b,2),ballNum,'HorizontalAlignment','center',...
        'VerticalAlignment','middle','color','g',...
        'FontWeight','bold','FontSize',14);
    x = round(handles.center(b,2));
    y = round(handles.center(b,1));
    rA=handles.table(x-3:x+3,y-3:y+3,1);
    gA=handles.table(x-3:x+3,y-3:y+3,2);
    bA=handles.table(x-3:x+3,y-3:y+3,3);
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
    fprintf('The RGB values of Ball %s are (%f, %f, %f)\n', ballNum, red, green, blue);
    handles.color{b} = getColor(red, green, blue);
    handles.theta(b) = atand((handles.center(b,2)-262)/(handles.center(b,1)-97));
    fprintf('The color of the ball %s is %s, and it''s center is at (%d, %d)\n', ballNum, handles.color{b}, round(handles.center(b,1)), round(handles.center(b,2)));
    clear rA; clear gA; clear bA;
end
fprintf('The number of pool balls in this picture is %d\n\n',length(handles.center));

contents = get(handles.selection, 'String');
popup_value = contents{get(handles.selection, 'Value')};

switch popup_value
    case 'Red'
        bNum = strmatch('red',handles.color);
        sz = size(bNum);
        if (sz)
            set_param('Project3/Constant','Value',num2str(handles.theta(bNum)));
            pause(2);
        end
    case 'Yellow'
        bNum = strmatch('yellow',handles.color);
        sz = size(bNum);
        if (sz)
            set_param('Project3/Constant','Value',num2str(handles.theta(bNum)));
            pause(2);
        end
    case 'Orange'
        bNum = strmatch('orange',handles.color);
        sz = size(bNum);
        if (sz)
            set_param('Project3/Constant','Value',num2str(handles.theta(bNum)));
            pause(2);
        end
    case 'Black'
        bNum = strmatch('black',handles.color);
        sz = size(bNum);
        if (sz)
            set_param('Project3/Constant','Value',num2str(handles.theta(bNum)));
            pause(2);
        end
    case 'Blue'
        bNum = strmatch('blue',handles.color);
        sz = size(bNum);
        if (sz)
            set_param('Project3/Constant','Value',num2str(handles.theta(bNum)));
            pause(2);
        end
    case 'White'
        bNum = strmatch('white',handles.color);
        sz = size(bNum);
        if (sz)
            set_param('Project3/Constant','Value',num2str(handles.theta(bNum)));
            pause(2);
        end
    case 'All'
       for i=1:1:handles.num
           set_param('Project3/Constant','Value',num2str(round(handles.theta(i))));
           pause(2);
       end
end

%}
cue = [87 242];
pocket_loc = [  45 104;
                303 107;
                559 101;
                557 368;
                307 368;
                54 372   ];
h = 1.0;
s = 2.0;
v = 1.0;

%handles.newimg = imread('new.jpg');
hsvImage = rgb2hsv(handles.newimg);
hChannel = h*hsvImage(:,:,1);
sChannel = s*hsvImage(:,:,2);
vChannel = v*hsvImage(:,:,3);

hsvImage2 = cat(3,hChannel,sChannel,vChannel);
% handles.newimg = im2uint8(hsv2rgb(hsvImage2));
rgb3 = im2uint8(hsv2rgb(hsvImage2));

handles.table=handles.newimg;
imshow (handles.table, 'Parent', handles.axes1); hold on;

% rgb1 = getappdata(0, 'bg');
rgb1 = imread('back.jpg');
hsvImage1 = rgb2hsv(rgb1);
hChannel1 = h*hsvImage1(:,:,1);
sChannel1 = s*hsvImage1(:,:,2);
vChannel1 = v*hsvImage1(:,:,3);

hsvImage3 = cat(3,hChannel1,sChannel1,vChannel1);
rgb4 = im2uint8(hsv2rgb(hsvImage3));

% rChannel1 = rgb4(:,:,1);
% gChannel1 = rgb4(:,:,2);
% bChannel1 = rgb4(:,:,3);
% 
% image = ((rgb4-handles.newimg)+(handles.newimg-rgb4));

image2 = imsubtract(rgb4,rgb3);
image3 = imsubtract(rgb3,rgb4);
image4 = image3+image2;
figure();
imshow(image4);

rChannel = image4(:,:,1);
gChannel = image4(:,:,2);
bChannel = image4(:,:,3);

[centers, radii, metric] = imfindcircles(image4,[10 30],'ObjectPolarity','bright','EdgeThreshold',0);
centersStrong5 = centers(1:size(centers,1),:);
radiiStrong5 = radii(1:size(centers,1));
metricStrong5 = metric(1:size(centers,1));


for i = 1:size(centers,1)
    th = 0:pi/50:2*pi;
    xunit = round(radii(i) * cos(th) + round(centers(i,1)));
    yunit = round(radii(i) * sin(th) + round(centers(i,2)));
    color(i,1) = round(max(median(rChannel(yunit,xunit))));
    color(i,2) = round(max(median(gChannel(yunit,xunit))));
    color(i,3) = round(max(median(bChannel(yunit,xunit))));
end;

for i=1:size(centers,1)
    viscircles(centersStrong5, radiiStrong5,'EdgeColor','b');
end;

Pockets = ['A','B','C','D','E','F'];
for i=1:6
    text(pocket_loc(i,1),pocket_loc(i,2),Pockets(i),'Color','w','FontWeight','b');
end

for i = 1:size(centers,1)
    if(color(i,1)>210 && color(i,1)<235)&&(color(i,2)>110 && color(i,2)<130)&&(color(i,3)>25 && color(i,3)<45)
        colors(i,1) = 'o';%2 = orange
    end;
    if(color(i,1)>160 && color(i,1)<190)&&(color(i,2)>110 && color(i,2)<130)&&(color(i,3)>25 && color(i,3)<45)
        colors(i,1) = 'r';%3 = red
    end;
    if(color(i,1)>200 && color(i,1)<225)&&(color(i,2)>20 && color(i,2)<45)&&(color(i,3)>20 && color(i,3)<45)
        colors(i,1) = 'y';%4 = yellow
    end;
    if(color(i,1)>15 && color(i,1)<30)&&(color(i,2)>70 && color(i,2)<100)&&(color(i,3)>90 && color(i,3)<120)
        colors(i,1) = 'l';%5 = blue
    end;
    if(color(i,1)>30 && color(i,1)<55)&&(color(i,2)>45 && color(i,2)<75)&&(color(i,3)>20 && color(i,3)<50)
        colors(i,1) = 'k';%6 = black
    end;
end;

for i=1:size(color,1)
    text(centersStrong5(i,1)+20,centersStrong5(i,2)-20,num2str(i),'Color','w');
end

mesg = getappdata(0, 'msg');

colors = 'l';

switch mesg(1)
    case 'l'
        idx = strmatch('l', colors);
    case 'k'
        idx = strmatch('k', colors);
    case 'r'
        idx = strmatch('r', colors);
    case 'y'
        idx = strmatch('y', colors);
    case 'o'
        idx = strmatch('o', colors);
end

switch mesg(2)
    case 'a'
        loc = 1;
    case 'b'
        loc = 2;
    case 'c'
        loc = 3;
    case 'd'
        loc = 4;
    case 'e'
        loc = 5;
    case 'f'
        loc = 6;
end
 
disp(color);
disp(colors);
angle = pot(cue,centers,idx,pocket_loc,loc,radii,color)
set_param('Project3/Constant','Value',angle);
pause(2);

imaqreset;


% --------------------------------------------------------------------
function FileMenu_Callback(hObject, eventdata, handles)
% hObject    handle to FileMenu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function OpenMenuItem_Callback(hObject, eventdata, handles)
% hObject    handle to OpenMenuItem (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
file = uigetfile('*.fig');
if ~isequal(file, 0)
    open(file);
end

% --------------------------------------------------------------------
function PrintMenuItem_Callback(hObject, eventdata, handles)
% hObject    handle to PrintMenuItem (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
printdlg(handles.figure1)

% --------------------------------------------------------------------
function CloseMenuItem_Callback(hObject, eventdata, handles)
% hObject    handle to CloseMenuItem (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
selection = questdlg(['Close ' get(handles.figure1,'Name') '?'],...
                     ['Close ' get(handles.figure1,'Name') '...'],...
                     'Yes','No','Yes');
if strcmp(selection,'No')
    return;
end

delete(handles.figure1)


% --- Executes on selection change in selection.
function selection_Callback(hObject, eventdata, handles)
% hObject    handle to selection (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = get(hObject,'String') returns selection contents as cell array
%        contents{get(hObject,'Value')} returns selected item from selection


% --- Executes during object creation, after setting all properties.
function selection_CreateFcn(hObject, eventdata, handles)
% hObject    handle to selection (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
     set(hObject,'BackgroundColor','white');
end

set(hObject, 'String', {'Red', 'Yellow', 'Orange', 'Blue', 'Black', 'White', 'All'});


% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
delete(handles.vid);
delete(hObject);


% --- Executes on button press in fire.
function fire_Callback(hObject, eventdata, handles)
% hObject    handle to fire (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

set_param('Project3/Subsystem/Constant','Value','5');
pause(0.250);
set_param('Project3/Subsystem/Constant','Value','0');
pause(0.5);
set_param('Project3/Constant', 'Value','0');


% --- Executes on button press in decodeQR.
function decodeQR_Callback(hObject, eventdata, handles)
% hObject    handle to decodeQR (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% WARNING SUPPRESSION ***************************************************
%this first warning warns the user that: there is a "core.jar" is
%already specified on static java path. Seeing as we don't use other java
%functions, we shouldn't have any conflict respecifying core.jar
s = warning('off','MATLAB:javaclasspath:jarAlreadySpecified');

%These javaaddpath cmds are the cause the suppressed warnings above and
%should point to the folder where you installed ZXing
javaaddpath('C:\Program Files\zxing-2.0\core\core.jar');
javaaddpath('C:\Program Files\zxing-2.0\javase\javase.jar');

%this second warning indicates an: Out of range value converted to
%intmin('uint8') or intmax('uint8'). This seems to be just a nanny alarm
%generated by decode_qr
r = warning('off','MATLAB:intConvertOverflow');

% CODE SECTION **********************************************************
% In this section, we will capture an image using the HP webcam and Matlab
% Image Acquisition Toolbox, then process it using decode_qr

test_encode = captureVideoFrame(10,2);

% Decode the QR code
message = decode_qr(test_encode);
set(handles.qr_text, 'string', message);
setappdata(0, 'msg', message);

switch message(1)
    case 'l'
        handles.colour = 'blue';
    case 'k'
        handles.colour = 'black';
    case 'r'
        handles.colour = 'red';
    case 'y'
        handles.colour = 'yellow';
    case 'o'
        handles.colour = 'orange';
end

switch message(2)
    case 'a'
        handles.pocket = 'left back';
    case 'b'
        handles.pocket = 'left middle';
    case 'c'
        handles.pocket = 'left front';
    case 'd'
        handles.pocket = 'right front';
    case 'e'
        handles.pocket = 'right middle';
    case 'f'
        handles.pocket = 'right back';
end

switch message(3)
    case '1'
        handles.quadrant = 'first';
    case '2'
        handles.quadrant = 'second';
    case '3'
        handles.quadrant = 'third';
    case '4'
        handles.quadrant = 'fourth';
end

fin = sprintf('You need to sink a %s ball in the %s pocket. It is located in the %s quadrant', handles.colour, handles.pocket, handles.quadrant);
set(handles.qr_text, 'string', fin);

%reinitialize the warnings that were turned off above
warning(s);
warning(r);

imaqreset;