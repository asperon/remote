Remote Control (remote.dll) version 1.02
This file was created on 2000-01-11 by Asperon
******************************************************************************
1. Introduction

   This is a general remote control module for litestep. By passing windows 
   messages to programs you can intreact with them through the litestep GUI
   (like shortcuts, popupmenu or whatever that supports bang commands).

******************************************************************************
2. Installation

   Unzip the remote.dll into your litestep dir. Add the line:

   loadmodule c:\litestep\remote.dll   

   to your step.rc (change c:\litestep to point at your litestep dir)
 
   after this you will have to add a *send command for each message you want
   to be able to use.

   the syntax is:

   *send <command-name> <window/program> <message> [program to run]

   where <command-name> is the name you want this message to have.
	 <window/program> is the name of the program/titel of the window
         <message> is the message number to send (check the program 
	   	   dokumentation for the right codes)
	 [program to run] optional, if the window isn't found, run this program

   example:

   *send IDNEXT CoolPlayer 40014, c:\program\coolplayer\coolplayer.exe

   would send 40014 to the CoolPlayer window whenever litestep runs a !Send IDNEXT
   and if that window isn't found it would run the coolplayer.exe.

   This way you can control everything from mp3-players to webbrowser to windows 
   native functions.

******************************************************************************
3. Commands
	
    Here are a couple of messagecodes for some programs, recived from the
    latest graphite build (which contains the feature that this dll handles).

    Settings for Windows Media Player:

	*Send PLAY "Media Player 2" 3047
	*Send STOP "Media Player 2" 3048
	*Send PAUSE "Media Player 2" 3047
	*Send OPEN "Media Player 2" 3009
	*Send PREVIOUS "Media Player 2" 3049
	*Send NEXT "Media Player 2" 3050

    Settings for Coolplayer:

	*Send PLAY "CoolPlayer" 40010
	*Send STOP "CoolPlayer" 40011
	*Send PAUSE "CoolPlayer" 40012
	*Send OPEN "CoolPlayer" 40013
	*Send PREVIOUS "CoolPlayer" 40015
	*Send NEXT "CoolPlayer" 40014

    Settings for WinAmp:

	*Send PLAY "WinAmp v1.x" 40045
	*Send STOP "WinAmp v1.x" 40047
	*Send PAUSE "WinAmp v1.x" 40046
	*Send OPEN "WinAmp v1.x" 40029
	*Send PREVIOUS "WinAmp v1.x" 40044
	*Send NEXT "WinAmp v1.x" 40048

    Settings for K-Jöfol v0.51:

	*Send PLAY "KjofolMainWindow" 8
	*Send STOP "KjofolMainWindow" 4
	*Send PAUSE "KjofolMainWindow" 12
	*Send OPEN "KjofolMainWindow" 2
	*Send PREVIOUS "KjofolMainWindow" 17
	*Send NEXT "KjofolMainWindow" 18

    Settings for K-Jöfol 2000 v1.0:

	*Send PLAY "KjofolMainWindow" 5128
	*Send STOP "KjofolMainWindow" 5124
	*Send PAUSE "KjofolMainWindow" 5132
	*Send OPEN "KjofolMainWindow" 5122
	*Send PREVIOUS "KjofolMainWindow" 5137
	*Send NEXT "KjofolMainWindow" 5128

******************************************************************************
4. Updates
	
   1.02 - Added the ability to run a program if the window wasn't found, so
	  that you could start up the required program. Also added the commands
	  section to this file, so you could get started easier.

   1.01 - Recompiled the module in a more aggressive manner, reducing its size 
	  to 20% of the last release. Enjoy!

******************************************************************************