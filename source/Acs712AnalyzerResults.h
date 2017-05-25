#ifndef ACS712_ANALYZER_RESULTS
#define ACS712_ANALYZER_RESULTS

#include <AnalyzerResults.h>

class Acs712Analyzer;
class Acs712AnalyzerSettings;

class Acs712AnalyzerResults : public AnalyzerResults
{
public:
	Acs712AnalyzerResults( Acs712Analyzer* analyzer, Acs712AnalyzerSettings* settings );
	virtual ~Acs712AnalyzerResults();

	virtual void GenerateBubbleText( U64 frame_index, Channel& channel, DisplayBase display_base );
	virtual void GenerateExportFile( const char* file, DisplayBase display_base, U32 export_type_user_id );

	virtual void GenerateFrameTabularText(U64 frame_index, DisplayBase display_base );
	virtual void GeneratePacketTabularText( U64 packet_id, DisplayBase display_base );
	virtual void GenerateTransactionTabularText( U64 transaction_id, DisplayBase display_base );

protected: //functions

protected:  //vars
	Acs712AnalyzerSettings* mSettings;
	Acs712Analyzer* mAnalyzer;
};

#endif //ACS712_ANALYZER_RESULTS
