%% Test QR encoding and decoding
% http://www.mathworks.com/matlabcentral/fileexchange/29239-qr-code-encode-
% and-decode
% by Lior Shapira 2010Nov
% edited by Matt Pepper 2012Mar

% WARNING SUPPRESSION ***************************************************
%this first warning warns the user that: there is a "core.jar" is
%already specified on static java path. Seeing as we don't use other java
%functions, we shouldn't have any conflict respecifying core.jar
s = warning('off','MATLAB:javaclasspath:jarAlreadySpecified');

%These javaaddpath cmds are the cause the suppressed warnings above
javaaddpath('C:\Program Files (x86)\ZXing\core\core.jar');
javaaddpath('C:\Program Files (x86)\ZXing\javase\javase.jar');

%this second warning indicates an: Out of range value converted to
%intmin('uint8') or intmax('uint8'). This seems to be just a nanny alarm
%generated by decode_qr
r = warning('off','MATLAB:intConvertOverflow');

% CODE SECTION **********************************************************
% Encode a new QR code
test_encode = ~encode_qr('this is only a test', [320 320]);
figure;
imshow(test_encode);
% Used for creating QR codes 
% imwrite(test_encode,'QR_testDecode.jpg','jpg');

% Decode the QR code
% test_encode = imread('QR_bkgndDecodeTest1.jpg');
message = decode_qr(test_encode)


%reinitialize the warnings that were turned off above
warning(s);
warning(r);