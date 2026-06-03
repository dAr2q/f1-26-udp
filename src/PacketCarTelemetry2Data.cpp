// File: PacketCarTelemetry2Data.cpp
#include "PacketCarTelemetry2Data.h"
#include <inttypes.h>
#include <cstring>

const int CARTELEMETRY2_BUFFER_SIZE = 269;

PacketCarTelemetry2Data::PacketCarTelemetry2Data()
: PHeader()
{}

PacketCarTelemetry2Data::~PacketCarTelemetry2Data()
{}

void PacketCarTelemetry2Data::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, CARTELEMETRY2_BUFFER_SIZE);
}


CarTelemetry2Data PacketCarTelemetry2Data::m_carTelemetry2Data(int index)
{
    if (index >= 0 && index < 24)
        return m_carTelemetry2Data_[index];
    else return CarTelemetry2Data{};
}

uint8_t PacketCarTelemetry2Data::m_mfdPanelIndex(void)
{
    return m_mfdPanelIndex_;
}

uint8_t PacketCarTelemetry2Data::m_mfdPanelIndexSecondaryPlayer(void)
{
    return m_mfdPanelIndexSecondaryPlayer_;
}

int8_t PacketCarTelemetry2Data::m_suggestedGear(void)
{
    return m_suggestedGear_;
}
