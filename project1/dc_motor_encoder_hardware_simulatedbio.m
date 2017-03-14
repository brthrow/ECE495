function bio=dc_motor_encoder_hardware_simulatedbio
bio = [];
bio(1).blkName='Derivative1';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&dc_motor_encoder_hardware_simulated_B.Derivative1';
bio(1).ndims=2;
bio(1).size=[];

bio(getlenBIO) = bio(1);

bio(2).blkName='Gain';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[3,1];
bio(2).sigWidth=3;
bio(2).sigAddress='&dc_motor_encoder_hardware_simulated_B.Gain[0]';
bio(2).ndims=2;
bio(2).size=[];


bio(3).blkName='Kd';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&dc_motor_encoder_hardware_simulated_B.Kd';
bio(3).ndims=2;
bio(3).size=[];


bio(4).blkName='Ki';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&dc_motor_encoder_hardware_simulated_B.Ki';
bio(4).ndims=2;
bio(4).size=[];


bio(5).blkName='Kp';
bio(5).sigName='';
bio(5).portIdx=0;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&dc_motor_encoder_hardware_simulated_B.Kp';
bio(5).ndims=2;
bio(5).size=[];


bio(6).blkName='gain';
bio(6).sigName='Setpoint';
bio(6).portIdx=0;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&dc_motor_encoder_hardware_simulated_B.Setpoint';
bio(6).ndims=2;
bio(6).size=[];


bio(7).blkName='Integrator1';
bio(7).sigName='';
bio(7).portIdx=0;
bio(7).dim=[1,1];
bio(7).sigWidth=1;
bio(7).sigAddress='&dc_motor_encoder_hardware_simulated_B.Integrator1';
bio(7).ndims=2;
bio(7).size=[];


bio(8).blkName='Sum1';
bio(8).sigName='Error Signal';
bio(8).portIdx=0;
bio(8).dim=[1,1];
bio(8).sigWidth=1;
bio(8).sigAddress='&dc_motor_encoder_hardware_simulated_B.ErrorSignal';
bio(8).ndims=2;
bio(8).size=[];


bio(9).blkName='Sum4';
bio(9).sigName='';
bio(9).portIdx=0;
bio(9).dim=[1,1];
bio(9).sigWidth=1;
bio(9).sigAddress='&dc_motor_encoder_hardware_simulated_B.Sum4';
bio(9).ndims=2;
bio(9).size=[];


bio(10).blkName='Real motor/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees';
bio(10).sigName='';
bio(10).portIdx=0;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&dc_motor_encoder_hardware_simulated_B.angular_positionrelative_countC';
bio(10).ndims=2;
bio(10).size=[];


bio(11).blkName='Real motor/Saturation';
bio(11).sigName='';
bio(11).portIdx=0;
bio(11).dim=[1,1];
bio(11).sigWidth=1;
bio(11).sigAddress='&dc_motor_encoder_hardware_simulated_B.Saturation';
bio(11).ndims=2;
bio(11).size=[];


bio(12).blkName='Real motor/Channel 0 of  Encoder Inputs ';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&dc_motor_encoder_hardware_simulated_B.Channel0ofEncoderInputs';
bio(12).ndims=2;
bio(12).size=[];


bio(13).blkName='Simulated motor/Back emf Ke1';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[1,1];
bio(13).sigWidth=1;
bio(13).sigAddress='&dc_motor_encoder_hardware_simulated_B.BackemfKe1';
bio(13).ndims=2;
bio(13).size=[];


bio(14).blkName='Simulated motor/Damping b1';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[1,1];
bio(14).sigWidth=1;
bio(14).sigAddress='&dc_motor_encoder_hardware_simulated_B.Dampingb1';
bio(14).ndims=2;
bio(14).size=[];


bio(15).blkName='Simulated motor/Gain Kt2';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[1,1];
bio(15).sigWidth=1;
bio(15).sigAddress='&dc_motor_encoder_hardware_simulated_B.GainKt2';
bio(15).ndims=2;
bio(15).size=[];


bio(16).blkName='Simulated motor/Gain Kt3';
bio(16).sigName='';
bio(16).portIdx=0;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&dc_motor_encoder_hardware_simulated_B.GainKt3';
bio(16).ndims=2;
bio(16).size=[];


bio(17).blkName='Simulated motor/Inductance';
bio(17).sigName='';
bio(17).portIdx=0;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&dc_motor_encoder_hardware_simulated_B.Inductance';
bio(17).ndims=2;
bio(17).size=[];


