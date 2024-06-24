#include "configuration.pb.h"

#include <google/protobuf/util/json_util.h>

#include <fstream>
#include <iostream>

int main(int argc, char const* argv[]) {
   if (2 != argc) {
      std::cerr << "Not enough arguments\n";
      return -1;
   }
   std::ifstream infile(argv[1]);
   if (!infile.good()) {
      std::cerr << "Failed to read file\n";
      return -1;
   }
   std::string input((std::istreambuf_iterator<char>(infile)),
                      std::istreambuf_iterator<char>());
   com::srcinc::example::config::Configuration config;
   auto res = google::protobuf::util::JsonStringToMessage(input, &config);
   if (!res.ok()) {
      std::cerr << "Failed to parse json into protobuf message\n";
      return -1;
   }
   google::protobuf::util::JsonPrintOptions options;
   options.add_whitespace = false;
   options.always_print_primitive_fields = true;
   options.preserve_proto_field_names = true;
   std::string output;
   MessageToJsonString(config, &output, options);
   std::cout << output << std::endl;
}
