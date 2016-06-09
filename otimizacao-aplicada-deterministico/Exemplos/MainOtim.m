format long

%***************Para o ExemOtim1****************

% clear all; clc; warning off;
% x0 = [-10 30];
% [x] = fminsearch(@ExemOtim1,x0)
% ************Fim Para o ExemOtim1***************
% 
% ***************Para o ExemOtim2****************

% clear all; clc; warning off;
% x0 = [2 9];
% %otimo local em [1 1];
% options = optimset('LargeScale','off');
% [x] = fmincon(@ExemOtim2,x0,[],[],[],[],[],[],@restrExemOtim2,options)
%************Fim Para o ExemOtim2***************

%***************Para o ExemOtim3****************

%clear all; clc; warning off;
%x0 = [5 5];
%options = optimset('LargeScale','off');
%[x,fval] = fmincon(@ExemOtim3,x0,[],[],[],[],[],[],@restrExemOtim3,options)
%[x,fval] = fminsearch(@ExemOtim3b,x0)
%************Fim Para o ExemOtim3***************

% %***************Para o ExemOtim4****************

% clear all; clc; warning off;
% x0 = [0 5000];
% options = optimset('LargeScale','off');
% [x,fval] = fminsearch(@ExemOtim4,x0)
% % [x] = fmincon(@ExemOtim4,x0,[],[],[],[],[],[],@restrExemOtim3,options)
%************Fim Para o ExemOtim4***************

%***************Para o ExemOtim5****************

% clear all; clc; warning off;
% options = optimset('TolX',1e-12,'Display','off');
% [x] = fminbnd(@ExemOtim5,0,0,options)
%************Fim Para o ExemOtim5***************

%***************Para o ExemOtim01****************

% % clear all; clc; warning off;
% % x0 = [0.2 0.2 0.5];
% % % x0 = [20 30 40];
% % options = optimset('LargeScale','off');
% % [x] = fminsearch(@MainExem01,x0)
% % % [x] = fmincon(@ExemOtim4,x0,[],[],[],[],[],[],@restrExemOtim3,options)
% % % %************Fim Para o ExemOtim01***************


%***************Para o ExemOtim1****************

% clear all; clc; warning off;
% x0 = [-10 30];
% [x,fval] = fminsearch(@ExemOtim1,x0)
% ************Fim Para o ExemOtim1***************
% 
% ***************Para o ExemOtim2****************

% clear all; clc; warning off;
% x0 = [1 1];
% options = optimset('LargeScale','off');
% [x,fval] = fmincon(@ExemOtim2,x0,[],[],[],[],[],[],@restrExemOtim2,options)
%************Fim Para o ExemOtim2***************

%***************Para o ExemOtim3****************

clear all; clc; warning off;
x0 = [5 5];
options = optimset('LargeScale','off');
% [x,fval] = fmincon(@ExemOtim3,x0,[],[],[],[],[],[],@restrExemOtim3,options)
[x,fval] = fminsearch(@ExemOtim3,x0)
%************Fim Para o ExemOtim3***************

% %***************Para o ExemOtim4****************

% clear all; clc; warning off;
% x0 = [0 5000];
% options = optimset('LargeScale','off');
% [x,fval] = fminsearch(@ExemOtim4,x0)
% % [x,fval] = fmincon(@ExemOtim4,x0,[],[],[],[],[],[],@restrExemOtim3,options)
%************Fim Para o ExemOtim4***************

%***************Para o ExemOtim5****************

% clear all; clc; warning off;
% options = optimset('TolX',1e-12,'Display','off');
% [x,fval] = fminbnd(@ExemOtim5,0,0,options)
%************Fim Para o ExemOtim5***************

%***************Para o ExemOtim01****************

% % clear all; clc; warning off;
% % x0 = [0.2 0.2 0.5];
% % % x0 = [20 30 40];
% % options = optimset('LargeScale','off');
% % [x,fval] = fminsearch(@MainExem01,x0)
% % % [x,fval] = fmincon(@ExemOtim4,x0,[],[],[],[],[],[],@restrExemOtim3,options)
% % % %************Fim Para o ExemOtim01***************


















