#include "helper/KeyCodes.h"

SHORT KeyCodes::keyboardKeyScans(std::string key)
{
    if (key == "SHIFT") return VK_SHIFT;
    if (key == "CTRL" || key == "CONTROL") return VK_CONTROL;
    if (key == "ALT" || key == "MENU") return VK_MENU;
    if (key == "ENTER" || key == "RETURN") return VK_RETURN;
    return 0x00;
}