MedicalTile
===========

Description
----------------
MedicalTile is an open source software for 2D, 3D and 4D medical image visualization and processing. 
It's based on Qt, ITK and DCMTK. It works on WIN32 platform for now.<br>
![Qt](https://github.com/chrisjin/MedicalTile_Resources/blob/master/Qt.png)
![ITK](https://github.com/chrisjin/MedicalTile_Resources/blob/master/ITK.png)
![DCMTK](https://github.com/chrisjin/MedicalTile_Resources/blob/master/dcmtk.png)

Release
--------------
[DOWNLOAD](https://github.com/chrisjin/MedicalTile/releases/download/FirstRelease/Release_10_25_2014.zip)
<p>
You can test the tool by loading the root folder of the data samples below.
<br>
[Dicom sample 1, more than 3D images taken at many sequential time points](https://github.com/chrisjin/MedicalTile/releases/download/FirstRelease/PA3_010-001.zip)
<p>
[Dynamic MRI samples](http://www.osirix-viewer.com/datasets/)
<p>
[More samples](http://www.creatis.insa-lyon.fr/~jpr/PUBLIC/gdcm/gdcmSampleData/Philips_Medical_Images/mr711-mr712/INDEX.htm)

doc & Manual
----------
[A simple slides](https://github.com/chrisjin/MedicalTile/releases/download/doc/doc.pptx)<br>
When images are loaded, drag it to the browser to display it, drag it to processing panel to manipulate...<br>
Drag, drag, drag.

Feature
---------------
* Import CT or MR image folders.
* Display 3D image as slices.
* MPR view.
* Image processing algorithms including morphological algorithms, watershed algorithm, registration etc.
* Data visualization.
* 3D image series or 4D image, time-density curve of a ROI
* Zoom, pan, Window level/width
* Extremely extensible. 
     You can:
      * Add new algorithms
      * Add new data types 
      * Add new visualization panels for different data types. <br>(so far, only 3D image type, data array type can be visualized)

Screeshot
------------------------
####Images of a swine taken by a MRI
3D images of 20 time points or 4D image<br>
You can see gradual changes among these images indicating the injection and attenuation of contrast medium.
![](https://github.com/chrisjin/MedicalTile_Resources/blob/master/time-density.PNG)
####Images of brain
MPR view
![](https://github.com/chrisjin/MedicalTile_Resources/blob/master/mainframe2.PNG)
####MPR View in red, green, blue
![](https://github.com/chrisjin/MedicalTile_Resources/blob/master/MPR2.PNG)
####Image processing panel
You can freely save, move, select, delete and manipulate multple 3D images and other data types on this panel. <br>
All tiles are dragged from the main viewer, generated by an algorthm or loaded from files of a format particularly designed for each type of data.<br>
Each tile can represent a 3D image, a number array or other types.<br>
![](https://github.com/chrisjin/MedicalTile_Resources/blob/master/algopanel.PNG)
####Data visualization panel
You can set the range of X, Y axis, change the role of each row of numbers.
![](https://github.com/chrisjin/MedicalTile_Resources/blob/master/datavis.PNG)
####Segmentation of kidney of swine
![](https://github.com/chrisjin/MedicalTile_Resources/blob/master/segmentation.PNG)
####Time-density curve of contrast medium in kidney after injection
![](https://github.com/chrisjin/MedicalTile_Resources/blob/master/tdc.PNG)

Structure
---------------------
####Main framework
![](https://github.com/chrisjin/MedicalTile_Resources/blob/master/structure.PNG)
####ITK and Qt encapsulation
![](https://github.com/chrisjin/MedicalTile_Resources/blob/master/data.PNG)

Plugin
-----------------
* DLL plugin. Inherit a base class running your GUI, receiving data from the main application, processing your data and returning the result to the main application. The main application can handle all the rest.
* XML plugin. kind of simple scrypt plugin. A XML plugin organizes existing plugins in a cascading manner. When you run a XML plugin, actually you run several different plugins cascadingly. <br>
The plugin below combines Subtraction, Gaussian, ROISegmentation, Threshold, Opening, and LargestComponent together.
```
      <Test>
      <version>1</version>
      <name>KidneySeg</name>
      <category>Kidney</category>
      <algo>Subtraction</algo>
      <algo>Gaussian</algo>
      <algo>ROISegmentation</algo>
      <algo>Threshold</algo>
      <algo>Opening</algo>
      <algo>LargestComponent</algo>
      </Test>
```
* Other scrypt plugin. I plan to embed a python interpreter inside my application, but it's not done yet.

How to compile?
---------------
####Step 1, download the 3rd party libraries.
* Download ITK 4.1.0 from [ITK](http://www.itk.org/ITK/resources/legacy_releases.html)
* Download Qt >= 4.8.1 (I use 4.8.1 for this project, and Qt 4.8.5 also works fine) from [Qt](http://download.qt-project.org/archive/qt/4.8/)
* Download DCMTK3.6 from [DCMTK](http://dicom.offis.de/dcmtk.php.en)

####Step 2, compile ITK, DCMTK, and Qt, if you donwload the qt source code package
* Download [CMake](http://www.cmake.org/download/).
* Use CMake to generate VS solution for ITK and DCMTK. <br>
Remember to set shared library option.
Remember to set the CMAKE_INSTALL_PREFIX before generating.<br>
Hint: CMAKE_INSTALL_PREFIX is the path where you can get full library files after compilation. 
* Compile ITK and DCMTK.
* Run the INSTALL within each VS solution. After that, you will get full lib and heade files collected in one path same as CMAKE_INSTALL_PREFIX you set.
* Copy the 3rd party library files into the project and make the directory tree look like the following,
```
.
|->AlgoCraft, GUICraft, etc.   (Already ex)
|
|->Other    (Rename the folder "Other")                                        -|
    |->itk_dll                                                                  |
    |     |->include                                                            |
    |     |    |->ITK-4.1-->All header files and header sub directories         |
    |     |->lib->*.lib files                                                   |
    |->dcmtk                                                                    |--->3rdparties
          |->include                                                            |
          |    |->dcmtk                                                         |
          |         |->dcmdata-->all header files                               |
          |         |->dcmimage-->all header files                              |
          |         |->...        -->all header files                           |
          |->lib->*.lib files                                                  -|
```
* Compile Qt, if you downloaded the source code instead of win32 binaries.

####Step 3, add 3rd pary libraries and compile. 
* Visual studio 2010 is suggested.<br>
* If you download the Qt binaries, install it.
* Install Qt add-in for visual studio. You can find it in the downloaded Qt package.<br>
* Add headers and libraries to visual studio. If you make the directory tree exactly as above, you can skip this step.<br>
* Then, open the sln file in your visual studio and click build!<br>

To do
----------------
* Reorganize this project using CMake to make path configuration easier when compiling.
* Add a curve fitting plugin.
* Some texts are still in Chinese. I need to fix it.
