// File: PacketCarTelemetry2Data.h
#ifndef PACKETCARTELEMETRY2DATA_H
#define PACKETCARTELEMETRY2DATA_H

#include "PHeader.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct CarTelemetry2Data
{
    uint8_t   m_activeAeroMode;                   // 0 = Corner mode, 1 = Straight mode
    uint8_t   m_activeAeroAvailable;              // 0 = not available, 1 = available
    uint16_t  m_activeAeroActivationDistance;     // 0 = Active aero not available, non-zero - Active aero will be available in [X] metres
    uint8_t   m_overtakeAvailable;                // 0 = not available, 1 = available
    uint8_t   m_overtakeActive;                   // 0 = not active, 1 = active
    uint16_t  m_overtakeActivationDistance;       // 0 = Overtake Mode not available, non-zero - Overtake Mode will be available in [X] metres
    uint8_t   m_2026Regulations;                  // 0 = vehicle conforms to pre-2026, 1 = 2026 regulations applicable
    uint8_t   m_drivingWrongWay;                  // Whether the car is driving the wrong way
};

struct PacketCarTelemetry2Data
{
    PacketHeader        m_header;               // Header

    // Packet specific data
    CarTelemetry2Data   m_carTelemetry2Data[cs_maxNumCarsInUDPData];   // data for all cars on track
};
#pragma pack(pop)

#endif 
