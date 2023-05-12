# CameraControl
A small command line utility to set focus and exposure settings on all attached and running webcams. NOTE: The cameras have to actually be active and running for this to work. 

# Usage
CameraControl.exe --exposure -6 --focus auto
CameraControl.exe --exposure auto
CameraControl.exe --focus 300

Options must either be numeric value or the word auto.
If an option isn't specified then its value is not changed

# Credit

This project was based heavily on SuslikV's cfg-cam project, https://github.com/SuslikV/cfg-cam
I liked it, but I had problem using it on an installation where I had multiple cameras attached to the computer and sometimes after reboot they would identify differently and consequently the desired settings wouldnt be restored. This app instead of trying to preserve camera settings in a config file lets you explicitly define focus and exposure settings for ALL attached and running cameras. 