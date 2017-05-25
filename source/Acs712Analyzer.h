#ifndef ACS712_ANALYZER_H
#define ACS712_ANALYZER_H

#include <Analyzer.h>
#include "Acs712AnalyzerResults.h"
#include "Acs712SimulationDataGenerator.h"

class Acs712AnalyzerSettings;
class ANALYZER_EXPORT Acs712Analyzer : public Analyzer2
{
public:
	Acs712Analyzer();
	virtual ~Acs712Analyzer();

	virtual void SetupResults();
	virtual void WorkerThread();

	virtual U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channels );
	virtual U32 GetMinimumSampleRateHz();

	virtual const char* GetAnalyzerName() const;
	virtual bool NeedsRerun();

protected: //vars
	std::auto_ptr< Acs712AnalyzerSettings > mSettings;
	std::auto_ptr< Acs712AnalyzerResults > mResults;
	AnalyzerChannelData* mSerial;

	Acs712SimulationDataGenerator mSimulationDataGenerator;
	bool mSimulationInitilized;

	//Serial analysis vars:
	U32 mSampleRateHz;
	U32 mStartOfStopBitOffset;
	U32 mEndOfStopBitOffset;
};

extern "C" ANALYZER_EXPORT const char* __cdecl GetAnalyzerName();
extern "C" ANALYZER_EXPORT Analyzer* __cdecl CreateAnalyzer( );
extern "C" ANALYZER_EXPORT void __cdecl DestroyAnalyzer( Analyzer* analyzer );

#endif //ACS712_ANALYZER_H
