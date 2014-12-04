function varargout = DataProcessGUI(varargin)
% DATAPROCESSGUI MATLAB code for DataProcessGUI.fig
%      DATAPROCESSGUI, by itself, creates a new DATAPROCESSGUI or raises the existing
%      singleton*.
%
%      H = DATAPROCESSGUI returns the handle to a new DATAPROCESSGUI or the handle to
%      the existing singleton*.
%
%      DATAPROCESSGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in DATAPROCESSGUI.M with the given input arguments.
%
%      DATAPROCESSGUI('Property','Value',...) creates a new DATAPROCESSGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before DataProcessGUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to DataProcessGUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help DataProcessGUI

% Last Modified by GUIDE v2.5 22-Sep-2014 17:43:40

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @DataProcessGUI_OpeningFcn, ...
                   'gui_OutputFcn',  @DataProcessGUI_OutputFcn, ...
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


% --- Executes just before DataProcessGUI is made visible.
function DataProcessGUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to DataProcessGUI (see VARARGIN)

% Choose default command line output for DataProcessGUI
handles.output = hObject;
result = evalin('base','exist(''simOutName'')');
if result == 1
    simOutName = evalin('base','simOutName');
    set(handles.editSimOutVar,'String',simOutName);
    if iscell(simOutName)
        simOutName = simOutName{1};
    end;
    simOut = evalin('base', simOutName);
    log = simOut.get('logsout');
    tsLog = convertDatasetToTsset(log);
    nSig = length(tsLog);
    handles.sigNames = cell(nSig,1);
    handles.sigData = cell(nSig,1);
    handles.simOutSelectIndex = zeros(nSig,1);
    handles.noSelectSimOut = 0;
    for i=1:nSig
        handles.sigNames{i} = tsLog{i}.Name;
        handles.sigData{i} = tsLog{i};
    end;
    guidata(handles.figure1,handles);
    set(handles.listboxSimOut,'String',handles.sigNames, ...
        'Value',1);
