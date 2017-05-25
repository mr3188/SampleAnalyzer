#ifndef ACS712_SIMULATION_DATA_GENERATOR
#define ACS712_SIMULATION_DATA_GENERATOR

#include <SimulationChannelDescriptor.h>
#include <string>
class Acs712AnalyzerSettings;

class Acs712SimulationDataGenerator
{
public:
	Acs712SimulationDataGenerator();
	~Acs712SimulationDataGenerator();

	void Initialize( U32 simulation_sample_rate, Acs712AnalyzerSettings* settings );
	U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channel );

protected:
	Acs712AnalyzerSettings* mSettings;
	U32 mSimulationSampleRateHz;

protected:
	void CreateSerialByte();
	std::string mSerialText;
	U32 mStringIndex;

	SimulationChannelDescriptor mSerialSimulationData;

};
#endif //ACS712_SIMULATION_DATA_GENERATOR