//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Register all services header.
//---------------------------------------------------------------------
#ifndef NIDEVICE_GRPC_REGISTER_ALL_SERVICES_H
#define NIDEVICE_GRPC_REGISTER_ALL_SERVICES_H
#include <server/feature_toggles.h>

#include <memory>
#include <vector>

namespace grpc {
class ServerBuilder;
}

namespace nidevice_grpc {

std::shared_ptr<std::vector<std::shared_ptr<void>>> register_all_services(
  grpc::ServerBuilder& server_builder,
  const nidevice_grpc::FeatureToggles& feature_toggles);

} // nidevice_grpc

#endif  // NIDEVICE_GRPC_REGISTER_ALL_SERVICES_H
