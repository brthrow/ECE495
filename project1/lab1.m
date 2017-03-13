clc
close all

decimation = 1;
samples = 250;
timestep = 0.0001;
frequency = 2000;
rad = 12566;
%{
figure(1)
p1 = plot(tg.TimeLog, tg.OutputLog(:,1));
xlabel('Time (s)');
ylabel('Voltage (V)');
title('2000 Hz Sinusoidal Wave');
grid on
axis([1,1.01,-1.1,1.1]);
%{
figure(2)
p2 = plot(tg.TimeLog, tg.OutputLog(:,2));
xlabel('Time (s)');
ylabel('Voltage (V)');
title('100 Hz Square Wave');
grid on
axis([0,0.1,-1,6]);

figure(3)
p3 = plot(tg.TimeLog, tg.OutputLog(:,3));
xlabel('Time (s)');
ylabel('Count (#)');
title('Encoder');
grid on
%axis([0,3.5,-40,100]);
%}
%}