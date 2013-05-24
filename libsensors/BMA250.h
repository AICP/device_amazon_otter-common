/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_BMA250_SENSOR_H
#define ANDROID_BMA250_SENSOR_H

#include <stdint.h>
#include <errno.h>
#include <sys/cdefs.h>
#include <sys/types.h>


#include "nusensors.h"
#include "SensorBase.h"
#include "InputEventReader.h"

#define BMA250_ENABLE_FILE "/sys/bus/i2c/devices/4-0018/enable"
#define BMA250_DELAY_FILE  "/sys/bus/i2c/devices/4-0018/delay"

/*****************************************************************************/

struct input_event;

class BMA250Sensor : public SensorBase {
public:
            BMA250Sensor();
    virtual ~BMA250Sensor();

    virtual int setDelay(int32_t handle, int64_t ns);
    virtual int enable(int32_t handle, int enabled);
    virtual int readEvents(sensors_event_t* data, int count);
    void processEvent(int code, int value);

private:
    int mEnabled;
    InputEventCircularReader mInputReader;
    sensors_event_t mPendingEvent;

    int isEnabled();
};

/*****************************************************************************/

#endif  // ANDROID_BMA250_SENSOR_H
