# CameraControl
A small Windows command line utility to set **focus** and **exposure** settings on all attached and running webcams.  Tested on Windows 10.  

**NOTE: The cameras have to actually be active and running for this to work.  Requires the Visual C++ Redistributable to be installed**
**

## Usage
You can download the **.exe** from the **Releases** page

CameraControl.exe --exposure -6 --focus auto  
CameraControl.exe --exposure auto  
CameraControl.exe --focus 300  
  
Options must either be numeric value or the word auto.
If an option isn't specified then its value is not changed

## Credit

This project was based heavily on SuslikV's cfg-cam project, https://github.com/SuslikV/cfg-cam  
  
I liked it, but I had a problem using it on an installation where I had multiple cameras attached to the computer and sometimes after reboot they would identify differently and consequently the desired settings wouldn't be restored. This app instead of trying to preserve camera settings in a config file lets you explicitly define focus and exposure settings for ALL attached and running cameras. 
