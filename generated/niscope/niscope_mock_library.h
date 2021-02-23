//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Mock of LibraryInterface for NI-SCOPE
//---------------------------------------------------------------------
#ifndef NI_SCOPE_GRPC_MOCK_LIBRARY_H
#define NI_SCOPE_GRPC_MOCK_LIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "niscope_library_interface.h"

namespace ni {
namespace tests {
namespace unit {

class NiScopeMockLibrary : public ni::scope::grpc::NiScopeLibraryInterface {
 public:
  MOCK_METHOD(ViStatus, Abort, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, AcquisitionStatus, (ViSession vi, ViInt32* acquisitionStatus), (override));
  MOCK_METHOD(ViStatus, ActualMeasWfmSize, (ViSession vi, ViInt32 arrayMeasFunction, ViInt32* measWaveformSize), (override));
  MOCK_METHOD(ViStatus, ActualNumWfms, (ViSession vi, ViConstString channelList, ViInt32* numWfms), (override));
  MOCK_METHOD(ViStatus, AddWaveformProcessing, (ViSession vi, ViConstString channelList, ViInt32 measFunction), (override));
  MOCK_METHOD(ViStatus, AutoSetup, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, CalSelfCalibrate, (ViSession vi, ViConstString channelList, ViInt32 option), (override));
  MOCK_METHOD(ViStatus, ClearWaveformMeasurementStats, (ViSession vi, ViConstString channelList, ViInt32 clearableMeasurementFunction), (override));
  MOCK_METHOD(ViStatus, ClearWaveformProcessing, (ViSession vi, ViConstString channelList), (override));
  MOCK_METHOD(ViStatus, Commit, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, ConfigureChanCharacteristics, (ViSession vi, ViConstString channelList, ViReal64 inputImpedance, ViReal64 maxInputFrequency), (override));
  MOCK_METHOD(ViStatus, ConfigureEqualizationFilterCoefficients, (ViSession vi, ViConstString channelList, ViInt32 numberOfCoefficients, ViReal64 coefficients[]), (override));
  MOCK_METHOD(ViStatus, ConfigureHorizontalTiming, (ViSession vi, ViReal64 minSampleRate, ViInt32 minNumPts, ViReal64 refPosition, ViInt32 numRecords, ViBoolean enforceRealtime), (override));
  MOCK_METHOD(ViStatus, ConfigureTriggerDigital, (ViSession vi, ViConstString triggerSource, ViInt32 slope, ViReal64 holdoff, ViReal64 delay), (override));
  MOCK_METHOD(ViStatus, ConfigureTriggerEdge, (ViSession vi, ViConstString triggerSource, ViReal64 level, ViInt32 slope, ViInt32 triggerCoupling, ViReal64 holdoff, ViReal64 delay), (override));
  MOCK_METHOD(ViStatus, ConfigureTriggerHysteresis, (ViSession vi, ViConstString triggerSource, ViReal64 level, ViReal64 hysteresis, ViInt32 slope, ViInt32 triggerCoupling, ViReal64 holdoff, ViReal64 delay), (override));
  MOCK_METHOD(ViStatus, ConfigureTriggerImmediate, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, ConfigureTriggerSoftware, (ViSession vi, ViReal64 holdoff, ViReal64 delay), (override));
  MOCK_METHOD(ViStatus, ConfigureTriggerVideo, (ViSession vi, ViConstString triggerSource, ViBoolean enableDcRestore, ViInt32 signalFormat, ViInt32 eventParameter, ViInt32 lineNumber, ViInt32 polarity, ViInt32 triggerCoupling, ViReal64 holdoff, ViReal64 delay), (override));
  MOCK_METHOD(ViStatus, ConfigureTriggerWindow, (ViSession vi, ViConstString triggerSource, ViReal64 lowLevel, ViReal64 highLevel, ViInt32 windowMode, ViInt32 triggerCoupling, ViReal64 holdoff, ViReal64 delay), (override));
  MOCK_METHOD(ViStatus, ConfigureVertical, (ViSession vi, ViConstString channelList, ViReal64 range, ViReal64 offset, ViInt32 coupling, ViReal64 probeAttenuation, ViBoolean enabled), (override));
  MOCK_METHOD(ViStatus, Disable, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, ExportAttributeConfigurationBuffer, (ViSession vi, ViInt32 sizeInBytes, ViInt8 configuration[]), (override));
  MOCK_METHOD(ViStatus, ExportAttributeConfigurationFile, (ViSession vi, ViConstString filePath), (override));
  MOCK_METHOD(ViStatus, Fetch, (ViSession vi, ViConstString channelList, ViReal64 timeout, ViInt32 numSamples, ViReal64 waveform[], struct niScope_wfmInfo wfmInfo[]), (override));
  MOCK_METHOD(ViStatus, FetchArrayMeasurement, (ViSession vi, ViConstString channelList, ViReal64 timeout, ViInt32 arrayMeasFunction, ViInt32 measurementWaveformSize, ViReal64 measWfm[], struct niScope_wfmInfo wfmInfo[]), (override));
  MOCK_METHOD(ViStatus, FetchBinary16, (ViSession vi, ViConstString channelList, ViReal64 timeout, ViInt32 numSamples, ViInt16 waveform[], struct niScope_wfmInfo wfmInfo[]), (override));
  MOCK_METHOD(ViStatus, FetchBinary32, (ViSession vi, ViConstString channelList, ViReal64 timeout, ViInt32 numSamples, ViInt32 waveform[], struct niScope_wfmInfo wfmInfo[]), (override));
  MOCK_METHOD(ViStatus, FetchBinary8, (ViSession vi, ViConstString channelList, ViReal64 timeout, ViInt32 numSamples, ViInt8 waveform[], struct niScope_wfmInfo wfmInfo[]), (override));
  MOCK_METHOD(ViStatus, FetchMeasurementStats, (ViSession vi, ViConstString channelList, ViReal64 timeout, ViInt32 scalarMeasFunction, ViReal64 result[], ViReal64 mean[], ViReal64 stdev[], ViReal64 min[], ViReal64 max[], ViInt32 numInStats[]), (override));
  MOCK_METHOD(ViStatus, GetAttributeViBoolean, (ViSession vi, ViConstString channelList, ViAttr attributeId, ViBoolean* value), (override));
  MOCK_METHOD(ViStatus, GetAttributeViInt32, (ViSession vi, ViConstString channelList, ViAttr attributeId, ViInt32* value), (override));
  MOCK_METHOD(ViStatus, GetAttributeViInt64, (ViSession vi, ViConstString channelList, ViAttr attributeId, ViInt64* value), (override));
  MOCK_METHOD(ViStatus, GetAttributeViReal64, (ViSession vi, ViConstString channelList, ViAttr attributeId, ViReal64* value), (override));
  MOCK_METHOD(ViStatus, GetAttributeViString, (ViSession vi, ViConstString channelList, ViAttr attributeId, ViInt32 bufSize, ViChar value[]), (override));
  MOCK_METHOD(ViStatus, GetEqualizationFilterCoefficients, (ViSession vi, ViConstString channel, ViInt32 numberOfCoefficients, ViReal64 coefficients[]), (override));
  MOCK_METHOD(ViStatus, GetError, (ViSession vi, ViStatus* errorCode, ViInt32 bufferSize, ViChar description[]), (override));
  MOCK_METHOD(ViStatus, ImportAttributeConfigurationBuffer, (ViSession vi, ViInt32 sizeInBytes, ViInt8 configuration[]), (override));
  MOCK_METHOD(ViStatus, ImportAttributeConfigurationFile, (ViSession vi, ViConstString filePath), (override));
  MOCK_METHOD(ViStatus, InitWithOptions, (ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViConstString optionString, ViSession* vi), (override));
  MOCK_METHOD(ViStatus, InitiateAcquisition, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, LockSession, (ViSession vi, ViBoolean* callerHasLock), (override));
  MOCK_METHOD(ViStatus, ProbeCompensationSignalStart, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, ProbeCompensationSignalStop, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, Read, (ViSession vi, ViConstString channelList, ViReal64 timeout, ViInt32 numSamples, ViReal64 waveform[], struct niScope_wfmInfo wfmInfo[]), (override));
  MOCK_METHOD(ViStatus, ResetDevice, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, ResetWithDefaults, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, SendSoftwareTriggerEdge, (ViSession vi, ViInt32 whichTrigger), (override));
  MOCK_METHOD(ViStatus, SetAttributeViBoolean, (ViSession vi, ViConstString channelList, ViAttr attributeId, ViBoolean value), (override));
  MOCK_METHOD(ViStatus, SetAttributeViInt32, (ViSession vi, ViConstString channelList, ViAttr attributeId, ViInt32 value), (override));
  MOCK_METHOD(ViStatus, SetAttributeViInt64, (ViSession vi, ViConstString channelList, ViAttr attributeId, ViInt64 value), (override));
  MOCK_METHOD(ViStatus, SetAttributeViReal64, (ViSession vi, ViConstString channelList, ViAttr attributeId, ViReal64 value), (override));
  MOCK_METHOD(ViStatus, SetAttributeViString, (ViSession vi, ViConstString channelList, ViAttr attributeId, ViConstString value), (override));
  MOCK_METHOD(ViStatus, UnlockSession, (ViSession vi, ViBoolean* callerHasLock), (override));
  MOCK_METHOD(ViStatus, close, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, error_message, (ViSession vi, ViStatus errorCode, ViChar errorMessage[256]), (override));
  MOCK_METHOD(ViStatus, reset, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, self_test, (ViSession vi, ViInt16* selfTestResult, ViChar selfTestMessage[256]), (override));
};

}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // NI_SCOPE_GRPC_MOCK_LIBRARY_H
