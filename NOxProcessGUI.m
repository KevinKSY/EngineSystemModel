function varargout = NOxProcessGUI(varargin)
% NOXPROCESSGUI M-file for NOxProcessGUI.fig
%      NOXPROCESSGUI, by itself, creates a new NOXPROCESSGUI or raises the existing
%      singleton*.
%
%      H = NOXPROCESSGUI returns the handle to a new NOXPROCESSGUI or the handle to
%      the existing singleton*.
%
%      NOXPROCESSGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in NOXPROCESSGUI.M with the given input arguments.
%
%      NOXPROCESSGUI('Property','Value',...) creates a new NOXPROCESSGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before NOxProcessGUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to NOxProcessGUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help NOxProcessGUI

% Last Modified by GUIDE v2.5 02-Oct-2014 12:55:03

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @NOxProcessGUI_OpeningFcn, ...
                   'gui_OutputFcn',  @NOxProcessGUI_OutputFcn, ...
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


% --- Executes just before NOxProcessGUI is made visible.
function NOxProcessGUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to NOxProcessGUI (see VARARGIN)

% Choose default command line output for NOxProcessGUI
handles.output = hObject;
result = evalin('base','exist(''simOutName'')');
if result == 1
    simOutName = evalin('base','simOutName');
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
%    set(handles.listboxSimOut,'String',handles.sigNames, ...
%        'Value',1);
    set(handles.popupmenuPhiCyl,'String',handles.sigNames);  
    set(handles.popupmenuPCyl,'String',handles.sigNames);
    set(handles.popupmenuTCyl,'String',handles.sigNames);
    set(handles.popupmenuFCyl,'String',handles.sigNames);
    set(handles.popupmenuVCyl,'String',handles.sigNames);
    set(handles.popupmenuMfCyl,'String',handles.sigNames);
    set(handles.popupmenuQCyl,'String',handles.sigNames);
    set(handles.popupmenuWCyl,'String',handles.sigNames);    
else
    error('No simulation result available. Please try again after you run the simulation');
end;
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes NOxProcessGUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = NOxProcessGUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in popupmenuPCyl.
function popupmenuPCyl_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenuPCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenuPCyl contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenuPCyl


% --- Executes during object creation, after setting all properties.
function popupmenuPCyl_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenuPCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenuTCyl.
function popupmenuTCyl_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenuTCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenuTCyl contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenuTCyl


% --- Executes during object creation, after setting all properties.
function popupmenuTCyl_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenuTCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenuFCyl.
function popupmenuFCyl_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenuFCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenuFCyl contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenuFCyl


% --- Executes during object creation, after setting all properties.
function popupmenuFCyl_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenuFCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenuVCyl.
function popupmenuVCyl_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenuVCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenuVCyl contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenuVCyl


% --- Executes during object creation, after setting all properties.
function popupmenuVCyl_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenuVCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenuMfCyl.
function popupmenuMfCyl_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenuMfCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenuMfCyl contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenuMfCyl


% --- Executes during object creation, after setting all properties.
function popupmenuMfCyl_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenuMfCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenuQCyl.
function popupmenuQCyl_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenuQCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenuQCyl contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenuQCyl


% --- Executes during object creation, after setting all properties.
function popupmenuQCyl_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenuQCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenuWCyl.
function popupmenuWCyl_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenuWCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenuWCyl contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenuWCyl


