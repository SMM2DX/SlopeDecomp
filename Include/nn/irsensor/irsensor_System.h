#pragma once

#include "applet.h"

namespace nn::irsensor::system {

void SetAppletResourceUserId(const applet::AppletResourceUserId&);
void RegisterAppletResourceUserId(const applet::AppletResourceUserId&, bool);
void UnregisterAppletResourceUserId(const applet::AppletResourceUserId&);
void EnableAppletToGetInput(const applet::AppletResourceUserId&, bool);

}  // namespace nn::irsensor::system