end;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes DataProcessGUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = DataProcessGUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in listboxSimOut.
function listboxSimOut_Callback(hObject, eventdata, handles)
% hObject    handle to listboxSimOut (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns listboxSimOut contents as cell array
%        contents{get(hObject,'Value')} returns selected item from listboxSimOut


% --- Executes during object creation, after setting all properties.
function listboxSimOut_CreateFcn(hObject, eventdata, handles)
% hObject    handle to listboxSimOut (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in listboxToPlot.
function listboxToPlot_Callback(hObject, eventdata, handles)
% hObject    handle to listboxToPlot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns listboxToPlot contents as cell array
%        contents{get(hObject,'Value')} returns selected item from listboxToPlot


% --- Executes during object creation, after setting all properties.
function listboxToPlot_CreateFcn(hObject, eventdata, handles)
% hObject    handle to listboxToPlot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbTo.
function pushbTo_Callback(hObject, eventdata, handles)
index_selected = get(handles.listboxSimOut,'Value');
handles.simOutSelectIndex(index_selected) = 1;
selectedIndex = find(handles.simOutSelectIndex ~= 0);
handles.noSelectSimOut = length(selectedIndex);
handles.simOutNameSelect = cell(handles.noSelectSimOut,1);
for i = 1:handles.noSelectSimOut
    handles.simOutNameSelect{i} = handles.sigNames{selectedIndex(i)};
end;
guidata(handles.figure1,handles);
set(handles.listboxToPlot,'String',handles.simOutNameSelect, ...
    'Value',1);

% hObject    handle to pushbTo (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbPlot.
function pushbPlot_Callback(hObject, eventdata, handles)
selectedIndex = find(handles.simOutSelectIndex ~= 0);
noPlot = 0;
h = handles.axes1;
for i = 1:handles.noSelectSimOut
    tSToPlot = handles.sigData{selectedIndex(i)};
    dataToPlot = tSToPlot.Data;
    [m n] = size(dataToPlot);
    for j = 1:n
        noPlot = noPlot + 1;
        dataName{noPlot} =  strcat(handles.sigNames{selectedIndex(i)},num2str(j));
    end;
    plot(h,tSToPlot.time,tSToPlot.Data);
    hold all
end;
legend(h,dataName);
hold off
% hObject    handle to pushbPlot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbSavePlot.
function pushbSavePlot_Callback(hObject, eventdata, handles)
figure;
selectedIndex = find(handles.simOutSelectIndex ~= 0);
noPlot = 0;
for i = 1:handles.noSelectSimOut
    tSToPlot = handles.sigData{selectedIndex(i)};
    dataToPlot = tSToPlot.Data;
    [m n] = size(dataToPlot);
    for j = 1:n
        noPlot = noPlot + 1;
        dataName{noPlot} =  strcat(handles.sigNames{selectedIndex(i)},num2str(j));
    end;
    plot(tSToPlot.time,tSToPlot.Data);
    hold all
end;
legend(dataName);
hold off
% hObject    handle to pushbSavePlot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbExportWS.
function pushbExportWS_Callback(hObject, eventdata, handles)
selectedIndex = find(handles.simOutSelectIndex ~= 0);
for i = 1:handles.noSelectSimOut
    tSData = handles.sigData{selectedIndex(i)};
    assignin('base',tSData.Name,tSData);
end;
% hObject    handle to pushbExportWS (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function editSimOutVar_Callback(hObject, eventdata, handles)
% hObject    handle to editSimOutVar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editSimOutVar as text
%        str2double(get(hObject,'String')) returns contents of editSimOutVar as a double


% --- Executes during object creation, after setting all properties.
function editSimOutVar_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editSimOutVar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbSimOutLoad.
function pushbSimOutLoad_Callback(hObject, eventdata, handles)
simOutName = get(handles.editSimOutVar,'String');
if iscell(simOutName)
    simOutName = simOutName{1};
end;
simOut = evalin('base', simOutName);
log = simOut.get('logsout');
tsLog = convertToTsset(log);
nSig = length(tsLog);
handles.sigNames = cell(nSig,1);
handles.sigData = cell(nSig,1);
handles.simOutSelectIndex = zeros(nSig,1);
handles.noSelectSimOut = 0;
for i=1:nSig
    handles.sigNames{i} = tsLog{i}.Name;
    handles.sigData{i} = tsLog{i};
end;
guidata(handles.figure1,handles);
set(handles.listboxSimOut,'String',handles.sigNames, ...
	'Value',1);


% --- Executes on button press in pushbFrom.
function pushbFrom_Callback(hObject, eventdata, handles)
% hObject    handle to pushbFrom (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
index_selected = get(handles.listboxToPlot,'Value');
preSelect = find(handles.simOutSelectIndex ~= 0);
handles.simOutSelectIndex(preSelect(index_selected)) = 0;
selectedIndex = find(handles.simOutSelectIndex ~= 0);
handles.noSelectSimOut = length(selectedIndex);
handles.simOutNameSelect = cell(handles.noSelectSimOut,1);
for i = 1:handles.noSelectSimOut
    handles.simOutNameSelect{i} = handles.sigNames{selectedIndex(i)};
end;
guidata(handles.figure1,handles);
set(handles.listboxToPlot,'String',handles.simOutNameSelect, ...
    'Value',1);


% --- Executes during object creation, after setting all properties.
function axes1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to axes1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: place code in OpeningFcn to populate axes1


% --- Executes during object deletion, before destroying properties.
function axes1_DeleteFcn(hObject, eventdata, handles)
% hObject    handle to axes1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on mouse press over axes background.
function axes1_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to axes1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


function Tsset = convertToTsset(log)
sub = log;
subWhos = sub.whos;
nSub = length(subWhos);
for i=1:nSub
    elementName{i} = subWhos(i).name;
    elementClass{i} = subWhos(i).simulinkClass;
    element{i} = sub.get(elementName{i});
end;
allTS = false;
while allTS == false;
    allTS = true;
    nSub = length(element);
    nSubNew = nSub;
    i = 1;
    while i <= nSub;
        if strcmp(elementClass{i},'TsArray')
            TsTemp = element{i}.flatten;
            nTs = length(TsTemp);
            tsName = elementName{i};
            for j=1:nTs
                if j == 1
                    elementName{i} = strcat(tsName,num2str(j));
                    elementClass{i} = 'Timeseries';
                    element{i} = TsTemp{j};
                else
                    elementName{nSubNew+j-1} = strcat(tsName,num2str(j));
                    elementClass{nSubNew+j-1} = 'Timeseries';
                    element{nSubNew+j-1} = TsTemp{j};
                end;
            end;
            nSubNew = nSubNew + nTs - 1;
            allTS = false;
        else
            if strcmp(elementClass{i},'SubsysDataLogs')
                subWhos = element{i}.whos;
                nSubSub = length(subWhos);
                subSub = element{i};
                nameTemp = elementName{i};
                for j=1:nSubSub
                    if j == 1
                        elementName{i} = strcat(subWhos(j).name,'_',nameTemp);
                        elementClass{i} = subWhos(j).simulinkClass;
                        element{i} = subSub.get(subWhos(j).name);
                    else
                        elementName{nSubNew+j-1} = strcat(subWhos(j).name,'_',nameTemp);
                        elementClass{nSubNew+j-1} = subWhos(j).simulinkClass;
                        element{nSubNew+j-1} = subSub.get(subWhos(j).name);
                    end;
                end;
                nSubNew = nSubNew + nSubSub - 1;
                allTS = false;
            end;
        end;
        i = i + 1;
    end;
end;
[elementName,I] = sort(elementName);
element = element(I);
for i = 1:nSub
    element{i}.Name = elementName{i};
end;
Tsset = element;

function Tsset = convertDatasetToTsset(log)
sub = log;
subWhos = sub.getElementNames;
nSub = length(subWhos);
for i=1:nSub
    element{i} = log.getElement(subWhos(i)).Name);
    elementName{i} = subWhos(i);
    if strcmp('',element{i}.Name)
        elementClass{i} = 'DataSet';
    else
        if length(element{I}.Values.Data) > 1
            elementClass{i} = 'tsArray';
        else
            elementClass{i} = 'timeseries';
        end;
            
    end;
    
    element{i} = sub.get(elementName{i});
end;
allTS = false;
while allTS == false;
    allTS = true;
    nSub = length(element);
    nSubNew = nSub;
    i = 1;
    while i <= nSub;
        if strcmp(elementClass{i},'TsArray')
            TsTemp = element{i}.flatten;
            nTs = length(TsTemp);
            tsName = elementName{i};
            for j=1:nTs
                if j == 1
                    elementName{i} = strcat(tsName,num2str(j));
                    elementClass{i} = 'Timeseries';
                    element{i} = TsTemp{j};
                else
                    elementName{nSubNew+j-1} = strcat(tsName,num2str(j));
                    elementClass{nSubNew+j-1} = 'Timeseries';
                    element{nSubNew+j-1} = TsTemp{j};
                end;
            end;
            nSubNew = nSubNew + nTs - 1;
            allTS = false;
        else
            if strcmp(elementClass{i},'SubsysDataLogs')
                subWhos = element{i}.whos;
                nSubSub = length(subWhos);
                subSub = element{i};
                nameTemp = elementName{i};
                for j=1:nSubSub
                    if j == 1
                        elementName{i} = strcat(subWhos(j).name,'_',nameTemp);
                        elementClass{i} = subWhos(j).simulinkClass;
                        element{i} = subSub.get(subWhos(j).name);
                    else
                        elementName{nSubNew+j-1} = strcat(subWhos(j).name,'_',nameTemp);
                        elementClass{nSubNew+j-1} = subWhos(j).simulinkClass;
                        element{nSubNew+j-1} = subSub.get(subWhos(j).name);
                    end;
                end;
                nSubNew = nSubNew + nSubSub - 1;
                allTS = false;
            end;
        end;
        i = i + 1;
    end;
end;
[elementName,I] = sort(elementName);
element = element(I);
for i = 1:nSub
    element{i}.Name = elementName{i};
end;
Tsset = element;




