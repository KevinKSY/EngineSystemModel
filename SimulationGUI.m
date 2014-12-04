function varargout = SimulationGUI(varargin)
% SIMULATIONGUI MATLAB code for SimulationGUI.fig
%      SIMULATIONGUI, by itself, creates a new SIMULATIONGUI or raises the existing
%      singleton*.
%
%      H = SIMULATIONGUI returns the handle to a new SIMULATIONGUI or the handle to
%      the existing singleton*.
%
%      SIMULATIONGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in SIMULATIONGUI.M with the given input arguments.
%
%      SIMULATIONGUI('Property','Value',...) creates a new SIMULATIONGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before SimulationGUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to SimulationGUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help SimulationGUI

% Last Modified by GUIDE v2.5 01-Oct-2014 21:46:07

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @SimulationGUI_OpeningFcn, ...
                   'gui_OutputFcn',  @SimulationGUI_OutputFcn, ...
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


% --- Executes just before SimulationGUI is made visible.
function SimulationGUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to SimulationGUI (see VARARGIN)

% Choose default command line output for SimulationGUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes SimulationGUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = SimulationGUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function editSimTime_Callback(hObject, eventdata, handles)
% hObject    handle to editSimTime (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editSimTime as text
%        str2double(get(hObject,'String')) returns contents of editSimTime as a double


% --- Executes during object creation, after setting all properties.
function editSimTime_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editSimTime (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editInputVar_Callback(hObject, eventdata, handles)
% hObject    handle to editInputVar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editInputVar as text
%        str2double(get(hObject,'String')) returns contents of editInputVar as a double


% --- Executes during object creation, after setting all properties.
function editInputVar_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editInputVar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushBRunSim.
function pushBRunSim_Callback(hObject, eventdata, handles)

initFileName = get(handles.editInitFileName,'String');
if iscell(initFileName)
    initFileName = initFileName{1};
end;
if isempty(initFileName)
    error('Initial file name has not been specified');
else
    if exist(initFileName,'file') == 2
        modelName = get(handles.editModelName,'String');
        if iscell(modelName)
            modelName = modelName{1};
        end;
        if isempty(modelName)
            error('Model name has not been specified');
        else
            if exist(modelName,'file') == 4
                dataPath = get(handles.editDataPath,'String');
                if iscell(dataPath)
                    dataPath = dataPath{1};
                end;
                if isempty(dataPath)
                    error('Model path has not been specified');
                else
                    if exist(dataPath,'dir') == 7
                        codePath = get(handles.editCodePath,'String');
                        if iscell(codePath)
                            codePath = codePath{1};
                        end;
                        if isempty(codePath)
                            error('Code path has not been specified');
                        else
                            if exist(codePath,'dir') == 7
                                simTime = get(handles.editSimTime,'String');
                                if iscell(simTime)
                                    simTime = simTime{1};
                                end;
                                if isempty(simTime)
                                    error('Simulation time has not been specified');
                                else
                                    simTimeTest = str2num(simTime);
                                    if isempty(simTimeTest)
                                        error('Simulation time has not been specified');
                                    else
                                        simOutName = get(handles.editOutputVar,'String');
                                        if iscell(simOutName)
                                            simOutName = simOutName{1};
                                        end;                                        
                                        if isempty(simOutName)
                                            error('Simulation output variable not specified');
                                        else
                                            initFileName = initFileName(1:end-2);
                                            run(initFileName);
                                            modelName = modelName(1:end-4);
                                            load_system(modelName);
                                            tic;
                                            simOut = sim(modelName,'SrcWorkspace','current','StartTime','0','StopTime',num2str(simTime), ...
                                                'Solver','ode4','FixedStep','1e-3','SignalLogging','on','SignalLoggingName','logsout', ...
                                                'SaveOutput','on','SaveFormat','StructureWithTime');
                                            toc;
                                            runCommend = strcat('assignin(''base'',''',simOutName,''',',simOutName,');');
                                            eval(runCommend);
                                            assignin('base',simOutName,simOut);
                                        end;
                                    end;
                                end;                                    
                            else
                                error('No folder for s-function code exists');
                            end;
                        end;                        
                    else
                        error('No folder for model data exists');
                    end;
                end;
            else
                error('No such model exists');
            end;
        end;
    else
        error('No such initialization file exists');
    end;
end;


    
% hObject    handle to pushBRunSim (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function editOutputVar_Callback(hObject, eventdata, handles)
% hObject    handle to editOutputVar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editOutputVar as text
%        str2double(get(hObject,'String')) returns contents of editOutputVar as a double


% --- Executes during object creation, after setting all properties.
function editOutputVar_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editOutputVar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editInitFileName_Callback(hObject, eventdata, handles)
% hObject    handle to editInitFileName (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.initFileName = get(hObject,'String');
% Hints: get(hObject,'String') returns contents of editInitFileName as text
%        str2double(get(hObject,'String')) returns contents of editInitFileName as a double


% --- Executes during object creation, after setting all properties.
function editInitFileName_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editInitFileName (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editModelName_Callback(hObject, eventdata, handles)
% hObject    handle to editModelName (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.modelName = get(hObject,'String');
% Hints: get(hObject,'String') returns contents of editModelName as text
%        str2double(get(hObject,'String')) returns contents of editModelName as a double


% --- Executes during object creation, after setting all properties.
function editModelName_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editModelName (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushBBrowseInitFile.
function pushBBrowseInitFile_Callback(hObject, eventdata, handles)
% hObject    handle to pushBBrowseInitFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[handles.initFileName, handles.path, ~] = uigetfile('*.m');
if handles.initFileName ~= 0
    set(handles.editInitFileName,'String',handles.initFileName);
    addpath(handles.path);
end;
    


% --- Executes on button press in pushBBrowseModel.
function pushBBrowseModel_Callback(hObject, eventdata, handles)
% hObject    handle to pushBBrowseModel (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[handles.modelName, handles.modelPath, ~] = uigetfile('*.mdl','*.slx');
if handles.modelName ~= 0
    set(handles.editModelName,'String',handles.modelName);
    addpath(handles.modelPath);
end;

% --- Executes on button press in pushBEditInitFile.
function pushBEditInitFile_Callback(hObject, eventdata, handles)
% hObject    handle to pushBEditInitFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
filename = get(handles.editInitFileName,'String');
if iscell(filename)
    filename = filename{1};
end;
if isempty(filename)
    warning('Initial file name has not been specified');
else
    if exist(filename,'file') == 2
        open(filename);
    else
        warning('No such file exists');
    end;
end;



% --- Executes on button press in pushBEditModel.
function pushBEditModel_Callback(hObject, eventdata, handles)
% hObject    handle to pushBEditModel (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
filename = get(handles.editModelName,'String');
if isempty(filename)
    warning('Initial file name has not been specified');
else
    if exist(filename,'file') == 4
        open(filename);
    else
        warning('No such file exists');
    end;
end;


function editDataPath_Callback(hObject, eventdata, handles)
% hObject    handle to editDataPath (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editDataPath as text
%        str2double(get(hObject,'String')) returns contents of editDataPath as a double


% --- Executes during object creation, after setting all properties.
function editDataPath_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editDataPath (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushBBrowseData.
function pushBBrowseData_Callback(hObject, eventdata, handles)
% hObject    handle to pushBBrowseData (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.dataPath = uigetdir;
if handles.dataPath ~= 0
    set(handles.editDataPath,'String',handles.dataPath);
    addpath(handles.dataPath);
end;

% --- Executes on button press in pushBViewResult.
function pushBViewResult_Callback(hObject, eventdata, handles)
simOutName = get(handles.editOutputVar,'String');
assignin('base','simOutName',simOutName);
DataProcessGUI;
% hObject    handle to pushBViewResult (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function editCodePath_Callback(hObject, eventdata, handles)
% hObject    handle to editCodePath (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editCodePath as text
%        str2double(get(hObject,'String')) returns contents of editCodePath as a double


% --- Executes during object creation, after setting all properties.
function editCodePath_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editCodePath (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushBBrowseCode.
function pushBBrowseCode_Callback(hObject, eventdata, handles)
% hObject    handle to pushBBrowseCode (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.codePath = uigetdir;
if handles.codePath ~= 0
    set(handles.editCodePath,'String',handles.codePath);
    addpath(handles.codePath);
end;


% --- Executes on button press in pushBCompile.
function pushBCompile_Callback(hObject, eventdata, handles)
% hObject    handle to pushBCompile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.currentPath = pwd;
handles.codePath = get(handles.editCodePath,'String');
if isempty(handles.codePath)
    warning('No path set for the codes')
else
    cd(handles.codePath);
    make;
    cd(handles.currentPath);
end;


% --- Executes on button press in pushbNOxAnalysis.
function pushbNOxAnalysis_Callback(hObject, eventdata, handles)
simOutName = get(handles.editOutputVar,'String');
assignin('base','simOutName',simOutName);
NOxProcessGUI;
% hObject    handle to pushbNOxAnalysis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
