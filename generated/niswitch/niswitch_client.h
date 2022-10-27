
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// EXPERIMENTAL Client convenience wrapper for NI-SWITCH.
//---------------------------------------------------------------------
#ifndef NISWITCH_GRPC_CLIENT_H
#define NISWITCH_GRPC_CLIENT_H

#include <grpcpp/grpcpp.h>

#include <niswitch.grpc.pb.h>
#include <tests/utilities/client_helpers.h>

#include <memory>
#include <vector>

namespace niswitch_grpc::experimental::client {

namespace pb = ::google::protobuf;
using StubPtr = std::unique_ptr<NiSwitch::Stub>;
using namespace nidevice_grpc::experimental::client;


AbortScanResponse abort_scan(const StubPtr& stub, const nidevice_grpc::Session& vi);
CanConnectResponse can_connect(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel1, const pb::string& channel2);
CheckAttributeViBooleanResponse check_attribute_vi_boolean(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id, const bool& attribute_value);
CheckAttributeViInt32Response check_attribute_vi_int32(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id, const simple_variant<NiSwitchInt32AttributeValues, pb::int32>& attribute_value);
CheckAttributeViReal64Response check_attribute_vi_real64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id, const double& attribute_value);
CheckAttributeViSessionResponse check_attribute_vi_session(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id, const nidevice_grpc::Session& attribute_value);
CheckAttributeViStringResponse check_attribute_vi_string(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id, const pb::string& attribute_value);
ClearErrorResponse clear_error(const StubPtr& stub, const nidevice_grpc::Session& vi);
ClearInterchangeWarningsResponse clear_interchange_warnings(const StubPtr& stub, const nidevice_grpc::Session& vi);
CloseResponse close(const StubPtr& stub, const nidevice_grpc::Session& vi);
CommitResponse commit(const StubPtr& stub, const nidevice_grpc::Session& vi);
ConfigureScanListResponse configure_scan_list(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& scanlist, const simple_variant<ScanMode, pb::int32>& scan_mode);
ConfigureScanTriggerResponse configure_scan_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const double& scan_delay, const simple_variant<TriggerInput, pb::int32>& trigger_input, const simple_variant<ScanAdvancedOutput, pb::int32>& scan_advanced_output);
ConnectResponse connect(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel1, const pb::string& channel2);
ConnectMultipleResponse connect_multiple(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& connection_list);
DisableResponse disable(const StubPtr& stub, const nidevice_grpc::Session& vi);
DisconnectResponse disconnect(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel1, const pb::string& channel2);
DisconnectAllResponse disconnect_all(const StubPtr& stub, const nidevice_grpc::Session& vi);
DisconnectMultipleResponse disconnect_multiple(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& disconnection_list);
ErrorMessageResponse error_message(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& error_code);
ErrorQueryResponse error_query(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetAttributeViBooleanResponse get_attribute_vi_boolean(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id);
GetAttributeViInt32Response get_attribute_vi_int32(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id);
GetAttributeViReal64Response get_attribute_vi_real64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id);
GetAttributeViSessionResponse get_attribute_vi_session(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id);
GetAttributeViStringResponse get_attribute_vi_string(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id);
GetChannelNameResponse get_channel_name(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& index);
GetErrorResponse get_error(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetNextCoercionRecordResponse get_next_coercion_record(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetNextInterchangeWarningResponse get_next_interchange_warning(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetPathResponse get_path(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel1, const pb::string& channel2);
GetRelayCountResponse get_relay_count(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& relay_name);
GetRelayNameResponse get_relay_name(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& index);
GetRelayPositionResponse get_relay_position(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& relay_name);
InitResponse init(const StubPtr& stub, const pb::string& resource_name, const bool& id_query, const bool& reset_device, const nidevice_grpc::SessionInitializationBehavior& initialization_behavior);
InitWithOptionsResponse init_with_options(const StubPtr& stub, const pb::string& resource_name, const bool& id_query, const bool& reset_device, const pb::string& option_string, const nidevice_grpc::SessionInitializationBehavior& initialization_behavior);
InitWithTopologyResponse init_with_topology(const StubPtr& stub, const pb::string& resource_name, const pb::string& topology, const bool& simulate, const bool& reset_device, const nidevice_grpc::SessionInitializationBehavior& initialization_behavior);
InitiateScanResponse initiate_scan(const StubPtr& stub, const nidevice_grpc::Session& vi);
InvalidateAllAttributesResponse invalidate_all_attributes(const StubPtr& stub, const nidevice_grpc::Session& vi);
IsDebouncedResponse is_debounced(const StubPtr& stub, const nidevice_grpc::Session& vi);
IsScanningResponse is_scanning(const StubPtr& stub, const nidevice_grpc::Session& vi);
RelayControlResponse relay_control(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& relay_name, const simple_variant<RelayAction, pb::int32>& relay_action);
ResetResponse reset(const StubPtr& stub, const nidevice_grpc::Session& vi);
ResetInterchangeCheckResponse reset_interchange_check(const StubPtr& stub, const nidevice_grpc::Session& vi);
ResetWithDefaultsResponse reset_with_defaults(const StubPtr& stub, const nidevice_grpc::Session& vi);
RevisionQueryResponse revision_query(const StubPtr& stub, const nidevice_grpc::Session& vi);
RouteScanAdvancedOutputResponse route_scan_advanced_output(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<ScanAdvancedOutput, pb::int32>& scan_advanced_output_connector, const simple_variant<ScanAdvancedOutput, pb::int32>& scan_advanced_output_bus_line, const bool& invert);
RouteTriggerInputResponse route_trigger_input(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<TriggerInput, pb::int32>& trigger_input_connector, const simple_variant<TriggerInput, pb::int32>& trigger_input_bus_line, const bool& invert);
ScanResponse scan(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& scanlist, const simple_variant<HandshakingInitiation, pb::int32>& initiation);
SelfTestResponse self_test(const StubPtr& stub, const nidevice_grpc::Session& vi);
SendSoftwareTriggerResponse send_software_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi);
SetAttributeViBooleanResponse set_attribute_vi_boolean(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id, const bool& attribute_value);
SetAttributeViInt32Response set_attribute_vi_int32(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id, const simple_variant<NiSwitchInt32AttributeValues, pb::int32>& attribute_value);
SetAttributeViReal64Response set_attribute_vi_real64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id, const double& attribute_value);
SetAttributeViSessionResponse set_attribute_vi_session(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id, const nidevice_grpc::Session& attribute_value);
SetAttributeViStringResponse set_attribute_vi_string(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiSwitchAttribute& attribute_id, const pb::string& attribute_value);
SetContinuousScanResponse set_continuous_scan(const StubPtr& stub, const nidevice_grpc::Session& vi, const bool& continuous_scan);
SetPathResponse set_path(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& path_list);
WaitForDebounceResponse wait_for_debounce(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& maximum_time_ms);
WaitForScanCompleteResponse wait_for_scan_complete(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& maximum_time_ms);

} // namespace niswitch_grpc::experimental::client

#endif /* NISWITCH_GRPC_CLIENT_H */
