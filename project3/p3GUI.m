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

% Last Modified by GUIDE v2.5 11-Apr-2017 23:23:11

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

handles.vid = videoinput('winvideo', 2, 'MJPG_640x480');


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

% if isfield(handles, 'vid')
%     stop(handles.vid);
% end

start(handles.vid);

data = getdata(handles.vid,1); 
handles.newimg = data(:,:,:,1);

stop(handles.vid);

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
Fire = 'N';

switch popup_value
    case 'Red'
        bNum = strmatch('red',handles.color);
        sz = size(bNum);
        if (sz)
            set_param('Project3/Constant','Value',num2str(handles.theta(bNum)));
            pause(2);
            Fire = input('Fire (Y/N): ','s');
            if (Fire=='Y' || Fire == 'y')
                set_param('Project3/Subsystem/Constant','Value','5');
                pause(0.250);
                set_param('Project3/Subsystem/Constant','Value','0');
            end
            pause(0.5);
            set_param('Project3/Constant', 'Value','0');
        end
    case 'Yellow'
        bNum = strmatch('yellow',handles.color);
        sz = size(bNum);
        if (sz)
            set_param('Project3/Constant','Value',num2str(handles.theta(bNum)));
            pause(2);
            Fire = input('Fire (Y/N): ','s');
            if (Fire=='Y' || Fire == 'y')
                set_param('Project3/Subsystem/Constant','Value','5');
                pause(0.250);
                set_param('Project3/Subsystem/Constant','Value','0');
            end
            pause(0.5);
            set_param('Project3/Constant', 'Value','0');
        end
    case 'Orange'
        bNum = strmatch('orange',handles.color);
        sz = size(bNum);
        if (sz)
            set_param('Project3/Constant','Value',num2str(handles.theta(bNum)));
            pause(2);
            Fire = input('Fire (Y/N): ','s');
            if (Fire=='Y' || Fire == 'y')
                set_param('Project3/Subsystem/Constant','Value','5');
                pause(0.250);
                set_param('Project3/Subsystem/Constant','Value','0');
            end
            pause(0.5);
            set_param('Project3/Constant', 'Value','0');
        end
    case 'Black'
        bNum = strmatch('black',handles.color);
        sz = size(bNum);
        if (sz)
            set_param('Project3/Constant','Value',num2str(handles.theta(bNum)));
            pause(2);
            Fire = input('Fire (Y/N): ','s');
            if (Fire=='Y' || Fire == 'y')
                set_param('Project3/Subsystem/Constant','Value','5');
                pause(0.250);
                set_param('Project3/Subsystem/Constant','Value','0');
            end
            pause(0.5);
            set_param('Project3/Constant', 'Value','0');
        end
    case 'Blue'
        bNum = strmatch('blue',handles.color);
        sz = size(bNum);
        if (sz)
            set_param('Project3/Constant','Value',num2str(handles.theta(bNum)));
            pause(2);
            Fire = input('Fire (Y/N): ','s');
            if (Fire=='Y' || Fire == 'y')
                set_param('Project3/Subsystem/Constant','Value','5');
                pause(0.250);
                set_param('Project3/Subsystem/Constant','Value','0');
            end
            pause(0.5);
            set_param('Project3/Constant', 'Value','0');
        end
    case 'White'
        bNum = strmatch('white',handles.color);
        fprintf('Just a test\n');
        fprintf('%f\n', bNum);
        if (bNum > 0)
            set_param('Project3/Constant','Value',num2str(handles.theta(bNum)));
            pause(2);
            Fire = input('Fire (Y/N): ','s');
            if (Fire=='Y' || Fire == 'y')
                set_param('Project3/Subsystem/Constant','Value','5');
                pause(0.250);
                set_param('Project3/Subsystem/Constant','Value','0');
            end
            pause(0.5);
            set_param('Project3/Constant', 'Value','0');
        end
    case 'All'
       for i=1:1:handles.num
           set_param('Project3/Constant','Value',num2str(round(handles.theta(i))));
           pause(2);
       end
end



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
