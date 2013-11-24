IpToolBox


This Program has 4 filters, each of which rely on different ROI files.

-----------------------------------------------
1. Compilation and execution
-----------------------------------------------
*To Compile use

>sh compile.sh


*Choose One of the filters

GrayThresh - sh exeme_GrayThresh.sh ipToolBox
ColorThresh - sh exeme_ColorThresh.sh ipToolBox
Arithmetic - sh exeme_Arithmetic.sh ipToolBox
AdaptThresh - sh exeme_AdaptThresh.sh ipToolBox



-----------------------------------------------
2. ROI format and Specifications
-----------------------------------------------

*********FIRST DIGIT OF ROI FILES MUST SPECIFY NUMBER OF DESIRED ROIs********************
*GrayThresh
-First Digit specifying number of ROIs
-then all other data should be in following format
  (x, y, sx, sy, Threshold)

*ColorThresh
-First Digit specifying number of ROIs
-then all other data shouuld be in following format
  (x, y, sx, sy, Distance, red, green, blue)    //red, green and blue are RGB value of Threshold

*Arithmetic
-First Digit specifying number of ROIs
-(x, y, sx, sy, value)

*AdaptThresh
-First Digit specifying number of ROIs
-(x, y, sx, sy, T, winsize, weight)


------------------------------------------------
3. Sample ROIs
------------------------------------------------
*Sample ROI files are contained in rois.zip