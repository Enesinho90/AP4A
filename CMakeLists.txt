cmake_minimum_required(VERSION 3.26)
project(projet_ap4a)

set(CMAKE_CXX_STANDARD 17)

add_executable(projet_ap4a main.cpp
        Server.cpp
        Server.h
        Sensor.cpp
        Sensor.h
        Scheduler.cpp
        Scheduler.h
        SoundSensor.cpp
        SoundSensor.h
        HumiditySensor.cpp
        HumiditySensor.h
        TemperatureSensor.h
        TemperatureSensor.cpp
        LightSensor.cpp
        LightSensor.h)
