#include "terminal/terminal.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

int main() {

  // init spdlog
  auto console = spdlog::stdout_color_mt("console");
  spdlog::set_default_logger(console);

  spdlog::set_level(spdlog::level::debug);

  // init terminal
  terminal::terminal terminal;
  terminal.run();

  return 0;
}
