# Remote Control for Tetris Project 
Author: Ben Evans 

The RemoteControl.ino file is to be compiled and loaded onto the Arduino Esplora remote control.  
This remote control will then have four output pins (one for each of 4 push buttons) to connect to the main Arduino. 

Pin assignments are: 
	SWITCH_1 => PIN8 
	SWITCH_2 => PIN0 
	SWITCH_3 => PIN7 
	SWITCH_4 => PIN1 

The logic in the code makes the assumption that more than one button will never need to be pressed simultaneously.  
If this functionality is needed, simply change all 'else if' statements and the ending 'else' to 'if' statements so that each is considered in every loop.  


