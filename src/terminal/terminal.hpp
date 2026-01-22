/**
 * @file Terminal.hpp
 * @brief Definition of the Terminal class for shell emulation.
 * @author yuanyi
 *
 * This class simulates terminal behavior and manages the command-line interface
 * logic. It serves as the central controller for user-system interaction.
 *
 * Key Responsibilities:
 * - Prompt Generation: Dynamically constructs the command-line prefix.
 * - Input Parsing: Sanitizes and tokenizes raw user input.
 * - Command Execution: Dispatches parsed commands to the respective logic
 * handlers.
 *
 * The terminal operates as a state machine with the following states:
 * - WAITING:   Idle state, awaiting the start of user interaction.
 * - TYPING:    Active state, buffering real-time keyboard input.
 * - EXECUTING: Processing state, running command logic and awaiting completion.
 */
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <string>
namespace terminal {

/**
 * @enum terminal_state
 * @brief Represents the current operational state of the terminal
 */
enum class terminal_state {
  waiting,  /**< Idle state, awaiting new user interaction. */
  typing,   /**< Active input mode, buffering keystrokes. */
  executing /**< Processing a command, input might be locked */
};

/**
 * @class terminal
 * @brief Core logic controller for the virtual shell enviroment
 */
class terminal {
public:
  terminal();
  ~terminal() = default;

  /**
   * @brief Dynamically constructs the command-line prefix string
   * @return A string representing the Prompt
   */
  std::string generate_prompt();

  /**
   * @brief Executes a validated command
   * @param command The command string to be processed
   */
  void execute_command(const std::string &command);

  /**
   * @breif Initialize terminal
   */
  void init_terminal();

  /**
   * @brief Terminal loop
   */
  void run();

  /**
   * @brief waiting状态时执行一次
   */
  void do_waiting();

  /**
   * @brief executing状态时执行一次
   */
  void do_executing();

  /**
   * @brief typing状态时执行一次
   */
  void do_typing();

private:
  terminal_state
      _current_state; /**< Current internal state of the state machine */

  // sfml window
  sf::RenderWindow _window;
};

} // namespace terminal
