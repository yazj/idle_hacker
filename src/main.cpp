#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

int main() {
  auto console = spdlog::stdout_color_mt("console");
  spdlog::set_default_logger(console);

  spdlog::set_level(spdlog::level::debug);

  spdlog::info("Welcome to idle_hacker");
  spdlog::error("Oh it's so cool");

  return 0;
}
