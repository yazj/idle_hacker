/**
 * @file terminal.cpp
 * @author yuanyi
 */
#include "terminal.hpp"
#include <spdlog/fmt/bundled/format.h>
#include <spdlog/fmt/fmt.h>
#include <spdlog/spdlog.h>
#include <string>

namespace terminal {

terminal::terminal() : _current_state(terminal_state::waiting) {
  spdlog::info("terminal initialized");
}

/** TODO render text*/
std::string terminal::generate_prompt() { return fmt::format("hello@ > "); }

void terminal::execute_command(const std::string &command) {
  spdlog::info("executing conmmand {}", command);

  // TODO add a new class 'command' to execute command string
  // now is just a simple demo to make sure game can run
  // RENDER TEXT
}

} // namespace terminal
