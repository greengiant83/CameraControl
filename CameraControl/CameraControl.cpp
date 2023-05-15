//#include <dshow.h>
#include <string>
#include "loginfo.h"
#include "camset.h"
#include <iostream>

int verbLevel = VERB_NORMAL; //display messages
//int verbLevel = VERB_FULL; //display debug messages
bool ignoreFriendlyName = false;

void helpme() {
    logMe(LOG_INFO, "");
    logMe(LOG_INFO, "CameraControl.Date.2023.version.1.0");
    logMe(LOG_INFO, "Sets focus and exposure on ALL attached cameras");
    logMe(LOG_INFO, "");
    logMe(LOG_INFO, "Usage: CameraControl.exe --exposure -6 --focus auto");
    logMe(LOG_INFO, "");
    logMe(LOG_INFO, "Options must either be numeric value or the word auto.");
    logMe(LOG_INFO, "if an option isn't specified then its value is not changed");
    logMe(LOG_INFO, "");
}

int main(int argc, char* argv[])
{
    //test
    /*argc = 3;
    argv[0] = (char*)"CameraControl";
    argv[1] = (char*)"--exposure";
    argv[2] = (char*)"-9";*/
    /*argv[1] = (char*)"--focus";
    argv[2] = (char*)"auto";*/

    Settings settings;
    if (argc <= 1)
    {
        helpme();
        return -1;
    }

    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];
        if (arg == "--exposure")
        {
            try
            {
                i++;
                if (i >= argc)
                {
                    logMe(LOG_ERR, "Missing exposure value");
                    settings.SetExposure = false;
                    continue;
                }

                string value = argv[i];

                settings.SetExposure = true;
                if (value == "auto")
                {
                    settings.IsExposureAuto = true;
                    logMe(LOG_DBG, "Exposure AUTO");
                }
                else
                {
                    settings.IsExposureAuto = false;
                    settings.ExposureValue = std::stol(value);
                }
            }
            catch (...)
            {
                settings.SetExposure = false;
                logMe(LOG_ERR, "Error parsing exposure value");
            }
        }
        else if (arg == "--focus")
        {
            try
            {
                i++;
                if (i >= argc)
                {
                    logMe(LOG_ERR, "Missing focus value");
                    settings.SetFocus = false;
                    continue;
                }

                string value = argv[i];

                settings.SetFocus = true;
                if (value == "auto")
                {
                    settings.IsFocusAuto = true;
                }
                else
                {
                    settings.IsFocusAuto = false;
                    settings.FocusValue = std::stol(value);
                }
            }
            catch (...)
            {
                settings.SetFocus = false;
                logMe(LOG_ERR, "Error parsing focus value");
            }
        }
    }

    try
    {
        CamSetAll cam;
        cam.executeSettings(settings);
        logMe(LOG_INFO, "Complete");
    }
    catch (...)
    {
        logMe(LOG_ERR, "Error executing settings");
    }

    return 0;
}
