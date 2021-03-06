#ifndef CLI_ARGS_HPP
#define CLI_ARGS_HPP

#include <iostream>
#include <string>

#include "clara.hpp"

namespace blas_benchmark {

typedef struct {
  std::string program_name;
  std::string device;
  std::string csv_param;
} Args;

namespace utils {

/**
 * @fn parse_args
 * @brief Returns a structure containing the data extracted from the
 * command-line arguments.
 */
inline Args parse_args(int argc, char** argv) {
  Args args;
  args.program_name = std::string(argv[0]);
  bool show_help;

  auto parser =
      clara::Help(show_help) |
      clara::Opt(args.device, "device")["--device"](
          "Select a device (best effort) for running the benchmark.") |
      clara::Opt(args.csv_param, "filepath")["--csv-param"](
          "Select which CSV file to read the benchmark parameters from");

  auto res = parser.parse(clara::Args(argc, argv));
  if (!res) {
    std::cerr << "Error in command line: " << res.errorMessage() << std::endl;
    exit(1);
  } else if (show_help) {
    std::cout << parser << std::endl;
  }

  return args;
}

}  // namespace utils
}  // namespace blas_benchmark

#endif
