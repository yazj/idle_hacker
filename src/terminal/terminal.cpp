/**
 * @file terminal.cpp
 * @author yuanyi
 */
#include "terminal.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <spdlog/fmt/bundled/format.h>
#include <spdlog/fmt/fmt.h>
#include <spdlog/spdlog.h>
#include <string>

namespace terminal {

terminal::terminal() : _current_state(terminal_state::waiting) {
  spdlog::info("terminal initialized");
}

std::string terminal::generate_prompt() { return fmt::format("hello@ > "); }

void terminal::execute_command(const std::string &command) {
  spdlog::info("executing conmmand {}", command);
}

void terminal::run() {
  // loop
  spdlog::info("terminal start running");
  while (1) {
    // 这里我使用switch来实现一个状态机,
    // 每个状态结束后, 会根据函数执行状态切换进下一个状态,
    // 从而实现循环
    switch (_current_state) {
    case terminal_state::waiting:
      terminal::do_waiting();
      break;
    case terminal_state::executing:
      terminal::do_executing();
      break;
    case terminal_state::typing:
      terminal::do_typing();
      break;
    }
    _window.display();
  }
}

void terminal::do_waiting() {
  spdlog::info("terminal is waiting");
  // show the prompt every frame
  generate_prompt();
  // TODO render on the scrren
};

void terminal::do_executing() { spdlog::info("terminal executing command"); };

void terminal::do_typing() { spdlog::info("user is typing"); };

void terminal::init_terminal(buffer::buffer &buffer, render::render &render) {
  _window =
      sf::RenderWindow(sf::VideoMode({800, 600}), "welcome to idle hacker!!");

  _p_buffer = &buffer;
  _p_render = &render;
}

} // namespace terminal
