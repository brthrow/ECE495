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

% Last Modified by GUIDE v2.5 14-Mar-2017 21:31:01

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

handles.background = imread('p3BG.JPG');

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

% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes1);
cla;

if isrunning(handles.vid) == 1
    stop(handles.vid);
end

start(handles.vid);

handles.data = getdata(handles.vid,1); 
handles.newimg = handles.data(:,:,:,1);

handles.table=handles.newimg;

handles.background=rgb2gray(handles.background);
handles.newimg=rgb2gray(handles.newimg);

figure, imshow (handles.table); hold on;

v={};
for i=3:1:9
    handles.back=im2bw(handles.background,i/10-0.1);
    handles.new=im2bw(handles.newimg,i/10);
    handles.foreground=bitxor(handles.new,handles.back);
    handles.binimg=im2bw(handles.foreground,0.5);
    [handles.centers, handles.radii, handles.metric]=imfindcircles(handles.binimg,[22,35]);
    if size(handles.centers) > 0 
        if exist('handles.v_centers')
            handles.v_centers=[handles.v_centers; handles.centers];
            handles.v_radii=[handles.v_radii; handles.radii];
            handles.v_metric=[handles.v_metric; handles.metric];
        else
            handles.v_centers=handles.centers;
            handles.v_radii=handles.radii;
            handles.v_metric=handles.metric;
        end
    end
    clear handles.back; clear handles.new; clear handles.foreground; clear handles.binimg;
    clear handles.centers; clear handles.radii; clear handles.metric;
end

handles.num=length(handles.v_centers);
handles.rad=mean(handles.v_radii);
handles.bin=ones(handles.num,1);

handles.idx = rangesearch(handles.v_centers, handles.v_centers, handles.rad);

handles.center=[];
handles.radii=[];
handles.metric=[];

k=1;
for i=1:1:handles.num
    if handles.bin(i)
        for j=1:1:(length(handles.idx{i})-1)
            handles.bin(handles.idx{i}(1+j),1)=0;
        end
        handles.center(k,:)=handles.v_centers(i,:);
        handles.radii(k,:)=handles.v_radii(i,:);
        handles.metric(k,:)=handles.v_metric(i,:);
        k=k+1;
    end
end

viscircles(handles.center, handles.radii, 'EdgeColor','b','LineStyle','--');

num=length(handles.metric);
for b=1:1:num
    handles.ballNum = sprintf('%1.0f', b);
    text(handles.center(b,1),handles.center(b,2),handles.ballNum,'HorizontalAlignment','center',...
        'VerticalAlignment','middle','color','g',...
        'FontWeight','bold','FontSize',14);
    handles.x = round(handles.center(b,2))-15;
    handles.y = round(handles.center(b,1))-10;
    handles.red = handles.table(handles.x, handles.y, 1);
    handles.green = handles.table(handles.x, handles.y, 2);
    handles.blue = handles.table(handles.x, handles.y, 3);
    handles.c = getColor(handles.red, handles.green, handles.blue);
    fprintf('The color of ball %s is %s, and it''s center is at (%d, %d)\n', handles.ballNum, handles.c, round(handles.center(b,1)), round(handles.center(b,2)));
end
fprintf('The number of pool balls in this picture is %d\n\n',length(handles.center));

%{
popup_sel_index = get(handles.popupmenu1, 'Value');
switch popup_sel_index
    case 1
        plot(rand(5));
    case 2
        plot(sin(1:0.01:25.99));
    case 3
        bar(1:.5:10);
    case 4
        plot(membrane);
    case 5
        surf(peaks);
end
%}
stop(handles.vid);


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


% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = get(hObject,'String') returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1


% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
     set(hObject,'BackgroundColor','white');
end

set(hObject, 'String', {'Red', 'Yellow', 'Orange', 'Blue', 'Black', 'White', 'All'});
