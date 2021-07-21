
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service header for the NI-FAKE-NON-IVI Metadata
//---------------------------------------------------------------------
#ifndef NIFAKE_NON_IVI_GRPC_SERVICE_H
#define NIFAKE_NON_IVI_GRPC_SERVICE_H

#include <nifake_non_ivi.grpc.pb.h>
#include <condition_variable>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <map>
#include <server/session_resource_repository.h>
#include <server/shared_library.h>
#include <server/exceptions.h>

#include "nifake_non_ivi_library_interface.h"

namespace nifake_non_ivi_grpc {

class NiFakeNonIviService final : public NiFakeNonIvi::Service {
public:
  using ResourceRepositorySharedPtr = std::shared_ptr<nidevice_grpc::SessionResourceRepository<FakeHandle>>;

  NiFakeNonIviService(NiFakeNonIviLibraryInterface* library, ResourceRepositorySharedPtr session_repository);
  virtual ~NiFakeNonIviService();
  
  ::grpc::Status Close(::grpc::ServerContext* context, const CloseRequest* request, CloseResponse* response) override;
  ::grpc::Status Init(::grpc::ServerContext* context, const InitRequest* request, InitResponse* response) override;
  ::grpc::Status InitWithHandleNameAsSessionName(::grpc::ServerContext* context, const InitWithHandleNameAsSessionNameRequest* request, InitWithHandleNameAsSessionNameResponse* response) override;
  ::grpc::Status InputArraysWithNarrowIntegerTypes(::grpc::ServerContext* context, const InputArraysWithNarrowIntegerTypesRequest* request, InputArraysWithNarrowIntegerTypesResponse* response) override;
  ::grpc::Status OutputArraysWithNarrowIntegerTypes(::grpc::ServerContext* context, const OutputArraysWithNarrowIntegerTypesRequest* request, OutputArraysWithNarrowIntegerTypesResponse* response) override;
  ::grpc::Status InputArrayOfBytes(::grpc::ServerContext* context, const InputArrayOfBytesRequest* request, InputArrayOfBytesResponse* response) override;
  ::grpc::Status OutputArrayOfBytes(::grpc::ServerContext* context, const OutputArrayOfBytesRequest* request, OutputArrayOfBytesResponse* response) override;
  ::grpc::Status RegisterCallback(::grpc::ServerContext* context, const RegisterCallbackRequest* request, RegisterCallbackResponse* response) override;
private:
  NiFakeNonIviLibraryInterface* library_;
  ResourceRepositorySharedPtr session_repository_;
};

} // namespace nifake_non_ivi_grpc

#endif  // NIFAKE_NON_IVI_GRPC_SERVICE_H