bio(18).blkName='Simulated motor/Resistance R1';
bio(18).sigName='';
bio(18).portIdx=0;
bio(18).dim=[1,1];
bio(18).sigWidth=1;
bio(18).sigAddress='&dc_motor_encoder_hardware_simulated_B.ResistanceR1';
bio(18).ndims=2;
bio(18).size=[];


bio(19).blkName='Simulated motor/Integrator1';
bio(19).sigName='';
bio(19).portIdx=0;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&dc_motor_encoder_hardware_simulated_B.Integrator1_h';
bio(19).ndims=2;
bio(19).size=[];


bio(20).blkName='Simulated motor/Integrator5';
bio(20).sigName='';
bio(20).portIdx=0;
bio(20).dim=[1,1];
bio(20).sigWidth=1;
bio(20).sigAddress='&dc_motor_encoder_hardware_simulated_B.Integrator5';
bio(20).ndims=2;
bio(20).size=[];


bio(21).blkName='Simulated motor/Integrator6';
bio(21).sigName='';
bio(21).portIdx=0;
bio(21).dim=[1,1];
bio(21).sigWidth=1;
bio(21).sigAddress='&dc_motor_encoder_hardware_simulated_B.Integrator6';
bio(21).ndims=2;
bio(21).size=[];


bio(22).blkName='Simulated motor/Sum1';
bio(22).sigName='';
bio(22).portIdx=0;
bio(22).dim=[1,1];
bio(22).sigWidth=1;
bio(22).sigAddress='&dc_motor_encoder_hardware_simulated_B.Sum1';
bio(22).ndims=2;
bio(22).size=[];


bio(23).blkName='Simulated motor/Sum2';
bio(23).sigName='';
bio(23).portIdx=0;
bio(23).dim=[1,1];
bio(23).sigWidth=1;
bio(23).sigAddress='&dc_motor_encoder_hardware_simulated_B.Sum2_e';
bio(23).ndims=2;
bio(23).size=[];


bio(24).blkName='input side switching logic/complement the input';
bio(24).sigName='';
bio(24).portIdx=0;
bio(24).dim=[1,1];
bio(24).sigWidth=1;
bio(24).sigAddress='&dc_motor_encoder_hardware_simulated_B.complementtheinput';
bio(24).ndims=2;
bio(24).size=[];


bio(25).blkName='input side switching logic/Product';
bio(25).sigName='';
bio(25).portIdx=0;
bio(25).dim=[1,1];
bio(25).sigWidth=1;
bio(25).sigAddress='&dc_motor_encoder_hardware_simulated_B.Product';
bio(25).ndims=2;
bio(25).size=[];


bio(26).blkName='input side switching logic/Product1';
bio(26).sigName='';
bio(26).portIdx=0;
bio(26).dim=[1,1];
bio(26).sigWidth=1;
bio(26).sigAddress='&dc_motor_encoder_hardware_simulated_B.Product1';
bio(26).ndims=2;
bio(26).size=[];


bio(27).blkName='switching logic/complement the input1';
bio(27).sigName='';
bio(27).portIdx=0;
bio(27).dim=[1,1];
bio(27).sigWidth=1;
bio(27).sigAddress='&dc_motor_encoder_hardware_simulated_B.complementtheinput1';
bio(27).ndims=2;
bio(27).size=[];


bio(28).blkName='switching logic/Product2';
bio(28).sigName='';
bio(28).portIdx=0;
bio(28).dim=[1,1];
bio(28).sigWidth=1;
bio(28).sigAddress='&dc_motor_encoder_hardware_simulated_B.Product2';
bio(28).ndims=2;
bio(28).size=[];


bio(29).blkName='switching logic/Product3';
bio(29).sigName='';
bio(29).portIdx=0;
bio(29).dim=[1,1];
bio(29).sigWidth=1;
bio(29).sigAddress='&dc_motor_encoder_hardware_simulated_B.Product3';
bio(29).ndims=2;
bio(29).size=[];


bio(30).blkName='switching logic/Sum2';
bio(30).sigName='';
bio(30).portIdx=0;
bio(30).dim=[1,1];
bio(30).sigWidth=1;
bio(30).sigAddress='&dc_motor_encoder_hardware_simulated_B.Sum2';
bio(30).ndims=2;
bio(30).size=[];


function len = getlenBIO
len = 30;

