# YM3812_VGM_Player
A Video Game Music player based on the YM3812 (OPL2) and Teensy 3.5.

You can view this project in action here:
https://www.youtube.com/watch?v=aLaUDFnNqQc

# Information about the main sound chips and VGM

The YM3812, AKA OPL2 was a staple FM soundchip of the early 1990's. It claim to fame was its inclusion on the Adlib and Soundblaster soundcards. OPL2 is THE FM sound of 1990's PC gaming.

VGM stands for Video Game Music, and it is a 44.1KHz logging format that stores real soundchip register information. My player will parse these files and send the data to the appropriate chips. You can learn more about the VGM file format here: http://www.smspower.org/Music/VGMFileFormat

http://www.smspower.org/uploads/Music/vgmspec170.txt?sid=58da937e68300c059412b536d4db2ca0

# Hook-up Guide

Teensy 3.5 | YM
------------ | -------------
23, 22, 21...17, 16 | D0-D7
34  | CS
33 | RD
32 | WR
31 | A0
30 | IC
29 | IRQ

The YM3812 requires a 3.579545 MHz signal to function properly. I just used a full-can crystal for this, but any clock source of that speed will work.
You will also need a Y3014B DAC IC along with an OP-amp (LM358).

# SD Card Information
The Teensy 3.5 has a built-in, high speed micro-SD card reader. You must format your SD card to Fat32 in order for this device to work correctly. Your SD card must only contain uncompressed .vgm files. VGZ FILES WILL NOT WORK! You may download .vgz files and use [7zip](http://www.7-zip.org/download.html) to extract the uncompressed file out of them. Vgm files on the SD card do not need to have the .vgm extension. As long as they contain valid, uncompressed vgm data, they will be read by the program regardless of their name.
You can find VGM files by Googling "myGameName VGM," or by checking out sites like http://vgmrips.net/packs/

# Control Over Serial
You can use a serial connection to control playback features. The commands are as follows:

Command | Result
------------ | -------------
\+ | Next Track
\- | Previous Track
\* | Random Track
\/ | Toggle Shuffle Mode
\. | Toggle Song Looping
r: | Request song

A song request is formatted as follows: ```r:mySongFile.vgm```
Once a song request is sent through the serial console, an attempt will be made to open that song file. The file must exist on the Teensy's SD card, and spelling/capitalization must be correct.
Need an easy-to-use serial console? [I've made one here.](https://github.com/AidanHockey5/OpenArduinoSerialConsole)

# Schematic
![Schematic](https://raw.githubusercontent.com/AidanHockey5/YM3812_VGM_Player/master/Schematics/OPL2_VGM_Player.sch.png)

[PDF](https://github.com/AidanHockey5/YM3812_VGM_Player/raw/master/Schematics/OPL2_VGM_Player.pdf)
