
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-SYNC Metadata
//---------------------------------------------------------------------
#include "nisync_service.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <atomic>
#include <vector>

namespace nisync_grpc {

  NiSyncService::NiSyncService(NiSyncLibraryInterface* library, nidevice_grpc::SessionRepository* session_repository)
      : library_(library), session_repository_(session_repository)
  {
  }

  NiSyncService::~NiSyncService()
  {
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::Init(::grpc::ServerContext* context, const InitRequest* request, InitResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      ViRsrc resource_name = (ViRsrc)request->resource_name().c_str();
      ViBoolean id_query = request->id_query();
      ViBoolean reset_device = request->reset_device();

      auto init_lambda = [&] () -> std::tuple<int, uint32_t> {
        ViSession vi;
        int status = library_->init(resource_name, id_query, reset_device, &vi);
        return std::make_tuple(status, vi);
      };
      uint32_t session_id = 0;
      const std::string& session_name = request->session_name();
      auto cleanup_lambda = [&] (uint32_t id) { library_->close(id); };
      int status = session_repository_->add_session(session_name, init_lambda, cleanup_lambda, session_id);
      response->set_status(status);
      if (status == 0) {
        response->mutable_vi()->set_id(session_id);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::Close(::grpc::ServerContext* context, const CloseRequest* request, CloseResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      session_repository_->remove_session(vi);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::RevisionQuery(::grpc::ServerContext* context, const RevisionQueryRequest* request, RevisionQueryResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      std::string driver_revision(256, '\0');
      std::string firmware_revision(256, '\0');
      auto status = library_->RevisionQuery(vi, (ViChar*)driver_revision.data(), (ViChar*)firmware_revision.data());
      response->set_status(status);
      if (status == 0) {
        response->set_driver_revision(driver_revision);
        response->set_firmware_revision(firmware_revision);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SendSoftwareTrigger(::grpc::ServerContext* context, const SendSoftwareTriggerRequest* request, SendSoftwareTriggerResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      auto status = library_->SendSoftwareTrigger(vi, src_terminal);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::ConnectClkTerminals(::grpc::ServerContext* context, const ConnectClkTerminalsRequest* request, ConnectClkTerminalsResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      ViConstString dest_terminal = request->dest_terminal().c_str();
      auto status = library_->ConnectClkTerminals(vi, src_terminal, dest_terminal);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::DisconnectClkTerminals(::grpc::ServerContext* context, const DisconnectClkTerminalsRequest* request, DisconnectClkTerminalsResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      ViConstString dest_terminal = request->dest_terminal().c_str();
      auto status = library_->DisconnectClkTerminals(vi, src_terminal, dest_terminal);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::ConnectSWTrigToTerminal(::grpc::ServerContext* context, const ConnectSWTrigToTerminalRequest* request, ConnectSWTrigToTerminalResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      ViConstString dest_terminal = request->dest_terminal().c_str();
      ViConstString sync_clock = request->sync_clock().c_str();
      ViInt32 invert = request->invert();
      ViInt32 update_edge = request->update_edge();
      ViReal64 delay = request->delay();
      auto status = library_->ConnectSWTrigToTerminal(vi, src_terminal, dest_terminal, sync_clock, invert, update_edge, delay);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::DisconnectSWTrigFromTerminal(::grpc::ServerContext* context, const DisconnectSWTrigFromTerminalRequest* request, DisconnectSWTrigFromTerminalResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      ViConstString dest_terminal = request->dest_terminal().c_str();
      auto status = library_->DisconnectSWTrigFromTerminal(vi, src_terminal, dest_terminal);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::ConnectTrigTerminals(::grpc::ServerContext* context, const ConnectTrigTerminalsRequest* request, ConnectTrigTerminalsResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      ViConstString dest_terminal = request->dest_terminal().c_str();
      ViConstString sync_clock = request->sync_clock().c_str();
      ViInt32 invert = request->invert();
      ViInt32 update_edge = request->update_edge();
      auto status = library_->ConnectTrigTerminals(vi, src_terminal, dest_terminal, sync_clock, invert, update_edge);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::DisconnectTrigTerminals(::grpc::ServerContext* context, const DisconnectTrigTerminalsRequest* request, DisconnectTrigTerminalsResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      ViConstString dest_terminal = request->dest_terminal().c_str();
      auto status = library_->DisconnectTrigTerminals(vi, src_terminal, dest_terminal);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::MeasureFrequencyEx(::grpc::ServerContext* context, const MeasureFrequencyExRequest* request, MeasureFrequencyExResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString src_terminal = request->src_terminal().c_str();
      ViReal64 duration = request->duration();
      ViUInt32 decimation_count = request->decimation_count();
      ViReal64 actual_duration {};
      ViReal64 frequency {};
      ViReal64 frequency_error {};
      auto status = library_->MeasureFrequencyEx(vi, src_terminal, duration, decimation_count, &actual_duration, &frequency, &frequency_error);
      response->set_status(status);
      if (status == 0) {
        response->set_actual_duration(actual_duration);
        response->set_frequency(frequency);
        response->set_frequency_error(frequency_error);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SetTime(::grpc::ServerContext* context, const SetTimeRequest* request, SetTimeResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViInt32 time_source = request->time_source();
      ViUInt32 time_seconds = request->time_seconds();
      ViUInt32 time_nanoseconds = request->time_nanoseconds();
      ViUInt16 time_fractional_nanoseconds = request->time_fractional_nanoseconds();
      auto status = library_->SetTime(vi, time_source, time_seconds, time_nanoseconds, time_fractional_nanoseconds);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::GetTime(::grpc::ServerContext* context, const GetTimeRequest* request, GetTimeResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViUInt32 time_seconds {};
      ViUInt32 time_nanoseconds {};
      ViUInt16 time_fractional_nanoseconds {};
      auto status = library_->GetTime(vi, &time_seconds, &time_nanoseconds, &time_fractional_nanoseconds);
      response->set_status(status);
      if (status == 0) {
        response->set_time_seconds(time_seconds);
        response->set_time_nanoseconds(time_nanoseconds);
        response->set_time_fractional_nanoseconds(time_fractional_nanoseconds);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SetTimeReferenceFreeRunning(::grpc::ServerContext* context, const SetTimeReferenceFreeRunningRequest* request, SetTimeReferenceFreeRunningResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      auto status = library_->SetTimeReferenceFreeRunning(vi);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SetTimeReferenceGPS(::grpc::ServerContext* context, const SetTimeReferenceGPSRequest* request, SetTimeReferenceGPSResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      auto status = library_->SetTimeReferenceGPS(vi);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SetTimeReferenceIRIG(::grpc::ServerContext* context, const SetTimeReferenceIRIGRequest* request, SetTimeReferenceIRIGResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViInt32 irig_type = request->irig_type();
      ViConstString terminal_name = request->terminal_name().c_str();
      auto status = library_->SetTimeReferenceIRIG(vi, irig_type, terminal_name);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SetTimeReferencePPS(::grpc::ServerContext* context, const SetTimeReferencePPSRequest* request, SetTimeReferencePPSResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString terminal_name = request->terminal_name().c_str();
      ViBoolean use_manual_time = request->use_manual_time();
      ViUInt32 initial_time_seconds = request->initial_time_seconds();
      ViUInt32 initial_time_nanoseconds = request->initial_time_nanoseconds();
      ViUInt16 initial_time_fractional_nanoseconds = request->initial_time_fractional_nanoseconds();
      auto status = library_->SetTimeReferencePPS(vi, terminal_name, use_manual_time, initial_time_seconds, initial_time_nanoseconds, initial_time_fractional_nanoseconds);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SetTimeReference1588OrdinaryClock(::grpc::ServerContext* context, const SetTimeReference1588OrdinaryClockRequest* request, SetTimeReference1588OrdinaryClockResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      auto status = library_->SetTimeReference1588OrdinaryClock(vi);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SetTimeReference8021AS(::grpc::ServerContext* context, const SetTimeReference8021ASRequest* request, SetTimeReference8021ASResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      auto status = library_->SetTimeReference8021AS(vi);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::CreateFutureTimeEvent(::grpc::ServerContext* context, const CreateFutureTimeEventRequest* request, CreateFutureTimeEventResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString terminal_name = request->terminal_name().c_str();
      ViInt32 output_level = request->output_level();
      ViUInt32 time_seconds = request->time_seconds();
      ViUInt32 time_nanoseconds = request->time_nanoseconds();
      ViUInt16 time_fractional_nanoseconds = request->time_fractional_nanoseconds();
      auto status = library_->CreateFutureTimeEvent(vi, terminal_name, output_level, time_seconds, time_nanoseconds, time_fractional_nanoseconds);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::ClearFutureTimeEvents(::grpc::ServerContext* context, const ClearFutureTimeEventsRequest* request, ClearFutureTimeEventsResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString terminal_name = request->terminal_name().c_str();
      auto status = library_->ClearFutureTimeEvents(vi, terminal_name);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::CreateClock(::grpc::ServerContext* context, const CreateClockRequest* request, CreateClockResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString terminal_name = request->terminal_name().c_str();
      ViUInt32 high_ticks = request->high_ticks();
      ViUInt32 low_ticks = request->low_ticks();
      ViUInt32 start_time_seconds = request->start_time_seconds();
      ViUInt32 start_time_nanoseconds = request->start_time_nanoseconds();
      ViUInt16 start_time_fractional_nanoseconds = request->start_time_fractional_nanoseconds();
      ViUInt32 stop_time_seconds = request->stop_time_seconds();
      ViUInt32 stop_time_nanoseconds = request->stop_time_nanoseconds();
      ViUInt16 stop_time_fractional_nanoseconds = request->stop_time_fractional_nanoseconds();
      auto status = library_->CreateClock(vi, terminal_name, high_ticks, low_ticks, start_time_seconds, start_time_nanoseconds, start_time_fractional_nanoseconds, stop_time_seconds, stop_time_nanoseconds, stop_time_fractional_nanoseconds);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::ClearClock(::grpc::ServerContext* context, const ClearClockRequest* request, ClearClockResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString terminal_name = request->terminal_name().c_str();
      auto status = library_->ClearClock(vi, terminal_name);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::GetAttributeViInt32(::grpc::ServerContext* context, const GetAttributeViInt32Request* request, GetAttributeViInt32Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString active_item = request->active_item().c_str();
      ViAttr attribute = request->attribute();
      ViInt32 value {};
      auto status = library_->GetAttributeViInt32(vi, active_item, attribute, &value);
      response->set_status(status);
      if (status == 0) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SetAttributeViInt32(::grpc::ServerContext* context, const SetAttributeViInt32Request* request, SetAttributeViInt32Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString active_item = request->active_item().c_str();
      ViAttr attribute = request->attribute();
      ViInt32 value = request->value();
      auto status = library_->SetAttributeViInt32(vi, active_item, attribute, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::GetAttributeViString(::grpc::ServerContext* context, const GetAttributeViStringRequest* request, GetAttributeViStringResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString active_item = request->active_item().c_str();
      ViAttr attribute = request->attribute();

      auto status = library_->GetAttributeViString(vi, active_item, attribute, 0, nullptr);
      if (status < 0) {
        response->set_status(status);
        return ::grpc::Status::OK;
      }
      ViInt32 buffer_size = status;

      std::string value(buffer_size, '\0');
      status = library_->GetAttributeViString(vi, active_item, attribute, buffer_size, (ViChar*)value.data());
      response->set_status(status);
      if (status == 0) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SetAttributeViString(::grpc::ServerContext* context, const SetAttributeViStringRequest* request, SetAttributeViStringResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString active_item = request->active_item().c_str();
      ViAttr attribute = request->attribute();
      ViConstString value = request->value().c_str();
      auto status = library_->SetAttributeViString(vi, active_item, attribute, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::GetAttributeViBoolean(::grpc::ServerContext* context, const GetAttributeViBooleanRequest* request, GetAttributeViBooleanResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString active_item = request->active_item().c_str();
      ViAttr attribute = request->attribute();
      ViBoolean value {};
      auto status = library_->GetAttributeViBoolean(vi, active_item, attribute, &value);
      response->set_status(status);
      if (status == 0) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SetAttributeViBoolean(::grpc::ServerContext* context, const SetAttributeViBooleanRequest* request, SetAttributeViBooleanResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString active_item = request->active_item().c_str();
      ViAttr attribute = request->attribute();
      ViBoolean value = request->value();
      auto status = library_->SetAttributeViBoolean(vi, active_item, attribute, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::GetAttributeViReal64(::grpc::ServerContext* context, const GetAttributeViReal64Request* request, GetAttributeViReal64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString active_item = request->active_item().c_str();
      ViAttr attribute = request->attribute();
      ViReal64 value {};
      auto status = library_->GetAttributeViReal64(vi, active_item, attribute, &value);
      response->set_status(status);
      if (status == 0) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiSyncService::SetAttributeViReal64(::grpc::ServerContext* context, const SetAttributeViReal64Request* request, SetAttributeViReal64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
      ViConstString active_item = request->active_item().c_str();
      ViAttr attribute = request->attribute();
      ViReal64 value = request->value();
      auto status = library_->SetAttributeViReal64(vi, active_item, attribute, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

} // namespace nisync_grpc