% --- Executes during object creation, after setting all properties.
function popupmenuWCyl_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenuWCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editFS_Callback(hObject, eventdata, handles)
% hObject    handle to editFS (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editFS as text
%        str2double(get(hObject,'String')) returns contents of editFS as a double


% --- Executes during object creation, after setting all properties.
function editFS_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editFS (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editFComb_Callback(hObject, eventdata, handles)
% hObject    handle to editFComb (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editFComb as text
%        str2double(get(hObject,'String')) returns contents of editFComb as a double


% --- Executes during object creation, after setting all properties.
function editFComb_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editFComb (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editXAir_Callback(hObject, eventdata, handles)
% hObject    handle to editXAir (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editXAir as text
%        str2double(get(hObject,'String')) returns contents of editXAir as a double


% --- Executes during object creation, after setting all properties.
function editXAir_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editXAir (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editFCC_Callback(hObject, eventdata, handles)
% hObject    handle to editFCC (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editFCC as text
%        str2double(get(hObject,'String')) returns contents of editFCC as a double


% --- Executes during object creation, after setting all properties.
function editFCC_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editFCC (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit5_Callback(hObject, eventdata, handles)
% hObject    handle to edit5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit5 as text
%        str2double(get(hObject,'String')) returns contents of edit5 as a double


% --- Executes during object creation, after setting all properties.
function edit5_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit6_Callback(hObject, eventdata, handles)
% hObject    handle to edit6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit6 as text
%        str2double(get(hObject,'String')) returns contents of edit6 as a double


% --- Executes during object creation, after setting all properties.
function edit6_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbCalcNOx.
function pushbCalcNOx_Callback(hObject, eventdata, handles)
% hObject    handle to pushbCalcNOx (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
index_selected = get(handles.popupmenuPhiCyl,'Value');
timeSim = handles.sigData{index_selected}.time;
phiCyl = handles.sigData{index_selected}.Data;
index_selected = get(handles.popupmenuPCyl,'Value');
pCyl = handles.sigData{index_selected}.Data;
index_selected = get(handles.popupmenuTCyl,'Value');
TCyl = handles.sigData{index_selected}.Data;
index_selected = get(handles.popupmenuFCyl,'Value');
FCyl = handles.sigData{index_selected}.Data;
index_selected = get(handles.popupmenuVCyl,'Value');
vCyl = handles.sigData{index_selected}.Data;
index_selected = get(handles.popupmenuMfCyl,'Value');
mfCyl = handles.sigData{index_selected}.Data;
index_selected = get(handles.popupmenuQCyl,'Value');
QCyl = handles.sigData{index_selected}.Data;
index_selected = get(handles.popupmenuWCyl,'Value');
WCyl = handles.sigData{index_selected}.Data;

fs = str2double(get(handles.editFS,'String'));
FComb = str2double(get(handles.editFComb,'String'));
xAir = str2num(get(handles.editXAir,'String'));
FCC = str2double(get(handles.editFCC,'String'));
FCH = str2double(get(handles.editFCH,'String'));
FCO = str2double(get(handles.editFCO,'String'));
FCN = str2double(get(handles.editFCN,'String'));
FC = [FCC;FCH;FCO;FCN];
TL = str2double(get(handles.editTL,'String'));
TH = str2double(get(handles.editTH,'String'));
hn = str2double(get(handles.editLHV,'String'));

[NOCalc, sNOxCalc] = NOxPostProcess(timeSim,phiCyl,pCyl,TCyl,FCyl,vCyl,mfCyl,...
    QCyl,WCyl,FComb,fs,xAir,FC,[TL;TH],hn);
NOCalc = timeseries(NOCalc,timeSim(1:end-1));
sNOxCalc = timeseries(sNOxCalc,timeSim(1:end-1));
assignin('base','NOCalc',NOCalc);
assignin('base','sNOxCalc',sNOxCalc);
fprintf('The result is saved in the workspace variable ''NOCalc'' and ''sNOxCalc''.\n');




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



function editFCH_Callback(hObject, eventdata, handles)
% hObject    handle to editFCH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editFCH as text
%        str2double(get(hObject,'String')) returns contents of editFCH as a double


% --- Executes during object creation, after setting all properties.
function editFCH_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editFCH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editFCO_Callback(hObject, eventdata, handles)
% hObject    handle to editFCO (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editFCO as text
%        str2double(get(hObject,'String')) returns contents of editFCO as a double


% --- Executes during object creation, after setting all properties.
function editFCO_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editFCO (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editFCN_Callback(hObject, eventdata, handles)
% hObject    handle to editFCN (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editFCN as text
%        str2double(get(hObject,'String')) returns contents of editFCN as a double


% --- Executes during object creation, after setting all properties.
function editFCN_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editFCN (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editTL_Callback(hObject, eventdata, handles)
% hObject    handle to editTL (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editTL as text
%        str2double(get(hObject,'String')) returns contents of editTL as a double


% --- Executes during object creation, after setting all properties.
function editTL_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editTL (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editTH_Callback(hObject, eventdata, handles)
% hObject    handle to editTH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editTH as text
%        str2double(get(hObject,'String')) returns contents of editTH as a double


% --- Executes during object creation, after setting all properties.
function editTH_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editTH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function [NOCalc, sNOxCalc] = NOxPostProcess(timeSim,phiCyl,pCyl,TCyl,FCyl,vCyl,mfCyl,QCyl,WCyl,varargin)

if isempty(varargin)
    FComb = 1;                  %Fuel air equivalent ratio of combustion
    fs = 0.0683;                %fs
    xAir = [0;0;0;0;0;0;0;0.2095;0;0.0003;0.7809;0.0093]; %Air composition in mole fraction
    FC = [1;1.8;0;0];           %Fuel composition as in [m;n;p;q] where CmHnOpNq
    TL = 1500;                  %Tempreature low limit for transition from complete combustion to dissociation
    TH = 1700;                  %Temperature high limit for transition from complete combustion to dissociation
    hn = 42707000;
else
    if isempty(varargin{1})
        FComb = 1;
    else 
        FComb = varargin{1};
    end;
    if isempty(varargin{2})
        fs = 0.0683;
    else
        fs = varargin{2};
    end;
    if isempty(varargin{3})
        xAir = [0;0;0;0;0;0;0;0.2095;0;0.0003;0.7809;0.0093];
    else
        xAir = varargin{3};
    end;    
    if isempty(varargin{4})
        FC = [1;1.8;0;0];
    else
        FC = varargin{4};
    end;
    if isempty(varargin{5})
        TL = 1500; TH = 1700;
    else
        TL = varargin{5}(1);
        TH = varargin{5}(2);
    end;    
    if isempty(varargin{6})
        hn = 42707000;
    else
        hn = varargin{6}*1e6;
    end;        
end;


[RCyl] = GetThdynCombGasZach(pCyl,TCyl,FCyl);
mCyl = pCyl.*vCyl./ (RCyl.*TCyl);


[TuCalc,TbCalc,FuCalc,FbCalc,vuCalc,vbCalc]= Get2ZoneTemp(phiCyl,pCyl,TCyl,FCyl,vCyl,mfCyl,QCyl,FComb,fs,hn);

timeSim = timeSim(1:end-1);
pCyl = pCyl(1:end-1);
mCyl = mCyl(1:end-1);
nStep = length(timeSim);
NOCalc = zeros(nStep,1);

phiCombCyl = phiCyl - 2*pi*(floor(phiCyl/(2*pi)));
phiCombCyl(phiCombCyl>pi) = phiCombCyl(phiCombCyl>pi) - 2*pi;

idx = find(phiCombCyl>-pi/9 & phiCombCyl < pi/2);
noIdx = length(idx);
noCyc = 1;
idxStartCyc(noCyc) = idx(1);
for i=1:noIdx-1
    if idx(i+1) - idx(i) ~= 1;
        idxEndCyc(noCyc) = idx(i);
        noCyc = noCyc + 1;
        idxStartCyc(noCyc) = idx(i+1);
    end;
end;
if noCyc ~= length(idxEndCyc) 
    noCyc = noCyc - 1;
end;



%Calculation of amount of NO produced per cycle in [mol]
progress_idx = 0;
for i = 1:noCyc
    idx = idxStartCyc(i):idxEndCyc(i);
    dNOFunc =  @(t,NO)dNO(t,NO,timeSim(idx),mCyl(idx),pCyl(idx),TbCalc(idx),FbCalc(idx),xAir,FC,TL,TH);
    ts = timeSim(idx(1));
    tf = timeSim(idx(end));
    [t,NO] = ode45(dNOFunc,[ts tf],0);
    NOCalc(idx) = interp1(t,NO,timeSim(idx));
    if i - progress_idx > 0.1*noCyc
        progress_idx = progress_idx + 0.1*noCyc;
        fprintf('.');
    end;
end;
fprintf('.\n');

idxEndCyc(1) = 0;
noCyc = 1;
for i=1:nStep-1
    if phiCombCyl(i+1) - phiCombCyl(i) < 0  % when the piston at BDC
        noCyc = noCyc + 1;                % count the cycle
        idxEndCyc(noCyc) = i;
    end;
end;
sNOxCalc = zeros(nStep,1);
for i=1:noCyc-1
    idx = idxEndCyc(i)+1:idxEndCyc(i+1);
    NO = max(NOCalc(idx))*30;                   % NOx produced per cycle [g]
    wCyc = WCyl(idx(end))-WCyl(idx(1));          % Work per cycle [kWh]
    sNOx = NO / wCyc;                           % Specific NOx [g/kWh]
    sNOxCalc(idx) = sNOx;
end;

function [TuCalc,TbCalc,FuCalc,FbCalc,vuCalc,vbCalc]= Get2ZoneTemp(phiCyl,pCyl,TCyl,FCyl,vCyl,mfCyl,QCyl,varargin)
% The function calculate the temperature of each of the burned and unburned
% zone in the engine cylinder from single zone simulation output.
% Input(must)
%   phiCyl : crank angle array           [rad]
%   pCyl : In-cylinder pressure array    [Pa]
%   TCyl : In-cylinder temperature array [K]
%   FCyl : Fuel-air equivalent ratio array 
%   vCyl : Cylinder volume array         [m3]
%   mfCyl : Mass of fuel injected array  [kg]
%   QCyl : Heat loss array               [J]
% Input(option)
%   FComb : Fuel-air equivalent ratio for combustion (default 1)
%   fs : Stoichiometric fuel to air ratio            (default 0.0683)
%   hn : LHV of the fuel [J/kg]                      (default 42707000)
%   gamma : Solution line search length              (default 0.05)
% Output
%   TuCalc : Temperature of the unburned zone (K)
%   TbCalc : Temperature of the burned zone (K)
%   FuCalc : Fuel-air equivalent ratio of unburned zone 
%   FbCalc : Fuel-air equivalent ratio of burned zone 
%   vuCalc : Volume of the unburned zone [m3]
%   vbCalc : Volume of the burned zone [m3]

%% Initialization
nStep = length(phiCyl);                % number of time steps
cycleNo = 0;
TuCalc = zeros(nStep-1,1);
TbCalc = TuCalc;
%puCalc = TuCalc;
%pbCalc = TbCalc;
FuCalc = TbCalc;
FbCalc = TbCalc;
%f1Calc = TbCalc;
%f2Calc = TbCalc;
vuCalc = TbCalc;
vbCalc = TbCalc;
resetCycle = 1;
nvar = length(varargin);
if nvar - 4 < 0
    for i=1:4-nvar
        varargin{nvar+i} = [];
    end;
end;
if isempty(varargin)
    FComb = 1;                  %Fuel air equivalent ratio of combustion
    fs = 0.0683;                %fs
    hn = 42707000;              %LHV of the fuel
    gamma = 0.1;                %length of search for gradient descent method
else
    if isempty(varargin{1})
        FComb = 1;
    else
        FComb = varargin{1};
    end;
    if isempty(varargin{2})
        fs = 0.0683;
    else
        fs = varargin{2};    
    end;
    if isempty(varargin{3})
        hn = 42707000;
    else
        hn = varargin{3};    
    end;
    if isempty(varargin{4})
        gamma = 0.05;
    else
        gamma = varargin{4};
    end;
end;
PreBurnedZoneRatiio = 0.01;

%% Additional calculation to find mass and internal energy 
[RCyl,~,~,uCyl] = GetThdynCombGasZach(pCyl,TCyl,FCyl);
mCyl = pCyl.*vCyl ./ (RCyl.*TCyl);
UCyl = mCyl.*uCyl;
mbCyl = mCyl.*FCyl*fs ./ (1+FCyl*fs);

%% Convert the crank angle to [-pi:pi]
phiCombCyl = phiCyl - 2*pi*(floor(phiCyl/(2*pi)));
phiCombCyl(phiCombCyl>pi) = phiCombCyl(phiCombCyl>pi) - 2*pi;

%% 2Zone Calculation
for i=1:nStep-1
    if phiCombCyl(i+1) - phiCombCyl(i) < 0  % when the piston at BDC
        cycleNo = cycleNo + 1;                % count the cycle
        resetCycle = 1;                       % reset the cycle
    end;
    if phiCombCyl(i) > -pi/9 && phiCombCyl(i) < pi/2  % -20deg<phi<90deg
        if resetCycle == 1                    % If the cycle is reset
            muTemp = mCyl(i)*(1-PreBurnedZoneRatiio);
            mbTemp = mCyl(i)*PreBurnedZoneRatiio;
            vuTemp = vCyl(i)*(1-PreBurnedZoneRatiio);
            vbTemp = vCyl(i)*PreBurnedZoneRatiio;
            resetCycle = 0;
            [~,huTemp,~,uuTemp,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(pCyl(i),TCyl(i),0);
            ubTemp = uuTemp;
            FbTemp = FCyl(i);
            FuTemp = FCyl(i);
            TuTemp = TCyl(i);
            TbTemp = TCyl(i);
  %          puTemp = pCyl(i);
  %          pbTemp = pCyl(i);
  %          vCylTemp = vCyl(i);
            UbTemp = mbTemp.*ubTemp;
        else
            DeltaMf = mfCyl(i) - mfCyl(i-1);
            DeltaQCyl = QCyl(i) - QCyl(i-1);
            maTemp = DeltaMf / (FComb*fs);
            mbTemp = mbPrev + DeltaMf + maTemp;
            muTemp = mCyl(i) - mbTemp;
            mbfTemp = mbPrev*FbPrev*fs/(1+FbPrev*fs) + DeltaMf;
            mufTemp = mbCyl(i) - mbfTemp;
            FbTemp = mbfTemp / (fs*(mbTemp - mbfTemp));
            FuTemp = mufTemp / (fs*(muTemp - mufTemp));
            TbTemp = TbPrev; %pCyl(i)*vbPrev / (mbTemp*RbPrev);
            TuTemp = TuPrev; %pCyl(i)*vuPrev / (muTemp*RuPrev);
            DeltaQb = mbPrev*TbPrev / (muPrev*TuPrev + mbPrev*TbPrev)*DeltaQCyl;
            err = 1;
            j = 0;
            while err > 0.001                          % Solve for Tb satisfying the ideal gas law and 1st law of thermodynamics 
                j = j + 1;
                [RbTemp,~,~,ubTemp,~,~,RTb,~,~,uTb,~,~,~] = GetThdynCombGasZach(pCyl(i),TbTemp,FbTemp);
                [RuTemp,~,~,uuTemp,~,~,RTu,~,~,uTu,~,~,~] = GetThdynCombGasZach(pCyl(i),TuTemp,FuTemp);
                pVbTemp = mbTemp.*RbTemp.*TbTemp;
                pVuTemp = muTemp.*RuTemp.*TuTemp;
                vbTemp = pVbTemp./pCyl(i);
                vuTemp = pVuTemp./pCyl(i);
                DeltaVb = vbTemp - vbPrev;
                DeltaUbCalc = DeltaMf*hn + maTemp*huPrev - DeltaQb - pCyl(i-1)*DeltaVb;
                UuTemp = muTemp.*uuTemp;
                UbTemp = mbTemp.*ubTemp;
                f1 = vuTemp.*pVbTemp - vbTemp.*pVuTemp;
                f2 = (UuTemp  + UbTemp - UCyl(i))/1000;
                f3 = (UbTemp - UbPrev - DeltaUbCalc)/1000;
                Jf11 = -vbTemp*muTemp*TuTemp*RTu;   Jf12 = vuTemp*mbTemp*TbTemp*RTb;
                Jf21 = uTu/1000;                         Jf22 = uTb/1000;
                Jf31 = 0;                                Jf32 = (uTb + mbTemp*pCyl(i-1)/pCyl(i)*(RbTemp + TbTemp*RTb))/1000;
                dTu = gamma*(Jf11*f1 + Jf21*f2 + Jf31*f3);
                dTb = gamma*(Jf12*f1 + Jf22*f2 + Jf32*f3);
                err = max(abs([dTu/TuTemp,dTb/TbTemp]));
                TbTemp = TbTemp - dTb;
                TuTemp = TuTemp - dTu;
                if j > 100000
                    warning('Could not achieve convergence after 10000 iternation');
                    warning('Error: %f',err);
                    break;
                end;
            end;
 %           puTemp = pVuTemp / vuTemp;
 %           pbTemp = pVbTemp / vbTemp;
 %           vCylTemp = vuTemp + vbTemp;
        end;
        muPrev = muTemp;
        mbPrev = mbTemp;
        vbPrev = vbTemp;
        huPrev = huTemp;
        UbPrev = UbTemp;
        TuPrev = TuTemp;
        TbPrev = TbTemp;
        FbPrev = FbTemp;
    else
        TuTemp = TCyl(i);
        TbTemp = TCyl(i);
%        pbTemp = pCyl(i);
%        puTemp = pCyl(i);
        FbTemp = FCyl(i);
        FuTemp = FCyl(i);
%        vCylTemp = vCyl(i);
    end;
    TuCalc(i) = TuTemp;
    TbCalc(i) = TbTemp;
%    puCalc(i) = puTemp;
%    pbCalc(i) = pbTemp;
    FuCalc(i) = FuTemp;
    FbCalc(i) = FbTemp;
    vuCalc(i) = vuTemp;
    vbCalc(i) = vbTemp;
    FbCalc(i) = FbTemp;
end;

function dNO = dNO(t,NO,tArray,mCyl,pCyl,TCyl,FCyl,varargin)
% The function calculates the derivative of NO formation by thermal NOx 
% using Zedovich's extended mechanism.
% Input (Variable)
%   t : simulation time
%   NO : NO formed          [mol]
% Input (Parameters)
%   tArray : time array for given cylinder data  [s]
%   pCyl : Time-series of pressure of the volume [Pa]
%   TCyl : Time-series of temperature of the volume [K]
%   FCyl : Time-series of fuel-air equivalent ratio of the volume 
% Input (Optional)
%   xAir : Air composition in mole fraction 
%           default([0;0;0;0;0;0;0;0.2095;0;0.0003;0.7809;0.0093])
%   FC : Fuel composition as in [m;n;p;q] where CmHnOpNq
%           default([1;1.8;0;0])          
%   TL : Tempreature low limit for transition from complete combustion to
%        dissociation (default 1500)                  
%   TH : Tempreature high limit for transition from complete combustion to
%        dissociation (default 1700)
% Output
%   dNO : Time derivative of the NO formation [mol/s]

if isempty(varargin)
    xAir = [0;0;0;0;0;0;0;0.2095;0;0.0003;0.7809;0.0093];
                            %Composition of the air (mole fraction) 
                            % [xH; xO; xN; xH2; xOH; xCO; xNO; xO2; xH2O;
                            %     xCO2; xN2; xAr];
    FC = [1;1.8;0;0];        %Composition of the fuel (CmHnOoNp)
    T_L = 1500;
    T_H = 1700;
else
    if isempty(varargin{1})
        xAir = [0;0;0;0;0;0;0;0.2095;0;0.0003;0.7809;0.0093];
    else
        xAir = varargin{1};        
    end;
    if isempty(varargin{2})
        FC = [1;1.8;0;0];        %Composition of the fuel (CmHnOoNp)
    else
        FC = varargin{2};
    end;
    if isempty(varargin{3})
        T_L = 1500;
    else
        T_L = varargin{3};
    end;
    if isempty(varargin{4})
        T_H = 1700;
    else
        T_H = varargin{4};        
    end;
end;

p = interp1(tArray,pCyl,t);
T = interp1(tArray,TCyl,t);
F = interp1(tArray,FCyl,t);
m = interp1(tArray,mCyl,t);
[R,~,~,~] = GetThdynCombGasZach(p,T,F);
MW = 8314.4621/R/1000;                      %kg/mol
noMol = m/MW;                               %mol

v = m*R*T/p*1e6;                            %volume in cm3
x = GetCompCombGas(p,T,F,T_L,T_H,FC,xAir);  %Composition in mole fraction
N = x*noMol;                                %Composition in moles
c = N / v;                                  % concentration mol/cm3
k1 = 7.6e13*exp(-38000/T);
k2 = 6.4e9*T*exp(-3150/T);
k3 = 4.13e13;
R1 = k1*c(2)*c(11);
R2 = k2*c(3)*c(8);
R3 = k3*c(3)*c(5);
cNO = NO / v;
if R2+R3 == 0
    dcNO = 0;
else
    dcNO = 2*R1*(1-(cNO/c(7))^2) / (1+cNO*c(7)*R1/(R2+R3));
end;
dNO = dcNO*v;



function editLHV_Callback(hObject, eventdata, handles)
% hObject    handle to editLHV (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editLHV as text
%        str2double(get(hObject,'String')) returns contents of editLHV as a double


% --- Executes during object creation, after setting all properties.
function editLHV_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editLHV (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenuPhiCyl.
function popupmenuPhiCyl_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenuPhiCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenuPhiCyl contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenuPhiCyl


% --- Executes during object creation, after setting all properties.
function popupmenuPhiCyl_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenuPhiCyl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbuttonPlot.
function pushbuttonPlot_Callback(hObject, eventdata, handles)


% hObject    handle to pushbuttonPlot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
result1 = evalin('base','exist(''NOCalc'')');
result2 = evalin('base','exist(''sNOxCalc'')');
if result1*result2 == 1
    NOCalc = evalin('base','NOCalc');
    sNOxCalc = evalin('base','sNOxCalc');
    figure
    haxes = plotyy(NOCalc.time,NOCalc.Data,sNOxCalc.time,sNOxCalc.Data);
    ylabel(haxes(1),'NO [mol]') % label left y-axis
    ylabel(haxes(2),'sNOx [g/kWh]') % label right y-axis
    xlabel(haxes(2),'Time [s]') % label x-axis
    ylim(haxes(1),[0 max(ylim)]);
    %ylim(haxes(2),[0 max(ylim)]);

else
    error('The NOx calculation results are not available. Try again after new calculation\n');
end;
