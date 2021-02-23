<%
import common_helpers
import handler_helpers

config = data['config']
functions = data['functions']

service_class_prefix = config["service_class_prefix"]
namespace_prefix = "ni::" + config["namespace_component"] + "::grpc"
include_guard_name = handler_helpers.get_include_guard_name(config, "_LIBRARY_H")
%>\
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Real implementation of LibraryInterface for ${config["driver_name"]}
//---------------------------------------------------------------------
#ifndef ${include_guard_name}
#define ${include_guard_name}

#include "${config["module_name"]}_library_interface.h"

#include <hardware/grpc/internal/shared_library.h>

namespace ni {
namespace ${config["namespace_component"]} {
namespace grpc {

class ${service_class_prefix}Library : public ${namespace_prefix}::${service_class_prefix}LibraryInterface {
 public:
  ${service_class_prefix}Library();
  virtual ~${service_class_prefix}Library();

  ::grpc::Status check_function_exists(std::string functionName);
% for method_name in handler_helpers.filter_api_functions(functions):
<%
  f = functions[method_name]
  parameters = f['parameters']
  handler_helpers.sanitize_names(parameters)
  return_type = f['returns']
%>\
  ${return_type} ${method_name}(${handler_helpers.create_params(parameters)});
%endfor

 private:
 % for method_name in handler_helpers.filter_api_functions(functions):
<%
  f = functions[method_name]
  parameters = f['parameters']
  return_type = f['returns']
%>\
  using ${method_name}Ptr = ${return_type} (*)(${handler_helpers.create_params(parameters)});
%endfor

  typedef struct FunctionPointers {
% for method_name in handler_helpers.filter_api_functions(functions):
    ${method_name}Ptr ${method_name};
%endfor
  } FunctionLoadStatus;

  ni::hardware::grpc::internal::SharedLibrary shared_library_;
  FunctionPointers function_pointers_;
};

}  // namespace grpc
}  // namespace ${config["namespace_component"]}
}  // namespace ni

#endif  // ${include_guard_name}
